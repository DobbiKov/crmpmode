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
						format(string, sizeof(string), "Введите количество доната, которое вы хотите перевести в рубли. В данный момент у вас: %d руб.", PlayerInfo[playerid][pDonate]);
						SPD(playerid, D_DONATE_BUY_MONEY, DIALOG_STYLE_INPUT, !"{"cblue"}Донат", string, !"Далее", "Назад");
					}
					case 1:{
						//смена имени
					}
					case 2:{
						//снять все предупреждения
					}
					case 3:{
						//снять розыск
					}
					case 4:{
						//военный билет
					}
					case 5:{
						//+1 exp
					}
					case 6:{
						//+1 lvl
					}
					case 7:{
						//оружие навыки
					}
					case 8:{
						//випка
					}
				}
			}
		}
		case D_DONATE_BUY_MONEY:{
			if(!response) return ShowDonateListDialog(playerid);
			else{
				if(PlayerInfo[playerid][pDonate] < strval(inputtext))
					return SCM(playerid, red, "У вас нет такого количество доната.");

				GiveMoney(playerid, strval(inputtext)*500, "Через донат");
				PlayerInfo[playerid][pDonate] -= strval(inputtext);

				new string[144];
				format(string, sizeof(string), "Вы приобрели %d виртуальных рублей за %d донат очков.", strval(inputtext)*500, strval(inputtext));
				SCM(playerid, blue, string);
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