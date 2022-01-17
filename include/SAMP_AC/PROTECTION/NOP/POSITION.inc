	if(SERVER_INFO[playerid][SAMP_FUNC][0] == 0)
	{
		if(IsPlayerInRangeOfPoint(playerid, 75.0, SERVER_INFO[playerid][SAMP_POS_SX], SERVER_INFO[playerid][SAMP_POS_SY], SERVER_INFO[playerid][SAMP_POS_SZ]))
		{
			SERVER_INFO[playerid][SAMP_FUNC][0] = 1;
			SERVER_INFO[playerid][SAMP_WARN][0] = 1;
		}
		else if(SAMP_AC_TICK > (SERVER_INFO[playerid][SAMP_LAGG][0] + 8000) + SAMP_AC_PING)
		{
			SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "SetPlayerPos", 1, 4);
		}
	}
