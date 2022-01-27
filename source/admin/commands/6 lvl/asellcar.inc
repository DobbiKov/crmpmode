CMD:asellcar(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);
    extract params -> new id; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /asellcar [ID транспорта]");
    new query[512];
    format(query, sizeof(query), "SELECT * FROM `ownable_cars` WHERE `id` = '%d'", id);
    mysql_tquery(connects, query, "SletCarACar", "ii", playerid, id);
    return 1;
}
// 
publics SletCarACar(playerid, id)
{
    static rows[2];
    cache_get_data(rows[0], rows[1]);
    if(!rows[0])
        return SCM(playerid, red, !"Такого транспорта не существует!");

    new acc_id = cache_get_field_content_int(0, "owner_id");
    
    new query[512];
    format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pID` = '%d'", acc_id);
    mysql_tquery(connects, query, "SletCarACarCheckAccount", "iii", playerid, id, acc_id);
    return 1;
}

publics ChangeCarId_ASellCar(playerid, acc_id)
{
    static rows[2];
    cache_get_data(rows[0], rows[1]);

    new new_car_id = (rows[0] > 0) ? 1 : -1;
    new query[256];
    format(query, sizeof(query), "UPDATE `accounts` SET `pCarID` = '%d' WHERE `pID` = '%d'", new_car_id, acc_id);
    return mysql_tquery(connects, query);
}

publics SletCarACarCheckAccount(playerid, id, acc_id)
{
    static rows[2];
    cache_get_data(rows[0], rows[1]);
    new _acc_id;
    if(!rows[0])
    {
        _acc_id = -1;
        SCM(playerid, red, !"Аккаунт владельца транспорта не существует!");
    }
    new to_player[32] = "None";

    if(rows[0])
    {
        _acc_id = acc_id;
        new adminlvl = cache_get_field_content_int(0, "bAdmin");
        if(PlayerInfo[playerid][bAdmin] <= adminlvl)
            return SCM(playerid, red, !"Вы не можете продать транспорт администратора!");
        cache_get_field_content(0, "pName", to_player, connects, 144);
    }

    new string[144];
    format(string, sizeof(string), "{ffffff}Вы желаете продать транспорт игрока {"cblue"}%s {ffffff}под номером {"cblue"}%d{ffffff}?",
        to_player, id
        );
    dialog_listitem_values[playerid][0] = id;
    dialog_listitem_values[playerid][1] = _acc_id;
    SetPVarString(playerid, "asellcar_pname", to_player);

    return ShowPlayerDialog(playerid, D_SURE_ASELLCAR, DIALOG_STYLE_MSGBOX, !"{"cblue"}Продажа транспорта игрока", string, !"Продать", !"Отмена");
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_SURE_ASELLCAR:{
            new to_player[32];
            GetPVarString(playerid, "asellcar_pname", to_player, 32);
            DeletePVar(playerid, "asellcar_pname");
            if(!response) return 1;
            new _car_id = dialog_listitem_values[playerid][0];
            new acc_id = dialog_listitem_values[playerid][1];

            new query[256];
            format(query, sizeof(query), "DELETE FROM `ownable_cars` WHERE `id` = '%d'", _car_id);
            mysql_tquery(connects, query);

            new string[144];
            format(string, sizeof(string), "[A] %s[%d] продал транспорт игрока %s под номером %d", 
                PlayerInfo[playerid][pName],
                playerid,
                to_player,
                _car_id    
            );
            SCMA(grey, string);

            if(acc_id == -1) return 1;
            format(query, sizeof(query), "SELECT * FROM `ownable_cars` WHERE `owner_id` = '%d'", acc_id);
            return mysql_tquery(connects, query, "ChangeCarId_ASellCar", "ii", playerid, acc_id);
        }
    }
	#if	defined	asellcar__OnDialogResponse
		return asellcar__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse asellcar__OnDialogResponse
#if	defined	asellcar__OnDialogResponse
	forward asellcar__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif