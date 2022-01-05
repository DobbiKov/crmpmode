#define MAX_GREEN_ZONES 9

enum E_GREEN_ZONE{
    Float:gz_X,
    Float:gz_Y,
    Float:gz_Z,
    Float:gz_Radius,
    gz_vw,
};

new GreenZones[MAX_GREEN_ZONES][E_GREEN_ZONE] = {
    {-811.8497,1894.7438,702.0200, 40.0, 0}, //больница
    {1820.8619,2524.6980,15.6825, 10.0, 0}, //вокзал батырево
    {1826.5944,2095.3025,15.8500, 20.0, 0}, //ап
    {2572.0474,-2415.8203,22.3870, 10.0, 0}, // ппс
    {2294.0359,1656.2986,-39.4774, 30.0, 0}, // шахта
    {634.4813,2315.5144,1504.3500, 20.0, 0}, // баня
    {2340.2949,-263.9067,1.5171, 30.0, 0}, // грузчики
    {2828.0510,-1364.9569,1.2283, 20.0, 0}, // водолазы
    {2509.3279,-2126.9639,23.4558, 20.0, 0} // вокзал южка
};

new GreenZoneAreas[MAX_GREEN_ZONES];

new bool:IsPlayerInGreenZone[MAX_PLAYERS];

public OnPlayerEnterDynamicArea(playerid, areaid)
{
    if(areaid >= GreenZoneAreas[0] && areaid <= GreenZoneAreas[MAX_GREEN_ZONES - 1])
    {
        for(new i = 0; i < sizeof(GreenZoneTD); i++)
            TextDrawShowForPlayer(playerid, GreenZoneTD[i]);
        IsPlayerInGreenZone[playerid] = true;
    }
    #if	defined	gz__OnPlayerEnterDynamicArea
		return gz__OnPlayerEnterDynamicArea(playerid, areaid);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerEnterDynamicArea
	#undef	OnPlayerEnterDynamicArea
#else
	#define	_ALS_OnPlayerEnterDynamicArea
#endif

#define	OnPlayerEnterDynamicArea gz__OnPlayerEnterDynamicArea
#if	defined	gz__OnPlayerEnterDynamicArea
	forward gz__OnPlayerEnterDynamicArea(playerid, areaid);
#endif

public OnPlayerLeaveDynamicArea(playerid, areaid)
{
    if(areaid >= GreenZoneAreas[0] && areaid <= GreenZoneAreas[MAX_GREEN_ZONES - 1])
    {
        for(new i = 0; i < sizeof(GreenZoneTD); i++)
            TextDrawHideForPlayer(playerid, GreenZoneTD[i]);
        IsPlayerInGreenZone[playerid] = false;
    }
    #if	defined	gz__OnPlayerLeaveDynamicArea
		return gz__OnPlayerLeaveDynamicArea(playerid, areaid);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerLeaveDynamicArea
	#undef	OnPlayerLeaveDynamicArea
#else
	#define	_ALS_OnPlayerLeaveDynamicArea
#endif

#define	OnPlayerLeaveDynamicArea gz__OnPlayerLeaveDynamicArea
#if	defined	gz__OnPlayerLeaveDynamicArea
	forward gz__OnPlayerLeaveDynamicArea(playerid, areaid);
#endif

stock LoadGreenZones()
{
    for(new i = 0; i < MAX_GREEN_ZONES; i++)
    {
        GreenZoneAreas[i] = CreateDynamicSphere(GreenZones[i][gz_X], GreenZones[i][gz_Y], GreenZones[i][gz_Z], GreenZones[i][gz_Radius], GreenZones[i][gz_vw]);
    }
    return 1;
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid)
{
    if(IsPlayerInGreenZone[playerid] && !IsAPolice(playerid) && PlayerInfo[playerid][bAdmin] < 2)
    {
        FreezePlayer(playerid, 3000);
        ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, !"{"cblue"}DM | Зелёная зона", !"{ffffff}DM в зелёной зоне запрещен!", !"Закрыть", !"");
    }
    #if	defined	greenzone__OnPlayerGiveDamage
		return greenzone__OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerGiveDamage
	#undef	OnPlayerGiveDamage
#else
	#define	_ALS_OnPlayerGiveDamage
#endif

#define	OnPlayerGiveDamage greenzone__OnPlayerGiveDamage
#if	defined	greenzone__OnPlayerGiveDamage
	forward greenzone__OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid);
#endif