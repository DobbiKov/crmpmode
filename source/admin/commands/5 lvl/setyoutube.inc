CMD:setyoutube(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 5) return ShowCommandNotFound(playerid);

	extract params -> new string: to_player[24], level; else return SCM(playerid, blue, "[���������] {ffffff}�������: /setyoutube [��� ������] [0 - ����� | 1 - ���������]");
	
	if(level != 1 && level != 0) return SCM(playerid, red, "������ 0, ��� 1!");

    if(IsNumeric(to_player))
    {
        new to_playerid = strval(to_player);
        if(!PlayerInfo[to_playerid][pLogin] || !IsPlayerConnected(to_playerid)) return PlayerOffLine(playerid);
        format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
    }

 	foreach(new i:Player)
 	{
 		if(!strcmp(PlayerInfo[i][pName], to_player, true))
 		{
	 		PlayerInfo[i][bYoutube] = level;

			new string[256];
			format(string, sizeof(string), "[A] %s[%d] ��������� ������ %s[%d] %d ������� ��������", PlayerInfo[playerid][pName], playerid, PlayerInfo[i][pName], i, level);
			SCMA(grey, string);
			SaveAccounts(playerid);
			return SaveAccounts(i);
		}
 	}
	static const fmt_query[] = "SELECT * FROM `accounts` WHERE `pName` = '%s' LIMIT 1";
    new query[sizeof(fmt_query)+(-2+MAX_PLAYER_NAME)];
    format(query, sizeof(query), fmt_query, to_player);
    return mysql_tquery(connects, query, "off_set_youtube", "isi", playerid, to_player, level);
}

publics off_set_youtube(playerid, to_player[], level)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
	    new string[256], sql_str[128];
	    format(string, sizeof(string), "[A] %s[%d] ��������� ������ %s %d ������� ��������", PlayerInfo[playerid][pName], playerid, to_player, level);
	    SCMA(grey, string);

	    format(sql_str, sizeof(sql_str), "UPDATE `accounts` SET `bYoutube` = '%d' WHERE `pName` = '%s' LIMIT 1", level, to_player);
	    mysql_tquery(connects, sql_str, "", "");
	}
	else
	{
	    SCM(playerid, red, "������ ������ ���.");
	}
	return 1;
}