new taxi_price[MAX_PLAYERS];
new PlayerTimerTaxi[MAX_PLAYERS] = -1;



public OnPlayerDisconnect(playerid, reason)
{
    if(PlayerInfo[playerid][pJob] == Job_Taxi && player_job_vehicle_arend[playerid] > 0) EndJobTaxi(playerid);
    #if defined taxi__OnPlayerDisconnect
        return taxi__OnPlayerDisconnect(playerid, reason);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect taxi__OnPlayerDisconnect
#if defined taxi__OnPlayerDisconnect
    forward taxi__OnPlayerDisconnect(playerid, reason);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
		case D_AREND_TAXI_CAR:
		{
		    if(!response) RemovePlayerFromVehicle(playerid);
		    else
		    {
		        if(PlayerInfo[playerid][pCash] < 200)
		        {
		            RemovePlayerFromVehicle(playerid);
		            return SCM(playerid, red, "� ��� ������������ �����!");
		        }

		        GiveMoney(playerid, -200, "������ ������ ��������");
				SPD(playerid, D_SET_TAXI_PRICE, DIALOG_STYLE_INPUT, "{"cblue"}������� | ��������� �������", "{"cblue"}���������� ���� �� ������ �� 1 ��.\n���� ������ ���� �� ����� {"cyellow"}100 ������ {"cblue"} � �� ����� {"cyellow"} 500 ������{"cblue"}!", "�����", "");
		    }
		}
		case D_SET_TAXI_PRICE:
		{
		    if(!response) SPD(playerid, D_SET_TAXI_PRICE, DIALOG_STYLE_INPUT, "{"cblue"}������� | ��������� �������", "{"cblue"}���������� ���� �� ������ �� 1 ��.\n���� ������ ���� �� ����� {"cyellow"}100 ������ {"cblue"} � �� ����� {"cyellow"} 500 ������{"cblue"}!", "�����", "");
			else
			{
			    if(!strlen(inputtext)) return SPD(playerid, D_SET_TAXI_PRICE, DIALOG_STYLE_INPUT, "{"cblue"}������� | ��������� �������", "{"cblue"}���������� ���� �� ������ �� 1 ��.\n���� ������ ���� �� ����� {"cyellow"}100 ������ {"cblue"} � �� ����� {"cyellow"} 500 ������{"cblue"}!", "�����", "");
				if(!IsNumeric(inputtext)) return SPD(playerid, D_SET_TAXI_PRICE, DIALOG_STYLE_INPUT, "{"cblue"}������� | ��������� �������", "{"cblue"}���������� ���� �� ������ �� 1 ��.\n���� ������ ���� �� ����� {"cyellow"}100 ������ {"cblue"} � �� ����� {"cyellow"} 500 ������{"cblue"}!", "�����", "");
				if(strval(inputtext) < 100 || strval(inputtext) > 500) return SPD(playerid, D_SET_TAXI_PRICE, DIALOG_STYLE_INPUT, "{"cblue"}������� | ��������� �������", "{"cblue"}���������� ���� �� ������ �� 1 ��.\n���� ������ ���� �� ����� {"cyellow"}100 ������ {"cblue"} � �� ����� {"cyellow"} 500 ������{"cblue"}!", "�����", "");

				taxi_price[playerid] = strval(inputtext);

				SCM(playerid, blue, "�� ������� ���������� ���������!");
				new string[128];
				format(string, sizeof(string), "�� ������ �������� {"cyellow"}%d ������{"cblue"} �� 1 �� ������� ���������!", taxi_price[playerid]);
				SCM(playerid, blue, string);
				SendClientMessage(playerid, white, "{"cblue"}/calling {FFFFFF}- ��������� ������.");

				SetPVarInt(playerid, "taxi_job", 1);
				player_job_vehicle_arend[playerid] = GetPlayerVehicleID(playerid);

				format(string, sizeof(string), "{15a6f8}��� << UNIGVA Taxi >>\n{FFFFFF}��������� �������: {15a6f8}%d ���/��", taxi_price[playerid]);
				vehicle[player_job_vehicle_arend[playerid]][veh_label] = CreateDynamic3DTextLabel(string, 0xFFFFFFFF, 0.0, 0.0, 1.5, 20.0, _, player_job_vehicle_arend[playerid]);
				vehicle[player_job_vehicle_arend[playerid]][veh_arend] = 1;

			}
		}
    }
	#if	defined	taxi__OnDialogResponse
		return taxi__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse taxi__OnDialogResponse
#if	defined	taxi__OnDialogResponse
	forward taxi__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
        if(job_car[TAXI_CAR][0] <= vehicleid <= job_car[TAXI_CAR][1])
        {
            if(PlayerInfo[playerid][pJob] != Job_Taxi)
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "�� �� �������!");
            }

            if(vehicle[vehicleid][veh_arend] != 0 && vehicleid != player_job_vehicle_arend[playerid])
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "�� �� ������ ������������ ���� ��������� � ������ ������!");
            }
        }
	}
	#if	defined	taxi__OnPlayerEnterVehicle
		return taxi__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerEnterVehicle
	#undef	OnPlayerEnterVehicle
#else
	#define	_ALS_OnPlayerEnterVehicle
#endif

#define	OnPlayerEnterVehicle taxi__OnPlayerEnterVehicle
#if	defined	taxi__OnPlayerEnterVehicle
	forward taxi__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	new vehicleid = GetPlayerVehicleID(playerid);
    if(newstate == PLAYER_STATE_DRIVER)
    {
        if(job_car[TAXI_CAR][0] <= vehicleid <= job_car[TAXI_CAR][1])
        {
			
            
			if(PlayerInfo[playerid][pJob] != Job_Taxi)
			{
				new Float:x, Float:y, Float:z;
				GetPlayerPos(playerid, x, y, z);
				SetPlayerPos(playerid, x + 2.0, y + 2.0, z);
				RemovePlayerFromVehicle(playerid);
				// if(AntiCheatInfo[TP_in_VEH_AC][acStatus] == 0) return ResultMessageCheat(playerid, 9);
				// else return ResultCheat(playerid, 9);
			}

            if(vehicle[vehicleid][veh_arend] != 0 && vehicleid != player_job_vehicle_arend[playerid])
            {
                RemovePlayerFromVehicle(playerid);
                return SCM(playerid, red, "�� �� ������ ������������ ���� ��������� � ������ ������!");
            }

            if(vehicleid != player_job_vehicle_arend[playerid])
            {
                ShowPlayerDialog
                (
                    playerid, D_AREND_TAXI_CAR, DIALOG_STYLE_MSGBOX,
                    "{"cblue"}������� | ������ ����������",
                    "{FFFFFF}������ ���������� �������� {"cblue"}200 ������{FFFFFF}.\n�� ������ ���������� ��������� � ������ ������ �������?",
                    "��", "���"
                );
            }
        }
		if(GetPlayerVehicleID(playerid) == player_job_vehicle_arend[playerid])
		{
		    if(GetPVarInt(playerid, "EndJobTaxi") == 1)
		    {
		        SCM(playerid, green, "�� ��������� � ���������! ����������� ������!");
				KillTimer(player_end_job_timer[playerid]);
				DeletePVar(playerid, "EndJobTaxi");
			}
		}
    }
    if(oldstate == PLAYER_STATE_DRIVER)
    {
  		if(player_job_vehicle_arend[playerid] != -1 && PlayerInfo[playerid][pJob] == Job_Taxi)
		{
		    if(GetPVarInt(playerid, "EndJobTaxi") == 1) return 1;
			player_end_job_timer[playerid] = SetTimerEx("EndJobTaxi", 15000, false, "i", playerid);
			SetPVarInt(playerid, "EndJobTaxi", 1);

			SCM(playerid, 0xFF6600FF, "� ��� ���� 15 ������ ����� ��������� � ���������");
		}
    }
	if(newstate == PLAYER_STATE_PASSENGER)
	{
        if(job_car[TAXI_CAR][0] <= vehicleid <= job_car[TAXI_CAR][1])
        {
			if(vehicle[vehicleid][veh_arend] != 1)
			{
				RemovePlayerFromVehicle(playerid);
				return SCM(playerid, red, "� ������ ������ ������ ����� �� ��������� �����!");
			}

			foreach(new i : Player)
			{
				if(vehicleid == player_job_vehicle_arend[i])
				{
					if(PlayerInfo[playerid][pCash] < taxi_price[i])
					{
						RemovePlayerFromVehicle(playerid);
						return SCM(playerid, red, "� ��� ������������ �����!");
					}
					else 
					{
						new string[128];
						format(string, sizeof(string), "�� ������ ������� �� �����. ��� �������� %s. �� ������ ������� %d ������ �� 1 ��!", PlayerInfo[i][pName], taxi_price[i]);
						SCM(playerid, blue, string);

						format(string, sizeof(string), "��� ����� �������� %s", PlayerInfo[playerid][pName]);
						SCM(i, blue, string);
						PlayerTimerTaxi[playerid] = SetTimerEx("PublicTimerTaxi", 15000, true, "i", playerid);
					}
				}
			}
        }
	}
	if(oldstate == PLAYER_STATE_PASSENGER)
	{
		if(PlayerTimerTaxi[playerid] > 0)
		{
			if(vehicle[vehicleid][veh_arend] != 1) return 1;

			SCM(playerid, green, "�� ��������� ������� �� �����!");
			KillTimer(PlayerTimerTaxi[playerid]);
			PlayerTimerTaxi[playerid] = -1;
			foreach(new j : Player)
			{
				if(vehicleid == player_job_vehicle_arend[j])
				{
					new string[128];
					format(string, sizeof(string), "�������� %s ����� �� ���� � �������� �������!");
					SCM(j, green, string);
				}
			}
		}
	}
    #if defined taxi__OnPlayerStateChange
        return taxi__OnPlayerStateChange(playerid, newstate, oldstate);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_OnPlayerStateChange
	#undef	OnPlayerStateChange
#else
	#define	_ALS_OnPlayerStateChange
#endif

#define	OnPlayerStateChange taxi__OnPlayerStateChange
#if	defined	taxi__OnPlayerStateChange
	forward taxi__OnPlayerStateChange(playerid, newstate, oldstate); 
#endif

publics EndJobTaxi(playerid)
{
	SCM(playerid, blue, "�� �� ������ ����� � ���������!");

	DeletePVar(playerid, "taxi_job");
	DeletePVar(playerid, "EndJobTaxi");
	
	DestroyDynamic3DTextLabel(vehicle[player_job_vehicle_arend[playerid]][veh_label]);
	SetVehicleToRespawn(player_job_vehicle_arend[playerid]);
	
	vehicle[player_job_vehicle_arend[playerid]][veh_arend] = 0;
	taxi_price[playerid] = -1;
	player_job_vehicle_arend[playerid] = -1;

	return 1;
}

publics PublicTimerTaxi(playerid)
{
	if(!IsPlayerInAnyVehicle(playerid))
	{
		KillTimer(PlayerTimerTaxi[playerid]);
		return PlayerTimerTaxi[playerid] = -1;
	}

	foreach(new i : Player)
	{
		if(GetPlayerVehicleID(playerid) == player_job_vehicle_arend[i])
		{
			if(PlayerInfo[playerid][pCash] < taxi_price[i])
			{
				new string[128];
				format(string, sizeof(string), "� ������ ������� ����������� ������!");
				SCM(i, blue, string);

				format(string, sizeof(string), "� ��� ����������� ������!");
				SCM(playerid, blue, string);
				return RemovePlayerFromVehicle(playerid);
			}
			if(SpeedVehicle(playerid) > 40)
			{
				GiveMoney(playerid, -taxi_price[i], "������ � �����");
				GiveMoney(i, taxi_price[i], "������ ��������");
			}
			else if(SpeedVehicle(playerid) < 5)
			{
				continue;
			}
			else
			{
				GiveMoney(playerid, floatround(-taxi_price[i]/2), "������ � �����");
				GiveMoney(i, floatround(taxi_price[i]/2), "������ ��������");	
			}
		}
	}
	return 1;
}