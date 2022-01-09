CMD:car(playerid)
{
    if(PlayerInfo[playerid][pCarID] == -1)
        return SCM(playerid, red, !"У вас нет личного транспорта!");
    new query[256];
    format(query, sizeof(query), "SELECT * FROM `ownable_cars` WHERE `owner_id` = '%d'", PlayerInfo[playerid][pID]);
    mysql_tquery(connects, query, "ShowCarListMySQL", "i", playerid);
    return 1;
}

publics ShowCarListMySQL(playerid)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
    {
        new string[2056] = "";
        for(new i = 0; i < rows; i++)
        {
            static id, model_id, number[32];

            id = cache_get_field_content_int(i, "id");
            model_id = cache_get_field_content_int(i, "model_id");
            cache_get_field_content(i, "number", number, connects, 64);

            if(!strcmp(number, "None", false)) number = "Нет номеров";

            new temp_string[144] = "";
            new use_string[144] = "";
            if(PlayerInfo[playerid][pCarID] == id)
                format(use_string, sizeof(use_string), "{"cgreen"}(Используется)");
            format(temp_string, sizeof(temp_string), "{ffffff}№%d. %s (%d) [ %s ] %s\n", i+1, GetCarName(model_id), model_id, number, use_string);
            strcat(string, temp_string);
            dialog_listitem_values[playerid][i] = id;
        }
        return ShowPlayerDialog(playerid, D_CAR_COMMAND, DIALOG_STYLE_LIST, !"{"cblue"}Ваш транспорт", string, !"Далее", !"Отмена");
    }
    else
        return SCM(playerid, red, !"Ваш транспорт не был найден!");
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
		case D_CAR_COMMAND:
		{
			if(response)
            {
                new query[256];
                format(query, sizeof(query), 
                "SELECT * FROM `ownable_cars` WHERE `owner_id` = '%d' AND `id` = '%d'", 
                PlayerInfo[playerid][pID], 
                dialog_listitem_values[playerid][listitem]);

                mysql_tquery(connects, query, "ShowCarFromCarListMySQL", "ii", playerid, listitem);
            }
		}
        case D_CAR_COMMAND_CHOOSE_CAR:
        {
            if(response)
            {
                DestroyOwnableCar(playerid);
                PlayerInfo[playerid][pCarID] = dialog_listitem[playerid];
                if(PlayerInfo[playerid][pHomeID] != -1)
                {
                    LoadMyCarFunc(playerid);
                }
                new query[256];
                format(query, sizeof(query), 
                "SELECT * FROM `ownable_cars` WHERE `owner_id` = '%d' AND `id` = '%d'", 
                PlayerInfo[playerid][pID], 
                PlayerInfo[playerid][pCarID]);
                mysql_tquery(connects, query, "SendMessFromCarListMySQL", "i", playerid);
            }
        }
    }
	#if	defined	car_comm__OnDialogResponse
		return car_comm__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse car_comm__OnDialogResponse
#if	defined	car_comm__OnDialogResponse
	forward car_comm__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

publics SendMessFromCarListMySQL(playerid)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
    {
        static model_id, number[32];
        model_id = cache_get_field_content_int(0, "model_id");
        cache_get_field_content(0, "number", number, connects, 64);

        if(!strcmp(number, "None", false)) number = "-----";

        new string[144];
        format(string, sizeof(string), "Вы сменили свой транспорт на: {"cyellow"}%s (%d) [%s]", GetCarName(model_id), model_id, number);
        return SCM(playerid, blue, string);
    }
    else
        return SCM(playerid, red, !"Ваш транспорт не был найден!");
}
publics ShowCarFromCarListMySQL(playerid, listitem)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
    {
        new string[1024] = "";

        static id, model_id, number[32], color[10], Float:mileage, Float:fuel, cost_car_;

        id = cache_get_field_content_int(0, "id");
        model_id = cache_get_field_content_int(0, "model_id");
        mileage = cache_get_field_content_float(0, "mileage");
        fuel = cache_get_field_content_float(0, "fuel");
        cost_car_ = cache_get_field_content_int(0, "cost_car");

        cache_get_field_content(0, "number", number, connects, 64);
        cache_get_field_content(0, "color", color, connects, 64);

        if(!strcmp(number, "None", false)) number = "-----";

        new use_string[144] = "";
        if(PlayerInfo[playerid][pCarID] == id)
            format(use_string, sizeof(use_string), "{"cgreen"}(Используется)");

        new temp_string[144];

        format(temp_string, sizeof(temp_string), "{"cred"}Автомбиль №%d \n\n", listitem+1);
        strcat(string, temp_string);
        format(temp_string, sizeof(temp_string), "{ffffff}Модель{"cblue"}: \t\t\t %s{"cyellow"}(%d)\n", GetCarName(model_id), model_id);
        strcat(string, temp_string);
        format(temp_string, sizeof(temp_string), "{ffffff}Номер{"cblue"}: \t\t\t %s\n", number);
        strcat(string, temp_string);
        format(temp_string, sizeof(temp_string), "{ffffff}Стоимость{"cblue"}: \t\t\t %d руб.\n", cost_car_);
        strcat(string, temp_string);
        format(temp_string, sizeof(temp_string), "{ffffff}Цвет{"cblue"}: \t\t\t\t %s\n", color);
        strcat(string, temp_string);
        format(temp_string, sizeof(temp_string), "{ffffff}Пробег{"cblue"}: \t\t\t %d КМ\n", floatround(mileage, floatround_round));
        strcat(string, temp_string);
        format(temp_string, sizeof(temp_string), "{ffffff}Топливо{"cblue"}: \t\t\t %d л.", floatround(fuel, floatround_round));
        strcat(string, temp_string);


        if(PlayerInfo[playerid][pCarID] == id)
            return ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, !"{"cblue"}Ваш транспорт", string, !"Закрыть", !"");

        dialog_listitem[playerid] = id;
        return ShowPlayerDialog(playerid, D_CAR_COMMAND_CHOOSE_CAR, DIALOG_STYLE_MSGBOX, !"{"cblue"}Ваш транспорт", string, !"Далее", !"Отмена");
    }
    else
        return SCM(playerid, red, !"Ваш транспорт не был найден!");
}