ORPC:RAKNET_SetPutVehicle(playerid, BitStream:CELL_BYTE)
{
	if(playerid == -1) return true;
	new RAKNET_VEHICLE_ID;
	BS_ReadUint16(CELL_BYTE, RAKNET_VEHICLE_ID);	
	//BS_ReadUint16(CELL_BYTE, SERVER_INFO[playerid][SAMP_ID_SEAT]);
	
	SERVER_INFO[playerid][SAMP_FIX_BRAKE] = GetTickCount() + 2500;
	SERVER_INFO[playerid][SERVER_VEHICLE] = SERVER_INFO[playerid][SERVER_ENTER_VEHICLE] = SERVER_INFO[playerid][SERVER_SET_VEHICLE] = RAKNET_VEHICLE_ID;
	SERVER_INFO[playerid][SERVER_FIX_GTC] = GetTickCount() + 3250;
	return true;
}