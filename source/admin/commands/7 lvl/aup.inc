CMD:aup(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

	extract params -> new string: to_player[24]; else return SCM(playerid, blue, "[���������] {ffffff}�������: /aup [��� ������]");

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
 		    if(PlayerInfo[i][bAdmin] == 0) return SCM(playerid, red, "������ ����� �� �������������.");
 		    if(PlayerInfo[playerid][bAdmin] == 6)
 		    {
 		        if(PlayerInfo[i][bAdmin] >= 5) return SCM(playerid, red, "������� �������������� ������� ������ ����� 5, ��� �����.");
 		    }
 		    if(PlayerInfo[i][bAdmin] >= 7) return SCM(playerid, red, "������� �������������� ������� ������ ����� 7, ��� �����.");
	 		PlayerInfo[i][bAdmin]++;

			new string[256];
			format(string, sizeof(string), "[A] %s[%d] ������� ������� �������������� ������ %s[%d] �� %d", PlayerInfo[playerid][pName], playerid, PlayerInfo[i][pName], i, PlayerInfo[i][bAdmin]);
			SCMA(grey, string);
			SaveAccounts(playerid);
			return SaveAccounts(i);
		}
 	}


	static const fmt_query[] = "SELECT * FROM `accounts` WHERE `pName` = '%s' LIMIT 1";
    new query[sizeof(fmt_query)+(-2+MAX_PLAYER_NAME)];
    format(query, sizeof(query), fmt_query, to_player);
    return mysql_tquery(connects, query, "off_aup","is", playerid, to_player);
}

publics off_aup(playerid, to_player[])
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
	    new admin;
	    admin = cache_get_field_content_int(0, "bAdmin");
	    if(admin > PlayerInfo[playerid][bAdmin] || admin > 5) return SCM(playerid, red, "������ ����� ��� �������������.");

	    admin++;

	    new string[256], sql_str[128];
	    format(string, sizeof(string), "[A] %s[%d] ������� ������ %s ������� �������������� �� %d", PlayerInfo[playerid][pName], playerid, to_player, admin);
	    SCMA(grey, string);

	    format(sql_str, sizeof(sql_str), "UPDATE `accounts` SET `bAdmin` = '%d' WHERE `pName` = '%s' LIMIT 1", admin, to_player);
	    mysql_tquery(connects, sql_str, "", "");
	}
	else
	{
	    SCM(playerid, red, "������ ������ ���.");
	}
	return 1;
}