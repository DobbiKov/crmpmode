CMD:fixveh(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);
	if(!strlen(params))
	{
		if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, red, "Вы должны находится в автомобиле!");

		stringer[0] = EOS;
		format(stringer, 128, "[A] %s [%d] отремонтировал автомобиль [vehicleid: %d]", PlayerInfo[playerid][pName],playerid, GetPlayerVehicleID(playerid));
		SCMA(grey, stringer);

		format(stringer, sizeof(stringer), "Вы отремонтировали автомобиль (vehicleid: %d)", GetPlayerVehicleID(playerid));
		SCM(playerid, white, stringer);
		RepairVehicle(GetPlayerVehicleID(playerid));
	}
	else
	{
		extract params -> new string:type[10], id; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /fixveh [ТИП car/player] [ID игрока/автомобиля]");
		if(!strlen(type))
			return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /fixveh [ТИП car/player] [ID игрока/автомобиля]");
		if(strcmp(type, "car") == 0){
			if(!IsValidVehicle(id))
				return SCM(playerid, red, "Авто под таким ID нет!");
			RepairVehicle(id);
			
			new string[144];
			format(string, sizeof(string), "[A] %s [%d] отремонтировал авто [vehicleid: %d]", PlayerInfo[playerid][pName], playerid, id);
			SCMA(grey, string);

			format(string, sizeof(string), "Вы отремонтировали автомобиль (vehicleid: %d)", id);
			SCMA(grey, string);
		}
		else if(strcmp(type, "player") == 0){
			if(!PlayerInfo[id][pLogin] || !IsPlayerConnected(id)) return PlayerOffLine(playerid);
			if(!IsPlayerInAnyVehicle(id))
				return SCM(playerid, red, "Игрок не в авто!");
			new vehid = GetPlayerVehicleID(id);
			RepairVehicle(vehid);
			new string[144];
			format(string, sizeof(string), "[A] %s [%d] отремонтировал авто игрока %s [%d] [vehicleid: %d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[id][pName], id, vehid);
			SCMA(grey, string);

			format(string, sizeof(string), "Вы отремонтировали автомобиль игрока %s [%d] (vehicleid: %d)", PlayerInfo[id][pName], id, vehid);
			SCMA(grey, string);
		}
		else{
			SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /fixveh [ТИП car/player] [ID игрока/автомобиля]");
		}
	}
	return 1;
}