ORPC:RAKNET_RemoveVehicle(playerid, BitStream:bs)
{
	if(playerid == -1) return true;
	SERVER_INFO[playerid][SERVER_VEHICLE] = SERVER_INFO[playerid][SERVER_ENTER_VEHICLE] = SERVER_INFO[playerid][SERVER_SET_VEHICLE] = 0;
	SERVER_INFO[playerid][SERVER_FIX_GTC] = GetTickCount() + 3250;
	return true;
}