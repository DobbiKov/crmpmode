	if(SAMP_AC_REAL_SPEED(playerid) > 750 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 520)
	{
		SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Speed Slap", 8, 2); 
		return 0;
	}