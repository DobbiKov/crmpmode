CMD:alock(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 2) return ShowCommandNotFound(playerid);

    if(!strlen(params))
    {
        foreach(new i : Vehicle)
        {
            new Float:car_x, Float: car_y, Float:car_z;
            GetVehiclePos(i, car_x, car_y, car_z);
            if(IsPlayerInRangeOfPoint(playerid, 5.0, car_x, car_y, car_z))
            {
                vehicle[i][veh_lock] = (vehicle[i][veh_lock] == true) ? (false) : (true);

                new engine, lights, alarm, doors, bonnet, boot, objective;
                GetVehicleParamsEx(i, engine, lights, alarm, doors, bonnet, boot, objective);	
                SetVehicleParamsEx(i, engine, lights, alarm, vehicle[i][veh_lock], bonnet, boot, objective);

                if(vehicle[i][veh_lock] == true)
                {
                    GameTextForPlayer(playerid, "~r~LOCK", 2000, 3);
                    PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
                }
                else
                {
                    GameTextForPlayer(playerid, "~g~LOCK", 2000, 3);
                    PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
                }
                return 1;
            }
        }
        return 1;
    }

    extract params -> new veh_id; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /alock [ID авто]");
    if(!IsValidVehicle(veh_id))
        return SCM(playerid, red, !"Не валидный транспорт!");
    vehicle[veh_id][veh_lock] = (vehicle[veh_id][veh_lock] == true) ? (false) : (true);

    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(veh_id, engine, lights, alarm, doors, bonnet, boot, objective);	
    SetVehicleParamsEx(veh_id, engine, lights, alarm, vehicle[veh_id][veh_lock], bonnet, boot, objective);

    if(vehicle[veh_id][veh_lock] == true)
    {
        GameTextForPlayer(playerid, "~r~LOCK", 2000, 3);
        PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
    }
    else
    {
        GameTextForPlayer(playerid, "~g~LOCK", 2000, 3);
        PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
    }
    return 1;
}