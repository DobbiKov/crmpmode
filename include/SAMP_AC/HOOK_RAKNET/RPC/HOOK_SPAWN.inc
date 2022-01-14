ORPC:RAKNET_SetSpawnPlayer(playerid, BitStream:bs)
{
	if(playerid == -1) return true;
	SERVER_INFO[playerid][SAMP_FIX_BRAKE] = GetTickCount() + 4000;
	SERVER_INFO[playerid][SAMP_FIX_SPAWN] = 0;
	return true;
}

