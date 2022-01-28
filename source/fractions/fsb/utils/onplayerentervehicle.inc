public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
        if(job_car[TEAM_FSB_CAR][0] <= vehicleid <= job_car[TEAM_FSB_CAR][1])
        {
            if(!IsAFSB(playerid))
            {
                SCM(playerid, red, "У Вас нет ключей от этого транспорта!");
                RemovePlayerFromVehicle(playerid);    
                return ClearAnimations(playerid, true);
            }
        }
	}
	#if	defined	fsb__OnPlayerEnterVehicle
		return fsb__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerEnterVehicle
	#undef	OnPlayerEnterVehicle
#else
	#define	_ALS_OnPlayerEnterVehicle
#endif

#define	OnPlayerEnterVehicle fsb__OnPlayerEnterVehicle
#if	defined	fsb__OnPlayerEnterVehicle
	forward fsb__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif