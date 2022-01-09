CMD:carpass(playerid, params[])
{
    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /carpass [ID игрока]");

    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        return SCM(playerid, red, !"Вы должны находиться за рулем автомобиля!");
    }

    new vehicleid = GetPlayerVehicleID(playerid);
    if (vehicleid == INVALID_VEHICLE_ID)
	{
		return 1;
	}
	new owner_id = owner_of_vehicle_by_id(vehicleid);
	if(owner_id == -1)
		return SCM(playerid, red, !"Этот транспорт никому не принадлежит!");

	new car_numbers[50];

	if(!strcmp(ownable_car[vehicleid][oc_number], "None"))
	{
		format(car_numbers, sizeof(car_numbers), "нет номеров");
	}
	else
	{
		format(car_numbers, sizeof(car_numbers), "%s", ownable_car[vehicleid][oc_number]);
	}

	new fmt_msg[128];

	format(fmt_msg, sizeof fmt_msg, "Вы показали птс %s [%d]", PlayerInfo[to_player][pName], to_player);
	SCM(playerid, -1, fmt_msg);
	
	format(fmt_msg, sizeof fmt_msg, "___________[ ДОКУМЕНТЫ НА АВТОМОБИЛЬ ]___________");
	SCM(to_player, -1, fmt_msg);
	SCM(to_player, -1, "");
	
	format(fmt_msg, sizeof fmt_msg, "Владелец: %s", PlayerInfo[owner_id][pName]);
	SCM(to_player, -1, fmt_msg);
	
	format(fmt_msg, sizeof fmt_msg, "Номерной знак: %s", car_numbers);
	SCM(to_player, -1, fmt_msg);
	
	format(fmt_msg, sizeof fmt_msg, "Модель авто: %s", GetCarName(GetVehicleModel(vehicleid)));
	SCM(to_player, -1, fmt_msg);
	
	SCM(to_player, -1, "_________________________________________________");
    return 1;
}