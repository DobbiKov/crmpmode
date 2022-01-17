	if(SAMP_AC_CHECK_MODEL_VEHICLE(RAKNET_DRIVER[RAKNET_VEHICLE]))
	{
		if(SAMP_AC_REAL_SPEED(playerid) != 0)
		{
			new AC_VALUE = GetVehicleModel(RAKNET_DRIVER[RAKNET_VEHICLE]);
			if(AC_VALUE != 481 && AC_VALUE != 509 && AC_VALUE != 510 && SERVER_INFO[playerid][SAMP_SPEED_Z] > -0.1)
			{
				if(SAMP_AC_REAL_SPEED(playerid) - SERVER_INFO[playerid][SAMP_FIX_SPEED] > 80)
				{
					SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Speed Hack", 7, 0); 
				}
			}
		}
		if(SERVER_INFO[playerid][SAMP_FIX_SPEED] != 0 && SAMP_AC_REAL_SPEED(playerid) != 0 && SERVER_INFO[playerid][SAMP_SPEED_Z] > -0.05)
		{
			if(SAMP_AC_REAL_SPEED(playerid) - SERVER_INFO[playerid][SAMP_FIX_SPEED] > 6)
			{
				SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Speed Hack Smooth", 24, 3);
			}
			else SAMP_AC_WARNING_PROGRESSIVE[playerid][24] = 0;
		}
		else SAMP_AC_WARNING_PROGRESSIVE[playerid][24] = 0;
	}
	SERVER_INFO[playerid][SAMP_FIX_SPEED] = SAMP_AC_REAL_SPEED(playerid);
