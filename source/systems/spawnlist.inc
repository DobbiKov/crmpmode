stock SpawnList(playerid)
{
	new fmt_dialog[528] = "{"cblue"}1. {FFFFFF}�� �������\n{"cblue"}2. {FFFFFF}����\n{"cblue"}3. {FFFFFF}� ��������\n{"cblue"}4. {FFFFFF}�� ���� �����������\n";
	if(PlayerInfo[playerid][pLogin] != true) strcat(fmt_dialog, "{"cblue"}5. {FFFFFF}��� �����");

    SPD(playerid, D_SPAWN_LIST, DIALOG_STYLE_LIST, "{"cblue"}����� ������", fmt_dialog, "�����", "");
	return 1;
}
stock SetSpawnVokzal(playerid)
{
    SpawnPlayer(playerid);
    SetPlayerPos(playerid, 1823.5634, 2528.6885, 15.6825);
    SetPlayerFacingAngle(playerid, 130.7277);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerInterior(playerid, 0);
	SetPlayerDefaultVariables(playerid);
	FreezePlayer(playerid, 5000);
	return 1;
}
stock SetSpawnAtHome(playerid)
{
	if(PlayerInfo[playerid][pHomeID] == -1)
	{
		SCM(playerid, red, "� ��� ��� ����.");
		return SpawnList(playerid);
	}
	new h;
	foreach(new i : Allhouses) if(HouseInfo[i][hID] == PlayerInfo[playerid][pHomeID])
	{
		h = i;
		break;
	}
    SpawnPlayer(playerid);
    SetPlayerPos(playerid, house_params[ HouseInfo[h][hType] ][store_pos_x], house_params[ HouseInfo[h][hType] ][store_pos_y], house_params[ HouseInfo[h][hType] ][store_pos_z] + 0.5);
    SetPlayerVirtualWorld(playerid, h);
    SetPlayerInterior(playerid, 0);
	SetPlayerDefaultVariables(playerid);
	FreezePlayer(playerid, 10000);
	return 1;
}
stock SetSpawnAtKvartira(playerid)
{
	if(PlayerInfo[playerid][pKvartID] == -1)
	{
		SCM(playerid, red, "� ��� ��� ��������.");
		return SpawnList(playerid);
	}
    SpawnPlayer(playerid);

    SetPlayerPos(playerid, kvart_params[0][kvart_spawn_x], kvart_params[0][kvart_spawn_y], kvart_params[0][kvart_spawn_z]);
	new kvart_idx = 0;
	foreach(new i : Allkvart) 
		if(KvartInfo[i][kvart_id] == PlayerInfo[playerid][pKvartID]) 
			kvart_idx = i;
    SetPlayerVirtualWorld(playerid, kvart_idx);
    SetPlayerInterior(playerid, 0);
	SetPlayerDefaultVariables(playerid);
	FreezePlayer(playerid, 10000);
	return 1;
}
stock SetSpawnAtOrganithation(playerid)
{
	if(PlayerInfo[playerid][pMember] < 1)
	{
	    SCM(playerid, red, "�� �� �������� � �����������.");
	    return SpawnList(playerid);
	}
	SpawnPlayer(playerid);

	new frac = PlayerInfo[playerid][pMember];
	SetPlayerInterior(playerid, FractionInfo[frac][fractionInt]);
	SetPlayerPos(playerid, FractionInfo[frac][fPosX],FractionInfo[frac][fPosY],FractionInfo[frac][fPosZ]);
	SetPlayerFacingAngle(playerid, FractionInfo[frac][fPosA]);
	SetPlayerVirtualWorld(playerid, FractionInfo[frac][fractionVirt]);
	SetCameraBehindPlayer(playerid);

    SetPlayerDefaultVariables(playerid);
	FreezePlayer(playerid, 10000);
	return 1;
}
stock SetSpawnAtLastPlace(playerid)
{
	new Float:x, Float:y, Float:z;
	x = PlayerInfo[playerid][pLastX];
	y = PlayerInfo[playerid][pLastY];
	z = PlayerInfo[playerid][pLastZ];
	
	if(x == 0.0 || y == 0.0 || z == 0.0)
	{
	    SCM(playerid, red, "���������� ���� �������.");
	    return SpawnList(playerid);
	}

    SpawnPlayer(playerid);
	SetPlayerPos(playerid, x, y, z);
	SetPlayerDefaultVariables(playerid);
	FreezePlayer(playerid, 10000);
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);
	return 1;
}
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
		case D_SPAWN_LIST:
		{
		    if(!response)
		    {
				if(PlayerInfo[playerid][pLogin] != true)
				{
					SCM(playerid, red, "�� ���� ������� � �������, ������ ��� ���������� �� �����������");
					NewKick(playerid);
				}
		    }
		    else
		    {
		        switch(listitem)
		        {
		            case 0: SetSpawnVokzal(playerid);
		            case 1: SetSpawnAtHome(playerid);
		            case 2: SetSpawnAtKvartira(playerid);
		            case 3: SetSpawnAtOrganithation(playerid);
		            case 4: SetSpawnAtLastPlace(playerid);
		        }
		    }
		}
    }
	#if	defined	spawn__OnDialogResponse
		return spawn__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse spawn__OnDialogResponse
#if	defined	spawn__OnDialogResponse
	forward spawn__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif