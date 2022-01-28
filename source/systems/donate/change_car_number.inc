stock ShowDonateCarNumberDialog(playerid)
{
    new string[256];
    format(string, sizeof(string), "{ffffff}Вы желаете приобрести донат номер на транспорт за {"cblue"}500 {ffffff}кредитов?");
    ShowPlayerDialog
    (
        playerid, 
        D_DONATE_CAR_NUMBER, 
        DIALOG_STYLE_MSGBOX, 
        !"{"cblue"}Донат номера", 
        string, 
        !"Да", 
        !"Нет"
    );
    return 1;
}

stock ShowDonateCarNumberInputDialog(playerid, error = 0)
{
    new string[256] = "";
    switch(error)
    {
        case 1: format(string, sizeof(string), "{"cred"}Неверный формат!\n\n");
        case 2: format(string, sizeof(string), "{"cred"}Данный номерной знак уже кем-то занят!\n\n");
    }
    new temp_string[256];
    format(temp_string, sizeof(temp_string), "{ffffff}Введите желаемый номерной знак.\nПример: {"cblue"}N111NN{ffffff}");
    strcat(string, temp_string);
    ShowPlayerDialog
    (
        playerid, 
        D_DONATE_INPUT_CAR_NUMBER, 
        DIALOG_STYLE_INPUT, 
        !"{"cblue"}Донат номера", 
        string, 
        !"Далее", 
        !"Назад"
    );
    return 1;
}

//ShowDonateListDialog(playerid);

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case D_DONATE_CAR_NUMBER:
		{
			if(!response) return ShowDonateListDialog(playerid);
			else
			{
                if(!IsPlayerInAnyVehicle(playerid)
                || PlayerInfo[playerid][pCarID] == -1
                || GetPlayerVehicleID(playerid) != player_ownable_car[playerid])
                    return SCM(playerid, red, !"Вы должны находится в личном транспорте!");
                if(strcmp(ownable_car[ player_ownable_car[playerid] ][oc_number], "None"))
                    return SCM(playerid, red, "На вашем транспорте уже имеются номера."); 
				ShowDonateCarNumberInputDialog(playerid);
			}
		}
        case D_DONATE_INPUT_CAR_NUMBER:
        {
            if(!response) return ShowDonateListDialog(playerid);
            if(!IsPlayerInAnyVehicle(playerid)
            || PlayerInfo[playerid][pCarID] == -1
            || GetPlayerVehicleID(playerid) != player_ownable_car[playerid])
                return SCM(playerid, red, !"Вы должны находится в личном транспорте!");
            if(strcmp(ownable_car[ player_ownable_car[playerid] ][oc_number], "None"))
                return SCM(playerid, red, "На вашем транспорте уже имеются номера."); 
            if(strlen(inputtext) < 6 || strlen(inputtext) > 6
            || !DonateSymbolIsLiter(inputtext[0])
            || !DonateSymbolIsNumber(inputtext[1])
            || !DonateSymbolIsNumber(inputtext[2])
            || !DonateSymbolIsNumber(inputtext[3])
            || !DonateSymbolIsLiter(inputtext[4])
            || !DonateSymbolIsLiter(inputtext[5])
            )
            {
                return ShowDonateCarNumberInputDialog(playerid, 1);
            }
            
            // SCM(playerid, white, "debug: номера доступны");

            new query[144];
            format(query, sizeof(query), "SELECT * FROM `ownable_cars` WHERE `number` = '%s'", inputtext);
            mysql_tquery(connects, query, "DonateCarNumberCheckAbility", "isi", playerid, inputtext, 0);
        }
        case D_DONATE_CAR_NUMBER_SURE:
        {
            new number[24];
            GetPVarString(playerid, "donate_buy_car_number", number, 24);
            DeletePVar(playerid, "donate_buy_car_number");
            if(!response) return ShowDonateCarNumberInputDialog(playerid);
            
            new query[144];
            format(query, sizeof(query), "SELECT * FROM `ownable_cars` WHERE `number` = '%s'", number);
            mysql_tquery(connects, query, "DonateCarNumberCheckAbility", "isi", playerid, number, 1);
        }
	}
	#if	defined	donate_ccn__OnDialogResponse
		return donate_ccn__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse donate_ccn__OnDialogResponse
#if	defined	donate_ccn__OnDialogResponse
	forward donate_ccn__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

publics DonateCarNumberCheckAbility(playerid, newNumber[], times)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
        return ShowDonateCarNumberInputDialog(playerid, 2);
    
    if(times == 0)
    {
        new model = GetVehicleModel(player_ownable_car[playerid]);
        new string[144];
        format(string, sizeof(string), "{ffffff}Вы желаете приобрести номерной знак {"cblue"}[%s] {ffffff} на свой автомобиль {"cblue"}%s{ffffff}?", newNumber, GetCarName(model));
        ShowPlayerDialog(playerid, D_DONATE_CAR_NUMBER_SURE, DIALOG_STYLE_MSGBOX, !"Донат номер", string, !"Далее", !"Назад");
        return SetPVarString(playerid, "donate_buy_car_number", newNumber);
    }

    new number[24] = "";
    strcat(number, newNumber);

    if(PlayerInfo[playerid][pDonate] < 500) return SCM(playerid, red, !"У Вас недостаточно кредитов.");
    if(!IsPlayerInAnyVehicle(playerid)
        || PlayerInfo[playerid][pCarID] == -1
        || GetPlayerVehicleID(playerid) != player_ownable_car[playerid]
    )
        return SCM(playerid, red, !"Вы должны находится в личном транспорте!");

    if(strcmp(ownable_car[ player_ownable_car[playerid] ][oc_number], "None"))
        return SCM(playerid, red, "На вашем транспорте уже имеются номера."); 
    
    PlayerInfo[playerid][pDonate] -= 500;

    new model = GetVehicleModel(player_ownable_car[playerid]);

    ownable_car[player_ownable_car[playerid]][oc_number] = EOS;
    strcat(ownable_car[player_ownable_car[playerid]][oc_number], number);

    new string[144];
    format(string, sizeof(string), "Вы приобрели номерной знак {"cwhite"}[%s] {"cblue"}на свой транспорт {"cwhite"}%s", ownable_car[ player_ownable_car[playerid] ][oc_number], GetCarName(model));
    SCM(playerid, blue, string);

    format(string, sizeof(string), "UPDATE `ownable_cars` SET `number` = '%s' WHERE `id` = '%d'", ownable_car[player_ownable_car[playerid]][oc_number], ownable_car[player_ownable_car[playerid]][oc_id]);
    mysql_tquery(connects, string, "", "");

    return UpdateDynamic3DTextLabelText(ownable_car_label[player_ownable_car[playerid]], 0xFFFFFFFF, ownable_car[player_ownable_car[playerid]][oc_number]);    
}

stock DonateSymbolIsLiter(symbol)
{
    switch(symbol)
    {
        case 'A'..'Z': return true;
    }
    return false;
}

stock DonateSymbolIsNumber(symbol)
{
    switch(symbol)
    {
        case '0'..'9': return true;
    }
    return false;
}