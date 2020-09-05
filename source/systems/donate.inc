enum
	E_DONATE_DATE
{
	donate_name[70]
};

new const
	donate_list[9][E_DONATE_DATE] =
{
	{"Перевести кредиты в рубли (1 кр. = 500 рублей)"},
	{"Сменить имя (50. кр.)"},
	{"Снять все предупреждения (100. кр.)"},
	{"Снять розыск (50 кр.)"},
	{"Военный билет (100. кр.)"},
	{"+1 EXP (10 кр.)"},
	{"+1 LvL (100 кр.)"},
	{"Навыки оружия (50 кр. = 1 шт. | 200 кр. = все)"},
	{"VIP аккаунт"}
};

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
	format(str, sizeof(str), "{ffffff}Количество ваших кредитов:\t{"cblue"}%d", PlayerInfo[playerid][pDonate]);
	strcat(string, str);
	SPD(playerid, D_DONATE, DIALOG_STYLE_MSGBOX, "{"cblue"}Дополнительные средства", string, "Далее", "Отмена");
	return 1;
}

stock ShowDonateListDialog(playerid){
	new fmt_dialog[528], string[128];
	for(new i = 0; i < 8; i++)
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
					case 1:{
						//смена имени
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
						
					}
					case 8:{//випка
						
					}
				}
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