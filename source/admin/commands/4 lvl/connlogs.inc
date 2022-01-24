CMD:connlogs(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 4) return ShowCommandNotFound(playerid);

    extract params -> new string: to_player[24]; else return SCM(playerid, blue, "[Подсказка] {ffffff}Введите: /connlogs [Ник/ID игрока]");

    if(IsNumeric(to_player))
    {
        new to_playerid = strval(to_player);
        if(!PlayerInfo[to_playerid][pLogin] || !IsPlayerConnected(to_playerid)) return PlayerOffLine(playerid);
        format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
    }

    if(!CheckFD(playerid) && CheckNickFD(to_player))
        return SCM(playerid, red, !"Вы не можете посмотреть логи данного аккаунта!");

    new query[345];
    format(query, sizeof(query), "SELECT pID, bAdmin FROM accounts WHERE pName = '%s'", to_player);
    mysql_tquery(connects, query, "Off_GetConnsAccount", "ds", playerid, to_player);
    return 1;
}

CMD:conniplogs(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 4) return ShowCommandNotFound(playerid);

    extract params -> new string: ip[24]; else return SCM(playerid, blue, "[Подсказка] {ffffff}Введите: /conniplogs [IP Адресс]");

    // if(IsNumeric(to_player))
    // {
    //     new to_playerid = strval(to_player);
    //     if(!PlayerInfo[to_playerid][pLogin] || !IsPlayerConnected(to_playerid)) return PlayerOffLine(playerid);
    //     format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
    // }

    // if(!CheckFD(playerid) && CheckNickFD(to_player))
    //     return SCM(playerid, red, !"Вы не можете посмотреть логи данного аккаунта!");

    new query[345];
    format(query, sizeof(query), "SELECT \
    id, nick, ip, date, type \
    FROM connects WHERE ip = '%s'\
    ORDER BY id DESC", ip);
    mysql_tquery(connects, query, "Off_GetConns", "ds", playerid, ip);
    return 1;
}

publics Off_GetConnsAccount(playerid, to_player[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(!rows)
        return SCM(playerid, red, !"Такого игрока нет!");

    new acc_id = cache_get_field_content_int(0, "pID");
    new badmin = cache_get_field_content_int(0, "bAdmin");

    if(PlayerInfo[playerid][bAdmin] < badmin)
        return SCM(playerid, red, !"Вы не можете посмотреть логи данного аккаунта!");

    new query[345];
    format(query, sizeof(query), "SELECT \
    id, nick, ip, date, type \
    FROM connects WHERE account_id = '%d'\
    ORDER BY id DESC", acc_id);
    mysql_tquery(connects, query, "Off_GetConns", "ds", playerid, to_player);

    return 1;
}

publics Off_GetConns(playerid, to_player[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(!rows)
        return SCM(playerid, red, !"Логов по данному игроку нет!");
    new string[4012] = "{"cblue"}Дата\t\t\tНикнейм\t\tТип\t\tIP Адресс\n\n";
    new title_string[64];
    format(title_string, sizeof(title_string), "{"cgrey"}%s", to_player);

    for(new i = 0; i < rows; i++)
    {
        new temp_string[256];
        new _type, _date[64], nickname[64], ip[16];

        _type = cache_get_field_content_int(i, "type");
        cache_get_field_content(i, "date", _date, connects, 144);
        cache_get_field_content(i, "nick", nickname, connects, 144);
        cache_get_field_content(i, "ip", ip, connects, 144);

        if(!CheckFD(playerid) && CheckNickFD(nickname))
            continue;

        new type_name[64];
        GetConnTypeString(_type, type_name);

        format(
            temp_string, 
            sizeof(temp_string), 
            "{"cblue"}{ffffff}%s \t%s\t\t%s \t%s\n",
            _date, nickname, type_name, ip
        );
        strcat(string, temp_string);
    }

    ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, title_string, string, !"Закрыть", !"");
    return 1;
}

stock GetConnTypeString(type, dest[])
{
    if(type == CONN_TYPE_CONNECT)
        format(dest, 64, "подключился");
    else if(type == CONN_TYPE_DISCONNECT)
        format(dest, 64, "отключился");
    return 1;
}