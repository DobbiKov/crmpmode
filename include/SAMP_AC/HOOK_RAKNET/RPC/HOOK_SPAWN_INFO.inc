ORPC:RAKNET_SetSpawnInfo(playerid, BitStream:CELL_BYTE)
{
	if(playerid == -1) return true;
	
	new
	AC_IGNORE;
	
	BS_ReadUint8(CELL_BYTE, AC_IGNORE);
	BS_ReadUint16(CELL_BYTE, AC_IGNORE);
	
	BS_ReadFloat(CELL_BYTE, SERVER_INFO[playerid][SAMP_POS_SX]);
	BS_ReadFloat(CELL_BYTE, SERVER_INFO[playerid][SAMP_POS_SY]);
	BS_ReadFloat(CELL_BYTE, SERVER_INFO[playerid][SAMP_POS_SZ]);
	
	SERVER_INFO[playerid][SAMP_FUNC][0] = SERVER_INFO[playerid][SAMP_WARN][0] = 0;
	SERVER_INFO[playerid][SAMP_LAGG][0] = GetTickCount();
	SERVER_INFO[playerid][SAMP_FIX_SPAWN] = 1;
	return true;
}


