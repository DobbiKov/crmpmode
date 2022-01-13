ORPC:RAKNET_ShowPlayerDialog(playerid, BitStream:CELL_BYTE)
{
	if(playerid == -1) return true;
	BS_ReadUint16(CELL_BYTE, SERVER_INFO[playerid][SAMP_DIALOG]);	

	SERVER_INFO[playerid][SAMP_FIX_DIALOG] = GetTickCount();
	
	return true;
}