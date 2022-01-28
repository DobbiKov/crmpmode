public OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER)
    {
        if(GetPVarInt(playerid, "smi_news") == 1)
        {
            DeletePVar(playerid, "smi_news");
            SCM(playerid, green, "Вы вышли из Эфира!");
        }
    }

    #if defined smi__OnPlayerStateChange
        return smi__OnPlayerStateChange(playerid, newstate, oldstate);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_OnPlayerStateChange
	#undef	OnPlayerStateChange
#else
	#define	_ALS_OnPlayerStateChange
#endif

#define	OnPlayerStateChange smi__OnPlayerStateChange
#if	defined	smi__OnPlayerStateChange
	forward smi__OnPlayerStateChange(playerid, newstate, oldstate); 
#endif

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 1789.6879,2045.6246,-18.0000))
        {
            if(PlayerInfo[playerid][pMember] != TEAM_SMI || PlayerInfo[playerid][pRang] < 10)
                return YouCannotUseThisFunc(playerid);
            ShowSmiBankDialog(playerid);
        }
    }
	#if	defined	smi__OnPlayerKeyStateChange
		return smi__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange smi__OnPlayerKeyStateChange
#if	defined	smi__OnPlayerKeyStateChange
	forward smi__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

stock ShowSmiBankDialog(playerid)
{
    ShowPlayerDialog(
                playerid, 
                D_SMI_BANK, 
                DIALOG_STYLE_LIST, 
                !"{"cblue"}Банк СМИ", 
                !"{"cblue"}1. {ffffff}Взять деньги\n\
                {"cblue"}2. {ffffff}Положить деньги\n", 
                !"Далее",
                !"Закрыть");
    return 1;
}
stock ShowSmiGetMoneyDialog(playerid)
{
    new string[256];
    format(
        string, 
        sizeof(string), 
        "{ffffff}В данный момент в банке СМИ лежит {"cblue"}%d {ffffff}руб.\n\
        {ffffff}Сколько денег Вы желаете снять?", smiMoney);
    ShowPlayerDialog(
                    playerid, 
                    D_SMI_GET_MONEY, 
                    DIALOG_STYLE_INPUT, 
                    !"{"cblue"}Банк СМИ", 
                    string, 
                    !"Снять", 
                    !"Назад");
    return 1;
}
stock ShowSmiPutMoneyDialog(playerid)
{
    new string[256];
    format(
        string, 
        sizeof(string), 
        "{ffffff}В данный момент в банке СМИ лежит {"cblue"}%d {ffffff}руб.\n\
        {ffffff}Сколько денег Вы желаете положить?", smiMoney);
    ShowPlayerDialog(
                    playerid, 
                    D_SMI_PUT_MONEY, 
                    DIALOG_STYLE_INPUT, 
                    !"{"cblue"}Банк СМИ", 
                    string, 
                    !"Положить", 
                    !"Назад");
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_SMI_BANK:
        {
            if(!response)
                return 1;
            if(listitem == 0)
            {
                return ShowSmiGetMoneyDialog(playerid);
            }
            return ShowSmiPutMoneyDialog(playerid);
        }
        case D_SMI_GET_MONEY:
        {
            if(!response)
                return ShowSmiBankDialog(playerid);
            if(!strlen(inputtext) || !IsNumeric(inputtext))
                return ShowSmiGetMoneyDialog(playerid);

            new _money = strval(inputtext);
            if(_money > smiMoney)
            {
                SCM(playerid, red, !"В банке СМИ нет столько денег!");
                return ShowSmiGetMoneyDialog(playerid);
            }
            GiveMoney(playerid, _money, "Снятие денег с банка СМИ");
            GiveSmiMoney(-_money);
            new string[144];
            format(string, sizeof(string), "[A] %s %s[%d] снял %d руб. с банка СМИ!", 
                GetPlayerRank(playerid),
                PlayerInfo[playerid][pName],
                playerid,
                _money);
            SCMA(grey, string);

            format(string, sizeof(string), "[R] %s %s[%d] снял %d руб. с банка СМИ!", 
                GetPlayerRank(playerid),
                PlayerInfo[playerid][pName],
                playerid,
                _money);
            SCMR(TEAM_SMI, green, string);

            format(string, sizeof(string), "Вы сняли %d руб. с банка СМИ!",
                _money);
            SCM(playerid, blue, string);
        }
        case D_SMI_PUT_MONEY:
        {
            if(!response)
                return ShowSmiBankDialog(playerid);
            if(!strlen(inputtext) || !IsNumeric(inputtext))
                return ShowSmiPutMoneyDialog(playerid);

            new _money = strval(inputtext);
            if(_money > PlayerInfo[playerid][pCash])
            {
                SCM(playerid, red, !"У Вас нет столько денег!");
                return ShowSmiPutMoneyDialog(playerid);
            }
            GiveMoney(playerid, -_money, "Положил деньги на банк СМИ");
            GiveSmiMoney(_money);
            new string[144];
            format(string, sizeof(string), "[A] %s %s[%d] положил %d руб. в банк СМИ!", 
                GetPlayerRank(playerid),
                PlayerInfo[playerid][pName],
                playerid,
                _money);
            SCMA(grey, string);

            format(string, sizeof(string), "[R] %s %s[%d] положил %d руб. в банк СМИ!", 
                GetPlayerRank(playerid),
                PlayerInfo[playerid][pName],
                playerid,
                _money);
            SCMR(TEAM_SMI, green, string);

            format(string, sizeof(string), "Вы положили %d руб. в банк СМИ!",
                _money);
            SCM(playerid, blue, string);
        }
    }
	#if	defined	smi__OnDialogResponse
		return smi__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse smi__OnDialogResponse
#if	defined	smi__OnDialogResponse
	forward smi__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
        if(job_car[TEAM_SMI_CAR][0] <= vehicleid <= job_car[TEAM_SMI_CAR][1])
        {
            if(PlayerInfo[playerid][pMember] != TEAM_SMI && !IsAFSB(playerid))
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "У Вас нет ключей от этого транспорта!");
            }
        }
	}
	#if	defined	smi__OnPlayerEnterVehicle
		return smi__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerEnterVehicle
	#undef	OnPlayerEnterVehicle
#else
	#define	_ALS_OnPlayerEnterVehicle
#endif

#define	OnPlayerEnterVehicle smi__OnPlayerEnterVehicle
#if	defined	smi__OnPlayerEnterVehicle
	forward smi__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif