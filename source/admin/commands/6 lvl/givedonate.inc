CMD:givedonate(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);
    extract params -> new string: to_playername[24], donate; else return SCM(playerid, blue, !"[Подсказка]: {ffffff}Используйте /givedonate [id игрока] [кол-во доната]");

    if(IsNumeric(to_playername))
    {
        new to_player = strval(to_playername);
        if(!PlayerInfo[to_player][pLogin] || !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);
        // format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
        PlayerInfo[to_player][pDonate] += donate;

        new string[144];

        format(string, sizeof(string), "{ffffff}Администратор %s выдал вам %d %d кредитов.", PlayerInfo[playerid][pName], donate);
        SCM(to_player, white, string);

        format(string, sizeof(string), "{ffffff}Вы выдали игроку %s %d кредитов.", PlayerInfo[to_player][pName], donate); 
        SCM(playerid, white, string);
        return 1;
    }


	static const fmt_query[] = "SELECT pID,pDonate FROM `accounts` WHERE `pName` = '%s' LIMIT 1";
    new query[sizeof(fmt_query)+(MAX_PLAYER_NAME)];
    format(query, sizeof(query), fmt_query, to_playername);
    return mysql_tquery(connects, query, "off_give_donate", "isi", playerid, to_playername, donate);
}

publics off_give_donate(playerid, to_player[], donate)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
        new old_donate, acc_id;
        old_donate = cache_get_field_content_int(0, "pDonate");
        acc_id = cache_get_field_content_int(0, "pID");

        old_donate += donate;

        new string[144];
        format(string, sizeof(string), "{ffffff}Вы выдали игроку %s %d кредитов.", to_player, donate); 
        SCM(playerid, white, string);

        new query[144];
        format(query, sizeof(query), "UPDATE `accounts` SET `pDonate` = '%d' WHERE `pID` = '%d'", old_donate, acc_id);
        return mysql_tquery(connects, query);
	}
	else
	{
	    SCM(playerid, red, "Такого игрока нет!");
	}
	return 1;
}

