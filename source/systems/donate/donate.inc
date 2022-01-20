enum
	E_DONATE_DATE
{
	donate_name[70]
};

new const
	donate_list[11][E_DONATE_DATE] =
{
	{"Перевести кредиты в рубли (1 кр. = 500 рублей)"},
	{"Сменить имя (50. кр.)"},
	{"Снять все предупреждения (100. кр.)"},
	{"Снять розыск (50 кр.)"},
	{"Военный билет (100. кр.)"},
	{"+1 EXP (10 кр.)"},
	{"+1 LvL (100 кр.)"},
	{"Навыки оружия (50 кр. = 1 шт. | 200 кр. = все)"},
	{"VIP аккаунт"},
	{"Приобрести номера на авто"},
	{"Приобрести уникальную симкарту"}
};

#include "../source/systems/donate/change_car_number.inc"

CMD:donate(playerid)
{
	new string[1024], str[128];
	strcat(string, "{"cblue"}Донат {ffffff}- это Ваше пожертвование нашему проекту реальными деньгами\nна развитие и поддержание серверов и обновлений. За это вы получаете кредиты.\n\n");
	strcat(string, "{"cblue"}1 российский рубль = 1 кредиту\n\n");
	strcat(string, "{FFFFFF}За кредиты можно приобретать на игровых серверах различные услуги, ценности, возможности,\n");
	strcat(string, "а также переводить в игровые деньги {"cblue"}(1 кредит = 500 игровых рублей)\n\n\n");

	strcat(string, "{"cred"}Что бы получить кредиты нужно:\n\n");
	strcat(string, "{"cblue"}1) {FFFFFF}Зайти на сайт {"cblue"}unigva-rp.ru/donate\n");
	strcat(string, "{"cblue"}2) {FFFFFF}Выбрать сервер, на котором Вы играете\n");
	strcat(string, "{"cblue"}3) {FFFFFF}Указать свой никнэйм и желаемую сумму поплнения\n");
	strcat(string, "{"cblue"}4) {FFFFFF}Выбрать способ оплаты (QIWI, WebMoney, Яндекс.Деньги, SMS, банковскую карту любого банка)\n");
	strcat(string, "{"cblue"}5) {FFFFFF}После этого написать команду {"cblue"}/donate\n\n");
	format(str, sizeof(str), "{ffffff}Ваш никнэйм:\t\t\t\t{"cblue"}%s\n", PlayerInfo[playerid][pName]);
	strcat(string, str);
	format(str, sizeof(str), "{ffffff}Номер вашего аккаунта:\t\t{"cblue"}%d\n", PlayerInfo[playerid][pID]);
	strcat(string, str);
	format(str, sizeof(str), "{ffffff}Количество ваших кредитов:\t\t{"cblue"}%d", PlayerInfo[playerid][pDonate]);
	strcat(string, str);
	SPD(playerid, D_DONATE, DIALOG_STYLE_MSGBOX, "{"cblue"}Дополнительные средства", string, "Далее", "Отмена");
	return 1;
}

stock ShowDonateListDialog(playerid){
	new fmt_dialog[528], string[128];
	for(new i = 0; i < sizeof(donate_list); i++)
	{
		format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i+1, donate_list[i][donate_name]);
		strcat(fmt_dialog, string);
	}
	SPD(playerid, D_DONATE_LIST, DIALOG_STYLE_LIST, "{"cblue"}Дополнительные услуги", fmt_dialog, "Далее", "Отмена");	
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
						format(string, sizeof(string), "{ffffff}Введите количество кредитов, которое вы хотите перевести в рубли. В данный момент у вас: %d руб.", PlayerInfo[playerid][pDonate]);
						SPD(playerid, D_DONATE_BUY_MONEY, DIALOG_STYLE_INPUT, !"{"cblue"}Донат", string, !"Далее", "Назад");
					}
					case 1:{//смена имени
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"У вас недостаточно кредитов.");
						SPD(playerid, D_DONATE_CHANGE_NAME, DIALOG_STYLE_INPUT, "{"cblue"}Смена ника", "{"cwhite"}Если ваш ник-нейм не соотвестует нормативам RolePlay, то вы можете его сменить.\n\nФормат: {"cblue"}Andrey_Sergeev, Ekaterina_Petrova", "Далее", "Отмена");
					}
					case 2:{
						if(PlayerInfo[playerid][pWarn] < 1) return SCM(playerid, red, !"У вас нет предупреждений.");
						ShowPlayerDialog(playerid, D_DONATE_BUY_NULL_WARN, DIALOG_STYLE_MSGBOX, !"{"cblue"}Донат", !"{FFFFFF}Вы желаете снять все предупреждения за 100 кредитов?", !"Да", !"Нет");
					}
					case 3:{
						if(PlayerInfo[playerid][pWANTED] < 1) return SCM(playerid, red, !"Вас не разыскивает полиция.");
						ShowPlayerDialog(playerid, D_DONATE_BUY_NULL_WANTED, DIALOG_STYLE_MSGBOX, !"Донат", !"{ffffff}Вы желаете снять розыск за 50 кредитов?", !"Да", !"Нет");
					}
					case 4:{
						if(PlayerInfo[playerid][pVoen] > 0) return SendClientMessage(playerid, red, !"У вас уже есть военный билет.");
						ShowPlayerDialog(playerid, D_DONATE_BUY_VOEN, DIALOG_STYLE_MSGBOX, !"{"cblue"}Донат", !"{ffffff}Вы желаете приобрести военный билет за 100 кредитов?", !"Да", !"Нет");
					}
					case 5:{//+1 exp
						ShowPlayerDialog(playerid, D_DONATE_BUY_1_EXP, DIALOG_STYLE_MSGBOX, !"{"cblue"}Донат", !"{FFFFFF}Вы желаете приобрести 1 exp за 10 рублей?", !"Да", !"Нет");
					}
					case 6:{//+1 lvl
						ShowPlayerDialog(playerid, D_DONATE_BUY_1_LVL, DIALOG_STYLE_MSGBOX, !"{"cblue"}Донат", !"{FFFFFF}Вы желаете приобрести 1 lvl за 100 рублей?", !"Да", !"Нет");
					}
					case 7:{//оружие навыки
						ShowPlayerDialog
						(
							playerid, D_DONATE_GUN_SKILLS_LIST, DIALOG_STYLE_LIST,
							!"{"cblue"}Донат | Навыки владения оружием",
							!"\
							{"cblue"}1. {FFFFFF}SD Pistol {"cblue"}(50 кр.){FFFFFF}\n\
							{"cblue"}2. {FFFFFF}Desert Eagle {"cblue"}(50 кр.){FFFFFF}\n\
							{"cblue"}3. {FFFFFF}ShotGun {"cblue"}(50 кр.){FFFFFF}\n\
							{"cblue"}4. {FFFFFF}MP5 {"cblue"}(50 кр.){FFFFFF}\n\
							{"cblue"}5. {FFFFFF}AK 47 {"cblue"}(50 кр.){FFFFFF}\n\
							{"cblue"}6. {FFFFFF}M4 {"cblue"}(50 кр.){FFFFFF}\n\
							{"cblue"}7. {FFFFFF}Все навыки {"cblue"}(50 кр.){FFFFFF}\n\
							",
							!"Купить", !"Назад"
						);
					}
					case 8:{//випка
						ShowPlayerDialog(playerid, D_DONATE_BUY_VIP, DIALOG_STYLE_LIST, !"{"cblue"}Донат", !"\
						{"cblue"}1. {ffffff}7 дней {"cblue"}(60 кр.)\n\
						{"cblue"}2. {ffffff}30 дней {"cblue"}(200 кр.)\n\
						{"cblue"}3. {ffffff}365 дней {"cblue"}(600 кр.)\
						", !"Купить", !"Назад");
					}
				}
			}
		}
		case D_DONATE_GUN_SKILLS_LIST:{
			if(!response) return ShowDonateListDialog(playerid); else{
				switch(listitem)
				{
					case 0:{
						if(PlayerInfo[playerid][SKILL_SD_PISTOL] >= 100) return SCM(playerid, red, !"Вы уже достаточно овладели данным видом оружия.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"У вас недостаточно кредитов.");

						PlayerInfo[playerid][SKILL_SD_PISTOL] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"Вы успешно приобрели навыки владения оружием SD Pistol.");
					}
					case 1:{
						if(PlayerInfo[playerid][SKILL_DEAGLE] >= 100) return SCM(playerid, red, !"Вы уже достаточно овладели данным видом оружия.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"У вас недостаточно кредитов.");

						PlayerInfo[playerid][SKILL_DEAGLE] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"Вы успешно приобрели навыки владения оружием Desert Eagle.");
					}
					case 2:{
						if(PlayerInfo[playerid][SKILL_SHOTGUN] >= 100) return SCM(playerid, red, !"Вы уже достаточно овладели данным видом оружия.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"У вас недостаточно кредитов.");

						PlayerInfo[playerid][SKILL_SHOTGUN] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"Вы успешно приобрели навыки владения оружием ShotGun.");
					}
					case 3:{
						if(PlayerInfo[playerid][SKILL_MP5] >= 100) return SCM(playerid, red, !"Вы уже достаточно овладели данным видом оружия.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"У вас недостаточно кредитов.");

						PlayerInfo[playerid][SKILL_MP5] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"Вы успешно приобрели навыки владения оружием АК-74У.");
					}
					case 4:{
						if(PlayerInfo[playerid][SKILL_AK_47] >= 100) return SCM(playerid, red, !"Вы уже достаточно овладели данным видом оружия.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"У вас недостаточно кредитов.");

						PlayerInfo[playerid][SKILL_AK_47] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"Вы успешно приобрели навыки владения оружием AK-47.");
					}
					case 5:{
						if(PlayerInfo[playerid][SKILL_M4] >= 100) return SCM(playerid, red, !"Вы уже достаточно овладели данным видом оружия.");
						if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"У вас недостаточно кредитов.");

						PlayerInfo[playerid][SKILL_M4] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 50;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"Вы успешно приобрели навыки владения оружием M4.");
					}
					case 6:{
						if(PlayerInfo[playerid][SKILL_M4] >= 100 && PlayerInfo[playerid][SKILL_MP5] == 100 && PlayerInfo[playerid][SKILL_AK_47] == 100 && PlayerInfo[playerid][SKILL_SHOTGUN] == 100 && PlayerInfo[playerid][SKILL_SD_PISTOL] == 100 && PlayerInfo[playerid][SKILL_DEAGLE] == 10) 
							return SCM(playerid, red, !"Вы уже достаточно овладели всеми видами оружия.");
						if(PlayerInfo[playerid][pDonate] < 200) return SCM(playerid, red, !"У вас недостаточно кредитов.");

						PlayerInfo[playerid][SKILL_M4] = 100;
						PlayerInfo[playerid][SKILL_AK_47] = 100;
						PlayerInfo[playerid][SKILL_MP5] = 100;
						PlayerInfo[playerid][SKILL_SHOTGUN] = 100;
						PlayerInfo[playerid][SKILL_SD_PISTOL] = 100;
						PlayerInfo[playerid][SKILL_DEAGLE] = 100;
						SetPlayerSkills(playerid);
						PlayerInfo[playerid][pDonate] -= 200;
						SaveAccounts(playerid);
						SCM(playerid, blue, !"Вы успешно приобрели навыки владения всем оружием.");
					}
				}
			}
		}
		case D_DONATE_BUY_VIP:{
			if(!response) return ShowDonateListDialog(playerid);
			else{
				switch(listitem){
					case 0:{
						if(PlayerInfo[playerid][pDonate] < 60) return SCM(playerid, red, !"У вас недостаточно кредитов.");

						SCM(playerid, blue, !"Вы успешно приобрели VIP на 7 дней за 60 кредитов.");
						PlayerInfo[playerid][pVIP] += gettime() + 7*86400;
						SaveAccounts(playerid);
					}
					case 1:{
						if(PlayerInfo[playerid][pDonate] < 200) return SCM(playerid, red, !"У вас недостаточно кредитов.");

						SCM(playerid, blue, !"Вы успешно приобрели VIP на один месяц за 200 кредитов.");
						PlayerInfo[playerid][pVIP] += gettime() + 30*86400;
						SaveAccounts(playerid);
					}
					case 2:{
						if(PlayerInfo[playerid][pDonate] < 600) return SCM(playerid, red, !"У вас недостаточно кредитов.");

						SCM(playerid, blue, !"Вы успешно приобрели VIP на один год за 600 кредитов.");
						PlayerInfo[playerid][pVIP] += gettime() + 365*86400;
						SaveAccounts(playerid);
					}
				}
			}
		}
		case D_DONATE_CHANGE_NAME:{
			if(!response) return ShowDonateListDialog(playerid);
			else{
				if(!IsRPNick(inputtext)){
					return SCM(playerid, red, !"Вы ввели NonRP ник.");
				}
				SCM(playerid, blue, !"Вы успешно сменили NickName за 50 кредитов.");
				PlayerInfo[playerid][pDonate] -= 50;
				DonateChangeName(playerid, inputtext);
			}
		}
		case D_DONATE_BUY_1_LVL:{
			if(!response) return ShowDonateListDialog(playerid); else{
				if(PlayerInfo[playerid][pDonate] < 100) return SCM(playerid, red, !"У вас недостаточно кредитов.");

				PlayerInfo[playerid][pDonate] -= 100;
				PlayerInfo[playerid][pLVL]++;
				SetPlayerScore(playerid, PlayerInfo[playerid][pLVL]);
				SCM(playerid, blue, !"Вы повысили уровень за 100 кредитов.");
				SCM(playerid, blue, !"Ваш уровень был повышен.");

				if(PlayerInfo[playerid][pLVL] == 5 && PlayerInfo[playerid][pExp] == 0)
				{
					if(strlen(PlayerInfo[playerid][pReferal]) > 5)
					{
						static const fmt_query[] = "INSERT INTO `referals` (`login`, `login_invited`) VALUES ('%s', '%s')";
						new query[sizeof(fmt_query)+(-2+MAX_PLAYER_NAME)];
						format(query, sizeof(query), fmt_query, PlayerInfo[playerid][pReferal], PlayerInfo[playerid][pName]);
						mysql_tquery(connects, query, "", "");

						PlayerInfo[playerid][pBCash] += 50000;
						SCM(playerid, blue, !"Поздравляем! Вы достигли 5 уровня, поэтому вы и ваш Реферал получили по 50.000!");

						if(IsPlayerConnected(GetPlayerID(PlayerInfo[playerid][pReferal])))
						{
							PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pBCash] += 50000;
							stringer[0] = EOS;
							format(stringer,512, "UPDATE `accounts` SET `pBCash` = '%d' WHERE `pName` = '%s'", PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pBCash], PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pName]);
							mysql_tquery(connects, stringer, "", "");

							SCM(GetPlayerID(PlayerInfo[playerid][pReferal]), blue, !"Поздравляем! Ваш реферал достиг 5 уровня и он и вы получили по 50000!");
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
				if(PlayerInfo[playerid][pDonate] < 10) return SCM(playerid, red, !"У вас недостаточно кредитов.");

				PlayerInfo[playerid][pDonate] -= 10;
				PlayerInfo[playerid][pExp]++;
				SCM(playerid, blue, !"Вы приобрели 1 exp за 10 кредитов.");
				if(PlayerInfo[playerid][pExp] >= (PlayerInfo[playerid][pLVL]*4)) {
					PlayerInfo[playerid][pLVL]++;
					SetPlayerScore(playerid, PlayerInfo[playerid][pLVL]);
					PlayerInfo[playerid][pExp] = 0;
					SCM(playerid, blue, !"Ваш уровень был повышен.");

					if(PlayerInfo[playerid][pLVL] == 5 && PlayerInfo[playerid][pExp] == 0)
					{
						if(strlen(PlayerInfo[playerid][pReferal]) > 5)
						{
							static const fmt_query[] = "INSERT INTO `referals` (`login`, `login_invited`) VALUES ('%s', '%s')";
							new query[sizeof(fmt_query)+(-2+MAX_PLAYER_NAME)];
							format(query, sizeof(query), fmt_query, PlayerInfo[playerid][pReferal], PlayerInfo[playerid][pName]);
							mysql_tquery(connects, query, "", "");

							PlayerInfo[playerid][pBCash] += 50000;
							SCM(playerid, blue, !"Поздравляем! Вы достигли 5 уровня, поэтому вы и ваш Реферал получили по 50.000!");

							if(IsPlayerConnected(GetPlayerID(PlayerInfo[playerid][pReferal])))
							{
								PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pBCash] += 50000;
								stringer[0] = EOS;
								format(stringer,512, "UPDATE `accounts` SET `pBCash` = '%d' WHERE `pName` = '%s'", PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pBCash], PlayerInfo[GetPlayerID(PlayerInfo[playerid][pReferal])][pName]);
								mysql_tquery(connects, stringer, "", "");

								SCM(GetPlayerID(PlayerInfo[playerid][pReferal]), blue, !"Поздравляем! Ваш реферал достиг 5 уровня и он и вы получили по 50000!");
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
				if(PlayerInfo[playerid][pDonate] < 100) return SCM(playerid, red, !"У вас недостаточно кредитов.");

				PlayerInfo[playerid][pDonate] -= 100;
				SCM(playerid, blue, !"Вы сняли все предупреждения с аккаунта за 100 кредитов.");

				new string[144];
				format(string, sizeof(string), "DELETE FROM `unwarn` WHERE `Nick` = '%s' LIMIT 1", PlayerInfo[playerid][pName]);
				mysql_tquery(connects, string, "","");

				PlayerInfo[playerid][pWarn] = 0;
				SaveAccounts(playerid);
			}
		}
		case D_DONATE_BUY_NULL_WANTED:{
			if(!response) return ShowDonateListDialog(playerid); else{
				if(PlayerInfo[playerid][pDonate] < 50) return SCM(playerid, red, !"У вас недостаточно кредитов.");

				PlayerInfo[playerid][pDonate] -= 50;
				SetPlayerWanted(playerid, 0);
				SCM(playerid, blue, !"Вы сняли с себя розыск за 50 кредитов."); 
				SaveAccounts(playerid);
			}
		}
		case D_DONATE_BUY_VOEN:{
			if(!response) return ShowDonateListDialog(playerid); else{
				if(PlayerInfo[playerid][pDonate] < 100) return SCM(playerid, red, !"У вас нет такого количества кредитов.");

				PlayerInfo[playerid][pVoen] = 1;
				PlayerInfo[playerid][pDonate] -= 100;
				SCM(playerid, blue, !"Вы успешно приобрели себе военный билет за 100 кредитов.");
				SaveAccounts(playerid);
			}
		}
		case D_DONATE_BUY_MONEY:{
			if(!response) return ShowDonateListDialog(playerid);
			else{
				if(PlayerInfo[playerid][pDonate] < strval(inputtext))
					return SCM(playerid, red, "У вас нет такого количество кредитов.");

				GiveMoney(playerid, strval(inputtext)*500, "Через донат");
				PlayerInfo[playerid][pDonate] -= strval(inputtext);

				new string[144];
				format(string, sizeof(string), "Вы приобрели %d виртуальных рублей за %d кредитов.", strval(inputtext)*500, strval(inputtext));
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

	format(stringer,100, "Игрок %s сменил имя на %s [Через донат]",PlayerInfo[playerid][pName],playerName);
	SCMA(orange, stringer);
	SetPVarInt(playerid,"changename_fix",true);
	SetPlayerName(playerid, playerName);
	strmid(PlayerInfo[playerid][pName], playerName, 0, strlen(playerName), 31);

 	SCM(playerid, blue, "[Внимание]{"cwhite"}: Пропишите новый ник в окне CR-MP");

	DeletePVar(playerid,"WantNickChange");
	return 1;
}