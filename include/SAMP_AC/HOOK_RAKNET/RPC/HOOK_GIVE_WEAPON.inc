ORPC:RAKNET_GivePlayerWeapon(playerid, BitStream:bs)
{
	if(playerid == -1) return true;
	new 
	SAMP_AC_WEAPON;
	
	BS_ReadUint16(bs, SAMP_AC_WEAPON);
	if(SAMP_AC_WEAPON > 46 || SAMP_AC_WEAPON < 0) return true;
	
	if(SAMP_AC_WEAPON > 0 && SAMP_AC_WEAPON < 46)
	{
		new
		SAMP_AC_GIVE_WEAPON_SLOT = SAMP_AC_WEAPON_SLOT[SAMP_AC_WEAPON];

		SERVER_INFO[playerid][SAMP_WEAPON][SAMP_AC_GIVE_WEAPON_SLOT] = SAMP_AC_WEAPON;
		SERVER_INFO[playerid][SAMP_FIX_WEAPON] = GetTickCount() + 1000;
	}
	return true;
}