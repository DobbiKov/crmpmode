public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    if(PlayerInfo[playerid][bAdmin] >= 2)
    {
        ShowPlayerDialog(playerid, D_ADMIN_TP_MAP, DIALOG_STYLE_MSGBOX, 
        !"{"cblue"}Телепортация на метку", 
        !"{ffffff}Была обнаружена новая метка на карте.\nТелепортировать вас?", 
        !"Да", 
        !"Нет");
        SetPVarFloat(playerid, "tp_map_x", fX);
        SetPVarFloat(playerid, "tp_map_y", fY);
        SetPVarFloat(playerid, "tp_map_z", fZ);
    }
    #if	defined	tp_map__OnPlayerClickMap
		return tp_map__OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerClickMap
	#undef	OnPlayerClickMap
#else
	#define	_ALS_OnPlayerClickMap
#endif

#define	OnPlayerClickMap tp_map__OnPlayerClickMap
#if	defined	tp_map__OnPlayerClickMap
	forward tp_map__OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_ADMIN_TP_MAP:
        {
            if(response)
            {
                new Float:mapX = GetPVarFloat(playerid, "tp_map_x");
                new Float:mapY = GetPVarFloat(playerid, "tp_map_y");
                new Float:mapZ = GetPVarFloat(playerid, "tp_map_z");


                if(IsPlayerInAnyVehicle(playerid))
				{
				    new vehid = GetPlayerVehicleID(playerid);
					new player_state = GetPlayerVehicleSeat(playerid);
				    SetVehiclePos(vehid, mapX, mapY, mapZ);
				    PutPlayerInVehicle(playerid, vehid, player_state);
				}
				else
				{
				    SetPlayerPos(playerid, mapX, mapY, mapZ);
					FreezePlayer(playerid, 3000);
				}

                SCM(playerid, white, !"Вы были перенесены на метку.");
                GameTextForPlayer(playerid, "~y~TELEPORTING", 500, 4);
            }
            DeletePVar(playerid, "tp_map_x");
            DeletePVar(playerid, "tp_map_y");
            DeletePVar(playerid, "tp_map_z");
        }
    }
	#if	defined	tp_map__OnDialogResponse
		return tp_map__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse tp_map__OnDialogResponse
#if	defined	tp_map__OnDialogResponse
	forward tp_map__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif