public OnPlayerDisconnect(playerid, reason)
{
    if(PlayerInfo[playerid][pJob] == Job_Car && player_job_vehicle_arend[playerid] > 0) EndJobMechanic(playerid);
    #if defined mech__OnPlayerDisconnect
        return mech__OnPlayerDisconnect(playerid, reason);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect mech__OnPlayerDisconnect
#if defined mech__OnPlayerDisconnect
    forward mech__OnPlayerDisconnect(playerid, reason);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
		case D_AREND_MECHANIC_CAR:
		{
		    if(!response) RemovePlayerFromVehicle(playerid);
		    else
		    {
		        if(PlayerInfo[playerid][pCash] < 200)
		        {
		            RemovePlayerFromVehicle(playerid);
		            return SCM(playerid, red, "� ��� ������������ �����!");
		        }

		        GiveMoney(playerid, -200, "������ ������ ������������");
				SPD(playerid, D_SET_REPAIR_PRICE, DIALOG_STYLE_INPUT, "{"cblue"}������� | ���� �������", "{FFFFFF}���������� ���� ��� ������� ����������.\n���� ������ ���� �� ����� {"cblue"}100 ������ {FFFFFF} � �� ����� {"cblue"} 5000 ������{FFFFFF}!", "�����", "");
		    }
		}
		case D_SET_REPAIR_PRICE:
		{
		    if(!response) SPD(playerid, D_SET_REPAIR_PRICE, DIALOG_STYLE_INPUT, "{"cblue"}������� | ���� �������", "{"cblue"}���������� ���� ��� ������� ����������.\n���� ������ ���� �� ����� {"cyellow"}100 ������ {"cblue"} � �� ����� {"cyellow"} 5000 ������{"cblue"}!", "�����", "");
			else
			{
			    if(!strlen(inputtext)) return SPD(playerid, D_SET_REPAIR_PRICE, DIALOG_STYLE_INPUT, "{"cblue"}������� | ���� �������", "{"cblue"}���������� ���� ��� ������� ����������.\n���� ������ ���� �� ����� {"cyellow"}100 ������ {"cblue"} � �� ����� {"cyellow"} 5000 ������{"cblue"}!", "�����", "");
				if(!IsNumeric(inputtext)) return SPD(playerid, D_SET_REPAIR_PRICE, DIALOG_STYLE_INPUT, "{"cblue"}������� | ���� �������", "{"cblue"}���������� ���� ��� ������� ����������.\n���� ������ ���� �� ����� {"cyellow"}100 ������ {"cblue"} � �� ����� {"cyellow"} 5000 ������{"cblue"}!", "�����", "");
				if(strval(inputtext) < 100 || strval(inputtext) > 5000) return SPD(playerid, D_SET_REPAIR_PRICE, DIALOG_STYLE_INPUT, "{"cblue"}������� | ���� �������", "{"cblue"}���������� ���� ��� ������� ����������.\n���� ������ ���� �� ����� {"cyellow"}100 ������ {"cblue"} � �� ����� {"cyellow"} 5000 ������{"cblue"}!", "�����", "");

				mech_repair_price[playerid] = strval(inputtext);
				mech_fuel_price[playerid] = -1;
				mech_fuel[playerid] = 0;

				SCM(playerid, blue, "�� ������� ���������� ���������!");
				new string[128];
				format(string, sizeof(string), "�� ������ ������ ����������, �� ������ �������� {"cyellow"}%d ������{"cblue"}!", mech_repair_price[playerid]);
				SCM(playerid, blue, string);
				SendClientMessage(playerid, white, "{"cblue"}/repair {FFFFFF}- ��������������� ������.");
				SendClientMessage(playerid, white, "{"cblue"}/join {FFFFFF}- ��������� �������� � ���.");
				SendClientMessage(playerid, white, "{"cblue"}/refill {FFFFFF}- ��������� ������.");
				SendClientMessage(playerid, white, "{"cblue"}/calling {FFFFFF}- ��������� ������.");

				SetPVarInt(playerid, "mechanic_job", 1);
				player_job_vehicle_arend[playerid] = GetPlayerVehicleID(playerid);

				format(string, sizeof(string), "{"cblue"}�����������\n{FFFFFF}���� �������: {"cblue"}%d ���\n{FFFFFF}�������: {"cblue"}���", mech_repair_price[playerid]);
				vehicle[player_job_vehicle_arend[playerid]][veh_label] = CreateDynamic3DTextLabel(string, 0xFFFFFFFF, 0.0, 0.0, 1.5, 20.0, _, player_job_vehicle_arend[playerid]);
				vehicle[player_job_vehicle_arend[playerid]][veh_arend] = 1;

			}
		}
		case D_JOIN_MECH:
		{
			if(!response)
			{
				return DeletePVar(playerid, "refill_biz_id");
			}
			else
			{
				new b = GetPVarInt(playerid, "refill_biz_id");

				mech_fuel_price[playerid] = BusinessInfo[b][bFillPrice]*2;
				mech_fuel_bizid[playerid] = b;

				SendClientMessage(playerid, blue, "�� ��������� �������� � ���!");
				SendClientMessage(playerid, white, "{"cblue"}/refill {FFFFFF}- ��������� ������.");

				new string[256];
				format(string, sizeof(string), "{"cblue"}�����������\n{FFFFFF}���� �������: {"cblue"}%d ���\n{FFFFFF}�������: {"cblue"}%d ���", mech_repair_price[playerid], mech_fuel_price[playerid]);
				UpdateDynamic3DTextLabelText(vehicle[player_job_vehicle_arend[playerid]][veh_label], 0xFFFFFFFF, string);
				return DeletePVar(playerid, "refill_biz_id");
			}
		}
    }
	#if	defined	mech__OnDialogResponse
		return mech__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse mech__OnDialogResponse
#if	defined	mech__OnDialogResponse
	forward mech__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
        if(job_car[MECHANIC_CAR][0] <= vehicleid <= job_car[MECHANIC_CAR][1])
        {
            if(PlayerInfo[playerid][pJob] != Job_Car)
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "�� �� �����������!");
            }

            if(vehicle[vehicleid][veh_arend] != 0 && vehicleid != player_job_vehicle_arend[playerid])
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "�� �� ������ ������������ ���� ��������� � ������ ������!");
            }
        }
	}
	#if	defined	mech__OnPlayerEnterVehicle
		return mech__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerEnterVehicle
	#undef	OnPlayerEnterVehicle
#else
	#define	_ALS_OnPlayerEnterVehicle
#endif

#define	OnPlayerEnterVehicle mech__OnPlayerEnterVehicle
#if	defined	mech__OnPlayerEnterVehicle
	forward mech__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER)
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        if(job_car[MECHANIC_CAR][0] <= vehicleid <= job_car[MECHANIC_CAR][1])
        {

            if(vehicleid != player_job_vehicle_arend[playerid])
            {
				if(PlayerInfo[playerid][pJob] != Job_Car)
				{
					new Float:x, Float:y, Float:z;
					GetPlayerPos(playerid, x, y, z);
					SetPlayerPos(playerid, x + 2.0, y + 2.0, z);
					RemovePlayerFromVehicle(playerid);
					// if(AntiCheatInfo[TP_in_VEH_AC][acStatus] == 0) return ResultMessageCheat(playerid, 9);
					// else return ResultCheat(playerid, 9);
				}
                ShowPlayerDialog
                (
                    playerid, D_AREND_MECHANIC_CAR, DIALOG_STYLE_MSGBOX,
                    "{"cblue"}����������� | ������ ����������",
                    "{FFFFFF}������ ���������� ������������ �������� {"cblue"}200 ������{FFFFFF}.\n�� ������ ���������� ��������� � ������ ������ �������?",
                    "��", "���"
                );
            }
        }
		if(GetPlayerVehicleID(playerid) == player_job_vehicle_arend[playerid])
		{
		    if(GetPVarInt(playerid, "EndJobMechanic") == 1)
		    {
		        SCM(playerid, green, "�� ��������� � ���������! ����������� ������!");
				KillTimer(player_end_job_timer[playerid]);
				DeletePVar(playerid, "EndJobMechanic");
			}
		}
    }
    if(oldstate == PLAYER_STATE_DRIVER)
    {
  		if(player_job_vehicle_arend[playerid] != -1 && PlayerInfo[playerid][pJob] == Job_Car)
		{
		    if(GetPVarInt(playerid, "EndJobMechanic") == 1) return 1;
			player_end_job_timer[playerid] = SetTimerEx("EndJobMechanic", 15000, false, "i", playerid);
			SetPVarInt(playerid, "EndJobMechanic", 1);

			SCM(playerid, 0xFF6600FF, "� ��� ���� 15 ������ ����� ��������� � ���������");
		}
    }
    #if defined mech__OnPlayerStateChange
        return mech__OnPlayerStateChange(playerid, newstate, oldstate);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_OnPlayerStateChange
	#undef	OnPlayerStateChange
#else
	#define	_ALS_OnPlayerStateChange
#endif

#define	OnPlayerStateChange mech__OnPlayerStateChange
#if	defined	mech__OnPlayerStateChange
	forward mech__OnPlayerStateChange(playerid, newstate, oldstate); 
#endif

publics EndJobMechanic(playerid)
{
	SCM(playerid, blue, "�� �� ������ ����� � ���������!");

	DeletePVar(playerid, "mechanic_job");
	DeletePVar(playerid, "EndJobMechanic");
	
	DestroyDynamic3DTextLabel(vehicle[player_job_vehicle_arend[playerid]][veh_label]);
	SetVehicleToRespawn(player_job_vehicle_arend[playerid]);
	
	vehicle[player_job_vehicle_arend[playerid]][veh_arend] = 0;
	mech_repair_price[playerid] = -1;
	mech_fuel_price[playerid] = -1;
	mech_fuel_bizid[playerid] = -1;
	mech_fuel[playerid] = 0;
	player_job_vehicle_arend[playerid] = -1;
}

CMD:repair(playerid, params[])
{
	if(PlayerInfo[playerid][pJob] != Job_Car) return SCM(playerid, red, "�� �� �����������!");
	
	extract params -> new to_player; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /repair [ID ������]");
	
	if(!IsPlayerConnected(to_player)) return SCM(playerid, 0xCECECEFF, "������ ������ ���");
	if(!IsPlayerInAnyVehicle(playerid) || !IsPlayerInAnyVehicle(to_player)) return SCM(playerid, red, "��, ��� ����� �� ������ � ����!");
	if(player_job_vehicle_arend[playerid] == -1) return SCM(playerid, red, "�� �� ������ ������� ����!");
	if(GetPVarInt(playerid, "mechanic_job") != 1) return SCM(playerid, red, "�� �� ������ ������� ����!");
	if(GetPlayerVehicleID(playerid) != player_job_vehicle_arend[playerid]) return SCM(playerid, red, "�� �� � ���� ������� ����������!");
	if(!IsPlayerInRangeOfPlayer(playerid, to_player, 15.0)) return SCM(playerid, red, "����� ��������� ������� ������");
	if(GetPlayerState(to_player) != PLAYER_STATE_DRIVER) return SCM(playerid, red, "������ ������ ��������� �� �����");
	if(PlayerInfo[to_player][pCash] < mech_repair_price[playerid]) return SCM(playerid, red, "� ������ ��� ������� �����!");
	if(to_player == playerid) return SCM(playerid, red, "�� �� ������ ��������������� ����!");
	
	return SendProposition(playerid, to_player, PROPOSITION_TYPE_REPAIR_CAR, mech_repair_price[playerid]);
}


CMD:refill(playerid, params[])
{
	if(PlayerInfo[playerid][pJob] != Job_Car) return SCM(playerid, red, "�� �� �����������!");
	if(mech_fuel_price[playerid] == -1 || mech_fuel_bizid[playerid] == -1) return SCM(playerid, red, "�� �� ��������� �������� � ���!");
	
	extract params -> new to_player, litrs; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /refill [ID ������] [���-�� ������]");
	
	if(!IsPlayerConnected(to_player)) return SCM(playerid, 0xCECECEFF, "������ ������ ���");
	if(!IsPlayerInAnyVehicle(playerid) || !IsPlayerInAnyVehicle(to_player)) return SCM(playerid, red, "��, ��� ����� �� ������ � ����!");
	if(player_job_vehicle_arend[playerid] == -1) return SCM(playerid, red, "�� �� ������ ������� ����!");
	if(GetPVarInt(playerid, "mechanic_job") != 1) return SCM(playerid, red, "�� �� ������ ������� ����!");
	if(GetPlayerVehicleID(playerid) != player_job_vehicle_arend[playerid]) return SCM(playerid, red, "�� �� � ���� ������� ����������!");
	if(!IsPlayerInRangeOfPlayer(playerid, to_player, 15.0)) return SCM(playerid, red, "����� ��������� ������� ������");
	if(GetPlayerState(to_player) != PLAYER_STATE_DRIVER) return SCM(playerid, red, "������ ������ ��������� �� �����");

	new toPlayerVehId = GetPlayerVehicleID(to_player);
	if(vehicle[toPlayerVehId][veh_fuel] + litrs > 100.0)
	{
		new string[144];
		format(string, sizeof(string), "� �������� ������� �� ����������� ������� �������. �� ������ ��������� ��� �� %d �.", 100 - floatround(vehicle[toPlayerVehId][veh_fuel]) );
		return SCM(playerid, white, string);
	} 
	if(PlayerInfo[to_player][pCash] < litrs * mech_fuel_price[playerid]) return SCM(playerid, red, "� ������ ��� ������� �����!");
	if(to_player == playerid) return SCM(playerid, red, "�� �� ������ ��������� ����!");
	
	return SendProposition(playerid, to_player, PROPOSITION_TYPE_REFILL_CAR, litrs);
}

CMD:join(playerid, params[])
{
	if(PlayerInfo[playerid][pJob] != Job_Car) return SCM(playerid, red, "�� �� �����������!");

	if(player_job_vehicle_arend[playerid] == -1) return SCM(playerid, red, "�� �� ������ ������� ����!");
	if(GetPlayerVehicleID(playerid) != player_job_vehicle_arend[playerid]) return SCM(playerid, red, "�� �� � ���� ������� ����������!");

	new b;
	foreach(new i : Allbusiness) 
	{
		if(BusinessInfo[i][bType] == b_type_FILL && IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]))
		{
			b = i;
			SetPVarInt(playerid, "refill_biz_id", b);

			new fmt_dialog[512];
			format(fmt_dialog, sizeof(fmt_dialog), "\
			{FFFFFF}�������� �������:\t%s(� %d)\n\
			���� �� 1 ����:\t\t%d ���.\n\n\
			��� �������/�������� ��� ����� ���������\n\
			50 ��������� �� ���� ����� ������\n\n\
			�� ��������, ��� ������ ��������� ��������?", business_params[BusinessInfo[b][bType]][bname], BusinessInfo[b][bID], BusinessInfo[b][bFillPrice]);

			return SPD(playerid, D_JOIN_MECH, DIALOG_STYLE_MSGBOX, "{"cblue"}��������", fmt_dialog, "��", "���");
		}
	}
	SCM(playerid, red, !"�� ������ ��������� � ���!");
	return 1;
}