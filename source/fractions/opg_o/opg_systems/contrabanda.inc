public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_CALL_CONTRABANDA:
        {
            if(!response) return SCM(playerid, blue, !"�� ���������� �� ������ �����������!");
            if(!IsAOpg(playerid) || PlayerInfo[playerid][pRang] < 10) return SCM(playerid, red, !"��� ���������� ������ �������!");
            new _contraband_price = CONTRABANDA_VALUE * CONTRABANDA_GRAM_IN_BAG * CONTRABANDA_PRICE;
            if(PlayerInfo[playerid][pBCash] < _contraband_price) return SCM(playerid, red, !"� ��� ������������ ����� �� ���������� �����!");


            SCM(playerid, blue, "�� ������� �������� �����������, �� �������������� �������� �� �����. �� ������ �� ������� ������ � ������� 10 �����!");
            next_contraband_time = gettime() + 86400 * 3;

            GiveBankMoney(playerid, -_contraband_price, "����� �����������");

            new string[256];
            format(string, sizeof(string), "UPDATE `other` SET `next_contraband_time` = '%d' LIMIT 1", next_contraband_time);
            mysql_tquery(connects, string, "", "");

            format(string, sizeof(string), "[A] %s %s[%d](%s) �������� �����������", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid, GetMember[PlayerInfo[playerid][pMember]]);
            SCMA(grey, string);

            format(string, sizeof(string), "[R] %s %s[%d] ������� ������ �����������", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid);
            SCMR(PlayerInfo[playerid][pMember], green, string);           

            contraband_pos_id = random(sizeof(contraband_pos));
            contraband_fraction = PlayerInfo[playerid][pMember];
            new Float: x, Float:y, Float:z;
            x = contraband_pos[contraband_pos_id][contraband_route_x];
            y = contraband_pos[contraband_pos_id][contraband_route_y];
            z = contraband_pos[contraband_pos_id][contraband_route_z];
            SetPlayerCheckpoint(playerid, x, y, z, 3.0);
            contraband_pickup = CreateDynamicPickup(1279, 23, x, y, z, 0);
            contraband_timer = SetTimer("contrabanda_timer", 1000 * 60 * 15, false);
            pCheckpoint[playerid] = CP_CONTRABANDA;
        }
    }
	#if	defined	contrabanda__OnDialogResponse
		return contrabanda__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse contrabanda__OnDialogResponse
#if	defined	contrabanda__OnDialogResponse
	forward contrabanda__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

publics contrabanda_timer()
{
    DestroyDynamicPickup(contraband_pickup);
    contraband_pos_id = -1;
    contraband_fraction = -1;
    contraband_bags = CONTRABANDA_VALUE;
}

public OnPlayerEnterCheckpoint(playerid) //������� ������� ������������� ����������, ����� ����� ���������� �� checkpoint
{
    switch(pCheckpoint[playerid])
    {
        case CP_CONTRABANDA: 
        {
            DisablePlayerCheckpoint(playerid); //������� ��������
            SCM(playerid, blue, "�� ������� �� ����� ����������"); //��������� � ���
        }
    }
    #if defined ctrbnd__OnPlayerEnterCheckpoint
        return ctrbnd__OnPlayerEnterCheckpoint(playerid);
    #else
        return 1;
    #endif
}
#if    defined    _ALS_OnPlayerEnterCheckpoint
    #undef    OnPlayerEnterCheckpoint
#else
    #define    _ALS_OnPlayerEnterCheckpoint
#endif

#define    OnPlayerEnterCheckpoint ctrbnd__OnPlayerEnterCheckpoint
#if    defined    ctrbnd__OnPlayerEnterCheckpoint
    forward ctrbnd__OnPlayerEnterCheckpoint(playerid);
#endif

public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
	if(pickupid == contraband_pickup && IsAOpg(playerid))
	{
        if(contraband_bags <= 0)
        {
            return SCM(playerid, red, !"������ � ������������ ������ ���!");
        }
        if(GetPVarInt(playerid, "contraband_meshok_load") == 1)
        {
            return SCM(playerid, red, "�� ��� ������� �����!");
        }
        ApplyAnimation(playerid,"CARRY","crry_prtial",4.1,1,1,1,1,1);
        SetPlayerAttachedObject(playerid, 1 ,1279, 1,0.11,0.36,0.0,0.0,90.0);
        SetPVarInt(playerid, "contraband_meshok_load", 1);
        SCM(playerid, blue, "�� ����� ����� � ������������, �������� ��� � ������!");
        contraband_bags--;
	}
    #if defined ctrbnd__OnPlayerPickUpDynPickup
        return ctrbnd__OnPlayerPickUpDynPickup(playerid, pickupid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerPickUpDynPickup
    #undef OnPlayerPickUpDynamicPickup
#else 
    #define _ALS_OnPlayerPickUpDynPickup
#endif

#define OnPlayerPickUpDynamicPickup ctrbnd__OnPlayerPickUpDynPickup
#if defined ctrbnd__OnPlayerPickUpDynPickup
    forward ctrbnd__OnPlayerPickUpDynPickup(playerid, pickupid);
#endif

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if((newkeys & KEY_JUMP) && !(oldkeys & KEY_JUMP) || (newkeys & KEY_FIRE))
    {
        if(GetPVarInt(playerid, "contraband_meshok_load") > 0  && IsAOpg(playerid))
        {
            SCM(playerid, red, !"�� ������� ���� � ������������!");
            DropContrabandaBag(playerid);
        }
    }
    if(newkeys == 1024 && GetPVarInt(playerid, "contraband_meshok_load") == 1)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 2610.9668,1767.7485,10.2175) && PlayerInfo[playerid][pMember] == TEAM_OREX) //orexi
        {
            new string[144];
            format(string, sizeof(string), "[R] %s %s[%d] �������� �� ����� ����������� ����� � 1 ��. ����������", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid);
            SCMR(PlayerInfo[playerid][pMember], green, string);

            OPG_O_DRUGS += CONTRABANDA_GRAM_IN_BAG; 

            SaveAccounts(playerid);
            SaveRepository();
            
            DropContrabandaBag(playerid);
        }
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1705.9067,1337.9858,26.0344) && PlayerInfo[playerid][pMember] == TEAM_SUN) //solnce
        {
            new string[144];
            format(string, sizeof(string), "[R] %s %s[%d] �������� �� ����� ����������� ����� � 1 ��. ����������", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid);
            SCMR(PlayerInfo[playerid][pMember], green, string);

            OPG_S_DRUGS += CONTRABANDA_GRAM_IN_BAG;

            SaveAccounts(playerid);
            SaveRepository();

            DropContrabandaBag(playerid);
        }

        if(IsPlayerInRangeOfPoint(playerid, 3.0, 1967.2764, -1944.4343, 25.1482))
        {
            // SCM(playerid, blue, !"�� ���������� 1 ����� � ������������!");
            DropContrabandaBag(playerid);
            new _money = (CONTRABANDA_GRAM_IN_BAG * CONTRABANDA_PRICE) / 2;
            GiveMoney(playerid, _money, "����������� ����������� �� ��.����.");

            new string[144] = "";
            format(string, sizeof(string), "��� ���� ��������� ������ � ������� %d ���., �� ����������� ����������� �������!", _money);
            SCM(playerid, green, string);
        }

    }
	#if	defined	ctrbnd__OnPlayerKeyStateChange
		return ctrbnd__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange ctrbnd__OnPlayerKeyStateChange
#if	defined	ctrbnd__OnPlayerKeyStateChange
	forward ctrbnd__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

stock DropContrabandaBag(playerid)
{
    DeletePVar(playerid, "contraband_meshok_load");
    ClearAnimations(playerid);

    if(IsPlayerAttachedObjectSlotUsed(playerid, 1))
        RemovePlayerAttachedObject(playerid, 1);
}



public OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_PASSENGER || newstate == PLAYER_STATE_DRIVER)
    {
        if(GetPVarInt(playerid, "contraband_meshok_load") > 0 && IsAOpg(playerid))
        {
            SCM(playerid, red, !"�� ������� ���� � ������������!");
            DropContrabandaBag(playerid);
        }       
    }
    #if defined ctrbnd__OnPlayerStateChange
        return ctrbnd__OnPlayerStateChange(playerid, newstate, oldstate);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_OnPlayerStateChange
	#undef	OnPlayerStateChange
#else
	#define	_ALS_OnPlayerStateChange
#endif

#define	OnPlayerStateChange ctrbnd__OnPlayerStateChange
#if	defined	ctrbnd__OnPlayerStateChange
	forward ctrbnd__OnPlayerStateChange(playerid, newstate, oldstate); 
#endif

public OnVehicleSpawn(vehicleid)
{
    ClearContrabandaBagsFromTrunks();
	#if defined ctrbnd__OnVehicleSpawn
        return ctrbnd__OnVehicleSpawn(vehicleid);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_OnVehicleSpawn
	#undef	OnVehicleSpawn
#else
	#define	_ALS_OnVehicleSpawn
#endif

#define	OnVehicleSpawn ctrbnd__OnVehicleSpawn
#if	defined	ctrbnd__OnVehicleSpawn
	forward ctrbnd__OnVehicleSpawn(vehicleid); 
#endif

public OnVehicleDeath(vehicleid, killerid)
{
    ClearContrabandaBagsFromTrunks();
	#if defined ctrbnd__OnVehicleDeath
        return ctrbnd__OnVehicleDeath(vehicleid, killerid);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_OnVehicleDeath
	#undef	OnVehicleDeath
#else
	#define	_ALS_OnVehicleDeath
#endif

#define	OnVehicleDeath ctrbnd__OnVehicleDeath
#if	defined	ctrbnd__OnVehicleDeath
	forward ctrbnd__OnVehicleDeath(vehicleid, killerid); 
#endif

stock ClearContrabandaBagsFromTrunks()
{
    for(new i = job_car[TEAM_OREX_FURGON_CAR][0]; i <= job_car[TEAM_OREX_FURGON_CAR][1]; i++)
    {
        vehicle_trunk[i][trunk_drugs_bags] = 0;
        DestroyDynamic3DTextLabel(vehicle[i][veh_label]);
    }

    for(new i = job_car[TEAM_SUN_FURGON_CAR][0]; i <= job_car[TEAM_SUN_FURGON_CAR][1]; i++)
    {
        vehicle_trunk[i][trunk_drugs_bags] = 0;
        DestroyDynamic3DTextLabel(vehicle[i][veh_label]);
    }

    for(new i = job_car[TEAM_FSB_FURGON_CAR][0]; i <= job_car[TEAM_FSB_FURGON_CAR][1]; i++)
    {
        vehicle_trunk[i][trunk_drugs_bags] = 0;
        DestroyDynamic3DTextLabel(vehicle[i][veh_label]);
    }
}

CMD:loaddrugs(playerid)
{
    if(!IsAOpg(playerid) && !IsAFSB(playerid)) return YouCannotUseThisFunc(playerid);
    if(GetPVarInt(playerid, "contraband_meshok_load") != 1) return SCM(playerid, red, !"� ��� ��� ����� � ������������!");
    if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, red, !"�� ������ ���� ��� ����������!");

    new near_ctrbnd_car = IsPlayerNearContrabandaCar(playerid);
    if(near_ctrbnd_car != -1)
    {
        return PutDrugsBagsIntoVehicle(playerid, near_ctrbnd_car);
    }

    return SCM(playerid, red, !"�� ������ ���������� � ��������� �������!");
}

stock PutDrugsBagsIntoVehicle(playerid, vehicleid)
{
    vehicle_trunk[vehicleid][trunk_drugs_bags] += 1;
    DeletePVar(playerid, "contraband_meshok_load");
    DropContrabandaBag(playerid);

    DestroyDynamic3DTextLabel(vehicle[vehicleid][veh_label]);
    new string[144]= "";
    format(string, sizeof(string), "�����������:\n%d ������", vehicle_trunk[vehicleid][trunk_drugs_bags]);
    vehicle[vehicleid][veh_label] = CreateDynamic3DTextLabel(string, white, 0.0, 0.0, 1.5, 20.0, _, vehicleid);

    return SCM(playerid, blue, !"�� �������� ����� � ������������ � ������.");
}

stock GetDrugsBagsFromVehicle(playerid, vehicleid)
{
    if(vehicle_trunk[vehicleid][trunk_drugs_bags] < 1) 
    {
        return SCM(playerid, red, !"� ������� ��� ������ � ������������!");
    }
    vehicle_trunk[vehicleid][trunk_drugs_bags] -= 1;
    ApplyAnimation(playerid,"CARRY","crry_prtial",4.1,1,1,1,1,1);
    SetPlayerAttachedObject(playerid, 1 ,1279, 1,0.11,0.36,0.0,0.0,90.0);
    SetPVarInt(playerid, "contraband_meshok_load", 1);
    SCM(playerid, blue, "�� ����� ����� � ������������, �������� ��� �� �����!");

    DestroyDynamic3DTextLabel(vehicle[vehicleid][veh_label]);
    if(vehicle_trunk[vehicleid][trunk_drugs_bags] > 0)
    {
        new string[144]= "";
        format(string, sizeof(string), "�����������:\n%d ������", vehicle_trunk[vehicleid][trunk_drugs_bags]);
        vehicle[vehicleid][veh_label] = CreateDynamic3DTextLabel(string, white, 0.0, 0.0, 1.5, 20.0, _, vehicleid);
    }
    return 1;
}

stock IsPlayerNearContrabandaCar(playerid)
{
    new Float:x, Float: y, Float: z;
    GetPlayerPos(playerid, x, y, z);

    for(new i = job_car[TEAM_OREX_FURGON_CAR][0]; i <= job_car[TEAM_OREX_FURGON_CAR][1]; i++)
    {
        GetCoordBootVehicle(i, x, y, z);

        if(IsPlayerInRangeOfPoint(playerid, 1.0, x, y, z))
        {
            return i;
        }
    }

    for(new i = job_car[TEAM_SUN_FURGON_CAR][0]; i <= job_car[TEAM_SUN_FURGON_CAR][1]; i++)
    {
        GetCoordBootVehicle(i, x, y, z);

        if(IsPlayerInRangeOfPoint(playerid, 1.0, x, y, z))
        {
            return i;
        }
    }
    for(new i = job_car[TEAM_FSB_FURGON_CAR][0]; i <= job_car[TEAM_FSB_FURGON_CAR][1]; i++)
    {
        GetCoordBootVehicle(i, x, y, z);

        if(IsPlayerInRangeOfPoint(playerid, 1.0, x, y, z))
        {
            return i;
        }
    }

    return -1;
}

CMD:unloaddrugs(playerid)
{
    if(!IsAOpg(playerid) && !IsAFSB(playerid)) return YouCannotUseThisFunc(playerid);
    if(GetPVarInt(playerid, "contraband_meshok_load") > 0) return SCM(playerid, red, !"� ��� ��� ���� ����� � ������������!");
    if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, red, !"�� ������ ���� ��� ����������!");
    
    new near_ctrbnd_car = IsPlayerNearContrabandaCar(playerid);
    if(near_ctrbnd_car != -1)
    {
        return GetDrugsBagsFromVehicle(playerid, near_ctrbnd_car);
    }

    return SCM(playerid, red, !"�� ������ ���������� � ��������� �������!");
}