#define CUSTOM_MAX_WEAPON_TYPES 50
new stock AccessedWeapons[MAX_PLAYERS][CUSTOM_MAX_WEAPON_TYPES];

stock GivePlayerWeaponAC(playerid, weaponid, ammo)
{
    new slot = GetWeaponSlotEx(weaponid);
	if(slot == -1) return 0;
	AccessedWeapons[playerid][weaponid] = 1;
	PlayerInfo[playerid][pGun][slot] = weaponid;
    if(ammo > 0) PlayerInfo[playerid][pAmmo][slot] += ammo;
    else PlayerInfo[playerid][pAmmo][slot] -= ammo;

	#if defined SLIPPYGUARD
	
	PG_DATA[playerid][pGunEst] = 1; 
	if(IsOdinPatrGun(weaponid)) ammo = 1, PG_DATA[playerid][pGuns][weaponid] = ammo;
	else PG_DATA[playerid][pGuns][weaponid] = PG_DATA[playerid][pGuns][weaponid] + ammo;
	
	#endif

	GivePlayerWeapon(playerid, weaponid, ammo);
	return 1;
}

stock SetPlayerWeaponAC(playerid, weaponid, ammo)
{
    new slot = GetWeaponSlotEx(weaponid);
	if(slot == -1) return 0;
	AccessedWeapons[playerid][weaponid] = 1;
	PlayerInfo[playerid][pGun][slot] = weaponid;
    if(ammo > 0) PlayerInfo[playerid][pAmmo][slot] += ammo;
    else PlayerInfo[playerid][pAmmo][slot] -= ammo;
	GivePlayerWeapon(playerid, weaponid, ammo);
	return 1;
}

stock RemovePlayerWeapon(playerid, weaponid)
{
	if(!IsPlayerConnected(playerid) || weaponid < 0 || weaponid > 50) return;
	for(new i = 0; i < 12; i++) GetPlayerWeaponData(playerid, i, PlayerInfo[playerid][pGun][i], PlayerInfo[playerid][pAmmo][i]);
	ResetPlayerWeaponsAC(playerid);
	for(new i = 0; i < 12; i++)
	{
		if(PlayerInfo[playerid][pGun][i] == weaponid || PlayerInfo[playerid][pAmmo][i] == 0) continue;
		GivePlayerWeaponAC(playerid, PlayerInfo[playerid][pGun][i], PlayerInfo[playerid][pAmmo][i]);
	}
	GivePlayerWeaponAC(playerid, 0, 1);
}
stock ResetPlayerWeaponsAC(playerid)
{
	for(new i = 0; i < 12; i++)
    {
        PlayerInfo[playerid][pGun][i] = 0;
		PlayerInfo[playerid][pAmmo][i] = 0;
	}

	#if defined SLIPPYGUARD
	
	PG_DATA[playerid][pGunEst] = 1; 
	for(new i =0 ; i < 47; i++) PG_DATA[playerid][pGuns][i] = 0;
	
	#endif

	ResetPlayerWeapons(playerid);
	return 1;
}
stock GetWeaponSlotEx(weaponid)
{
	switch(weaponid)
	{
		case 0,1:			return 0;
		case 2..9:			return 1;
		case 22..24:		return 2;
		case 25..27:		return 3;
		case 28,29,32:		return 4;
		case 30,31:			return 5;
		case 33,34:			return 6;
		case 35..38:		return 7;
		case 16..18,39:		return 8;
		case 41..43:		return 9;
		case 10..15:		return 10;
		case 44..46:		return 11;
		case 40:			return 12;
	}
	return -1;
}

publics PlayerSecondTimer(playerid)
{
    // new player_weapon = GetPlayerWeapon(playerid);
	// new str[60];
	// format(str, sizeof(str), "DEBUG: %d %s", player_weapon, (AccessedWeapons[playerid][player_weapon] > 0) ? ("true") : ("false"));
	// SCM(playerid, white, str);
	// if(player_weapon > 0 && AccessedWeapons[playerid][player_weapon] < 1)
	// {
	// 	ResetPlayerWeaponsAC(playerid);
	// 	// ResultMessageCheat(playerid, 1);
	// }

    #if defined ac_weap__PlayerSecondTimer
        return ac_weap__PlayerSecondTimer(playerid);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_PlayerSecondTimer
	#undef	PlayerSecondTimer
#else
	#define	_ALS_PlayerSecondTimer
#endif

#define	PlayerSecondTimer ac_weap__PlayerSecondTimer
#if	defined	ac_weap__PlayerSecondTimer
	forward ac_weap__PlayerSecondTimer(playerid); 
#endif

// public OnPlayerUpdate(playerid)
// {
// 	// new weapon[13][2];
// 	// for(new i = 0; i < 13; i++)
// 	// {
// 	// 	GetPlayerWeaponData(playerid, i, weapon[i][0], weapon[i][1]);
// 	// 	if(PlayerInfo[playerid][pGun][i] < 1) continue;
// 	// 	if(PlayerInfo[playerid][pGun][i] != weapon[i][0])
// 	// 	{ 
// 	// 	    if( GetPVarInt(playerid, "Cheater") != 1 ) return ResultMessageCheat(playerid, 1);
// 	// 	}
// 	// }
// 	#if defined ac_weap__OnPlayerUpdate
// 		return ac_weap__OnPlayerUpdate(playerid);
// 	#else
// 		return 1;
// 	#endif
// }
// #if defined _ALS_OnPlayerUpdate
// 	#undef OnPlayerUpdate
// #else
// 	#define _ALS_OnPlayerUpdate
// #endif

// #define OnPlayerUpdate ac_weap__OnPlayerUpdate
// #if defined ac_weap__OnPlayerUpdate
// 	forward ac_weap__OnPlayerUpdate(playerid);
// #endif