publics CheckBan(playerid)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
		new string[512], AdminName[MAX_PLAYER_NAME], reason[256], data[64], unbandate;
		unbandate = cache_get_field_content_int(0, "UnbanDate");
		cache_get_field_content(0, "Reason", reason, connects, 256);
		cache_get_field_content(0, "BanDate", data, connects, 50);
		cache_get_field_content(0, "AdminNick", AdminName, connects, 32);

        if(gettime() >= unbandate)
        {
            format(string, sizeof(string), "DELETE FROM `bans` WHERE `Nick` = '%s' LIMIT 1", PlayerInfo[playerid][pName]);
            mysql_tquery(connects, string, "","");

       	    SpawnList(playerid);
			if(strcmp(PlayerInfo[playerid][pJailOffMess], "None", true))
			{
			    SCM(playerid, red, "Jail:");
			    SCM(playerid, red, PlayerInfo[playerid][pJailOffMess]);
			}
			if(strcmp(PlayerInfo[playerid][pMuteOffMess], "None", true))
			{
			    SCM(playerid, red, "Mute:");
			    SCM(playerid, red, PlayerInfo[playerid][pMuteOffMess]);
			}
			if(XDay != 1)
			{
				format(string, sizeof(string), "������� �� ������� X%d ����! ��� ������, ��� ������ �� �������, �������� �� ��������, ���� � �.� ������������ � ���� ������.", XDay);
				SCM(playerid, yellow, string);
			}

            return 1;
        }
		else
		{
			format(string, sizeof(string), "\
			{FFFFFF}�� �������� �� ���� �������.\n\n\
			{FFFFFF}��� ���:\t\t\t{"cblue"}%s\n\
			{FFFFFF}��� ��������������:\t\t{"cblue"}%s\n\
			{FFFFFF}�������:\t\t\t{"cblue"}%s\n\
			{FFFFFF}���� ����������:\t\t{"cblue"}%s\n\
			{FFFFFF}���� �������������:\t\t{"cblue"}%s\n\n\
			{FFFFFF}���� �� �� �������� � ����������,\n\
		 	�� ������ �������� ������ �� ��� �����!\n\n\
	 		������� {"cblue"}/q {FFFFFF}��� � �����.", PlayerInfo[playerid][pName], AdminName, reason, data, date("%dd/%mm/%yyyy �����: %hh:%ii:%ss", unbandate));
			SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}���������� ��������", string, "�������", "");
			NewKick(playerid);
		}
	}
	else
	{
	    SpawnList(playerid);
		if(strcmp(PlayerInfo[playerid][pJailOffMess], "None", true))
		{
		    SCM(playerid, red, "Jail:");
		    SCM(playerid, red, PlayerInfo[playerid][pJailOffMess]);
		}
		if(strcmp(PlayerInfo[playerid][pMuteOffMess], "None", true))
		{
		    SCM(playerid, red, "Mute:");
		    SCM(playerid, red, PlayerInfo[playerid][pMuteOffMess]);
		}
		if(XDay != 1)
		{
			new string[150];
			format(string, sizeof(string), "������� �� ������� X%d ����! ��� ������, ��� ������ �� �������, �������� �� ��������,���� � �.� ������������ � ���� ������.", XDay);
			SCM(playerid, yellow, string);
		}
	}
	return 1;
}
publics on_player_unban_check_acc(playerid, to_player[])
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
		new acc_id;
		acc_id = cache_get_field_content_int(0, "pID");
	    
		new query[256];
		format(query, sizeof(query), "SELECT * FROM `bans` WHERE `Nick` = '%s'", to_player);
		mysql_tquery(connects, query, "on_player_unban", "isi", playerid, to_player, acc_id);
	}
	else
	{
	    SCM(playerid, red, "������ ������ ���.");
	}
	return 1;
}
publics on_player_unban(playerid, to_player[], acc_id)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
		new string[256], data[64], year, month, day, hour, minute, second;
		// acc_id = cache_get_field_content_int(0, "pID");
	    gettime(hour, minute, second);
	    getdate(year, month, day);
	    format(data, sizeof(data), "%d/%d/%d -- %d:%d:%d", year, month, day, hour, minute, second);

        format(string, sizeof(string), "DELETE FROM `bans` WHERE `Nick` = '%s' LIMIT 1", to_player);
        mysql_tquery(connects, string, "","");

		mysql_format(connects, string, sizeof(string), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', 'unban', 'unban')", 
			PlayerInfo[playerid][pName], 
			to_player, 
			PlayerInfo[playerid][pID], 
			acc_id,
			data, 
			0);
		mysql_tquery(connects, string, "", "");

		format(string, sizeof(string), "[A] %s[%d] �������� ������ %s", PlayerInfo[playerid][pName], playerid, to_player);
		SCMA(red, string);

		PlayerInfo[playerid][bUnBan]++;
		SaveAccounts(playerid);
	}
	else
	{
	    SCM(playerid, red, "������ ����� �� �������!");
	}
	return 1;
}
publics on_player_offban(playerid, to_player[], time, reason[])
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
	    new admin, string[256], lastip[24], regip[24], accid;

		accid = cache_get_field_content_int(0, "pID");
		cache_get_field_content(0, "pRegIP", regip, connects, 16);
		cache_get_field_content(0, "pLastIP", lastip, connects, 16);
		admin = cache_get_field_content_int(0, "bAdmin");
		if(admin > PlayerInfo[playerid][bAdmin])
		{ 
			format(string, sizeof(string), "[A] %s[%d] ��������� �������� %s.", PlayerInfo[playerid][pName], playerid, to_player);
			SCMA(red, string);
			PlayerInfo[playerid][bAdmin] = 0;
			SaveAccounts(playerid);
			return SCM(playerid, red, "�� ��������� �������� ��������������.");
		}

		format(string, sizeof(string), "SELECT * FROM `bans` WHERE `Nick` = '%s' LIMIT 1", to_player);
		mysql_tquery(connects, string, "on_player_offbans","isisssi", playerid, to_player, time, reason,lastip,regip,accid);
	}
	else
	{
	    SCM(playerid, red, "������ ������ ���.");
	}
	return 1;
}
publics on_player_offbans(playerid, to_player[], time, reason[],lastip[], regip[],accid)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
		return SCM(playerid, red, "����� ��� �������.");
	}
	else
	{
		new string[256], unbandate, data[64], year, month, day, hour, minute, second;

	    gettime(hour, minute, second);
	    getdate(year, month, day);
	    format(data, sizeof(data), "%d/%d/%d -- %d:%d:%d", year, month, day, hour, minute, second);

	    unbandate = gettime() + time*86400;
	    format(string, sizeof(string), "INSERT INTO `bans` (`Nick`, `UnbanDate`, `AdminNick`, `BanDate`, `Type`, `Reason`) VALUES ('%s', '%d', '%s', '%s', 'offBan', '%s')", to_player, unbandate, PlayerInfo[playerid][pName], data, reason); // ����������� ������ � ��
	    mysql_tquery(connects, string, "","");

	    format(string, sizeof(string), "������������� %s ������� ������ %s �� %d ���� � Offline. �������: %s", PlayerInfo[playerid][pName], to_player, time, reason);
	    SCMTA(red, string);
	    format(string, sizeof(string), "[ Account ID: %d | Last IP: %s | Reg IP: %s ]", accid, lastip, regip);
	    SCMTA(red, string);

		mysql_format(connects, string, sizeof(string), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', '%s', 'offban')", 
			PlayerInfo[playerid][pName], 
			to_player, 
			PlayerInfo[playerid][pID], 
			accid,
			data, 
			time,
			reason);
		mysql_tquery(connects, string, "", "");

		PlayerInfo[playerid][bOffBan]++;
		SaveAccounts(playerid);

	}
	return 1;
}

CMD:ban(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);

	extract params -> new string: to_player[24], time, string: reason[30]; else return SCM(playerid, 0xFFCC00AA, "�[���������] {ffffff}�������: /ban [��� ������] [���(1-30)] [�������]");

	// if(PlayerInfo[playerid][bAdmin] >= 5 && time == 0)
	// {
	// 	time = 2555;
	// }
	if(time < 1)
	    return SCM(playerid, red, "�� 1, �� 30-�� ����.");
	if(time > 30 && time < 365)
		return SCM(playerid, red, "�� 1, �� 30-�� ����.");
	if(time > 365)
		return SCM(playerid, red, "�� 1, �� 30-�� ����.");

	if(IsNumeric(to_player))
    {
        new to_playerid = strval(to_player);
        if(!PlayerInfo[to_playerid][pLogin] || !IsPlayerConnected(to_playerid)) return PlayerOffLine(playerid);
        format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
    }	

	new string[512], unbandate, data[64], year, month, day, hour, minute, second;
 	foreach(new i:Player)
 	{
 		if(!strcmp(PlayerInfo[i][pName], to_player, true))
 		{
 		    if(PlayerInfo[i][bAdmin] > PlayerInfo[playerid][bAdmin])
 		    {
 		        format(string, sizeof(string), "[A] %s[%d] ��������� �������� %s[%d].", PlayerInfo[playerid][pName], playerid, PlayerInfo[i][pName], i);
 		        SCMA(red, string);
 		        PlayerInfo[playerid][bAdmin] = 0;
 		        return SaveAccounts(playerid);
 		    }

 		    gettime(hour, minute, second);
 		    getdate(year, month, day);
 		    format(data, sizeof(data), "%d/%d/%d -- %d:%d:%d", year, month, day, hour, minute, second);

 		    unbandate = gettime() + time*86400; // ��� �� ���. ���������� �������� ���� + ����� ���������� �� 86400 = ��� ����.
		    format(string, sizeof(string), "INSERT INTO `bans` (`Nick`, `UnbanDate`, `AdminNick`, `BanDate`, `Type`, `Reason`) VALUES ('%s', '%d', '%s', '%s', 'Ban', '%s')", PlayerInfo[i][pName], unbandate, PlayerInfo[playerid][pName], data, reason); // ����������� ������ � ��
		    mysql_tquery(connects, string, "","");

		    format(string, sizeof(string), "������������� %s ������� ������ %s �� %d ����. �������: %s", PlayerInfo[playerid][pName], PlayerInfo[i][pName], time, reason);
		    SCMTA(red, string);
		    format(string, sizeof(string), "[IP: %s | Last IP: %s | Reg IP: %s]", PlayerInfo[playerid][pNewIp], PlayerInfo[playerid][pLastIP], PlayerInfo[i][pRegIP]);
		    SCMA(red, string);

			mysql_format(connects, string, sizeof(string), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', '%s', 'ban')", 
				PlayerInfo[playerid][pName], 
				PlayerInfo[i][pName], 
				PlayerInfo[playerid][pID], 
				PlayerInfo[i][pID],
				data, 
				time,
				reason);
			mysql_tquery(connects, string, "", "");

			PlayerInfo[i][bAdmin] = 0;
			PlayerInfo[playerid][bBan]++;

			SaveAccounts(i);
			SaveAccounts(playerid);

			format(string, sizeof(string), "\
			{FFFFFF}�� �������� �� ���� �������!\n\n\
			{FFFFFF}��� ���:\t\t{"cblue"}%s\n\
			{FFFFFF}��� ��������������:\t{"cblue"}%s\n\
			{FFFFFF}�������:\t\t{"cblue"}%s\n\
			{FFFFFF}���� ����������:\t{"cblue"}%s\n\
			{FFFFFF}���� �������������:\t{"cblue"}%s\n\n\
			{FFFFFF}���� �� �� �������� � ����������,\n\
		 	�� ������ �������� ������ �� ��� �����!\n\n\
		 	������� {"cblue"}/q {FFFFFF}��� � �����.", PlayerInfo[i][pName], PlayerInfo[playerid][pName], reason, data, date("%dd/%mm/%yyyy �����: %hh:%ii:%ss", unbandate));
			SPD(i, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}���������� ��������", string, "�������", "");
            return NewKick(i);
	 	}
 	}


	static const fmt_query[] = "SELECT * FROM `accounts` WHERE `pName` = '%s' LIMIT 1";
    new query[sizeof(fmt_query)+(-2+MAX_PLAYER_NAME)];
    format(query, sizeof(query), fmt_query, to_player);
    return mysql_tquery(connects, query, "on_player_offban", "isis", playerid, to_player, time, reason);
}

CMD:unban(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 4) return ShowCommandNotFound(playerid);

	extract params -> new string: to_player[24]; else return SCM(playerid, blue, "� [���������]: {FFFFFF}����������� /unabn [NickName ������]");

	new query[256];
	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
	mysql_tquery(connects, query, "on_player_unban_check_acc", "is", playerid, to_player);
	return 1;
}