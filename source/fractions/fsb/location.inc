CMD:location(playerid, params[])
{
    if(!IsAFSB(playerid) || (IsAFSB(playerid) && PlayerInfo[playerid][pRang] < 5))
        return YouCannotUseThisFunc(playerid);
    
    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /location [ID игрока]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if((PlayerInfo[playerid][bAdmin] < PlayerInfo[to_player][bAdmin]) && PlayerInfo[to_player][bAdmin] >= 6)
        return SCM(playerid, red, !"Невозможно распознать местоположение данного игрока!");
    
    new Float: posX, Float: posY, Float: posZ;
    GetPlayerPos(to_player, posX, posY, posZ);
    
    new fmt_msg[128];
    
    format(fmt_msg, sizeof(fmt_msg), "Гражданин %s отмечен на карте красной меткой", PlayerInfo[to_player][pName]);
    SCM(playerid, blue, fmt_msg);

    SetPlayerCheckpoint(playerid, posX, posY, posZ, 5.0);
    pCheckpoint[playerid] = CP_LOCATION;
    return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
    switch(pCheckpoint[playerid])
	{
		case CP_LOCATION:
		{
			DisablePlayerCheckpoint(playerid);
			SCM(playerid, blue, "Последний раз гражданина видели тут!");
		}
	}
    #if defined location__OnPlayerEnterCheckp
        return location__OnPlayerEnterCheckp(playerid);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_OnPlayerEnterCheckpoint
	#undef	OnPlayerEnterCheckpoint
#else
	#define	_ALS_OnPlayerEnterCheckpoint
#endif

#define	OnPlayerEnterCheckpoint location__OnPlayerEnterCheckp
#if	defined	location__OnPlayerEnterCheckp
	forward location__OnPlayerEnterCheckp(playerid);
#endif