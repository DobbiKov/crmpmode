CMD:setadmin(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

	extract params -> new string: to_player[24], level; else return SCM(playerid, blue, "[���������] {ffffff}�������: /setadmin [��� ������] [LVL �������]");

	if(PlayerInfo[playerid][bAdmin] == 6 && level != 1) return SCM(playerid, red, !"�� ������ ��������� ������ ������������� �� 1 ������� ��������������.");

	if(PlayerInfo[playerid][bAdmin] <= level)
	{
		return SCM(playerid, red, !"�� �� ������ ��������� �������������� ������� ���� ����!");
	}
	if(PlayerInfo[playerid][bAdmin] < 7)
	{
		if(level < 0 || level > 5)
			return SCM(playerid, red, "������� �������������� �� ������ 5 � �� ������ 0!");
	}
	if(level < 0 || level > 7) return SCM(playerid, red, "������� �������������� �� ������ 7 � �� ������ 0!");

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
			if(!IsPlayerConnected(i) || PlayerInfo[i][pLogin] != true) return PlayerOffLine(playerid);
	 		PlayerInfo[i][bAdmin] = level;

			new string[256];
			format(string, sizeof(string), "[A] %s[%d] ��������� ������ %s[%d] %d ������� �������", PlayerInfo[playerid][pName], playerid, PlayerInfo[i][pName], i, level);
			SCMA(grey, string);
			SaveAccounts(playerid);
			return SaveAccounts(i);
		}
 	}
	static const fmt_query[] = "SELECT * FROM `accounts` WHERE `pName` = '%s' LIMIT 1";
    new query[sizeof(fmt_query)+(-2+MAX_PLAYER_NAME)];
    format(query, sizeof(query), fmt_query, to_player);
    return mysql_tquery(connects, query, "off_set_admin", "isi", playerid, to_player, level);
}

publics off_set_admin(playerid, to_player[], level)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
	    new admin;
	    admin = cache_get_field_content_int(0, "bAdmin");
	    if(admin > PlayerInfo[playerid][bAdmin]) return SCM(playerid, red, "������ ����� ��� �������������.");

	    new string[256], sql_str[128];
	    format(string, sizeof(string), "[A] %s[%d] ��������� ������ %s %d ������� ��������������", PlayerInfo[playerid][pName], playerid, to_player, level);
	    SCMA(grey, string);

	    format(sql_str, sizeof(sql_str), "UPDATE `accounts` SET `bAdmin` = '%d' WHERE `pName` = '%s' LIMIT 1", level, to_player);
	    mysql_tquery(connects, sql_str, "", "");
	}
	else
	{
	    SCM(playerid, red, "������ ������ ���.");
	}
	return 1;
}