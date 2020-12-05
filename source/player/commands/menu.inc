enum E_CMDS_ORG_STRUCT
{
	ORG_INFO[1048]
};

new help_cmds_org_list[8][E_CMDS_ORG_STRUCT] =
{
	{
		"{ffffff}Команды организации: {ffcc00}Администрация области{ffffff}\n\n"\
		"/free [id игрока] [цена] - выпустить игрока из КПЗ\n"\
		"/tazer [id игрока] - ударить игрока электрошокером"
	},
	{
		"\n{ffffff}Команды организации: {ffcc00}Патрульно-Постовая Служба (ППС){ffffff}\n\n"\
		"/open - открыть ворота\n"\
		"/tazer [id игрока] - ударить игрока электрошокером\n"\
		"/su [id игрока] [причина] - объявить игрока в розыск\n"\
		"/clear [id игрока] - снять с игрока розыск\n"\
		"/arrest [id игрока] - посадить игрока в КПЗ\n"\
		"/incar [id игрока] - затащить игрока в машину\n"\
		"/cuff [id игрока] - надеть наручники на игрока\n"\
		"/uncuff [id игрока] - снять наручники с игрока\n"\
		"/stopcar - поднять/опустить жезл\n"\
		"/deject [id игрока] - насильно вытащить игрока из авто\n"\
		"/m [текст] - сказать в мегафон\n"\
		"/ticket [id игрока] [штраф] [причина] - выписать штраф игроку\n"\
		"/calling - список входящих вызовов"
	},
	{
		"\n{ffffff}Команды организации: {ffcc00}Скорая Медицинская Помощь (СМП){ffffff}\n\n"\
		"/heal [id игрока] [стоимость] - вылечить игрока до 100 ХП\n"\
		"/calling - список входящих вызовов"
	},
	{
		"\n{ffffff}Команды организации: {ffcc00}Воздушно-десантные войска (ВДВ){ffffff}\n\n"\
		"/openvdv - открыть ворота\n"\
		"/putmet [количество] - положить металл на склад ВДВ\n"\
		"/getmet [количество] - взять металл сл склада ВДВ"
	},
	{
		"\n{ffffff}Команды организации: {ffcc00}Средства Массовой Информации (СМИ){ffffff}\n\n"\
		"/edit - редактировать объявление\n"\
		"/news - эфир"
	},
	{
		"\n{ffffff}Команды организации: {ffcc00}Организованные Преступные Группировки (ОПГ){ffffff}\n\n"\
		"/bizwar - начать войну за бизнесс\n"\
		"/makegun - создать оружие\n"\
		"/tie [id игрока] - связать игрока\n"\
		"/untie [id игрока] - развязать игрока\n"\
		"/sellgun [id игрока] [кол-во патронов] [цена] - продать оружие игроку\n"\
		"/selldrugs [id игрока] [кол-во грам] [цена] - продать наркотики игроку"
	},
	{
		"\n{ffffff}Команды организации: {ffcc00}Общие{ffffff}\n\n"\
		"/find - посмотреть список онлайн игроков в организации\n"\
		"/r [текст] - написать в РП чат организации/работы\n"\
		"/rb [текст] - написать в ООС чат организации/работы\n"\
		"/d [текст] - IC (RP) гос.чат фракций (Для ОПГ недоступен!)\n"\
		"/db [текст] - OOC (NoNRP) гос.чат фракций (Для ОПГ недоступен!)"
	},
	{
		"\n{ffffff}Команды организации: {ffcc00}Лидер/заместитель{ffffff}\n\n"\
		"/invite [ID игрока] - принять игрока в вашу фракцию\n"\
		"/uninvite [ID игрока] [Причина увольнения] - уволить игрока\n"\
		"/uninviteoff [Ник игрока] [Причина увольнения] - уволить игрока оффлайн\n"\
		"/showall - посмотреть всех членов фракции\n"\
		"/rang [ID игрока] [+/-] - повысить игрока/понизить игрока\n"\
		"/r [текс] - IC (RP) чат фракции\n"\
		"/rb[текст] - OOC (NoNRP) чат фракции)\n"\
		"/d [текст] - IC (RP) гос.чат фракций (Для ОПГ недоступен!)\n"\
		"/db [текст] - OOC (NoNRP) гос.чат фракций (Для ОПГ недоступен!)\n"\
		"/gov [текст] - новости (Проведение набора)\n"\
		"/changeskin [ID игрока] - изменить скин (внешность) игрока (Доступно только для 8+ рангов)"
	}
};

ALTX:menu("/mn", "/mm");
CMD:menu(playerid)
{
    ShowMenu(playerid);
	return 1;
}
CMD:ask(playerid)
{
	return SPD(playerid, D_MENU_ASK, DIALOG_STYLE_INPUT, !"{"cblue"}Задать вопрос", !"{FFFFFF}На большинство ваших вопросов есть ответы, напшите - {"cblue"}/help {"cwhite"}и почитайте, если вы не нашли ответ на ваш вопрос, то вы можете его тут задать!\n\nПожалуйста, напишите всё кратко и четко и администрация вам ответит в ближайшее время!", !"Далее", !"Назад");
}
CMD:report(playerid)
{
	return SPD(playerid, D_MENU_REP, DIALOG_STYLE_INPUT, !"{"cblue"}Подать жалобу", !"{FFFFFF}Если вы заметили нарушителя, то здесь вы можете на него подать жалобу!\n\nПожалуйста напишите ID нарушителя и кртако опишите его нарушение.\nВ случае, если нарушитель {"cred"}оффлайн {FFFFFF}, но у вас есть доказательства, что он нарушил правила, \nто вы можете подать жалобу на нашем форуме.", !"Далее", !"Назад");
}

stock ShowMenu(playerid)
{
	SPD(playerid, 8, DIALOG_STYLE_LIST, !"{"cblue"}Меню", !"\
	{"cblue"}1. {FFFFFF}Статистика\n\
	{"cblue"}2. {FFFFFF}Команды сервера\n\
	{"cblue"}3. {FFFFFF}Защита аккаунта\n\
	{"cblue"}4. {FFFFFF}Вопросы / жалобы на игроков\n\
	{"cblue"}5. {FFFFFF}Смена NonRP ника\n\
	{"cblue"}6. {FFFFFF}Персональные настройки\n\
	{"cblue"}7. {FFFFFF}Дополнитильные услуги", !"Далее", !"Отмена");
	return 1;
}


public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case 8:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0: stats_player(playerid, playerid);
					case 1: SPD(playerid, 11, DIALOG_STYLE_LIST, "{"cblue"}Команды сервер", "{"cblue"}1. {FFFFFF}Команды организаций\n{"cblue"}2. {FFFFFF}Команды работ\n{"cblue"}3. {FFFFFF}Команды недвижимости\n{"cblue"}4. {FFFFFF}Команды общения\n{"cblue"}5. {FFFFFF}Команды остальные", "Далее", "Отмена");
					case 2: SPD(playerid, 13, DIALOG_STYLE_LIST, "{"cblue"}Безопасность аккаунта", "{"cblue"}1. {FFFFFF}Смена пароля", "Далее", "Назад");
					case 3: SPD(playerid, D_MENU_ASK_REP, DIALOG_STYLE_LIST, !"{"cblue"}Вопросы / жалобы на игроков", !"{"cblue"}1. {FFFFFF}Задать вопрос\n{"cblue"}2. {FFFFFF}Жалоба на игрока", !"Далее", !"Назад");
					case 4: SPD(playerid, 9, DIALOG_STYLE_INPUT, "{"cblue"}Смена ника", "{"cwhite"}Если ваш ник-нейм не соотвестует нормативам RolePlay, то вы можете его сменить.\n\nФормат: {"cblue"}Andrey_Sergeev, Ekaterina_Petrova", "Далее", "Отмена");
					case 5:
					{
						stringer[0] = EOS;
						format(stringer, 500, "\
						{"cblue"}1. {FFFFFF}3D TextDraw\t\t| %s {"cred"}(BETA){"cwhite"}\n\
						{"cblue"}2. {FFFFFF}Очистить чат\n\
						{"cblue"}3. {FFFFFF}Указать телеграм",
						((PlayerInfo[playerid][pLogo] == 0) ? ("{"clred"}Отключен") : ("{"cblue"}Включен")));
						SPD(playerid, 10, DIALOG_STYLE_LIST, "{"cblue"}Персональные настройки", stringer, "Далее", "Назад");
					}
					case 6: cmd::donate(playerid);
					//case 6: SPD(playerid, 12, DIALOG_STYLE_INPUT, "{"cblue"}Пожертвование денег", "{"cwhite"}Введите сумму, которую вы готовы пожертвовать на развитие области!", "Далее", "Назад");
				}
			}
		}
		case 9:
		{
			if(response)
			{
				if(!strlen(inputtext)) return SPD(playerid, 9, DIALOG_STYLE_INPUT, "{"cblue"}Смена ника", "{"cwhite"}Если ваш ник-нейм не соотвестует нормативам RolePlay, то вы можете его сменить.\n\nФормат: {"cblue"}Andrey_Sergeev, Ekaterina_Petrova", "Далее", "Отмена");
				if(IsTextInvalid(inputtext)) return SPD(playerid, 9, DIALOG_STYLE_INPUT, "{"cblue"}Смена ника", "{"cwhite"}Если ваш ник-нейм не соотвестует нормативам RolePlay, то вы можете его сменить.\n\nФормат: {"cblue"}Andrey_Sergeev, Ekaterina_Petrova", "Далее", "Отмена");
				if(strlen(inputtext) < 6 || strlen(inputtext) > 24) return SPD(playerid, 9, DIALOG_STYLE_INPUT, "{"cblue"}Смена ника", "{"cwhite"}Если ваш ник-нейм не соотвестует нормативам RolePlay, то вы можете его сменить.\n\nФормат: {"cblue"}Andrey_Sergeev, Ekaterina_Petrova", "Далее", "Отмена");
				stringer[0] = EOS;
				SetPVarString(playerid,"WantNickChange", inputtext);
				format(stringer,128, "SELECT `pName` FROM `accounts` WHERE `pName` = '%s' LIMIT 1", inputtext);
				mysql_tquery(connects, stringer,  "CallChangeName", "d", playerid);
			}
		}
		case 10:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(PlayerInfo[playerid][pLogo] == 0)
						{
							PlayerInfo[playerid][pLogo] = 1;
							SCM(playerid, white, "{"cgreen"}[Успешно]{"cwhite"}: Вы Включили 3D TextDraw!");
							for(new i = 0; i < 3; i++) TextDrawHideForPlayer(playerid, logotype_td[i]);

							TextDrawShowForPlayer(playerid, logotype_td[3]);
						}
						else
						{
							PlayerInfo[playerid][pLogo] = 0;
							SCM(playerid, white, "{"cgreen"}[Успешно]{"cwhite"}: Вы Отключили 3D TextDraw!");
							TextDrawHideForPlayer(playerid, logotype_td[3]);

							for(new i = 0; i < 3; i++) TextDrawShowForPlayer(playerid, logotype_td[i]);
						}
					}
					case 1:
					{
						for(new i = 0; i < 100; i++)
						{
							SCM(playerid, white, "");
						}
						SCM(playerid, white, "Вы успешно очистили чат!");
					}
					case 2:{
						if(response){
							SPD(playerid, D_MENU_SET_TELEGRAM_ID, DIALOG_STYLE_INPUT, !"{"cblue"}Меня | Telegram", !"\
							{ffffff}Укажите ваш телеграм ID, дабы потом воспользоватся функциями нашего бота.\n\
							Узнать свой телеграм ID вы можете так же в нашем боте, воспользовавшись командой /get_my_id\n\
							Ссылка на наш telegram bot: {"cblue"}t.me/unigva_rp_bot{ffffff}\n\n\
							{"cblue"}Примечание: {ffffff}Если вы укажите неправильно telegramid, вы не сможете воспользоватся функциями нашего бота.\
							", !"Указать", !"Закрыть");
						} else return 1;
					}
				}
			}
		}
		case D_MENU_SET_TELEGRAM_ID:{
			if(response){
				if(!strlen(inputtext)){
					SPD(playerid, D_MENU_SET_TELEGRAM_ID, DIALOG_STYLE_INPUT, !"{"cblue"}Меня | Telegram", !"\
					{ffffff}Укажите ваш телеграм ID, дабы потом воспользоватся функциями нашего бота.\n\
					Узнать свой телеграм ID вы можете так же в нашем боте, воспользовавшись командой /get_my_id\n\
					Ссылка на наш telegram bot: {"cblue"}t.me/unigva_rp_bot{ffffff}\n\n\
					{"cblue"}Примечание: {ffffff}Если вы укажите неправильно telegramid, вы не сможете воспользоватся функциями нашего бота.\
					", !"Указать", !"Закрыть");
					return 1;
				}
				if(!IsNumeric(inputtext)){
					SPD(playerid, D_MENU_SET_TELEGRAM_ID, DIALOG_STYLE_INPUT, !"{"cblue"}Меня | Telegram", !"\
					{ffffff}Укажите ваш телеграм ID, дабы потом воспользоватся функциями нашего бота.\n\
					Узнать свой телеграм ID вы можете так же в нашем боте, воспользовавшись командой /get_my_id\n\
					Ссылка на наш telegram bot: {"cblue"}t.me/unigva_rp_bot{ffffff}\n\n\
					{"cblue"}Примечание: {ffffff}Если вы укажите неправильно telegramid, вы не сможете воспользоватся функциями нашего бота.\
					", !"Указать", !"Закрыть");
					return 1;					
				}
				PlayerInfo[playerid][pTelegramId] = strval(inputtext);
				SaveAccounts(playerid);
				SCM(playerid, blue, !"Вы успешно указали Telegram ID.");
			}else return 1;
		}
		case 11:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:{
						ShowPlayerDialog
						(
							playerid, D_MENU_ORG_COMMANDS, DIALOG_STYLE_LIST,
							!"{"cblue"}Команды организаций",
							!"\
							{"cblue"}1. {ffffff}Администрация посёлка\n\
							{"cblue"}2. {ffffff}Патрульно-постовая служба (ППС)\n\
							{"cblue"}3. {ffffff}Скорая медицинская помощь (СМП)\n\
							{"cblue"}4. {ffffff}Воздушно-десантные войска (ВДВ)\n\
							{"cblue"}5. {ffffff}Средства массовой информации (СМИ)\n\
							{"cblue"}6. {ffffff}Организованные преступные группировки (ОПГ)\n\
							{"cblue"}7. {ffffff}Общие команды организаций\n\
							{"cblue"}8. {ffffff}Команды лидеров/заместителей организаций\
							",
							!"Далее", !"Отмена"
						);
					}
					case 1:{
						ShowPlayerDialog
						(
							playerid, D_NULL, DIALOG_STYLE_MSGBOX,
							"{"cblue"}Команды для работы",
							"\n{ffffff}Команды: {ffcc00}Работ{ffffff}\n\n\
							/calling - посмотреть список вызовов (Механик)\n\
							/repair [id игрока] [стоимость] - починить авто игроку (Механик)\n\
							/jskill - посмотреть свои рабочие навыки (Дальнобойщик)\n\
							/end - окончить работу (Уборщик улиц)\n\
							",
							"Закрыть", ""
						);
					}
					case 2:{
						ShowPlayerDialog
						(
							playerid, D_NULL, DIALOG_STYLE_MSGBOX,
							"{ffcc00}Команды недвижимости",
							"\n{ffffff}Команды недвижимости: {ffcc00}Транспорт, дом, бизнес{ffffff}\n\n\
							/lock [1] - закрыть/открыть личный транспорт\n\
							/sellcar - продать авто государству\n\
							/sellmycar [id игрока] [цена] - продать авто игроку\n\
							/buybiz - купить бизнес\n\
							/business - управление бизнесом\n\
							/sellmybusiness [id игрока] [цена] - продать бизнес игроку\n\
							/sellhome - продать дом государству\n\
							/sellmyhome [id игрока] [цена] - продать дом игроку\n\
							/hlock - закрыть дом\n\
							/hopen - открыть дом\n\
							/home - меню дома\n\
							/use - управление шкафом дома\n\
							/rlock - закрыть/открыть номер в отеле\n\
							/klock - закрыть/открыть квартиру",
							"Закрыть", ""
						);
					}
					case 3:{
						ShowPlayerDialog
						(
							playerid, D_NULL, DIALOG_STYLE_MSGBOX,
							"{ffcc00}Команды общения",
							"\n{ffffff}Команды: {ffcc00}Общение{ffffff}\n\n\
							/rb [текст] - написать в ООС чат организации\n\
							/r [текст] - написать в РП чат организации\n\
							/db [текст] - написать в ООС чат департамента\n\
							/d [текст] - написать в РП чат департамента\n\
							/gov [текст] - написать в гос новости\n\
							/ad [текст] - подать объявление\n\
							/me [текст] - действие игрока от 1 лица\n\
							/try [текст] - действие игрока на удачу\n\
							/do [текст] - действие игрока от 3 лица\n\
							/b [текст] - написать в ООС чат\n\
							/s [текст] - крикнуть в чат\n\
							/call [номер телефона] - позвонить\n\
							/p - взять трубку\n\
							/h - положить трубку\n\
							/sms [номер телефона] [текст] - написать смс игроку\n\
							/togphone - выключить телефон",
							"Закрыть", ""
						);
					}
					case 4:{
						ShowPlayerDialog
						(
							playerid, D_NULL, DIALOG_STYLE_MSGBOX,
							"{ffcc00}Команды остальные",
							"\n{ffffff}Команды: {ffcc00}Остальные{ffffff}\n\n\
							/drugs [количество] - использовать наркотики\n\
							/en - запустить двигатель в транспорте\n\
							/rem - пристегнуть ремень безопасности в транспорте\n\
							/myskill - просмотреть навыки владения оружием\n\
							/skill [id игрока] - показать игроку навыки владения оружием\n\
							/gotomp - телепортиваться на мероприятие\n\
							/pass [id игрока] - показать паспорт\n\
							/lic [id игрока] - показать лицензии\n\
							/time - посмотреть время\n\
							/leaders - посмотреть лидеров в сети\n\
							/eject [id игрока] - выкинуть игрока из авто\n\
							/carpass [id игрока] - показать документы на авто\n\
							/tune - поставить тюннинг на своё авто в СТО\n\
							/gps - навигатор по серверу\n\
							/pay [id игрока] [кол-во] - передать деньги игроку\n\
							/anim [номер анимации] - анимация",
							"Закрыть", ""
						);
					}
				}
			}
		}
		case D_MENU_ORG_COMMANDS:{
			if(response){
				ShowPlayerDialog
				(
					playerid, D_MENU_ORGS_COMMANDS, DIALOG_STYLE_MSGBOX, 
					!"{"cblue"}Команды организаций",
					help_cmds_org_list[listitem][ORG_INFO],
					!"Назад", !""
				);
			}
		}
		case D_MENU_ORGS_COMMANDS:{
			if(!response || response){
				ShowPlayerDialog
				(
					playerid, D_MENU_ORG_COMMANDS, DIALOG_STYLE_LIST,
					!"{"cblue"}Команды организаций",
					!"\
					{"cblue"}1. {ffffff}Администрация посёлка\n\
					{"cblue"}2. {ffffff}Патрульно-постовая служба (ППС)\n\
					{"cblue"}3. {ffffff}Скорая медицинская помощь (СМП)\n\
					{"cblue"}4. {ffffff}Воздушно-десантные войска (ВДВ)\n\
					{"cblue"}5. {ffffff}Средства массовой информации (СМИ)\n\
					{"cblue"}6. {ffffff}Организованные преступные группировки (ОПГ)\n\
					{"cblue"}7. {ffffff}Общие команды организаций\n\
					{"cblue"}8. {ffffff}Команды лидеров/заместителей организаций\
					",
					!"Далее", !"Отмена"
				);				
			}
		}
		case 12:
		{
			if(response)
			{
				if(!strval(inputtext)) return SPD(playerid, 12, DIALOG_STYLE_INPUT, "{"cblue"}Пожертвование денег", "{"cwhite"}Введите сумму, которую вы готовы пожертвоать на развитие области!", "Далее", "Назад");
				if(PlayerInfo[playerid][pCash] < 0 || strval(inputtext) > PlayerInfo[playerid][pCash]) return SCM(playerid, red, "У вас не достаточно денег.");
				PlayerInfo[playerid][pCash] -= strval(inputtext);
			}
		}
		case 13:
		{
			if(!response) return ShowMenu(playerid);
			else
			{
				switch(listitem)
				{
					case 0: return SPD(playerid, D_CHECK_PASS, DIALOG_STYLE_INPUT, "{"cblue"}Смена пароля", "{FFFFFF}Введите существующий пароль:", "Далее", "Назад");
				}
			}
		}
		case D_CHECK_PASS:
		{
			if(!response) return ShowMenu(playerid);
			else
			{
				if(!strlen(inputtext))
				{
					SCM(playerid, red, "Вы ничего не ввели!");
					return SPD(playerid, D_CHECK_PASS, DIALOG_STYLE_INPUT, "{"cblue"}Смена пароля", "{FFFFFF}Введите существующий пароль:", "Далее", "Назад");
				}

				new mysqlstr[144];
				mysql_format(connects, mysqlstr, sizeof(mysqlstr),"SELECT * FROM `accounts` WHERE `pName` = '%s' AND `pKey` = MD5('%s')", PlayerInfo[playerid][pName], inputtext);
				mysql_function_query(connects, mysqlstr, true, "CheckPassChangePass","ds", playerid, inputtext);
				return 1;
			}
		}
		case D_CHANGE_PASS:
		{
			if(!response) return ShowMenu(playerid);
			else
			{
				if(strlen(inputtext) < 6 || strlen(inputtext) > 20)
				{
					SPD(playerid, D_CHANGE_PASS, DIALOG_STYLE_INPUT, "{"cblue"}Смена пароля", "{"cwhite"}Введите новый пароль для вашего аккаунта.\nОн будет запрашиваться при каждом входе на сервер.\n\n{"cblue"}Примечения:\n\
					- Пароль должен быть сложным (Пример: s9cQ17)\n- Пароль должен состоять из цифр и букв\n- Максимальная длина пароля от 6 до 20 символов.", "Далее", "Отмена");
					return 1;
				}
				for(new i = strlen(inputtext); i != 0; --i)
				switch(inputtext[i])
				{
					case 'а'..'я', 'А'..'Я', '=', ' ':
					{
						SPD(playerid, D_CHANGE_PASS, DIALOG_STYLE_INPUT, "{"cblue"}Смена пароль", "{"cwhite"}Введите новый пароль для вашего аккаунта.\nОн будет запрашиваться при каждом входе на сервер.\n\n{"cblue"}Примечения:\n\
						- Пароль должен быть сложным (Пример: s9cQ17)\n- Пароль должен состоять из цифр и букв\n- Максимальная длина пароля от 6 до 20 символов.", "Далее", "Отмена");
						return SCM(playerid, red, "Не верный синтаксис!");
					}
				}
				strdel(PlayerInfo[playerid][pKey], 0, 24);
				strmid(PlayerInfo[playerid][pKey], inputtext, 0, strlen(inputtext), 64);

				new string[256];
				format(string, sizeof(string), "UPDATE `accounts` SET `pKey` = MD5('%s') WHERE `pName` = '%s' LIMIT 1", PlayerInfo[playerid][pKey], PlayerInfo[playerid][pName]);
				mysql_tquery(connects, string, "", "");

				format(string, sizeof(string), "{"cblue"}Ваш новый пароль: {"cyellow"}%s{"cblue"}. Постарайтесь его не забыть! Если вы его забудете, то вы не сможете зайти на аккаунт!", PlayerInfo[playerid][pKey]);
				SCM(playerid, blue, string);
			}
		}
		case D_MENU_ASK_REP:
		{
		    if(!response) return ShowMenu(playerid);
		    else
		    {
		        switch(listitem)
		        {
		            case 0: SPD(playerid, D_MENU_ASK, DIALOG_STYLE_INPUT, !"{"cblue"}Задать вопрос", !"{FFFFFF}На большинство ваших вопросов есть ответы, напшите - {"cblue"}/help {"cwhite"}и почитайте, если вы не нашли ответ на ваш вопрос, то вы можете его тут задать!\n\nПожалуйста, напишите всё кратко и четко и администрация вам ответит в ближайшее время!", !"Далее", !"Назад");
					case 1: SPD(playerid, D_MENU_REP, DIALOG_STYLE_INPUT, !"{"cblue"}Подать жалобу", !"{FFFFFF}Если вы заметили нарушителя, то здесь вы можете на него подать жалобу!\n\nПожалуйста напишите ID нарушителя и кртако опишите его нарушение.\nВ случае, если нарушитель {"cred"}оффлайн {FFFFFF}, но у вас есть доказательства, что он нарушил правила, \nто вы можете подать жалобу на нашем форуме.", !"Далее", !"Назад");
				}
		    }
		}
		case D_MENU_ASK:
		{
			if(!response) return SPD(playerid, D_MENU_ASK_REP, DIALOG_STYLE_LIST, !"{"cblue"}Вопросы / жалобы на игроков", !"{"cblue"}1. {FFFFFF}Задать вопрос\n{"cblue"}2. {FFFFFF}Подать жалобу на игрока", !"Далее", !"Назад");
			else
			{
			    new len = strlen(inputtext);
			    if(1 <= len <= 80)
			    {
			    	new string[256];
				    format(string, sizeof(string), "[A] Вопрос от %s[%d]: {"cyellow"}%s", PlayerInfo[playerid][pName], playerid, inputtext);
				    SCM(playerid, green, string);
				    return SCMA(green, string);
			    }
			    else
			    {
			        SCM(playerid, red, !"Слишком длинное сообщение");
			        return SPD(playerid, D_MENU_ASK, DIALOG_STYLE_INPUT, !"{"cblue"}Задать вопрос", !"{FFFFFF}На большинство ваших вопросов есть ответы, напшите - {"cblue"}/help {"cwhite"}и почитайте, если вы не нашли ответ на ваш вопрос, то вы можете его тут задать!\n\nПожалуйста, напишите всё кратко и четко и администрация вам ответит в ближайшее время!", !"Далее", !"Назад");
			    }
			}
		}
		case D_MENU_REP:
		{
			if(!response) return SPD(playerid, D_MENU_ASK_REP, DIALOG_STYLE_LIST, !"{"cblue"}Вопросы / жалобы на игроков", !"{"cblue"}1. {FFFFFF}Задать вопрос\n{"cblue"}2. {FFFFFF}Подать жалобу на игрока", !"Далее", !"Назад");
			else
			{
			    new len = strlen(inputtext);
			    if(1 <= len <= 80)
			    {
			    	new string[256];
				    format(string, sizeof(string), "[A] Жалоба от %s[%d]: {"cyellow"}%s", PlayerInfo[playerid][pName], playerid, inputtext);
				    SCM(playerid, green, string);
				    return SCMA(green, string);
			    }
			    else
			    {
			        SCM(playerid, red, !"Слишком длинное сообщение");
					return SPD(playerid, D_MENU_REP, DIALOG_STYLE_INPUT, !"{"cblue"}Подать жалобу", !"{FFFFFF}Если вы заметили нарушителя, то здесь вы можете на него подать жалобу!\n\nПожалуйста напишите ID нарушителя и кртако опишите его нарушение.\nВ случае, если нарушитель {"cred"}оффлайн {FFFFFF}, но у вас есть доказательства, что он нарушил правила, \nто вы можете подать жалобу на нашем форуме.", !"Далее", !"Назад");
			    }
			}
		}
	}
	#if	defined	menu__OnDialogResponse
		return menu__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse menu__OnDialogResponse
#if	defined	menu__OnDialogResponse
	forward menu__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif