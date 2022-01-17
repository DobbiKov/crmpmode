	if(SERVER_INFO[playerid][SAMP_FUNC][0] != 0 && SERVER_INFO[playerid][SAMP_FUNC][1] != 0 && SERVER_INFO[playerid][SAMP_FUNC][2] != 0 && SERVER_INFO[playerid][SAMP_FIX_CARID] != 0)
	{
		if(SAMP_AC_TICK > SERVER_INFO[playerid][SAMP_FIX_BRAKE] + SAMP_AC_PING)
		{
			new SAMP_AC_DISTANCE = floatround(GetPlayerDistanceFromPoint(playerid, SERVER_INFO[playerid][SAMP_POS_X], SERVER_INFO[playerid][SAMP_POS_Y], SERVER_INFO[playerid][SAMP_POS_Z]));
			if(SAMP_AC_DISTANCE > 25 && SAMP_AC_REAL_SPEED(playerid) < 10 && SERVER_INFO[playerid][SAMP_POS_Z] > - 95.0)
			{
				SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Teleport Car", 12, 0);
			}
		}
	}