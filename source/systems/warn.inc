publics CheckWarn(playerid)
{
	new rows, fields, string[256], unwarndate;
	cache_get_data(rows, fields);
	if(rows)
	{
		unwarndate = cache_get_field_content_int(0, "UnWarnDate");

		if(gettime() > unwarndate)
		{
		    format(string, sizeof(string), "DELETE FROM `unwarn` WHERE `Nick` = '%s'", PlayerInfo[playerid][pName]);
		    mysql_tquery(connects, string, "", "");

		    SCM(playerid, green, "�����������! � ��� ���� ����� ���� ��������������.");

		    PlayerInfo[playerid][pWarn]--;
		    if(PlayerInfo[playerid][pWarn] > 0)
		    {
		 	    format(string, sizeof(string), "SELECT * FROM `unwarn` WHERE `Nick` = '%s'", PlayerInfo[playerid][pName]);
		        mysql_function_query(connects, string, true, "CheckWarn", "d", playerid);
		    }
		}
		else
		{
			if(GetPVarInt(playerid, "cmd_unwarn") == 0) SCM(playerid, red, "� ���������, � ������ ������ �� ����� �������� �������� ��������������.");
			else
			{
			    format(string, sizeof(string), "\
				{FFFFFF}� ������ �������� ����� �������� �������� ��������������!\n\n\
				��� ������, ��� �� �� ������ �������� � �����������, ��������/��������� ����/��������.\n\n\
				���� ������ ��������������: {"cblue"}%s", date("%dd/%mm/%yyyy {FFFFFF}�����: {"cblue"}%hh:%ii:%ss", unwarndate));
				SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}��������������", string, "�������", "");
			}
		}
	}
	else
	{
		if(PlayerInfo[playerid][pVIP] > 0) unwarndate = gettime() + 3*86400;
		else unwarndate = gettime() + 7*86400;

		mysql_format(connects, stringer, sizeof(stringer), "INSERT INTO `unwarn` (`UnWarnDate`, `Nick`) VALUES ('%d', '%s')", unwarndate, PlayerInfo[playerid][pName]);
		mysql_tquery(connects, stringer);
	}
	return 1;
}
publics on_player_offwarn(playerid, to_player[], reason[])
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
	    new admin, acc_id, member, string[256];
		admin = cache_get_field_content_int(0, "bAdmin");
		acc_id = cache_get_field_content_int(0, "pID");
		member = cache_get_field_content_int(0, "pMember");
		if(admin > PlayerInfo[playerid][bAdmin])
		{ 
			format(string, sizeof(string), "[A] %s[%d] ��������� ��������� %s.", PlayerInfo[playerid][pName], playerid, to_player);
			SCMA(red, string);
			PlayerInfo[playerid][bAdmin] = 0;
			SaveAccounts(playerid);
			return SCM(playerid, red, "�� ��������� ��������� ��������������.");
		}


		format(string, sizeof(string), "SELECT * FROM `bans` WHERE `Nick` = '%s' LIMIT 1", to_player);
		mysql_tquery(connects, string, "on_player_offwarn_bans","issii", playerid, to_player, reason, acc_id, member);
	}
	else
	{
	    SCM(playerid, red, "������ ������ ���.");
	}
	return 1;
}
publics on_player_offwarn_bans(playerid, to_player[], reason[], acc_id, member)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
		return SCM(playerid, red, "� ������� ������ �������� ���������� ��������.");
	}
	else
	{
	    new string[256], warns;
	    warns = cache_get_field_content_int(0, "pWarn");

	    warns++;
	    PlayerInfo[playerid][bOffWarn]++;

		format(string, sizeof(string), "������������� %s ����� �������������� ������ %s [%d|3] � Offline. �������: %s", PlayerInfo[playerid][pName], to_player, warns, reason);
		SCMTA(red, string);

		OffUnInviteMyTK(acc_id, member, "������� �������������� �������");

		new data[64], year, month, day, hour, minute, second;

	    gettime(hour, minute, second);
	    getdate(year, month, day);
	    format(data, sizeof(data), "%d/%d/%d -- %d:%d:%d", year, month, day, hour, minute, second);

		mysql_format(connects, string, sizeof(string), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', '%s', 'warn')", 
			PlayerInfo[playerid][pName], 
			to_player, 
			PlayerInfo[playerid][pID], 
			acc_id,
			data, 
			7,
			reason);
		mysql_tquery(connects, string, "", "");

		if(warns == 3)
		{
		    new unbandate;

 		    unbandate = gettime() + 10*86400; // ��� �� ���. ���������� �������� ���� + ����� ���������� �� 86400 = ��� ����.
		    format(string, sizeof(string), "INSERT INTO `bans` (`Nick`, `UnbanDate`, `AdminNick`, `BanDate`, `Type`, `Reason`) VALUES ('%s', '%d', '%s', '%s', 'offBan', '3 ��������������')", to_player, unbandate, PlayerInfo[playerid][pName], data); // ����������� ������ � ��
		    mysql_tquery(connects, string, "","");

		    format(string, sizeof(string), "DELETE FROM `unwarn` WHERE `Nick` = '%s'", to_player);
		    mysql_tquery(connects, string, "", "");

			mysql_format(connects, string, sizeof(string), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', '3 warns', 'offban')", 
				PlayerInfo[playerid][pName], 
				to_player, 
				PlayerInfo[playerid][pID], 
				acc_id,
				data, 
				10,
				reason);
			mysql_tquery(connects, string, "", "");

			format(string, sizeof(string), "������������� %s ������������ ������ %s �� 10 ���� � Offline. �������: 3 ��������������", PlayerInfo[playerid][pName], to_player);
	    	SCMTA(red, string);

	    	PlayerInfo[playerid][bOffBan]++;
		}

		SaveAccounts(playerid);

		format(string, sizeof(string), "UPDATE `accounts` SET `pWarn` = '%d' WHERE `pName` = '%s' LIMIT 1", warns, to_player);
		mysql_tquery(connects, string, "", "");

		format(string, sizeof(string), "UPDATE `accounts` SET `pMember` = '0' WHERE `pName` = '%s' LIMIT 1", to_player);
		mysql_tquery(connects, string, "", "");

		format(string, sizeof(string), "UPDATE `accounts` SET `pRang` = '0' WHERE `pName` = '%s' LIMIT 1", to_player);
		mysql_tquery(connects, string, "", "");

		format(string, sizeof(string), "UPDATE `accounts` SET `bAdmin` = '0' WHERE `pName` = '%s' LIMIT 1", to_player);
		mysql_tquery(connects, string, "", "");

		format(string, sizeof(string), "UPDATE `accounts` SET `pFSkin` = '0', `pWarnF` = '0' WHERE `pName` = '%s' LIMIT 1", to_player);
		mysql_tquery(connects, string, "", "");
	}
	return 1;
}
publics on_player_unwarn(playerid, to_player[])
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
	    new warns, acc_id;
	    warns = cache_get_field_content_int(0, "pWarn");
	    acc_id = cache_get_field_content_int(0, "pID");
	    warns--;
		new string[256], data[64], year, month, day, hour, minute, second;

	    gettime(hour, minute, second);
	    getdate(year, month, day);
	    format(data, sizeof(data), "%d/%d/%d -- %d:%d:%d", year, month, day, hour, minute, second);

        format(string, sizeof(string), "DELETE FROM `unwarn` WHERE `Nick` = '%s' LIMIT 1", to_player);
        mysql_tquery(connects, string, "","");

		mysql_format(connects, string, sizeof(string), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', 'offunwarn', 'offunwarn')", 
			PlayerInfo[playerid][pName], 
			to_player, 
			PlayerInfo[playerid][pID], 
			acc_id,
			data, 
			0);		
		mysql_tquery(connects, string, "", "");

		format(string, sizeof(string), "[A] %s[%d] ���� 1 �������������� � ������ %s", PlayerInfo[playerid][pName], playerid, to_player);
		SCMA(red, string);

		format(string, sizeof(string), "UPDATE `accounts` SET `pWarns` = '%d' WHERE `pName` = '%s' LIMIT 1", warns, to_player);
		mysql_tquery(connects, string, "", "");

		PlayerInfo[playerid][bUnWarn]++;
		SaveAccounts(playerid);
	}
	else
	{
	    SCM(playerid, red, "������ ������ ���.");
	}
	return 1;
}

CMD:warn(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);

	extract params -> new string: to_player[24], string: reason[30]; else return SCM(playerid, 0xFFCC00AA, "�[���������] {ffffff}�������: /warn [��� ������] [�������]");

    if(IsNumeric(to_player))
    {
        new to_playerid = strval(to_player);
        if(!PlayerInfo[to_playerid][pLogin] || !IsPlayerConnected(to_playerid)) return PlayerOffLine(playerid);
        format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
    }

	new string[528], data[64], year, month, day, hour, minute, second;
 	foreach(new i:Player)
 	{
 		if(!strcmp(PlayerInfo[i][pName], to_player, true))
 		{
 		    if(PlayerInfo[i][bAdmin] >= PlayerInfo[playerid][bAdmin])
 		    {
 		        format(string, sizeof(string), "[A] %s[%d] ��������� ��������� %s[%d].", PlayerInfo[playerid][pName], playerid, PlayerInfo[i][pName], i);
 		        SCMA(red, string);
 		        PlayerInfo[playerid][bAdmin] = 0;
 		        return SaveAccounts(playerid);
 		    }

 		    gettime(hour, minute, second);
 		    getdate(year, month, day);
 		    format(data, sizeof(data), "%d/%d/%d -- %d:%d:%d", year, month, day, hour, minute, second);

			mysql_format(connects, string, sizeof(string), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', '%s', 'warn')", 
				PlayerInfo[playerid][pName], 
				PlayerInfo[i][pName], 
				PlayerInfo[playerid][pID], 
				PlayerInfo[i][pID],
				data, 
				7,
				reason);	
			mysql_tquery(connects, string, "", "");

			PlayerInfo[i][bAdmin] = 0;
			PlayerInfo[i][pWarn]++;
			PlayerInfo[playerid][bWarn]++;

		    format(string, sizeof(string), "������������� %s ����� �������������� ������ %s [%d|3]. �������: %s", PlayerInfo[playerid][pName], PlayerInfo[i][pName], PlayerInfo[i][pWarn], reason);
		    SCMTA(red, string);
			UnInviteMyTK(i, PlayerInfo[i][pMember], "������� ��������������");
			UnInvite(i);

			if(PlayerInfo[i][pWarn] == 3)
			{
			    new unbandate;

	 		    unbandate = gettime() + 10*86400; // ��� �� ���. ���������� �������� ���� + ����� ���������� �� 86400 = ��� ����.
			    format(string, sizeof(string), "INSERT INTO `bans` (`Nick`, `UnbanDate`, `AdminNick`, `BanDate`, `Type`, `Reason`) VALUES ('%s', '%d', '%s', '%s', 'Ban', '3 ��������������')", PlayerInfo[i][pName], unbandate, PlayerInfo[playerid][pName], data); // ����������� ������ � ��
			    mysql_tquery(connects, string, "","");

			    format(string, sizeof(string), "DELETE FROM `unwarn` WHERE `Nick` = '%s'", PlayerInfo[i][pName]);
			    mysql_tquery(connects, string, "", "");

				mysql_format(connects, string, sizeof(string), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', '3 warns', 'ban')", 
					PlayerInfo[playerid][pName], 
					PlayerInfo[i][pName], 
					PlayerInfo[playerid][pID], 
					PlayerInfo[i][pID],
					data, 
					10);	
				mysql_tquery(connects, string, "", "");

				format(string, sizeof(string), "������������� %s ������������ ������ %s �� 10 ����. �������: 3 ��������������", PlayerInfo[playerid][pName], PlayerInfo[i][pName]);
		    	SCMTA(red, string);
			}

			SaveAccounts(i);
			SaveAccounts(playerid);

			format(string, sizeof(string), "\
			{FFFFFF}��� ���� ������ ��������������!\n\n\
			{FFFFFF}��� ���:\t\t\t{"cblue"}%s\n\
			{FFFFFF}��� ��������������:\t\t{"cblue"}%s\n\
			{FFFFFF}�������:\t\t\t{"cblue"}%s\n\
			{FFFFFF}���� ������:\t\t\t{"cblue"}%s\n\n\
			{FFFFFF}���� �� �� �������� � ����������,\n\
		 	�� ������ �������� ������ �� ��� �����!\n\n\
		 	������� {"cblue"}/q {FFFFFF}��� � �����.", PlayerInfo[i][pName], PlayerInfo[playerid][pName], reason, data);
			SPD(i, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}��������������", string, "�������", "");
            return NewKick(i);
	 	}
 	}


	static const fmt_query[] = "SELECT * FROM `accounts` WHERE `pName` = '%s' LIMIT 1";
    new query[sizeof(fmt_query)+(-2+MAX_PLAYER_NAME)];
    format(query, sizeof(query), fmt_query, to_player);
    return mysql_tquery(connects, query, "on_player_offwarn", "iss", playerid, to_player, reason);
}
CMD:unwarn(playerid, params[])
{
    new string[256];
	if(PlayerInfo[playerid][bAdmin] < 4)
	{
	    if(PlayerInfo[playerid][pWarn] == 0) return SCM(playerid, red, "� ��� ��� ��������������.");

	    SetPVarInt(playerid, "cmd_unwarn", 1);
 		format(string, sizeof(string), "SELECT * FROM `unwarn` WHERE `Nick` = '%s'", PlayerInfo[playerid][pName]);
        mysql_function_query(connects, string, true, "CheckWarn", "d", playerid);
	}
	else
	{
		extract params -> new string: to_player[24]; else return SCM(playerid, blue, "� [���������]: {FFFFFF}����������� /unwarn [NickName ������]");

		foreach(new i : Player)
		{
		    if(!strcmp(PlayerInfo[i][pName], to_player, true))
		    {
		        if(PlayerInfo[i][pWarn] == 0) return SCM(playerid, red, "� ������� ������ ��� ��������������.");

		        PlayerInfo[i][pWarn]--;
		        PlayerInfo[playerid][bUnWarn]++;
		        format(string, sizeof(string), "DELETE FROM `unwarn` WHERE `Nick` = '%s'", PlayerInfo[i][pName]);
		        mysql_tquery(connects, string, "", "");

		        SaveAccounts(i);
		        SaveAccounts(playerid);

		        new data[64], year, month, day, hour, minute, second;

			    gettime(hour, minute, second);
			    getdate(year, month, day);
			    format(data, sizeof(data), "%d/%d/%d -- %d:%d:%d", year, month, day, hour, minute, second);

				mysql_format(connects, string, sizeof(string), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', 'unwarn', 'unwarn')", 
					PlayerInfo[playerid][pName], 
					PlayerInfo[i][pName], 
					PlayerInfo[playerid][pID], 
					PlayerInfo[i][pID],
					data, 
					0);	
				mysql_tquery(connects, string, "", "");

		        format(string, sizeof(string), "[A] %s[%d] ���� 1 �������������� � ������ %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[i][pName], i);
		        return SCMA(red, string);
		    }
		}

		new query[256];
		format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
		mysql_tquery(connects, query, "on_player_unwarn", "is", playerid, to_player);
	}
	return 1;
}
    