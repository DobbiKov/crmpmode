// Spec
new SpID[MAX_PLAYERS] = -1;
new SpType[MAX_PLAYERS];
new SpecTimer[MAX_PLAYERS];



CMD:spec(playerid, params[])
    return cmd::sp(playerid, params);
CMD:re(playerid, params[])
    return cmd::sp(playerid, params);
CMD:sp(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 1) return ShowCommandNotFound(playerid);

	extract params -> new to_player; else return SCM(playerid, yellow, !"[���������]: {FFFFFF}����������� /sp [ID ������]");

	if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return SCM(playerid, red, !"����� �� �����������, ��� ������ ������ ���!");

	if(SpType[to_player] != SP_TYPE_NONE) return SCM(playerid, red, "������ ������������ �� ���-�� ���������!");
	if(to_player == playerid) return SCM(playerid, red, "������ �� ����� ���������!");

	if(SpType[playerid] == SP_TYPE_NONE)
	{
	    new Float:x, Float:y, Float:z, Float:rot, vw, interior;
	    GetPlayerPos(playerid, x, y, z);
	    GetPlayerFacingAngle(playerid, rot);
	    vw = GetPlayerVirtualWorld(playerid);
	    interior = GetPlayerInterior(playerid);

	    SetPVarFloat(playerid, "sp_x", x);
	    SetPVarFloat(playerid, "sp_y", y);
	    SetPVarFloat(playerid, "sp_z", z);
	    SetPVarFloat(playerid, "sp_rot", rot);
	    SetPVarInt(playerid, "sp_vw", vw);
	    SetPVarInt(playerid, "sp_int", interior);
	}
	if(IsPlayerInAnyVehicle(to_player))
	{
	    SpID[playerid] = to_player;
	    SpType[playerid] = SP_TYPE_VEHICLE;
	    TogglePlayerSpectating(playerid, 1);
	    PlayerSpectateVehicle(playerid, GetPlayerVehicleID(to_player));
	    SetPlayerInterior(playerid, GetPlayerInterior(to_player));
	    SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(to_player));
	}
	else
	{
    	SpID[playerid] = to_player;
	    SpType[playerid] = SP_TYPE_PLAYER;
	    TogglePlayerSpectating(playerid, 1);
	    PlayerSpectatePlayer(playerid, to_player);
	    SetPlayerInterior(playerid, GetPlayerInterior(to_player));
	    SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(to_player));
	}
	new string[144];
	format(string, sizeof(string), "�� ������ ������� �� %s [%d]", PlayerInfo[to_player][pName], to_player);
	SCM(playerid, yellow, string);
	for(new i = 0; i < 48; i++){ PlayerTextDrawShow(playerid, spec_menu_TD_PTD[playerid][i]); }
 	SelectTextDraw(playerid,0xFFFFFFFF);
 	KillTimer(SpecTimer[playerid]);
	SpecTimer[playerid] = SetTimerEx("Spec_Menu_TD", 500, true, "ff", playerid, SpID[playerid]);
	return 1;
}

CMD:reoff(playerid)
    return cmd::spoff(playerid);
CMD:specoff(playerid)
    return cmd::spoff(playerid);
CMD:spoff(playerid)
{
	if(PlayerInfo[playerid][bAdmin] < 1) return ShowCommandNotFound(playerid);

	if(SpType[playerid] == SP_TYPE_NONE) return 1;

	CancelSelectTextDraw(playerid);

	return TogglePlayerSpectating(playerid, 0);
}

public OnPlayerSpawn(playerid)
{
	if(SpType[playerid] != SP_TYPE_NONE)
	{
	    if(PlayerInfo[playerid][bAdmin] != 0)
	    {
	        SpType[playerid] = SP_TYPE_NONE;
	        SpID[playerid] = -1;

			if(PlayerInfo[playerid][pMember] > 0) SetPlayerSkin(playerid, PlayerInfo[playerid][pFSkin]);
			else SetPlayerSkin(playerid, PlayerInfo[playerid][pChar]);
	        SetPlayerPos(playerid, GetPVarFloat(playerid, "sp_x"), GetPVarFloat(playerid, "sp_y"), GetPVarFloat(playerid, "sp_z"));
	        SetPlayerFacingAngle(playerid, GetPVarInt(playerid, "sp_rot"));
	        SetPlayerVirtualWorld(playerid, GetPVarInt(playerid, "sp_vw"));
	        SetPlayerInterior(playerid, GetPVarInt(playerid, "sp_int"));

	        DeletePVar(playerid, "sp_x");
	        DeletePVar(playerid, "sp_y");
	        DeletePVar(playerid, "sp_z");
	        DeletePVar(playerid, "sp_rot");
	        DeletePVar(playerid, "sp_vw");
	        DeletePVar(playerid, "sp_int");
	        for(new i = 0; i < 48; i++){ PlayerTextDrawHide(playerid, spec_menu_TD_PTD[playerid][i]); }
	        KillTimer(SpecTimer[playerid]);
	        CancelSelectTextDraw(playerid);
	    }
	}
    #if defined spec__OnPlayerSpawn
        return spec__OnPlayerSpawn(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn spec__OnPlayerSpawn
#if defined spec__OnPlayerSpawn
    forward spec__OnPlayerSpawn(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
    foreach(new i : Player)
    {
        if(SpID[i] == playerid)
        {
            SCM(i, red, "�����, �� ������� �� ��������� ������� ����!");
            TogglePlayerSpectating(i, 0);
        }
    }
	#if defined spec__OnPlayerDisconnect
		return spec__OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else 
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect spec__OnPlayerDisconnect
#if defined spec__OnPlayerDisconnect
	forward spec__OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid) 
{
	if(playertextid == PlayerText:spec_menu_TD_PTD[playerid][28]) // spoff
	{
		cmd::spoff(playerid);
	}
	if(playertextid == PlayerText:spec_menu_TD_PTD[playerid][32]) // slap
	{
		Slap(playerid, SpID[playerid]);
	}
	if(playertextid == PlayerText:spec_menu_TD_PTD[playerid][35]) // update
	{
		new string[3];
		format(string, sizeof(string), "%d", SpID[playerid]);
		cmd::sp(playerid, string);
	}
	if(playertextid == PlayerText:spec_menu_TD_PTD[playerid][33]) // stat
	{
		stats_player(playerid, SpID[playerid]);
	}

	if(playertextid == PlayerText:spec_menu_TD_PTD[playerid][34]) // unfreeze
	{
		new to_player = SpID[playerid];
		if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);
		new string[256];
		format(string, sizeof(string), "[A] %s[%d] ��������� ������ %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
		SCMA(grey, string);

		format(string, sizeof(string), "������������� %s[%d] ���������� ���!", PlayerInfo[playerid][pName], playerid);
		SCM(to_player, white, string);
		TogglePlayerControllable(to_player, 1);
	}
	if(playertextid == PlayerText:spec_menu_TD_PTD[playerid][31]) // freeze
	{
		new to_player = SpID[playerid];
		if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);
		new string[256];
		format(string, sizeof(string), "[A] %s[%d] �������� ������ %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
		SCMA(grey, string);
		
		format(string, sizeof(string), "������������� %s[%d] ��������� ���!", PlayerInfo[playerid][pName], playerid);
		SCM(to_player, white, string);
		
		TogglePlayerControllable(to_player, 0);
	}

	if(playertextid == PlayerText:spec_menu_TD_PTD[playerid][30]) // weap
	{
		new to_player = SpID[playerid];
		new strings[1000],strin[70],strs[100];
		new weapons[13][2];
		format(strs, 100, "{"cblue"}�����:\t\t\t%s{FFFFFF}", PlayerInfo[to_player][pName]);
		strcat(strings, strs);
		for(new i = 0; i != 12; i ++)
		{
			GetPlayerWeaponData(to_player, i, weapons[i][0], weapons[i][1]);
			if(weapons[i][0] != 0)
			{
				format(strin,70,"\n\n������:\t\t%s (%d)\n�������:\t\t%d", gun_name[ weapons[i][0] ],weapons[i][0],weapons[i][1]);
				strcat(strings,strin);
			}
		}
		SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}������ ������", strings, "�������", "");
	}

	if(playertextid == PlayerText:spec_menu_TD_PTD[playerid][29]) // back
	{
		for(new id = SpID[playerid]; id > 0; id--)
		{
			if(id == SpID[playerid])
				continue;
			if(id < 0) continue;
			if(PlayerInfo[id][pLogin] == false) continue;
			// switch(GetPlayerState(id))
			// {
			// 	case 1..3: {}
			// 	default: continue;
			// }

			if(SpID[playerid] != INVALID_PLAYER_ID)
				SpID[playerid] = INVALID_PLAYER_ID;

			new param_str[4];
			format(param_str, sizeof param_str, "%i", id);
			cmd::sp(playerid, param_str);
			break;
		}
	}
	if(playertextid == PlayerText:spec_menu_TD_PTD[playerid][27]) // next
	{
		for(new id = SpID[playerid]; id < MAX_PLAYERS; id++)
		{
			if(id == SpID[playerid])
				continue;
			if(id > MAX_PLAYERS) continue;

			if(PlayerInfo[id][pLogin] == false) continue;
			// switch(GetPlayerState(id))
			// {
			// 	case 1..3: {}
			// 	default: continue;
			// }

			if(SpID[playerid] != INVALID_PLAYER_ID)
				SpID[playerid] = INVALID_PLAYER_ID;

			new param_str[4];
			format(param_str, sizeof param_str, "%i", id);
			cmd::sp(playerid, param_str);
			break;
		}
	}
	#if defined sp__OnPlayerClickPlayerTextDraw
		return sp__OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);
	#else
		return 0;
	#endif
}
#if defined _ALS_OnPlayerClickPlayerTextDra || defined _ALS_OnPlayerClickPlayerTD
	#undef OnPlayerClickPlayerTextDraw
#else
	#define _ALS_OnPlayerClickPlayerTextDra
	#define _ALS_OnPlayerClickPlayerTD
#endif

#define OnPlayerClickPlayerTextDraw sp__OnPlayerClickPlayerTextDraw
#if defined sp__OnPlayerClickPlayerTextDraw
	forward sp__OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);
#endif

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == Text:INVALID_TEXT_DRAW) // ������
    {
		if(SpID[playerid] != -1) cmd::spoff(playerid);
    }
    #if defined sp__OnPlayerClickTextDraw
        return sp__OnPlayerClickTextDraw(playerid, Text:clickedid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerClickTextDraw
    #undef OnPlayerClickTextDraw
#else
    #define _ALS_OnPlayerClickTextDraw
#endif

#define OnPlayerClickTextDraw sp__OnPlayerClickTextDraw
#if defined sp__OnPlayerClickTextDraw
    forward sp__OnPlayerClickTextDraw(playerid, Text:clickedid);
#endif

publics Spec_Menu_TD(playerid, specid)
{
	//if(SpType[playerid] == SP_TYPE_NONE) return KillTimer(SpecTimer[playerid]);
	new info[128], Float:health, Float:arm;
	GetPlayerHealth(specid, health);
	GetPlayerArmour(specid, arm);

	new str_money[20], str_bmoney[20];
	if(PlayerInfo[specid][pCash] > 10000000) format(str_money, sizeof(str_money), "%d", floatround(PlayerInfo[specid][pCash]/1000000, floatround_round));
	else format(str_money, sizeof(str_money), "%d", PlayerInfo[specid][pCash]);

	if(PlayerInfo[specid][pBCash] > 10000000) format(str_bmoney, sizeof(str_bmoney), "%d", floatround(PlayerInfo[specid][pBCash]/1000000, floatround_round));
	else format(str_bmoney, sizeof(str_bmoney), "%d", PlayerInfo[specid][pBCash]);

	format(info, sizeof(info), "%s(%d)", PlayerInfo[specid][pName], specid);
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][5], info);

	format(info, sizeof(info), "%d", PlayerInfo[specid][pLVL]);
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][36], info);

	format(info, sizeof(info), "%s", str_money);
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][46], info);

	format(info, sizeof(info), "%s", str_bmoney);
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][47], info);

	format(info, sizeof(info), "%d", SpeedVehicle(specid));
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][41], info);






	format(info, sizeof(info), "%d", GetPlayerWeapon(specid));
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][37], info);
	format(info, sizeof(info), "%d", GetPlayerAmmo(specid));
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][38], info);

	format(info, sizeof(info), "%d", floatround(health, floatround_round));
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][39], info);
	format(info, sizeof(info), "%d", floatround(arm, floatround_round));
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][40], info);

	format(info, sizeof(info), "%d", GetPlayerPing(specid));
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][42], info);

	format(info, sizeof(info), "%d", GetPlayerVirtualWorld(specid));
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][43], info);
	format(info, sizeof(info), "%d", GetPlayerInterior(specid));
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][44], info);
	format(info, sizeof(info), "%d", GetPlayerState(specid));
	PlayerTextDrawSetString(playerid, spec_menu_TD_PTD[playerid][45], info);

	return 1;
}


public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	if(PlayerInfo[playerid][bAdmin] > 0)
	{
		new string[4] = "";
		valstr(string, clickedplayerid);
		return cmd::sp(playerid, string);
	}
	#if defined spec__OnPlayerClickPlayer
        return spec__OnPlayerClickPlayer(playerid, clickedplayerid, source);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerClickPlayer
    #undef OnPlayerClickPlayer
#else
    #define _ALS_OnPlayerClickPlayer
#endif

#define OnPlayerClickPlayer spec__OnPlayerClickPlayer
#if defined spec__OnPlayerClickPlayer
    forward spec__OnPlayerClickPlayer(playerid, clickedplayerid, source);
#endif