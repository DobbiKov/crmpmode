ORPC:RAKNET_SetVehiclePos(playerid, BitStream:CELL_BYTE)
{
	if(playerid == -1) return true;
	SERVER_INFO[playerid][SAMP_FIX_BRAKE] = GetTickCount() + 5000;
	return true;
}

