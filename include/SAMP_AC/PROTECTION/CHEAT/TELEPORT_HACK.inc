	if(SERVER_INFO[playerid][SAMP_FUNC][0] != 0 && SERVER_INFO[playerid][SAMP_FUNC][1] != 0 && SERVER_INFO[playerid][SAMP_FUNC][2] != 0)
	{
		if(SAMP_AC_TICK > SERVER_INFO[playerid][SAMP_FIX_BRAKE] + SAMP_AC_PING)
		{
			new SAMP_AC_DISTANCE = floatround(GetPlayerDistanceFromPoint(playerid, SERVER_INFO[playerid][SAMP_POS_X], SERVER_INFO[playerid][SAMP_POS_Y], SERVER_INFO[playerid][SAMP_POS_Z]));
			if(SAMP_AC_DISTANCE > 25 && SERVER_INFO[playerid][SAMP_FIX_Z] > -95)
			{
				if(GetPlayerSurfingVehicleID(playerid) == 0xFFFF && GetPlayerSurfingObjectID(playerid) == 0xFFFF)
				{
					SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Teleport Hack", 6, 0);
				}
			}
		}
	}