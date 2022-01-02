#if !defined gc_SUSPECT_UPDATE_INTERVAL
	#define gc_SUSPECT_UPDATE_INTERVAL 1000
#endif

#if !defined gc_CUFF_DISTANCE
	#define gc_CUFF_DISTANCE 3.0
#endif

#if !defined gc_UNCUFF_DISTANCE
	#define gc_UNCUFF_DISTANCE 3.0
#endif

#if !defined gc_FOLLOW_DISTANCE
	#define gc_FOLLOW_DISTANCE 5.0
#endif

#if !defined gc_SUSPECT_RANGE_RUN
	#define gc_SUSPECT_RANGE_RUN 4.0
#endif

#if !defined gc_SUSPECT_RANGE_TP
	#define gc_SUSPECT_RANGE_TP 20.0
#endif

#if !defined gc_COLOR_INFO
	#define gc_COLOR_INFO "{ecf0f1}"
#endif

#if !defined gc_COLOR_NOTE
	#define gc_COLOR_NOTE "{e67e22}"
#endif

#if !defined gc_COLOR_ERROR
	#define gc_COLOR_ERROR "{c0392b}"
#endif

#if !defined gc_COLOR_SUCCESS
	#define gc_COLOR_SUCCESS "{2ecc71}"
#endif

stock gc_IsSuspectCuffed(suspectid)
{
	return (gc_suspect_status{suspectid}) ? (1) : (0);
}


stock gc_SetSuspectLook(suspectid, Float: look_x, Float: look_y)
{
	new 
		Float: _x,
		Float: _y,
		Float: _a;

	GetPlayerPos(suspectid, _x, _y, _a);
	_a = atan2(look_y - _y, look_x - _x) - 90.0;
	SetPlayerFacingAngle(suspectid, _a);
	return 1;
}


CMD:gotome(playerid, params[])
{
    if(!IsAPolice(playerid) && PlayerInfo[playerid][pMember] != TEAM_ADM && !IsAOpg(playerid)) 
        return YouCannotUseThisFunc(playerid);//Проверка на фракцию
    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /gotome [ID игрока]");
    if(to_player == playerid)
        return SCM(playerid, red, !"Вы указали свой ID!");
    if(!IsPlayerConnected(to_player)) 
        return PlayerOffLine(playerid);//Коннект ли игрок
    if(GetPVarInt(to_player, "tied") != 1 && GetPVarInt(to_player, "cuffed") != 1) 
        return SCM(playerid, red, "Игрок не в наручниках!");//Проверка на наручники.
    if(!IsPlayerInRangeOfPlayer(playerid, to_player, 7.0))
        return SCM(playerid, red, !"Игрок далеко от вас!");

    new string[128];
    format(string, sizeof(string), "Вы начали конвоировать %s", PlayerInfo[to_player][pName]);
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s начал вас конвоировать", PlayerInfo[playerid][pName]);
    SCM(to_player, blue, string);
    
    format(string, sizeof(string), "начал конвоировать %s", PlayerInfo[to_player][pName]);
    cmd::me(playerid, string);

    new suspectid = to_player;

	gc_suspect_status{suspectid} = gc_SUSPECT_STATUS_FOLLOWING;
	gc_cufferid[suspectid] = playerid;
	gc_cuffed_playerid[playerid] = suspectid;
	gc_UpdateSuspect(suspectid);
    return 1;
}

CMD:ungotome(playerid, params[])
{
    if(!IsAPolice(playerid) && PlayerInfo[playerid][pMember] != TEAM_ADM && !IsAOpg(playerid)) 
        return YouCannotUseThisFunc(playerid);//Проверка на фракцию
    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /ungotome [ID игрока]");
    if(to_player == playerid)
        return SCM(playerid, red, !"Вы указали свой ID!");
    if(!IsPlayerConnected(to_player)) 
        return PlayerOffLine(playerid);//Коннект ли игрок
    if(!IsPlayerInRangeOfPlayer(playerid, to_player, 7.0))
        return SCM(playerid, red, !"Игрок далеко от вас!");
    if(gc_cuffed_playerid[playerid] != to_player)
		return SCM(playerid, red, !"Вы не конвоируете данного игрока!");

    new string[128];
    format(string, sizeof(string), "Вы перестали конвоировать %s", PlayerInfo[to_player][pName]);
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s перестал вас конвоировать", PlayerInfo[playerid][pName]);
    SCM(to_player, blue, string);
    
    format(string, sizeof(string), "перестал конвоировать %s", PlayerInfo[to_player][pName]);
    cmd::me(playerid, string);

    new suspectid = to_player;

	if(gc_suspect_status{suspectid} == gc_SUSPECT_STATUS_FOLLOWING ||
		gc_suspect_status{suspectid} == gc_SUSPECT_STATUS_WAITING)
	{
		func_ungotome(playerid, suspectid);
	}
	return 1;
}

stock func_ungotome(playerid, suspectid)
{
    gc_suspect_status{suspectid} = gc_SUSPECT_STATUS_CUFFED;
    gc_suspect_status{suspectid} = gc_SUSPECT_STATUS_UNCUFFED;
    gc_cufferid[suspectid] = gc_cuffed_playerid[playerid] = INVALID_PLAYER_ID;

    ClearAnimations(suspectid, 1);
    TogglePlayerControllable(suspectid, 0);
    return 1;   
}

publics gc_UpdateSuspect(suspectid)
{
	if(gc_suspect_status{suspectid} == gc_SUSPECT_STATUS_FOLLOWING ||
		gc_suspect_status{suspectid} == gc_SUSPECT_STATUS_WAITING)
	{
		new
			Float: _x,
			Float: _y,
			Float: _z;

		GetPlayerPos(gc_cufferid[suspectid], _x, _y, _z);
		// distance =
		// 	gc_GetDistanceBetweenPlayers(gc_cufferid[suspectid], suspectid);

		if(!IsPlayerInRangeOfPlayer(gc_cufferid[suspectid], suspectid, gc_SUSPECT_RANGE_TP))
		{
			new Float: _a;
			GetPlayerFacingAngle(gc_cufferid[suspectid], _a);

			_x += ((gc_SUSPECT_RANGE_RUN - 1.0 > 0.0) ?
				(gc_SUSPECT_RANGE_RUN - 1.0) : (1.0)) * floatsin(-_a, degrees);
			_y += ((gc_SUSPECT_RANGE_RUN - 1.0 > 0.0) ?
				(gc_SUSPECT_RANGE_RUN - 1.0) : (1.0)) * floatcos(-_a, degrees);
			gc_suspect_status{suspectid} = gc_SUSPECT_STATUS_WAITING;

			SetPlayerPos(suspectid, _x, _y, _z);
			goto gc_reset_suspect_updating;
		}
		else if(!IsPlayerInRangeOfPlayer(gc_cufferid[suspectid], suspectid, gc_SUSPECT_RANGE_RUN))
		{
			if(gc_suspect_status{suspectid} == gc_SUSPECT_STATUS_WAITING)
			{
				TogglePlayerControllable(suspectid, 1);
				ApplyAnimation(suspectid, "ped", "run_civi",
					4.1, 1, 1, 1, 0, 0, 1);

				gc_suspect_status{suspectid} = gc_SUSPECT_STATUS_FOLLOWING;
			}
		}
		else if(IsPlayerInRangeOfPlayer(gc_cufferid[suspectid], suspectid, gc_SUSPECT_RANGE_RUN) &&
                IsPlayerInRangeOfPlayer(gc_cufferid[suspectid], suspectid, gc_SUSPECT_STATUS_FOLLOWING))
		{
			TogglePlayerControllable(suspectid, 0);
			gc_suspect_status{suspectid} = gc_SUSPECT_STATUS_WAITING;
		}

		gc_reset_suspect_updating:
		gc_SetSuspectLook(suspectid, _x, _y);
		SetTimerEx("gc_UpdateSuspect", gc_SUSPECT_UPDATE_INTERVAL, 0, 
			"i", suspectid);
	}
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	if(gc_cuffed_playerid[playerid] != INVALID_PLAYER_ID)
	{
		gc_suspect_status{gc_cuffed_playerid[playerid]} =
			gc_SUSPECT_STATUS_UNCUFFED;
		gc_cufferid[gc_cuffed_playerid[playerid]] =
			gc_cuffed_playerid[playerid] = INVALID_PLAYER_ID;
	}

	else if(gc_cufferid[playerid] != INVALID_PLAYER_ID)
	{
		gc_suspect_status{playerid} = gc_SUSPECT_STATUS_UNCUFFED;
		gc_cuffed_playerid[gc_cufferid[playerid]] = gc_cufferid[playerid] =
			INVALID_PLAYER_ID;
	}
	#if defined gc_OnPlayerDisconnect
		return gc_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect gc_OnPlayerDisconnect
#if defined gc_OnPlayerDisconnect
	forward gc_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerSpawn(playerid)
{
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    DeletePVar(playerid, "cuffed");
	if(gc_cuffed_playerid[playerid] != INVALID_PLAYER_ID)
	{
		gc_suspect_status{gc_cuffed_playerid[playerid]} =
			gc_SUSPECT_STATUS_UNCUFFED;
		gc_cufferid[gc_cuffed_playerid[playerid]] =
			gc_cuffed_playerid[playerid] = INVALID_PLAYER_ID;
	}
	else if(gc_cufferid[playerid] != INVALID_PLAYER_ID)
	{
		gc_suspect_status{playerid} = gc_SUSPECT_STATUS_UNCUFFED;
		gc_cuffed_playerid[gc_cufferid[playerid]] = gc_cufferid[playerid] =
			INVALID_PLAYER_ID;
	}
    #if defined gc__OnPlayerSpawn
        return gc__OnPlayerSpawn(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else 
    #define _ALS_OnPlayerSpawn
#endif


#define OnPlayerSpawn gc__OnPlayerSpawn
#if defined gc__OnPlayerSpawn
    forward gc__OnPlayerSpawn(playerid);
#endif

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	if(gc_cuffed_playerid[playerid] != INVALID_PLAYER_ID)
	{
		SetPlayerInterior(gc_cuffed_playerid[playerid], newinteriorid);

		new
			Float: x,
			Float: y,
			Float: z,
			Float: a;

		GetPlayerPos(playerid, x, y, z);
		GetPlayerFacingAngle(playerid, a);

		x += floatsin(-a, degrees);
		y += floatcos(-a, degrees);

		SetPlayerPos(gc_cuffed_playerid[playerid], x, y, z);
	}
	#if defined gc_OnPlayerInteriorChange
		return gc_OnPlayerInteriorChange(playerid, newinteriorid,
			oldinteriorid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerInteriorChange
	#undef OnPlayerInteriorChange
#else
	#define _ALS_OnPlayerInteriorChange
#endif

#define OnPlayerInteriorChange gc_OnPlayerInteriorChange
#if defined gc_OnPlayerInteriorChange
	forward gc_OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);
#endif


stock gc_SetPlayerVirtualWorld(playerid, worldid)
{
	if(gc_cuffed_playerid[playerid] != INVALID_PLAYER_ID)
	{
		SetPlayerVirtualWorld(gc_cuffed_playerid[playerid], worldid);
	}
	return SetPlayerVirtualWorld(playerid, worldid);
}
#if defined _ALS_SetPlayerVirtualWorld
	#undef SetPlayerVirtualWorld
#else
	#define _ALS_SetPlayerVirtualWorld
#endif

#define SetPlayerVirtualWorld gc_SetPlayerVirtualWorld