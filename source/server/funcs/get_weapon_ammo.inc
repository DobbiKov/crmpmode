stock GetPlayerWeaponAmmo(playerid, weaponid)
{
    new weapons[13][2];

    for(new i = 0; i != 12; i ++)
	{
		GetPlayerWeaponData(playerid, i, weapons[i][0], weapons[i][1]);
		if(weapons[i][0] == weaponid)
		{
            return weapons[i][1];
		}
	}
    return 0;
}