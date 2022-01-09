CMD:get_player_by_mysql(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 2) return ShowCommandNotFound(playerid);

    extract params -> new mysql_id; else return SCM(playerid, blue, "[Подсказка] {FFFFFF}Используйте: /get_player_by_mysql [MySQL ID]");

    foreach(new i : Player)
    {
        if(PlayerInfo[i][pID] == mysql_id)
        {
            new string[256] = "";
            format(string, sizeof(string), "{ffffff}Игрок: %s[%d]\n\
                                            {ffffff}Посмотреть статистику игрока - {"cblue"}/stat %d", PlayerInfo[i][pName], i, i);
            return SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}Игрок обнаружен на сервере!", string, "Закрыть", "");
        }
    }

    new string[128];
    format(string, sizeof(string), "SELECT * FROM `accounts` WHERE `pID` = '%d'", mysql_id);
    mysql_tquery(connects, string, "OffGetPlayerByMySQL", "dd", playerid, mysql_id);
    return 1;
}

publics OffGetPlayerByMySQL(playerid, mysql_id)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
    {
        new p_name[50], ip[16];

        cache_get_field_content(0, "pLastIP", ip, connects, 144);
        cache_get_field_content(0, "pName", p_name, connects, 144);

        for(new i = 0; i < sizeof(SuperNick_S); i++) if(!strcmp(p_name, SuperNick_S[i], true)) return SCM(playerid, red, "Игрока с таким ID аккаунта не существует!");


        new string[256];
        format(string, sizeof(string), "{FFFFFF}ID аккаунта игрока: %d\nНикнейм игрока: %s\nLast IP: %s", 
        mysql_id, p_name, ip);

        SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}Игрок найден", string, "Закрыть", "");
    }
    else
    {
        SCM(playerid, red, "Игрока с таким ID аккаунта не существует!");
    }
    return 1;
}