public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024)
    {

		if(IsPlayerInRangeOfPoint(playerid, 2.0, 2583.4426,-2417.6323,900.2700))
		{
			if(!IsAPolice(playerid) && PlayerInfo[playerid][bAdmin] < 3) return 1;

			if(dps_door_status == true)
			{
				SCM(playerid, red, !"Вы закрыли дверь");
				MoveObject(dps_door,   2583.39, -2417.25, 900.48, 4.00, 0.00, 0.00, 180.00);
				dps_door_status = false;
			}
			else if(dps_door_status == false)
			{
				SCM(playerid, green, !"Вы открыли дверь");
				MoveObject(dps_door,  2582.86, -2418.05, 900.48, 4.00, 0.00, 0.00, 110.90);
				dps_door_status = true;
			}

		}
    }
	#if	defined	dps__OnPlayerKeyStateChange
		return dps__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange dps__OnPlayerKeyStateChange
#if	defined	dps__OnPlayerKeyStateChange
	forward dps__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif