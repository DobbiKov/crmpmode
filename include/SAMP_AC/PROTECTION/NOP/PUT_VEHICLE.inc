	if(SERVER_INFO[playerid][SAMP_FUNC][2] == 0)
	{
		if(GetPlayerVehicleSeat(playerid) == SERVER_INFO[playerid][SAMP_ID_SEAT])
		{
			SERVER_INFO[playerid][SAMP_FUNC][2] = 
			SERVER_INFO[playerid][SAMP_WARN][2] = 1;
		}
		else 
		{
			if(SAMP_AC_TICK > SERVER_INFO[playerid][SAMP_LAGG][2] + SAMP_AC_PING)
			{
				SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "PutPlayerInVehicle", 52, 0);
			}
		}
	}