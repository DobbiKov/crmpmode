enum
	E_DONATE_DATE
{
	donate_name[70]
};

new const
	donate_list[11][E_DONATE_DATE] =
{
	{"��������� ������� � ����� (1 ��. = 500 ������)"},
	{"������� ��� (50. ��.)"},
	{"����� ��� �������������� (100. ��.)"},
	{"����� ������ (50 ��.)"},
	{"������� ����� (100. ��.)"},
	{"+1 EXP (10 ��.)"},
	{"+1 LvL (100 ��.)"},
	{"������ ������ (50 ��. = 1 ��. | 200 ��. = ���)"},
	{"VIP �������"},
	{"���������� ������ �� ���� (500 ��.)"},
	{"���������� VIP ����� �������� (500 ��.)"}
};

#include "../source/systems/donate/change_car_number.inc"
#include "../source/systems/donate/change_phone_number.inc"

CMD:donate(playerid)
{
	new string[1024], str[128];
	strcat(string, "{"cblue"}����� {ffffff}- ��� ���� ������������� ������ ������� ��������� ��������\n�� �������� � ����������� �������� � ����������. �� ��� �� ��������� �������.\n\n");
	strcat(string, "{"cblue"}1 ���������� ����� = 1 �������\n\n");
	strcat(string, "{FFFFFF}�� ������� ����� ����������� �� ������� �������� ��������� ������, ��������, �����������,\n");
	strcat(string, "� ����� ���������� � ������� ������ {"cblue"}(1 ������ = 500 ������� ������)\n\n\n");

	strcat(string, "{"cred"}��� �� �������� ������� �����:\n\n");
	strcat(string, "{"cblue"}1) {FFFFFF}����� �� ���� {"cblue"}unigva-rp.ru/donate\n");
	strcat(string, "{"cblue"}2) {FFFFFF}������� ������, �� ������� �� �������\n");
	strcat(string, "{"cblue"}3) {FFFFFF}������� ���� ������� � �������� ����� ���������\n");
	strcat(string, "{"cblue"}4) {FFFFFF}������� ������ ������ (QIWI, WebMoney, ������.������, SMS, ���������� ����� ������ �����)\n");
	strcat(string, "{"cblue"}5) {FFFFFF}����� ����� �������� ������� {"cblue"}/donate\n\n");
	format(str, sizeof(str), "{ffffff}��� �������:\t\t\t\t{"cblue"}%s\n", PlayerInfo[playerid][pName]);
	strcat(string, str);
	format(str, sizeof(str), "{ffffff}����� ������ ��������:\t\t{"cblue"}%d\n", PlayerInfo[playerid][pID]);
	strcat(string, str);
	format(str, sizeof(str), "{ffffff}���������� ����� ��������:\t\t{"cblue"}%d", PlayerInfo[playerid][pDonate]);
	strcat(string, str);
	SPD(playerid, D_DONATE, DIALOG_STYLE_MSGBOX, "{"cblue"}�������������� ��������", string, "�����", "������");
	return 1;
}

stock ShowDonateListDialog(playerid){
	new fmt_dialog[1024], string[144];
	for(new i = 0; i < sizeof(donate_list); i++)
	{
		format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i+1, donate_list[i][donate_name]);
		strcat(fmt_dialog, string);
	}
	SPD(playerid, D_DONATE_LIST, DIALOG_STYLE_LIST, "{"cblue"}�������������� ������", fmt_dialog, "�����", "������");	
	return 1;
}



public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case D_DONATE:
		{
			if(!response) return 1;
			else
			{
				ShowDonateListDialog(playerid);
			}
		}
		case D_DONATE_LIST:{
			if(!response) return 1; else{
				switch(listitem){
					case 0: {
						new string[256];
						format(string, sizeof(string), "{ffffff}������� ���������� ��������, ������� �� ������ ��������� � �����. � ������ ������ � ���: %d ���.", PlayerInfo[playerid][pDonate]);
						SPD(playerid, D_DONATE_BUY_MONEY, DIALOG_STYLE_INPUT, !"{"cblue"}�����", string, !"�����", "�����");
					}
					case 1:{//����� �����
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"� ��� ������������ ��������.");
						SPD(playerid, D_DONATE_CHANGE_NAME, DIALOG_STYLE_INPUT, "{"cblue"}����� ����", "{"cwhite"}���� ��� ���-���� �� ����������� ���������� RolePlay, �� �� ������ ��� �������.\n\n������: {"cblue"}Andrey_Sergeev, Ekaterina_Petrova", "�����", "������");
					}
					case 2:{
						if(PlayerInfo[playerid][pWarn] < 1) return SCM(playerid, red, !"� ��� ��� ��������������.");
						ShowPlayerDialog(playerid, D_DONATE_BUY_NULL_WARN, DIALOG_STYLE_MSGBOX, !"{"cblue"}�����", !"{FFFFFF}�� ������� ����� ��� �������������� �� 100 ��������?", !"��", !"���");
					}
					case 3:{
						if(PlayerInfo[playerid][pWANTED] < 1) return SCM(playerid, red, !"��� �� ����������� �������.");
						ShowPlayerDialog(playerid, D_DONATE_BUY_NULL_WANTED, DIALOG_STYLE_MSGBOX, !"�����", !"{ffffff}�� ������� ����� ������ �� 50 ��������?", !"��", !"���");
					}
					case 4:{
						if(PlayerInfo[playerid][pVoen] > 0) return SendClientMessage(playerid, red, !"� ��� ��� ���� ������� �����.");
						ShowPlayerDialog(playerid, D_DONATE_BUY_VOEN, DIALOG_STYLE_MSGBOX, !"{"cblue"}�����", !"{ffffff}�� ������� ���������� ������� ����� �� 100 ��������?", !"��", !"���");
					}
					case 5:{//+1 exp
						ShowPlayerDialog(playerid, D_DONATE_BUY_1_EXP, DIALOG_STYLE_MSGBOX, !"{"cblue"}�����", !"{FFFFFF}�� ������� ���������� 1 exp �� 10 ������?", !"��", !"���");
					}
					case 6:{//+1 lvl
						ShowPlayerDialog(playerid, D_DONATE_BUY_1_LVL, DIALOG_STYLE_MSGBOX, !"{"cblue"}�����", !"{FFFFFF}�� ������� ���������� 1 lvl �� 100 ������?", !"��", !"���");
					}
					case 7:{//������ ������
						ShowPlayerDialog
						(
							playerid, D_DONATE_GUN_SKILLS_LIST, DIALOG_STYLE_LIST,
							!"{"cblue"}����� | ������ �������� �������",
							!"\
							{"cblue"}1. {FFFFFF}SD Pistol {"cblue"}(50 ��.){FFFFFF}\n\
							{"cblue"}2. {FFFFFF}Desert Eagle {"cblue"}(50 ��.){FFFFFF}\n\
							{"cblue"}3. {FFFFFF}ShotGun {"cblue"}(50 ��.){FFFFFF}\n\
							{"cblue"}4. {FFFFFF}MP5 {"cblue"}(50 ��.){FFFFFF}\n\
							{"cblue"}5. {FFFFFF}AK 47 {"cblue"}(50 ��.){FFFFFF}\n\
							{"cblue"}6. {FFFFFF}M4 {"cblue"}(50 ��.){FFFFFF}\n\
							{"cblue"}7. {FFFFFF}��� ������ {"cblue"}(50 ��.){FFFFFF}\n\
							",
							!"������", !"�����"
						);
					}
					case 8:{//�����
						ShowPlayerDialog(playerid, D_DONATE_BUY_VIP, DIALOG_STYLE_LIST, !"{"cblue"}�����", !"\
						{"cblue"}1. {ffffff}7 ���� {"cblue"}(60 ��.)\n\
						{"cblue"}2. {ffffff}30 ���� {"cblue"}(200 ��.)\n\
						{"cblue"}3. {ffffff}365 ���� {"cblue"}(600 ��.)\
						", !"������", !"�����");
					}
					case 9:{
						if(PlayerInfo[playerid][pDonate] < 500) return SCM(playerid, red, !"� ��� ������������ ��������.");
						return ShowDonateCarNumberDialog(playerid);
					}
					case 10:{
						if(PlayerInfo[playerid][pDonate] < 500) return SCM(playerid, red, !"� ��� ������������ ��������.");
						return ShowDonatePhoneNumberDialog(playerid);
					}
				}
			}
		}
		case D_DONATE_GUN_SKILLS_LIST:{
			if(!response) return ShowDonateListDialog(playerid); else{
				switch(listitem)
				{
					case 0:{
						if(PlayerInfo[playerid][SKILL_SD_PISTOL] >= 100) return SCM(playerid, red, !"�� ��� ���������� �������� ������ ����� ������.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"� ��� ������������ ��������.");

						PlayerInfo[playerid][SKILL_SD_PISTOL] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"�� ������� ��������� ������ �������� ������� SD Pistol.");
					}
					case 1:{
						if(PlayerInfo[playerid][SKILL_DEAGLE] >= 100) return SCM(playerid, red, !"�� ��� ���������� �������� ������ ����� ������.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"� ��� ������������ ��������.");

						PlayerInfo[playerid][SKILL_DEAGLE] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"�� ������� ��������� ������ �������� ������� Desert Eagle.");
					}
					case 2:{
						if(PlayerInfo[playerid][SKILL_SHOTGUN] >= 100) return SCM(playerid, red, !"�� ��� ���������� �������� ������ ����� ������.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"� ��� ������������ ��������.");

						PlayerInfo[playerid][SKILL_SHOTGUN] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"�� ������� ��������� ������ �������� ������� ShotGun.");
					}
					case 3:{
						if(PlayerInfo[playerid][SKILL_MP5] >= 100) return SCM(playerid, red, !"�� ��� ���������� �������� ������ ����� ������.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"� ��� ������������ ��������.");

						PlayerInfo[playerid][SKILL_MP5] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"�� ������� ��������� ������ �������� ������� ��-74�.");
					}
					case 4:{
						if(PlayerInfo[playerid][SKILL_AK_47] >= 100) return SCM(playerid, red, !"�� ��� ���������� �������� ������ ����� ������.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"� ��� ������������ ��������.");

						PlayerInfo[playerid][SKILL_AK_47] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"�� ������� ��������� ������ �������� ������� AK-47.");
					}
					case 5:{
						if(PlayerInfo[playerid][SKILL_M4] >= 100) return SCM(playerid, red, !"�� ��� ���������� �������� ������ ����� ������.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"� ��� ������������ ��������.");

						PlayerInfo[playerid][SKILL_M4] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"�� ������� ��������� ������ �������� ������� M4.");
					}
					case 6:{
						if(PlayerInfo[playerid][SKILL_M4] >= 100 && PlayerInfo[playerid][SKILL_MP5] == 100 && PlayerInfo[playerid][SKILL_AK_47] == 100 && PlayerInfo[playerid][SKILL_SHOTGUN] == 100 && PlayerInfo[playerid][SKILL_SD_PISTOL] == 100 && PlayerInfo[playerid][SKILL_DEAGLE] == 10) 
							return SCM(playerid, red, !"�� ��� ���������� �������� ����� ������ ������.");
						if(PlayerInfo[playerid][pDonate] < 200) return SCM(playerid, red, !"� ��� ������������ ��������.");

						PlayerInfo[playerid][SKILL_M4] = 100;
						PlayerInfo[playerid][SKILL_AK_47] = 100;
						PlayerInfo[playerid][SKILL_MP5] = 100;
						PlayerInfo[playerid][SKILL_SHOTGUN] = 100;
						PlayerInfo[playerid][SKILL_SD_PISTOL] = 100;
						PlayerInfo[playerid][SKILL_DEAGLE] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 200;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"�� ������� ��������� ������ �������� ���� �������.");
					}
				}
			}
		}
		case D_DONATE_BUY_VIP:{
			if(!response) return ShowDonateListDialog(playerid);
			else{
				switch(listitem){
					case 0:{
						if(PlayerInfo[playerid][pDonate] < 60) return SCM(playerid, red, !"� ��� ������������ ��������.");

						SCM(playerid, blue, !"�� ������� ��������� VIP �� 7 ���� �� 60 ��������.");
						PlayerInfo[playerid][pVIP] += gettime() + 7*86400;
						PlayerInfo[playerid][pDonate] -= 60;
						SaveAccounts(playerid);
					}
					case 1:{
						if(PlayerInfo[playerid][pDonate] < 200) return SCM(playerid, red, !"� ��� ������������ ��������.");

						SCM(playerid, blue, !"�� ������� ��������� VIP �� ���� ����� �� 200 ��������.");
						PlayerInfo[playerid][pVIP] += gettime() + 30*86400;
						PlayerInfo[playerid][pDonate] -= 200;
						SaveAccounts(playerid);
					}
					case 2:{
						if(PlayerInfo[playerid][pDonate] < 600) return SCM(playerid, red, !"� ��� ������������ ��������.");

						SCM(playerid, blue, !"�� ������� ��������� VIP �� ���� ��� �� 600 ��������.");
						PlayerInfo[playerid][pVIP] += gettime() + 365*86400;
						PlayerInfo[playerid][pDonate] -= 600;
						SaveAccounts(playerid);
					}
				}
			}
		}
		case D_DONATE_CHANGE_NAME:{
			if(!response) return ShowDonateListDialog(playerid);
			else{
				if(!IsRPNick(inputtext)){
					return SCM(playerid, red, !"�� ����� NonRP ���.");
				}
				SCM(playerid, blue, !"�� ������� ������� NickName �� 50 ��������.");
				PlayerInfo[playerid][pDonate] -= 50;
				DonateChangeName(playerid, inputtext);
			}
		}
		case D_DONATE_BUY_1_LVL:{
			if(!response) return ShowDonateListDialog(playerid); else{
				if(PlayerInfo[playerid][pDonate] < 100) return SCM(playerid, red, !"� ��� ������������ ��������.");

				PlayerInfo[playerid][pDonate] -= 100;
				PlayerInfo[playerid][pLVL]++;
				SetPlayerScore(playerid, PlayerInfo[playerid][pLVL]);
				SCM(playerid, blue, !"�� �������� ������� �� 100 ��������.");
				SCM(playerid, blue, !"��� ������� ��� �������.");

				if(PlayerInfo[playerid][pLVL] == 5 && PlayerInfo[playerid][pExp] == 0)
				{
					if(strlen(PlayerInfo[playerid][pReferal]) > 5)
					{
						static const fmt_query[] = "INSERT INTO `referals` (`login`, `login_invited`) VALUES ('%s', '%s')";
						new query[sizeof(fmt_query)+(-2+MAX_PLAYER_NAME)];
						format(query, sizeof(query), fmt_query, PlayerInfo[playerid][pReferal], PlayerInfo[playerid][pName]);
						mysql_tquery(connects, query, "", "");

						PlayerInfo[playerid][pBCash] += 50000;
						SCM(playerid, blue, !"�����������! �� �������� 5 ������, ������� �� � ��� ������� �������� �� 50.000!");

						if(IsPlayerConnected(GetPlayerID(PlayerInfo[playerid][pReferal])))
						{
							PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pBCash] += 50000;
							stringer[0] = EOS;
							format(stringer,512, "UPDATE `accounts` SET `pBCash` = '%d' WHERE `pName` = '%s'", PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pBCash], PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pName]);
							mysql_tquery(connects, stringer, "", "");

							SCM(GetPlayerID(PlayerInfo[playerid][pReferal]), blue, !"�����������! ��� ������� ������ 5 ������ � �� � �� �������� �� 50000!");
						}
						else
						{
							new mysqlstr[144];
							mysql_format(connects,mysqlstr, sizeof(mysqlstr),"SELECT * FROM `accounts` WHERE `pName` = '%s'", PlayerInfo[playerid][pReferal]);
							mysql_function_query(connects, mysqlstr, true, "PayDayReferal","ds", PlayerInfo[playerid][pReferal]);
						}
					}
				}
				SaveAccounts(playerid);
			}
		}
		case D_DONATE_BUY_1_EXP:{
			if(!response) return ShowDonateListDialog(playerid); else{
				if(PlayerInfo[playerid][pDonate] < 10) return SCM(playerid, red, !"� ��� ������������ ��������.");

				PlayerInfo[playerid][pDonate] -= 10;
				PlayerInfo[playerid][pExp]++;
				SCM(playerid, blue, !"�� ��������� 1 exp �� 10 ��������.");
				if(PlayerInfo[playerid][pExp] >= (PlayerInfo[playerid][pLVL]*4)) {
					PlayerInfo[playerid][pLVL]++;
					SetPlayerScore(playerid, PlayerInfo[playerid][pLVL]);
					PlayerInfo[playerid][pExp] = 0;
					SCM(playerid, blue, !"��� ������� ��� �������.");

					if(PlayerInfo[playerid][pLVL] == 5 && PlayerInfo[playerid][pExp] == 0)
					{
						if(strlen(PlayerInfo[playerid][pReferal]) > 5)
						{
							static const fmt_query[] = "INSERT INTO `referals` (`login`, `login_invited`) VALUES ('%s', '%s')";
							new query[sizeof(fmt_query)+(-2+MAX_PLAYER_NAME)];
							format(query, sizeof(query), fmt_query, PlayerInfo[playerid][pReferal], PlayerInfo[playerid][pName]);
							mysql_tquery(connects, query, "", "");

							PlayerInfo[playerid][pBCash] += 50000;
							SCM(playerid, blue, !"�����������! �� �������� 5 ������, ������� �� � ��� ������� �������� �� 50.000!");

							if(IsPlayerConnected(GetPlayerID(PlayerInfo[playerid][pReferal])))
							{
								PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pBCash] += 50000;
								stringer[0] = EOS;
								format(stringer,512, "UPDATE `accounts` SET `pBCash` = '%d' WHERE `pName` = '%s'", PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pBCash], PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pName]);
								mysql_tquery(connects, stringer, "", "");

								SCM(GetPlayerID(PlayerInfo[playerid][pReferal]), blue, !"�����������! ��� ������� ������ 5 ������ � �� � �� �������� �� 50000!");
							}
							else
							{
								new mysqlstr[144];
								mysql_format(connects,mysqlstr, sizeof(mysqlstr),"SELECT * FROM `accounts` WHERE `pName` = '%s'", PlayerInfo[playerid][pReferal]);
								mysql_function_query(connects, mysqlstr, true, "PayDayReferal","ds", PlayerInfo[playerid][pReferal]);
							}
						}
					}
				}
				SaveAccounts(playerid);
			}
		}
		case D_DONATE_BUY_NULL_WARN:{
			if(!response) return ShowDonateListDialog(playerid); else{
				if(PlayerInfo[playerid][pDonate] < 100) return SCM(playerid, red, !"� ��� ������������ ��������.");

				PlayerInfo[playerid][pDonate] -= 100;
				SCM(playerid, blue, !"�� ����� ��� �������������� � �������� �� 100 ��������.");

				new string[144];
				format(string, sizeof(string), "DELETE FROM `unwarn` WHERE `Nick` = '%s' LIMIT 1", PlayerInfo[playerid][pName]);
				mysql_tquery(connects, string, "","");

				PlayerInfo[playerid][pWarn] = 0;
				SaveAccounts(playerid);
			}
		}
		case D_DONATE_BUY_NULL_WANTED:{
			if(!response) return ShowDonateListDialog(playerid); else{
				if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"� ��� ������������ ��������.");

				PlayerInfo[playerid][pDonate] -= 50;
				SetPlayerWanted(playerid, 0);
				SCM(playerid, blue, !"�� ����� � ���� ������ �� 50 ��������."); 
				SaveAccounts(playerid);
			}
		}
		case D_DONATE_BUY_VOEN:{
			if(!response) return ShowDonateListDialog(playerid); else{
				if(PlayerInfo[playerid][pDonate] < 100) return SCM(playerid, red, !"� ��� ��� ������ ���������� ��������.");

				PlayerInfo[playerid][pVoen] = 1;
				PlayerInfo[playerid][pDonate] -= 100;
				SCM(playerid, blue, !"�� ������� ��������� ���� ������� ����� �� 100 ��������.");
				SaveAccounts(playerid);
			}
		}
		case D_DONATE_BUY_MONEY:{
			if(!response) return ShowDonateListDialog(playerid);
			else{
				if(PlayerInfo[playerid][pDonate] < strval(inputtext))
					return SCM(playerid, red, "� ��� ��� ������ ���������� ��������.");

				GiveMoney(playerid, strval(inputtext)*500, "����� �����");
				PlayerInfo[playerid][pDonate] -= strval(inputtext);

				new string[144];
				format(string, sizeof(string), "�� ��������� %d ����������� ������ �� %d ��������.", strval(inputtext)*500, strval(inputtext));
				SCM(playerid, blue, string);
				SaveAccounts(playerid);
			}
		}
	}
	#if	defined	donate__OnDialogResponse
		return donate__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse donate__OnDialogResponse
#if	defined	donate__OnDialogResponse
	forward donate__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

stock DonateChangeName(playerid, playerName[])
{
    stringer[0] = EOS;
	format(stringer,512, "UPDATE `accounts` SET `pName` = '%s' WHERE `pName` = '%s' LIMIT 1",playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");

	format(stringer, 512, "UPDATE `referals` SET `login` = '%s' WHERE `login` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");

	format(stringer, 512, "UPDATE `referals` SET `login_invited` = '%s' WHERE `login_invited` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `kvart` SET `kvart_Owner` = '%s' WHERE `kvart_Owner` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `houses` SET `hOwner` = '%s' WHERE `hOwner` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `fines` SET `fined` = '%s' WHERE `fined` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `familys` SET `fCreatorName` = '%s' WHERE `fCreatorName` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `bussines` SET `bOwner` = '%s' WHERE `bOwner` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `bans` SET `AdminNick` = '%s' WHERE `AdminNick` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");
	
	format(stringer, 512, "UPDATE `radars` SET `radar_set` = '%s' WHERE `radar_set` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");

	format(stringer, 512, "UPDATE `unwarn` SET `Nick` = '%s' WHERE `Nick` = '%s'", playerName,PlayerInfo[playerid][pName]);
	mysql_tquery(connects, stringer, "", "");

	if(PlayerInfo[playerid][pBizID] != -1){
		foreach(new i : Allbusiness){
			if(BusinessInfo[i][bID] == PlayerInfo[playerid][pBizID]){
				format(BusinessInfo[i][bOwner], 50, "%s", playerName);
				UpdateBusiness(i);
				break;
			}
		}
	}
	if(PlayerInfo[playerid][pHomeID] != -1){
		foreach(new i : Allhouses){
			if(HouseInfo[i][hID] == PlayerInfo[playerid][pHomeID]){
				format(HouseInfo[i][hOwner], 50, "%s", playerName);
				SaveHouse(i);
				break;
			}
		}
	}
	if(PlayerInfo[playerid][pKvartID] != -1){
		foreach(new i : Allkvart){
			if(KvartInfo[i][kvart_id] == PlayerInfo[playerid][pKvartID]){
				format(KvartInfo[i][kvart_Owner], 50, "%s", playerName);
				SaveKvart(i);
				break;
			}
		}
	}

 	stringer[0] = EOS;
	new strstre[30];
	new day, month, year, hour, minute, second;
	getdate(day, month, year);
	gettime(hour, minute, second);
	format(strstre, sizeof(strstre), "%d/%d/%d - %d:%d:%d", day, month, year, hour, minute, second);
	mysql_format(connects, stringer, sizeof(stringer), "INSERT INTO `name_log` (`nOldName`, `nNewName`, `nDate`, `nAccountId`) VALUES ('%s', '%s', '%s', '%d')", 
	PlayerInfo[playerid][pName], 
	playerName, 
	strstre,
	PlayerInfo[playerid][pID]);
	mysql_tquery(connects, stringer);

	format(stringer,100, "����� %s ������ ��� �� %s [����� �����]",PlayerInfo[playerid][pName],playerName);
	SCMA(orange, stringer);
	SetPVarInt(playerid,"changename_fix",true);
	SetPlayerName(playerid, playerName);
	strmid(PlayerInfo[playerid][pName], playerName, 0, strlen(playerName), 31);

 	SCM(playerid, blue, "[��������]{"cwhite"}: ��������� ����� ��� � ���� CR-MP");

	DeletePVar(playerid,"WantNickChange");
	return 1;
}