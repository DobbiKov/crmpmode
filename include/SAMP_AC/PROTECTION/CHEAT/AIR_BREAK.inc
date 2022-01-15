	if(SERVER_INFO[playerid][SAMP_FUNC][0] != 0 && SERVER_INFO[playerid][SAMP_FUNC][1] != 0 && SERVER_INFO[playerid][SAMP_FUNC][2] != 0)
	{
		new Float: SAMP_AC_DISTANCE = GetPlayerDistanceFromPoint(playerid, SERVER_INFO[playerid][SAMP_POS_X], SERVER_INFO[playerid][SAMP_POS_Y], SERVER_INFO[playerid][SAMP_POS_Z]);
		if(SAMP_AC_TICK > SERVER_INFO[playerid][SAMP_FIX_BRAKE] + SAMP_AC_PING)
		{
			if(SAMP_AC_DISTANCE >= 1.2 && SAMP_AC_DISTANCE <= 3.0 && SAMP_AC_REAL_SPEED(playerid) <= 12 && SERVER_INFO[playerid][SAMP_POS_Z] > - 95.0)
			{
				if(GetPlayerSurfingVehicleID(playerid) == 0xFFFF && GetPlayerSurfingObjectID(playerid) == 0xFFFF)
				{
					SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Air Break", 2, 5);
				}
			}
			else SAMP_AC_WARNING_PROGRESSIVE[playerid][2] = 0;
		}
		if(SAMP_AC_TICK > SERVER_INFO[playerid][SAMP_FIX_BRAKE] + SAMP_AC_PING)
		{
			if(SAMP_AC_DISTANCE >= 3.0 && SAMP_AC_DISTANCE <= 5.0 && SAMP_AC_REAL_SPEED(playerid) < 15 && SERVER_INFO[playerid][SAMP_POS_Z] > - 95.0)
			{
				if(GetPlayerSurfingVehicleID(playerid) == 0xFFFF && GetPlayerSurfingObjectID(playerid) == 0xFFFF)
				{
					SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Air Break", 20, 3);
				}
			}
			else SAMP_AC_WARNING_PROGRESSIVE[playerid][20] = 0;
		}
		if(SAMP_AC_TICK > SERVER_INFO[playerid][SAMP_FIX_BRAKE] + SAMP_AC_PING)
		{
			if(SAMP_AC_DISTANCE >= 5.0 && SAMP_AC_REAL_SPEED(playerid) <= 3 && SERVER_INFO[playerid][SAMP_POS_Z] > - 95.0)
			{
				if(GetPlayerSurfingVehicleID(playerid) == 0xFFFF && GetPlayerSurfingObjectID(playerid) == 0xFFFF)
				{
					SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Air Break", 21, 3);
				}
			}
			else SAMP_AC_WARNING_PROGRESSIVE[playerid][21] = 0;
		}
	}