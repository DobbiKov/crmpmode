CMD:delveh(playerid,params[])
{
	if(PlayerInfo[playerid][bAdmin] < 4 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);
	if(!TotalAdminVehicles) return 1;
	new vehh = -1;
	if(!strlen(params)){
		if(GetPlayerState(playerid) != 2) return SCM(playerid,  red, "Вы не в автомобиле.");
		vehh = GetPlayerVehicleID(playerid);
	}
	else{
		extract params -> new id; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /delveh [ID автомобиля]");
		if(!IsValidVehicle(id))
			return SCM(playerid, red, "Авто под таким ID нет!");
		vehh = id;
	}
	new slot = -1;
	for(new i = 0; i < TotalAdminVehicles; i++)
	{
	    if(vehh == AVehicle[i])
	    {
	    	slot=i;
	    	break;
	    }

	}
	if(slot == -1) return SCM(playerid,  red, "Этот автомобиль не создавал администратор");
	stringer[0] = EOS;
	format(stringer, 128, "[A] %s удалил автомобиль [model: %d] [vehicleid: %d]", PlayerInfo[playerid][pName],GetVehicleModel(AVehicle[slot]),AVehicle[slot]);
	SCMA(grey, stringer);
	if(IsValidVehicle(AVehicle[slot]))
	{
		DestroyVehicle(AVehicle[slot]);
		vehicle[AVehicle[slot]][veh_limit] = 0.0;
	}
	AVehicle[slot] = 0;
    TotalAdminVehicles--;
	return 1;
}