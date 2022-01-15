	if(SAMP_AC_REAL_SPEED(playerid) > 500 && GetVehicleModel(RAKNET_DRIVER[RAKNET_VEHICLE]) != 520)
	{
		SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Warp Mode", 11, 2);
	}