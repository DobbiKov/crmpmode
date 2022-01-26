CMD:delacc(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);

	extract params -> new string:to_player[32]; else return SCM(playerid, blue, "[Подсказка] {ffffff}Введите: /delacc [Ник игрока]");

    new query[256];
    format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    mysql_tquery(connects, query, "delacc_check_account", "is", playerid, to_player);
    return 1;
}

publics delacc_check_account(playerid, to_player[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(!rows)  
        return SCM(playerid, red, !"Такого аккаунта не существует!");
    
    new adminlvl, acc_id;
    adminlvl = cache_get_field_content_int(0, "bAdmin");
    acc_id = cache_get_field_content_int(0, "pID");

    if(adminlvl >= PlayerInfo[playerid][bAdmin])
        return SCM(playerid, red, !"Вы не можете удалить данный аккаунт!");

    dialog_listitem[playerid] = acc_id;
    SetPVarString(playerid, "delacc_pname", to_player);

    new string[144];
    format(string, sizeof(string), "{ffffff}Вы желаете удалить аккаунт игрока {"cblue"}%s {ffffff}(№%d)?", to_player, acc_id);

    ShowPlayerDialog(playerid, D_SURE_DELACC, DIALOG_STYLE_MSGBOX, !"{"cblue"}Удаление аккаунта", string, !"Удалить", !"Отмена");

    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case D_SURE_DELACC:{
            new to_player[64];
            GetPVarString(playerid, "delacc_pname", to_player, 64);
            DeletePVar(playerid, "delacc_pname");
            if(!response) return 1;

            new acc_id = dialog_listitem[playerid];

            new string[256];
            format(string, sizeof(string), "DELETE FROM `accounts` WHERE `pID` = '%d'", acc_id);
            mysql_tquery(connects, string, "", ""); 

            format(string, sizeof(string), "[A] %s %s[%d] удалил аккаунт игрока %s (№%d)", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ],
            PlayerInfo[playerid][pName],
            playerid,
            to_player,
            acc_id);
            return SCMA(red, string);
        }
	}
	#if	defined	delacc__OnDialogResponse
		return delacc__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse delacc__OnDialogResponse
#if	defined	delacc__OnDialogResponse
	forward delacc__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif