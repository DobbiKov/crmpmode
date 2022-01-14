ORPC:RAKNET_ResetPlayerWeapon(playerid, BitStream:bs)
{
	if(playerid == -1) return true;
	for(new i = 0; i != 13; i ++)
	{
		WEAPON_FIX_WARNING[i][playerid] = 0;
		SERVER_INFO[playerid][SAMP_WEAPON][i] = 0;
	}
	SERVER_INFO[playerid][SAMP_FIX_WEAPON] = GetTickCount() + 1000;
	return true;
}