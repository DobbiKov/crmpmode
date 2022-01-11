CMD:punishments(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);

    extract params -> new string: to_player[24]; else return SCM(playerid, blue, "[Подсказка] {FFFFFF}Используйте: /punishments [ID/NickName игрока]");

    if(IsNumeric(to_player))
    {
        new to_playerid = strval(to_player);
        if(!PlayerInfo[to_playerid][pLogin] || !IsPlayerConnected(to_playerid)) return PlayerOffLine(playerid);
        format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
    }

    new query[144];
    format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    mysql_tquery(connects, query, "punishments_check_account", "ds", playerid, to_player);
    return 1;
}

publics punishments_check_account(playerid, to_player[])
{
    new rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        new acc_id = cache_get_field_content_int(0, "pID");  
        new adm_lvl = cache_get_field_content_int(0, "bAdmin"); 

        if(PlayerInfo[playerid][bAdmin] < adm_lvl)
            return SCM(playerid, red, !"Вы не можете просмотреть историю наказаний данного игрока!");
        
        new query[144];
        format(query, sizeof(query), "SELECT * FROM `nakazania` WHERE `AccountId` = '%d' ORDER BY `id` DESC", acc_id);
        mysql_tquery(connects, query, "player_punishments", "dsd", playerid, to_player, acc_id);
    }
    else
        return SCM(playerid, red, !"Такого аккаунта не существует!");
    return 1;
}

publics player_punishments(playerid, to_player[], acc_id)
{
    new rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        new string[2056];
        for(new i = 0; i < rows[0]; i++)
        {
            new adminName[MAX_PLAYER_NAME], playerName[MAX_PLAYER_NAME], _date[64], _time, _reason[144], _type[144];

            cache_get_field_content(i, "AdminName", adminName, connects, MAX_PLAYER_NAME);
            cache_get_field_content(i, "Name", playerName, connects, MAX_PLAYER_NAME);
            cache_get_field_content(i, "Date", _date, connects, 64);
            cache_get_field_content(i, "Reason", _reason, connects, 144);
            cache_get_field_content(i, "Type", _type, connects, 144);
            _time = cache_get_field_content_int(i, "Time");

            new temp_string[256];
            format(temp_string, sizeof(temp_string), "{"cred"}%s\n", InterpritatePunishmentMessage(adminName, playerName, _date, _time, _reason, _type));
            strcat(string, temp_string);
        }
        new string_title[64];
        format(string_title, sizeof(string_title), "{"cred"}История наказаний %s", to_player);
        return ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, string_title, string, !"Закрыть", !"");
    }
    else
        return SCM(playerid, red, !"История наказаний игрока пуста!");
}

stock InterpritatePunishmentMessage(adminName[], playerName[], _date[], _time, _reason[], _type[])
{
    new _string[256];
    if(!strcmp(_type, "ban"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s забанил %s на %d дней. Причина: %s", _date, adminName, playerName, _time, _reason);
    }
    if(!strcmp(_type, "offban"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s забанил оффлайн %s на %d дней. Причина: %s", _date, adminName, playerName, _time, _reason);
    }
    if(!strcmp(_type, "unban"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s разбанил %s.", _date, adminName, playerName);
    }
    if(!strcmp(_type, "warn"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s выдал предупреждение %s. Причина: %s", _date, adminName, playerName, _reason);
    }
    if(!strcmp(_type, "offwarn"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s выдал предупреждение оффлайн %s. Причина: %s", _date, adminName, playerName, _reason);
    }
    if(!strcmp(_type, "unwarn"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s снял предупреждение %s.", _date, adminName, playerName, _time, _reason);
    }
    if(!strcmp(_type, "offunwarn"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s снял предупреждение оффлайн %s.", _date, adminName, playerName, _time, _reason);
    }
    if(!strcmp(_type, "mute"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s выдал затычку %s на %d минут. Причина: %s", _date, adminName, playerName, _time, _reason);
    }
    if(!strcmp(_type, "offmute"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s выдал затычку оффлайн %s на %d минут. Причина: %s", _date, adminName, playerName, _time, _reason);
    }
    if(!strcmp(_type, "unmute"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s снял затычку %s.", _date, adminName, playerName);
    }
    if(!strcmp(_type, "jail"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s посадил в деморган %s на %d минут. Причина: %s", _date, adminName, playerName, _time, _reason);
    }
    if(!strcmp(_type, "offjail"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s посадил в деморган оффлайн %s на %d минут. Причина: %s", _date, adminName, playerName, _time, _reason);
    }
    if(!strcmp(_type, "unjail"))
    {
        format(_string, sizeof(_string), "%s | Администратор %s выпустил из деморгана %s.", _date, adminName, playerName);
    }
    return _string;
}