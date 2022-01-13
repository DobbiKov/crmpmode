//----------------------------[ Unigva AntiCheat ]---------------------------
#if defined SLIPPYGUARD

stock PG_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
	PG_DATA[playerid][pCarAC] = vehicleid;
	PutPlayerInVehicle(playerid,vehicleid,seatid);
}
#define PutPlayerInVehicle PG_PutPlayerInVehicle

stock PG_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
	if(PlayerInfo[playerid][pLogin] == true)
	{
		PG_DATA[playerid][P_SET_POS_X] = x,
		PG_DATA[playerid][P_SET_POS_Y] = y,
		PG_DATA[playerid][P_SET_POS_Z] = z,
		PG_DATA[playerid][P_SET_POS_TICK] = GetTickCount();
	}
	SetPlayerPos(playerid, x,y,z);
}
#define SetPlayerPos PG_SetPlayerPos

stock PG_RemovePlayerFromVehicle(playerid)
{
	SetTimerEx("PG_nopRPFV",3000,0,"i", playerid);
	return RemovePlayerFromVehicle(playerid);
}
#define RemovePlayerFromVehicle PG_RemovePlayerFromVehicle

#endif

/* */
// publics Float:GetDistanceBetweenPoints(Float:_X, Float:_Y, Float:_Z, Float:_PointX, Float:_PointY, Float:_PointZ)
// {
// 	new Float:_Distance;
//     _Distance = floatabs(floatsub(_X, _PointX)) + floatabs(floatsub(_Y, _PointY)) + floatabs(floatsub(_Z, _PointZ));
// 	return _Distance;
// }
/* */

#if defined SLIPPYGUARD

public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat)
{

	if(PG_DATA[playerid][pCarTolkTick] <= GetTickCount())
	{
		PG_DATA[playerid][pCarTolkKol] = 0;
		PG_DATA[playerid][pCarTolkTick] = GetTickCount()+3000;
	}

	new Float:XYZ[3];
	GetVehiclePos(vehicleid, XYZ[0], XYZ[1], XYZ[2]);

	if(PG_DATA[playerid][pCarTolkVeh] == INVALID_VEHICLE_ID)
	{
		for(new i; i < 3; i++) PG_DATA[playerid][pCarTolkKord][i] = XYZ[i];
		PG_DATA[playerid][pCarTolkVeh] = vehicleid;
	}

	if(PG_DATA[playerid][pCarTolkVeh] == vehicleid)
	{
		printf("%s | %d | %d", PlayerInfo[playerid][pName], PG_DATA[playerid][pCarTolkVeh], vehicleid);
		new Float:destation = floatsqroot(floatpower(XYZ[0] - PG_DATA[playerid][pCarTolkKord][0],2) + floatpower(XYZ[1] - PG_DATA[playerid][pCarTolkKord][1],2) + floatpower(XYZ[2] - PG_DATA[playerid][pCarTolkKord][2],2));

		if(destation >= 10.0) PG_DATA[playerid][pCarTolkKol]++;

		if(PG_DATA[playerid][pCarTolkKol] > 3) return PG_KICK(playerid,"UNSYNC - 1",5561);
		PG_WARNING(playerid,"UNSYNC - 1",5561);


		GetVehiclePos(vehicleid,
		PG_DATA[playerid][pCarTolkKord][0],
		PG_DATA[playerid][pCarTolkKord][1],
		PG_DATA[playerid][pCarTolkKord][2]);
	}
	else
	{
		for(new i; i < 3; i++) PG_DATA[playerid][pCarTolkKord][i] = XYZ[i];
		PG_DATA[playerid][pCarTolkVeh] = vehicleid;
	}

    #if defined slac__OnUnoccupiedVehicleUpdate
		return slac__OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnUnoccupiedVehicleUpdate
	#undef OnUnoccupiedVehicleUpdate
#else
	#define _ALS_OnUnoccupiedVehicleUpdate
#endif

#define OnUnoccupiedVehicleUpdate slac__OnUnoccupiedVehicleUpdate
#if defined slac__OnUnoccupiedVehicleUpdate
	forward slac__OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat);
#endif

new Float:Tp_Hack_Massiv_1 = 100.0, Float:Tp_Hack_Massiv_2 = 100.0;

// cmd:settphack(playerid,params[])
// {
// 	if(PI[playerid][pAdmin] < 11) return 1;
// 	new Float:floatavskaya;
// 	if(sscanf(params, "df",params[0],floatavskaya)) return 1;
// 	if(params[0] == 1) Tp_Hack_Massiv_1 = floatavskaya;
// 	else if(params[0] == 2) Tp_Hack_Massiv_2 = floatavskaya;
// 	return 1;
// }

#endif

forward @_200mc_PlayerTimer(playerid);
public @_200mc_PlayerTimer(playerid)
{
	if(!IsPlayerConnected(playerid)) return 1;

    #if defined SLIPPYGUARD

	if(!IsPlayerInAnyVehicle(playerid))
	{
		new Float:x,Float:y,Float:z;
		GetPlayerPos(playerid, x,y,z);

		if(PG_DATA[playerid][P_SET_POS_TICK] != 0)
		{
			// if(GetDistanceBetweenPoints(x, y, z, PG_DATA[playerid][P_SET_POS_X], PG_DATA[playerid][P_SET_POS_Y], PG_DATA[playerid][P_SET_POS_Z]) <= Tp_Hack_Massiv_1)
			// {
			// 	PG_DATA[playerid][P_SET_POS_X] = x,
			// 	PG_DATA[playerid][P_SET_POS_Y] = y,
			// 	PG_DATA[playerid][P_SET_POS_Z] = z,
			// 	PG_DATA[playerid][P_SET_POS_TICK] = 0;

			// 	PG_DATA[playerid][P_POS_X] = x,
			// 	PG_DATA[playerid][P_POS_Y] = y,
			// 	PG_DATA[playerid][P_POS_Z] = z;
			// }
			// else if(GetTickCount() >= (PG_DATA[playerid][P_SET_POS_TICK] + 2000))
			// {
			// 	if(!PlayerInfo[playerid][pAFK]) PG_WARNING(playerid,"SetPPos - NOP",6774);//nop
			// }
		}
		else
		{
			// if(GetDistanceBetweenPoints(x, y, z, PG_DATA[playerid][P_POS_X], PG_DATA[playerid][P_POS_Y], PG_DATA[playerid][P_POS_Z]) >= Tp_Hack_Massiv_2)
			// {
			// 	PG_WARNING(playerid,"TP Hack",6775); // teleport
			// }
			PG_DATA[playerid][P_POS_X] = x,
			PG_DATA[playerid][P_POS_Y] = y,
			PG_DATA[playerid][P_POS_Z] = z;
		}
	}
	else if(IsPlayerInAnyVehicle(playerid))
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			new speedvehicle = SpeedVehicle(playerid);

			if(speedvehicle >= 1200)
			{
				PG_KICK(playerid,"warpmode",7821); //warpmode
			}

			if(speedvehicle >= 450)
			{
				if(PG_DATA[playerid][pCarEntTime] > GetTickCount())
				{
					PG_KICK(playerid,"CarGun",7921); //cargun
				}
			}

			if(GetPlayerState(playerid) == 2 && GetPlayerVehicleID(playerid) != PlayerInfo[playerid][pCarID])
			{
				if(speedvehicle > (PG_DATA[playerid][pCarSpeed]+50)) PG_WARNING(playerid,"SPEEDHACK",8880);
				PG_DATA[playerid][pCarSpeed] = speedvehicle;
			}
		}
	}
	#endif
    return 1;
}

forward @_1000mc_PlayerTimer(playerid);
public @_1000mc_PlayerTimer(playerid)
{
	if(!IsPlayerConnected(playerid)) return 1;
	#if defined SLIPPYGUARD

	if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK) PG_KICK(playerid,"Использование JetPack",8912); //usejetpack
	new Float:PizdosPos[3];
	GetPlayerVelocity(playerid,PizdosPos[0],PizdosPos[1],PizdosPos[2]);
	if(PizdosPos[0] > 2.0 || PizdosPos[1] > 2.0)
	{
		PG_DATA[playerid][Pizdorvanka]++;
		if(PG_DATA[playerid][Pizdorvanka] >= 3) PG_KICK(playerid,"Пиздарванка",1925); //pizdarvanka
	}

	#endif

    if(PlayerInfo[playerid][pLogin] != false)
    {
        #if defined SLIPPYGUARD
		if(PlayerInfo[playerid][bAdmin] < 4)
		{
			// for(new i; i < sizeof(prohibited_weapons); i++)
			// {
			// 	if(GetPlayerWeapon(playerid) == prohibited_weapons[i])
			// 	{
			// 		global_string = "";

			// 		format(global_string, 144, "(WARNING) {b1b5b8}Игрок %s[%d] подозревается в читерстве (#Запрещеное оружие [CODE: 1511])",GetName(playerid),playerid);
			// 		SendAdminMessage(COLOR_REDD, global_string);

			// 		RemovePlayerWeapon(playerid, GetPlayerWeapon(playerid));
			// 		SendClientMessage(playerid, COLOR_RED, "Это оружие входит в список запрещенных на сервере");
			// 		SendClientMessage(playerid, COLOR_RED, "Оружие было отнято у Вас");
			// 		SendClientMessage(playerid, COLOR_RED, "Если считаете, что произошла ошибка, обратитесь к администратору");
			// 	}
			// }
		}

		#endif
    }
    return 1;
}

forward @_5000mc_PlayerTimer(playerid);
public @_5000mc_PlayerTimer(playerid)
{
	if(!IsPlayerConnected(playerid)) return 1;
	#if defined SLIPPYGUARD
	if(PlayerInfo[playerid][pAFK] >= 3) goto koneccoda;
	new wid, amm;
	if(PG_DATA[playerid][pGunEst] > 0)
	{
		PG_DATA[playerid][pGunEst]--;
		goto koneccoda;
	}
	for(new s=1;s<13;s++)
	{
		GetPlayerWeaponData(playerid, s, wid, amm);
		if(amm == -1 && IsOdinPatrGun(wid)) amm = 1;
		if(PG_DATA[playerid][pGuns][wid] < amm)
		{
			if(wid != 46) PG_WARNING(playerid,"GunCheat",6666); //GunCheat
		}
		if(amm >= 0) PG_DATA[playerid][pGuns][wid] = amm;
	}
koneccoda:
	#endif
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	#if defined SLIPPYGUARD
	
	PG_DATA[playerid][PG_ObhodAvt] = true;
	
	#endif


    #if defined slyac__OnPlayerRequestClass
		return slac__OnPlayerRequestClass(playerid, classid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerRequestClass
	#undef OnPlayerRequestClass
#else
	#define _ALS_OnPlayerRequestClass
#endif

#define OnPlayerRequestClass slac__OnPlayerRequestClass
#if defined slac__OnPlayerRequestClass
	forward slac__OnPlayerRequestClass(playerid, classid);
#endif

public OnPlayerCommandPerformed(playerid, cmdtext[], success)
{
	
	#if defined SLIPPYGUARD
	PG_DATA[playerid][FLOOD_CMD] = 0;
	PG_DATA[playerid][FLOOD_TICK] = GetTickCount() + 500;
	#endif


    #if defined slyac__OnPlayerCommandPerformed
		return slac__OnPlayerCommandPerformed(playerid, cmdtext, success);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerCommandPerformed
	#undef OnPlayerCommandPerformed
#else
	#define _ALS_OnPlayerCommandPerformed
#endif

#define OnPlayerCommandPerformed slac__OnPlayerCommandPerformed
#if defined slac__OnPlayerCommandPerformed
	forward slac__OnPlayerCommandPerformed(playerid, cmdtext[], success);
#endif

public OnPlayerConnect(playerid)
{
	// if(playerid == INVALID_PLAYER_ID || gamemodeloaded != 1) return NewKick(playerid);
	#if defined SLIPPYGUARD
	
	// SendClientMessage(playerid,-1,"Сервер находится под защитой Unigva AntiCheat "VERISON_AntiCheat"");
	//SendClientMessage(playerid,-1,"Unigva AntiCheat powered by Unigva Community (Feliks Macalister) in 2017-2018");
	
	// if(antibots == true)
	// {
	// 	GetPlayerIp(playerid, PG_DATA[playerid][PG_InterP], 16);
	// 	new num_ip = GetPlayerOnOneIp(PG_DATA[playerid][PG_InterP]);
	// 	if(num_ip > 5) return PlayerBanCheat(playerid,"BotATTACK");
	// }
	
	#endif


    #if defined slyac__OnPlayerConnect
		return slac__OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect slac__OnPlayerConnect
#if defined slac__OnPlayerConnect
	forward slac__OnPlayerConnect(playerid);
#endif

public OnPlayerSpawn(playerid)
{	
	#if defined SLIPPYGUARD
	
	PG_DATA[playerid][Kill_Time] = 0;
	
	#endif


    #if defined slyac__OnPlayerSpawn
		return slac__OnPlayerSpawn(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn slac__OnPlayerSpawn
#if defined slac__OnPlayerSpawn
	forward slac__OnPlayerSpawn(playerid);
#endif

public OnPlayerDeath(playerid, killerid, reason)
{
	
	#if defined SLIPPYGUARD

	if(killerid == playerid) return PG_KICK(playerid,"KIL = PLAYER",6412);//Gay Kill
	if(!IsPlayerConnected(killerid) && killerid != INVALID_PLAYER_ID) return PG_KICK(playerid,"Lol Kill",8936);//Lol Kill
	if(GetPlayerState(playerid) != 7) return PG_KICK(playerid,"FakeKillOne",6398);//Fake kill one
	if(reason == 38 && GetPlayerState(killerid) == PLAYER_STATE_PASSENGER) return PG_KICK(killerid,"Пассажир с миниганом",8292);//MinigunPassenger

	PG_DATA[playerid][Kill_Time]++;
	if(PG_DATA[playerid][Kill_Time] > 1) return PG_KICK(playerid,"Флуд смертями",8291);//DeathFlood

	#endif


    #if defined slyac__OnPlayerDeath
		return slac__OnPlayerDeath(playerid, killerid, reason);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerDeath
	#undef OnPlayerDeath
#else
	#define _ALS_OnPlayerDeath
#endif

#define OnPlayerDeath slac__OnPlayerDeath
#if defined slac__OnPlayerDeath
	forward slac__OnPlayerDeath(playerid, killerid, reason);
#endif

public OnPlayerText(playerid, text[])
{
	// if(!PlayerInfo[playerid][pLogin]) return 0;
	// if(emptyMessage(text)) return 0;
	
	#if defined SLIPPYGUARD
	if(PG_DATA[playerid][FLOOD_TICK] > GetTickCount())
	{
		PG_DATA[playerid][FLOOD_TXT]++;
		if(PG_DATA[playerid][FLOOD_TXT] > 5) return PG_KICK(playerid, "FLOOD TEXT", 1112),0;
		return SendClientMessage(playerid,-1,"Пожалуйста, не флудите!"),0;
	}
	PG_DATA[playerid][FLOOD_TXT] = 0;
	PG_DATA[playerid][FLOOD_TICK] = GetTickCount()+500;
	#endif


    #if defined slyac__OnPlayerText
		return slac__OnPlayerText(playerid, text);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerText
	#undef OnPlayerText
#else
	#define _ALS_OnPlayerText
#endif

#define OnPlayerText slac__OnPlayerText
#if defined slac__OnPlayerText
	forward slac__OnPlayerText(playerid, text[]);
#endif

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{

	#if defined SLIPPYGUARD
	PG_DATA[playerid][pCarEntTime] = GetTickCount()+3000;
	PG_DATA[playerid][pCarAC] = vehicleid;
	#endif


    #if defined slyac__OnPlayerEnterVehicle
		return slac__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerEnterVehicle
	#undef OnPlayerEnterVehicle
#else
	#define _ALS_OnPlayerEnterVehicle
#endif

#define OnPlayerEnterVehicle slac__OnPlayerEnterVehicle
#if defined slac__OnPlayerEnterVehicle
	forward slac__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif

public OnPlayerStateChange(playerid, newstate, oldstate)
{

	#if defined SLIPPYGUARD

	if(!PG_DATA[playerid][PG_ObhodAvt] && newstate == PLAYER_STATE_ONFOOT && oldstate == PLAYER_STATE_NONE) return PG_KICK(playerid,"Обход авторизации",7261); //notlogingame

	if(PlayerInfo[playerid][pLogin] == true)
	{
		new Float:x,Float:y,Float:z;
		GetPlayerPos(playerid, x,y,z);

		PG_DATA[playerid][P_POS_X] = x,
		PG_DATA[playerid][P_POS_Y] = y,
		PG_DATA[playerid][P_POS_Z] = z;
	}

	if(oldstate == PLAYER_STATE_PASSENGER && newstate == PLAYER_STATE_DRIVER) PG_KICK(playerid,"Пассажир водитель",9001); //управлять тачкой пассажиром

	if(newstate == PLAYER_STATE_DRIVER)
	{
		new model = GetPlayerVehicleSeat(playerid);
		if(model != 128)
		{
			if(!model)
			{
				model = GetVehicleModel(GetPlayerVehicleID(playerid));
				if(!(400 <= model <= 611) || Maximum_Passengers[model - 400 >>> 3] >>> ((model - 400 & 7) << 2) & 0xF == 15) PG_DATA[playerid][USE_CRASHER] = true,PG_KICK(playerid,"CRASH1",6561); //crash
			}
			else PG_DATA[playerid][USE_CRASHER] = true,PG_KICK(playerid,"CRASH2",6562); //crash
		}
	}
	else if(newstate == PLAYER_STATE_PASSENGER)
	{
		new model = GetVehicleModel(GetPlayerVehicleID(playerid));
		if(400 <= model <= 611)
		{
			model -= 400;
			new seat = GetPlayerVehicleSeat(playerid);
			if(seat != 128)
			{
				model = (Maximum_Passengers[model >>> 3] >>> ((model & 7) << 2)) & 0xF;
				if(!model || model == 15) PG_DATA[playerid][USE_CRASHER] = true,PG_KICK(playerid,"CRASH3",6563); //crash
			}
			else PG_DATA[playerid][USE_CRASHER] = true,PG_KICK(playerid,"CRASH4",6565); //crash
		}
	}
	if((newstate == 2 && oldstate == 3) || (newstate == 3 && oldstate == 2)  || (newstate == 2 && oldstate == 2))
	{
		SetPVarInt(playerid, "AC124", GetPVarInt(playerid,"AC124") + 1);
		if(GetPVarInt(playerid,"AC124") >= 3)
		{
			SetVehicleToRespawn(GetPlayerVehicleID(playerid));
			PG_KICK(playerid,"Забив машины",8593);//забиваетоднумашину
		}
	}

	#endif


    #if defined slyac__OnPlayerStateChange
		return slac__OnPlayerStateChange(playerid, newstate, oldstate);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerStateChange
	#undef OnPlayerStateChange
#else
	#define _ALS_OnPlayerStateChange
#endif

#define OnPlayerStateChange slac__OnPlayerStateChange
#if defined slac__OnPlayerStateChange
	forward slac__OnPlayerStateChange(playerid, newstate, oldstate);
#endif

public OnVehicleMod(playerid, vehicleid, componentid)
{	
	#if defined SLIPPYGUARD
	
	RemoveVehicleComponent(vehicleid,componentid);
	
	PG_DATA[playerid][USE_CRASHER] = true;
	PG_KICK(playerid,"CRASH5",7812); //Car crasher
	
	#endif
	
    #if defined slyac__OnVehicleMod
		return slac__OnVehicleMod(playerid, vehicleid, componentid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnVehicleMod
	#undef OnVehicleMod
#else
	#define _ALS_OnVehicleMod
#endif

#define OnVehicleMod slac__OnVehicleMod
#if defined slac__OnVehicleMod
	forward slac__OnVehicleMod(playerid, vehicleid, componentid);
#endif

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	#if defined SLIPPYGUARD
	if(GetPlayerInterior(playerid) == 0 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER) return PG_KICK(playerid,"PaintJob",8983); //antihui
	#endif

    
    #if defined slyac__OnVehiclePaintjob
		return slac__OnVehiclePaintjob(playerid, vehicleid, paintjobid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnVehiclePaintjob
	#undef OnVehiclePaintjob
#else
	#define _ALS_OnVehiclePaintjob
#endif

#define OnVehiclePaintjob slac__OnVehiclePaintjob
#if defined slac__OnVehiclePaintjob
	forward slac__OnVehiclePaintjob(playerid, vehicleid, paintjobid);
#endif


public OnPlayerUpdate(playerid)
{
	
	#if defined SLIPPYGUARD
	
	if(IsPlayerInAnyVehicle(playerid))
	{
		if(GetPlayerVehicleID(playerid) != PG_DATA[playerid][pCarAC])
		{
			PG_DATA[playerid][pCarAC] = -1;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid,x,y,z);
			PG_SetPlayerPos(playerid,x,y,z+1);
			PG_KICK(playerid,"Tp to car",777); //tpincar
		}
	}
	
	#endif
	
    #if defined slyac__OnPlayerUpdate
		return slac__OnPlayerUpdate(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate slac__OnPlayerUpdate
#if defined slac__OnPlayerUpdate
	forward slac__OnPlayerUpdate(playerid);
#endif
//***************************************************************************** *
public OnPlayerCommandReceived(playerid, cmdtext[])
{
	#if defined SLIPPYGUARD
	if(PG_DATA[playerid][FLOOD_TICK] > GetTickCount())
	{
		PG_DATA[playerid][FLOOD_CMD]++;
		if(PG_DATA[playerid][FLOOD_CMD] > 8) return PG_KICK(playerid, "FLOOD CMD",1111),0;
		return SendClientMessage(playerid,-1,"Пожалуйста, не флудите!"),0;
	}
	#endif
	
    #if defined slyac__OnPlayerCommandReceived
		return slac__OnPlayerCommandReceived(playerid, cmdtext);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerCommandReceived
	#undef OnPlayerCommandReceived
#else
	#define _ALS_OnPlayerCommandReceived
#endif

#define OnPlayerCommandReceived slac__OnPlayerCommandReceived
#if defined slac__OnPlayerCommandReceived
	forward slac__OnPlayerCommandReceived(playerid, cmdtext[]);
#endif

#if defined SLIPPYGUARD

new CheatDisableCode[10];
CMD:cheatdisable(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 6)
        return 1;
	// if(strcmp(GetName(playerid), "Empire_Bay")) return 1;
	if(sscanf(params, "dd", params[0],params[1])) return SendClientMessage(playerid, -1, "ВВЕДИ /cheatdisable [massiv] [code]");
	CheatDisableCode[params[0]] = params[1];
	return 1;
}

publics PG_nopRPFV(playerid)
{
	if(IsPlayerInAnyVehicle(playerid)) PG_WARNING(playerid, "USED CLOSED CAR (nop)", 7176);
    return 1;
}

publics PG_acOPENCAR(playerid,vehicleid)
{
	if(IsPlayerInVehicle(playerid,vehicleid)) PG_WARNING(playerid, "USED CLOSED CAR", 7177);
}

stock PG_WARNING(USERID, const SAC_NAME[], SAC_CODE)
{
	if(PlayerInfo[USERID][pLogin] == false) return 1;
	if(PlayerInfo[USERID][bAdmin] > 0 && !PG_DATA[USERID][USE_CRASHER]) return 1;
	for(new idcheat; idcheat < 10; idcheat++) if(CheatDisableCode[idcheat] == SAC_CODE) return 1;

	if(GetTickCount()-GetPVarInt(USERID, "CheaterWarning") < 3000) return 1;
	SetPVarInt(USERID, "CheaterWarning", GetTickCount());

	new string[144];

	format(string, 144, "(WARNING) {b1b5b8}%s[%d] подозревается в использовании чит-программ < Код: %i > (%s)",PlayerInfo[USERID][pName], USERID, SAC_CODE, SAC_NAME);
	SCMA(red, string);

	switch(SAC_CODE)
	{
	case /*8880..*/8880:
		{
			PG_DATA[USERID][warning_kick]++;
			if(PG_DATA[USERID][warning_kick] >= 5) PG_KICK(USERID, SAC_NAME, SAC_CODE);
		}
	case 6775:
		{
			PG_DATA[USERID][warning_kick]++;
			if(PG_DATA[USERID][warning_kick] >= 5) PG_KICK(USERID, SAC_NAME, SAC_CODE);
		}
	}
	return 1;
}

stock PG_KICK(USERID, const SAC_NAME[], SAC_CODE)
{
	for(new idcheat; idcheat < 10; idcheat++) if(CheatDisableCode[idcheat] == SAC_CODE) return 1;

	if(GetTickCount()-GetPVarInt(USERID, "-Cheater") < 3000) return 1;
	SetPVarInt(USERID, "-Cheater", GetTickCount());

	// new string[144];

	if(PlayerInfo[USERID][bAdmin] > 0 && !PG_DATA[USERID][USE_CRASHER]) return 1;

	//SendMes(USERID, -1, "Вы были кикнуты по подозрению в использовании чит-программ (CODE: #%d)",SAC_CODE);

	new h, m, s, day, month, year;
	gettime(h, m, s);
	getdate(year, month, day);

	new string[1024] = "";
	format(string, 512, "\
	{FFFFFF}Вы были кикнуты с сервера по подозрению в использовании {FA5353}запрещенного ПО\n\n\
	{FFFFFF}Имя: {EEBC35}%s | Пинг: %d\n\
	{FFFFFF}Код анти-чита: {EEBC35}< %i > (%s)\n\
	{FFFFFF}Дата и время: {EEBC35}%02d.%02d.%d - %02d:%02d:%02d\n\n\
	{FFFFFF}Если Вы считаете, что произошла ошибка, обратитесь на форум\n\n\
	{FFFFFF}Форум: {7FBD45}"forum_url"\n\
	{FFFFFF}Официальный сайт: {7FBD45}"site_url"", PlayerInfo[USERID][pName], GetPlayerPing(USERID), SAC_CODE, SAC_NAME, day, month, year, h, m, s);
	ShowPlayerDialog(USERID, 0000, DIALOG_STYLE_MSGBOX, "{E83E14}Unigva AntiCheat", string, "Закрыть", "");


	format(string, 144, "[AntiCheat] {b1b5b8}Игрок %s[%d] был кикнут по подозрению в читерстве < %i > (%s)",PlayerInfo[USERID][pName], USERID, SAC_CODE, SAC_NAME);
	SCMA(red, string);


	// format(string,144,"USERID: %s[%d] | SAC_NAME: %s | SAC_CODE: %d",PlayerInfo[USERID][pName],USERID,SAC_NAME, SAC_CODE);
	// AddLog(string, 40);

	#if defined very_needed_plugin_inc
	//DisablePacketReceiving(USERID);
	#endif
	NewKick(playerid);
	return true;
}

forward BannedPlayer(playerid);
public BannedPlayer(playerid)
{
	BanEx(playerid,reasonSTR);
	reasonSTR = "";
	return 1;
}

stock GetPlayerOnOneIp(test_ip[])
{
	new against_ip[32];
	new ip_count = 0;
	foreach(new x: Player)
	{
		if(!IsPlayerConnected(x)) continue;
		GetPlayerIp(x,against_ip,32);
		if(!strcmp(against_ip,test_ip)) ip_count++;
	}
	return ip_count;
}

stock PlayerBanCheat(playerid,reason[])
{
	SendClientMessage(playerid,-1,"Вы были заблокированы системой Unigva AntiCheat за атаку в сторону сервера");
	SendClientMessage(playerid,-1,"Если бан выдан ложно сообщите разработчику проекта немедленно(forum.unigva-rp.ru)");
	//SendClientMessage(playerid,-1,"Perfect AntiCheat powered by Perfect Community (Feliks Macalister) in 2017-2018");

	format(reasonSTR,sizeof(reasonSTR),"[Unigva AntiCheat] %s",reason);

	SetTimerEx("BannedPlayer",100,0,"i", playerid);
	return 1;
}

/*public OnIncomingRPC(playerid, rpcid, BitStream:bs)
{
	switch(rpcid)
	{
	case 9:
		{
			if(playerid == -1 || playerid == INVALID_PLAYER_ID) return 1;
			new vehicleid;
			BS_ReadUint16(bs, vehicleid);

			if (GetVehicleModel(vehicleid) < 400) return 0;
			return OnVehicleDeathRequest(vehicleid, playerid);
		}
	}
	return 1;
}*/

publics OnVehicleDeathRequest(vehicleid, killerid)
{
	new Float:health;

	GetVehicleHealth(vehicleid, health);

	if (health > 250.0 && !VehicleInWater(vehicleid))
	{
		return 0;
	}

	return 1;
}

stock VehicleInWater(vehicleid)
{
	new Float:Pos_Veh;
	GetVehiclePos(vehicleid, Pos_Veh,Pos_Veh,Pos_Veh);
	if(Pos_Veh > 3.0) return 0;
	return 1;
}

#endif
