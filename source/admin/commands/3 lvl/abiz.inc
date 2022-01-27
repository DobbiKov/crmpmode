CMD:abiz(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);
    extract params -> new id; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /abiz [ID бизнесса]");

    new b = -1;
    foreach(new i : Allbusiness) 
    {
        if(BusinessInfo[i][bID] == id)
        {
            b = i; 
            break;
        }
    }
    if(b == -1)
    {
        return SCM(playerid, red, !"Бизнесса под таким ID нет!");
    }
	new fmt_dialog[1024], text[128];
	
	format
	(
		fmt_dialog, sizeof fmt_dialog,
		"{ffffff}Название:\t\t\t{0099FF}%s(%d)\n\
		{ffffff}Владелец:\t\t\t{0099FF}%s\n\
		{ffffff}Стоимость:\t\t\t{0099FF}%d рублей\n\
		{ffffff}Баланс:\t\t\t{0099FF}%d рублей\n\
        {ffffff}Прибыль:\t\t\t{0099FF}%d рублей\n\
		{ffffff}Оплачен на:\t\t\t{0099FF}%d из 30 дней\n\
		{ffffff}Цена за вход:\t\t\t{0099FF}%d рублей",
		business_params[BusinessInfo[b][bType]][bname], BusinessInfo[b][bID],
		BusinessInfo[b][bOwner],
		BusinessInfo[b][bPrice],
		BusinessInfo[b][bCash],
		BusinessInfo[b][bProfit],
		BusinessInfo[b][bDays],
		BusinessInfo[b][bEnterPrice]
	);
	
	if(BusinessInfo[b][bType] == b_type_REPAIR)
	{
		format(text, sizeof text, "\n{ffffff}Стоимость починки:\t\t%d рублей", BusinessInfo[b][bRepairPrice]);
		strcat(fmt_dialog, text);
	}
	if(BusinessInfo[b][bType] == b_type_FILL)
	{
		format(text, sizeof text, "\n{ffffff}Стоимость бензина за 1 литр:\t\t%d рублей", BusinessInfo[b][bFillPrice]);
		strcat(fmt_dialog, text);
	}
	
    SetPVarInt(playerid, "abiz_biz_id", b);

	SPD
	(
		playerid, D_CMD_ABIZ, DIALOG_STYLE_MSGBOX,
		"{"cblue"}Информация о бизнесе",
		fmt_dialog,
		"Финка", "Закрыть"
	);

    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_CMD_ABIZ:{
            if(!response) return DeletePVar(playerid, "abiz_biz_id");
            else{
                new b = GetPVarInt(playerid, "abiz_biz_id");
                new query[256];
                format(query, sizeof(query), "SELECT * FROM `business_profit` WHERE `bid` = '%d' ORDER BY date DESC LIMIT 30", BusinessInfo[b][bID]);
                mysql_tquery(connects, query, "ShowBusinessProfitABiz", "i", playerid);
                DeletePVar(playerid, "abiz_biz_id");
            }
        }
    }
	#if	defined	abiz__OnDialogResponse
		return abiz__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse abiz__OnDialogResponse
#if	defined	abiz__OnDialogResponse
	forward abiz__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

publics ShowBusinessProfitABiz(playerid)
{
    static rows, fields;
    cache_get_data(rows, fields);
    
    new string[10000];
    
    if(rows)
    {
        new fmt_str[144];
        new money, _date[64];
        
        string = "{FFFFFF}Дата\t\t\tПрибыль\n\n{FFFFFF}";
        
        for(new idx; idx < rows; idx++)
        {
            cache_get_field_content(idx, "date", _date, connects, 64);
            money = cache_get_field_content_int(idx, "money");
            
            format(fmt_str, sizeof fmt_str, "{"cblue"}%d. {FFFFFF}%s\t\t%d рублей\n", idx+1, _date, money);
            strcat(string, fmt_str);
        }
    }
    else string = "{FFFFFF}Финансовая статистика данного бизнеса еще не сформирована";
    
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "{"cblue"}Доход бизнеса за 30 дней", string, "Закрыть", "");
}
