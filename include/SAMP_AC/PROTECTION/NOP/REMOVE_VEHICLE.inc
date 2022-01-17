	if(SERVER_INFO[playerid][SAMP_FUNC][1] == 0 && SERVER_INFO[playerid][SAMP_ID_VEHICLE] > 0)
	{
		if(SAMP_AC_TICK > SERVER_INFO[playerid][SAMP_LAGG][1] + SAMP_AC_PING)
		{
			SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "RemovePlayerFromVehicle", 51, 0);
		}
	}