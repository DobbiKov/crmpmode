CMD:offmute(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 4) return ShowCommandNotFound(playerid);

	extract params -> new string: to_player[24], time, string: reason[30]; else return SCM(playerid, 0xFFCC00AA, "�[���������] {ffffff}�������: /offmute [��� ������] [������] [�������]");

	if(!(1 <= time <= 280))
	    return SCM(playerid, red, "����� �� 1 �� 280 �����");

 	foreach(new i:Player)
 	{
 		if(!strcmp(PlayerInfo[i][pName], to_player, true))
 			return SCM(playerid, white, !"����� ������. ����������� /mute");
 	}


	static const fmt_query[] = "SELECT * FROM `accounts` WHERE `pName` = '%s' LIMIT 1";
    new query[sizeof(fmt_query)+(-2+MAX_PLAYER_NAME)];
    format(query, sizeof(query), fmt_query, to_player);
    return mysql_tquery(connects, query, "on_player_offmute","isis", playerid, to_player, time, reason);
}

publics on_player_offmute(playerid, to_player[], time, reason[])
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
	    new admin, mute, acc_id;
 	    mute = cache_get_field_content_int(0, "pMute");
		admin = cache_get_field_content_int(0, "bAdmin");
		acc_id = cache_get_field_content_int(0, "pID");
		if(admin > PlayerInfo[playerid][bAdmin]) return SCM(playerid, red, "�� ��������� �������� ��������������.");

    	if(mute > 0) return SCM(playerid, red, "� ������� ������ ��� ����� �������.");

    	PlayerInfo[playerid][bOffMute]++;
    	SaveAccounts(playerid);

		new string[256], sql_str[256];
		format(string, sizeof(string), "[A] ������������� %s �������� ������� ������ %s ������� �� %d �����. �������: %s", PlayerInfo[playerid][pName], to_player, time, reason);
		SCMA(lightblue, string);

		format(sql_str, sizeof(sql_str), "UPDATE `accounts` SET `pMute` = '%d' WHERE `pName` = '%s' LIMIT 1", time*60, to_player);
		mysql_tquery(connects, sql_str, "", "");

		format(string, sizeof(string), "������������� %s �������� ��� ������� ������� �� %d �����. ������: %s", PlayerInfo[playerid][pName], time, reason);

		format(sql_str, sizeof(sql_str), "UPDATE `accounts` SET `pMuteOffMess` = '%s' WHERE `pName` = '%s'", string, to_player);
		mysql_tquery(connects, sql_str, "", "");


		new day, month, year, hour, minute, second;
		getdate(day, month, year);
		gettime(hour, minute, second);
		format(string, sizeof(string), "%d/%d/%d - %d:%d:%d", day, month, year, hour, minute, second);

		mysql_format(connects, sql_str, sizeof(sql_str), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', '%s', 'offmute')", 
			PlayerInfo[playerid][pName], 
			to_player, 
			PlayerInfo[playerid][pID], 
			acc_id,
			string, 
			time,
			reason);
		mysql_tquery(connects, sql_str, "", "");
	}
	else
	{
	    SCM(playerid, red, "������ ������ ���!");
	}
	return 1;
}