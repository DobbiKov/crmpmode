CMD:givemoney(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

	extract params -> new string: to_playername[24], count; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /givemoney [ID игрока] [количество]");

	if(IsNumeric(to_playername))
    {
        new to_player = strval(to_playername);
        if(!PlayerInfo[to_player][pLogin] || !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);
        // format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
		GiveMoney(to_player, count, "/givemoney");

		SaveAccounts(playerid);
		SaveAccounts(to_player);

        new string[144];

        format(string, sizeof(string), "{ffffff}Администратор %s выдал вам %d %d руб.", PlayerInfo[playerid][pName], count);
        SCM(to_player, white, string);

        format(string, sizeof(string), "{ffffff}Вы выдали игроку %s %d руб.", PlayerInfo[to_player][pName], count); 
        SCM(playerid, white, string);
        return 1;
    }


	static const fmt_query[] = "SELECT pID,pCash FROM `accounts` WHERE `pName` = '%s' LIMIT 1";
    new query[sizeof(fmt_query)+(MAX_PLAYER_NAME)];
    format(query, sizeof(query), fmt_query, to_playername);
    return mysql_tquery(connects, query, "off_give_money", "isi", playerid, to_playername, count);
}

publics off_give_money(playerid, to_player[], cash)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
        new old_cash, acc_id;
        old_cash = cache_get_field_content_int(0, "pCash");
        acc_id = cache_get_field_content_int(0, "pID");

        old_cash += cash;

        new string[144];
        format(string, sizeof(string), "{ffffff}Вы выдали игроку %s %d руб.", to_player, cash); 
        SCM(playerid, white, string);

        new query[144];
        format(query, sizeof(query), "UPDATE `accounts` SET `pCash` = '%d' WHERE `pID` = '%d'", old_cash, acc_id);
        mysql_tquery(connects, query);

		new Year, Month, Day;
		getdate(Year, Month, Day);

		new Hour, Minute;
		gettime(Hour, Minute);

		mysql_format(connects, stringer, sizeof(stringer), "INSERT INTO `givemoney` (`Nick`, `Money`, `Reason`, `ip`, `time`) VALUES ('%d', '%d', '%s', '%s', '%d-%02d-%02d %d:%02d')", acc_id, cash, "выдача денег оффлайн администратором", "0.0.0.0", Day, Month, Year, Hour, Minute);
		mysql_tquery(connects, stringer);

		return 1;
	}
	else
	{
	    SCM(playerid, red, "Такого игрока нет!");
	}
	return 1;
}