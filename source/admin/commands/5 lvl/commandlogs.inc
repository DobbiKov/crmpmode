CMD:commandlogs(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 5) return ShowCommandNotFound(playerid);

    extract params -> new account_id, string: cmd_name[24]; else return SCM(playerid, blue, "[Подсказка] {ffffff}Введите: /commandlogs [ID аккаунта] [название команды]");
    
    new query[144];
    format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pID` = '%d'", account_id);
    mysql_tquery(connects, query, "Off_commandlogs", "dds", playerid, account_id, cmd_name);
    
    return 1;
}

publics Off_commandlogs(playerid, account_id, cmd_name[])
{
    new rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        new admin = cache_get_field_content_int(0, "bAdmin");
        new to_player[64];
        
        
        if(PlayerInfo[playerid][bAdmin] < admin) 
            return SCM(playerid, red, !"Вы не можете посмотреть логи данного администратора!");
        
        cache_get_field_content(0, "pName", to_player, connects, MAX_PLAYER_NAME);
        
        new string[128] = "";
        if(strcmp(cmd_name, "all", true))
        {
            format(string, sizeof(string), "AND `cmd_name` = '%s'", cmd_name);
    
        }

        new query[144];
        format(query, sizeof(query), "SELECT * FROM `commands_logs` WHERE `account_id` = '%d' %s ORDER BY `date` DESC", account_id, string);
        mysql_tquery(logs_connects, query, "Off_commandlogs_check", "ddss", playerid, account_id, cmd_name, to_player);

        return 1;
    }
    else
    {
        return SCM(playerid, red, "Такого игрока нет!");
    }
}

publics Off_commandlogs_check(playerid, account_id, cmd_name[], to_player[])
{
    new rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {  
        new string[2096] = "";
        for(new i = 0; i < rows[0]; i++)
        {
            new temp_string[1024] = "";
            new _date;
            new _cmd_name[64] = "";
            new cmd_text[256] = "";
            _date = cache_get_field_content_int(i, "date");
            cache_get_field_content(i, "cmd_name", _cmd_name, logs_connects, MAX_PLAYER_NAME);
            cache_get_field_content(i, "cmd_text", cmd_text, logs_connects, MAX_PLAYER_NAME);
            format(temp_string, sizeof(temp_string), "{ffffff}%s %s\n", date("%dd.%mm.%yyyy, %hh:%ii:%ss",_date), cmd_text);
            strcat(string, temp_string);
        }

        new title_string[128] = "";
        format(title_string, sizeof(title_string), "{"cblue"}Logs %s %s", cmd_name, to_player);


        ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, title_string, string, !"Закрыть", !"");

        return 1;
    }
    else
    {
        return SCM(playerid, red, "Логи по данной команде не найдены!");
    }
}