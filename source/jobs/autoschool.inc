static
	Float: coord_exam[][3] =
	{
	    {1900.8645,2246.9185,15.7139},
	    {1887.3710,2234.1155,15.9526},
	    {1812.2502,2229.4512,15.8299},
	    {1767.7695,2182.2048,16.0229},
	    {1768.1252,2099.5193,16.0256},
	    {1897.6904,2053.0505,15.8772},
	    {1962.0665,2024.2561,15.8934},
	    {1961.3899,1932.3246,15.5232},
	    {2015.4318,1902.5724,15.7642},
	    {2152.4326,1904.7816,15.9052},
	    {2311.6511,1905.1666,15.9277},
	    {2411.7380,1894.4161,15.7045},
	    {2621.6543,1894.2843,16.2632},
	    {2762.4751,2048.6665,17.8023},
	    {2764.9043,2114.3000,17.9937},
	    {2753.1733,2381.4368,15.6969},
	    {2715.2339,2599.9829,15.9807},
	    {2690.4092,2726.3848,17.4332},
	    {2509.3948,2934.0823,24.2594},
	    {2218.9395,2968.1694,12.0910},
	    {2091.2639,2962.8284,12.0685},
	    {2058.8801,2881.8621,13.4363},
	    {1917.3143,2687.9778,15.1904},
	    {1771.4794,2555.7429,15.1725},
	    {1791.0187,2447.4050,15.9530},
	    {1850.5253,2357.6616,15.9530},
	    {1885.9377,2271.0728,15.9526},
	    {1903.1064,2246.7146,15.7141},
	    {1914.1827,2246.4639,15.7139} // 29
	};
new autoschool_car[MAX_PLAYERS];

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{

    if(newkeys == 1024)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 131.3660,1368.7767,1002.9600))
        {
			if(PlayerInfo[playerid][pFines] >= 1) return SCM(playerid, red, "� ��� ���� ����������� ������. �������� �� � ��������� ���������.");
			SPD(playerid, D_EXAM_DRIVING, DIALOG_STYLE_LIST, "{"cblue"}����� ��������", "\
			{FFFFFF}��������� A\t\t\t{"cblue"}4000 ������\n\
			{FFFFFF}��������� B\t\t\t{"cblue"}5000 ������\n\
			{FFFFFF}��������� C\t\t\t{"cblue"}5500 ������\n\
			{FFFFFF}��������� D\t\t\t{"cblue"}6500 ������", "�����", "�������");
        }
    }
	#if	defined	ah__OnPlayerKeyStateChange
		return ah__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange ah__OnPlayerKeyStateChange
#if	defined	ah__OnPlayerKeyStateChange
	forward ah__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	if(GetPVarInt(playerid, "lesson") == 1)
	{
		SCM(playerid, red, "� ���������, �� ��������� ������� �� ��������.");
		DisablePlayerRaceCheckpoint(playerid);
		DeletePVar(playerid, "lesson");
		DestroyVehicle(autoschool_car[playerid]);
		autoschool_car[playerid] = -1;
		SetPlayerVirtualWorld(playerid, 0);
	}
	if(GetPVarInt(playerid, "lesson") == 2)
	{
		SCM(playerid, red, "� ���������, �� ��������� ������� �� ��������.");
		DisablePlayerRaceCheckpoint(playerid);
		DeletePVar(playerid, "lesson");
		DestroyVehicle(autoschool_car[playerid]);
		autoschool_car[playerid] = -1;
		SetPlayerVirtualWorld(playerid, 0);
	}
	if(GetPVarInt(playerid, "lesson") == 3)
	{
		SCM(playerid, red, "� ���������, �� ��������� ������� �� ��������.");
		DisablePlayerRaceCheckpoint(playerid);
		DeletePVar(playerid, "lesson");
		DestroyVehicle(autoschool_car[playerid]);
		autoschool_car[playerid] = -1;
		SetPlayerVirtualWorld(playerid, 0);
	}
	if(GetPVarInt(playerid, "lesson") == 4)
	{
		SCM(playerid, red, "� ���������, �� ��������� ������� �� ��������.");
		DisablePlayerRaceCheckpoint(playerid);
		DeletePVar(playerid, "lesson");
		DestroyVehicle(autoschool_car[playerid]);
		autoschool_car[playerid] = -1;
		SetPlayerVirtualWorld(playerid, 0);
	}
	#if	defined	ah__OnPlayerDisconnect
		return ah__OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerDisconnect
	#undef	OnPlayerDisconnect
#else
	#define	_ALS_OnPlayerDisconnect
#endif

#define	OnPlayerDisconnect ah__OnPlayerDisconnect
#if	defined	ah__OnPlayerDisconnect
	forward ah__OnPlayerDisconnect(playerid, reason);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
		case D_EXAM_DRIVING:
		{
		    if(!response) return 1;
		    else
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
						if(PlayerInfo[playerid][pCash] < 4000) return SCM(playerid, red, "� ��� ������������ �����!");
						if(PlayerInfo[playerid][pLicA] == 1) return SCM(playerid, red, "� ��� ���� ����� ��������� �!");
						if(GetPVarInt(playerid, "lesson") != 0) return SCM(playerid, red, "� ������ ������ �� ������ �����-�� �������!");
						
						GiveMoney(playerid, -4000, "����� ��������");
      					SCM(playerid, green, "�� ������ ������������ ����� ����� �������� �� ��������.");
		                SCM(playerid, green, "������� �� ���� � ������ � ��������.");
		                
		                SetPVarInt(playerid, "lesson", 1);
		            }
		            case 1:
		            {
                        if(PlayerInfo[playerid][pCash] < 5000) return SCM(playerid, red, "� ��� ������������ �����!");
                        if(PlayerInfo[playerid][pLicB] == 1) return SCM(playerid, red, "� ��� ���� ����� ��������� B!");
						if(GetPVarInt(playerid, "lesson") != 0) return SCM(playerid, red, "� ������ ������ �� ������ �����-�� �������!");

						GiveMoney(playerid, -5000, "����� ��������");
                        SCM(playerid, green, "�� ������ ������������ ����� ����� �������� �� ��������.");
		                SCM(playerid, green, "������� �� ���� � ������ � ����������.");
		                
		                SetPVarInt(playerid, "lesson", 2);
		            }
		            case 2:
		            {
		                if(PlayerInfo[playerid][pCash] < 5500) return SCM(playerid, red, "� ��� ������������ �����!");
		                if(PlayerInfo[playerid][pLicC] == 1) return SCM(playerid, red, "� ��� ���� ����� ��������� C!");
						if(GetPVarInt(playerid, "lesson") != 0) return SCM(playerid, red, "� ������ ������ �� ������ �����-�� �������!");

						GiveMoney(playerid, -5500, "����� ��������");
		                SCM(playerid, green, "�� ������ ������������ ����� ����� �������� �� ��������.");
		                SCM(playerid, green, "������� �� ���� � ������ � ��������.");
		                
		                SetPVarInt(playerid, "lesson", 3);
		            }
		            case 3:
		            {
		                if(PlayerInfo[playerid][pCash] < 6500) return SCM(playerid, red, "� ��� ������������ �����!");
		                if(PlayerInfo[playerid][pLicD] == 1) return SCM(playerid, red, "� ��� ���� ����� ��������� D!");
						if(GetPVarInt(playerid, "lesson") != 0) return SCM(playerid, red, "� ������ ������ �� ������ �����-�� �������!");

						GiveMoney(playerid, -6500, "����� ��������");
		                SCM(playerid, green, "�� ������ ������������ ����� ����� �������� �� ��������.");
		                SCM(playerid, green, "������� �� ���� � ������ � �������.");
		                
		                SetPVarInt(playerid, "lesson", 4);
		            }
		        }
		    }
		}
    }
	#if	defined	ah__OnDialogResponse
		return ah__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse ah__OnDialogResponse
#if	defined	ah__OnDialogResponse
	forward ah__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
    	new newcar = vehicleid;
        if(job_car[CATEG_A_CAR][0] <= newcar <= job_car[CATEG_A_CAR][1])
        {
			if(GetPVarInt(playerid, "lesson") != 1)
			{
				ClearAnimations(playerid, true);
			    return SCM(playerid, red, "���� ���������, ������������, ��� ����� �������� �� ��������� A!");
			}
        }
        if(job_car[CATEG_B_CAR][0] <= newcar <= job_car[CATEG_B_CAR][1])
        {
			if(GetPVarInt(playerid, "lesson") != 2)
			{
			    ClearAnimations(playerid, true);
			    return SCM(playerid, red, "���� ���������, ������������, ��� ����� �������� �� ��������� B!");
			}
        }
        if(job_car[CATEG_C_CAR][0] <= newcar <= job_car[CATEG_C_CAR][1])
        {
			if(GetPVarInt(playerid, "lesson") != 3)
			{
			    ClearAnimations(playerid, true);
			    return SCM(playerid, red, "���� ���������, ������������, ��� ����� �������� �� ��������� C!");
			}
        }
        if(newcar == job_car[CATEG_D_CAR][0])
        {
			if(GetPVarInt(playerid, "lesson") != 4)
			{
			    ClearAnimations(playerid, true);
			    return SCM(playerid, red, "���� ���������, ������������, ��� ����� �������� �� ��������� D!");
			}
        }
        if(IsAMoped(newcar) && PlayerInfo[playerid][pLicA] != 1)
        {
            if(GetPVarInt(playerid, "lesson") == 1) return 1;
            else
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "� ��� ��� ���� ��������� A!");
            }
        }
        if(IsACar(newcar) && PlayerInfo[playerid][pLicB] != 1)
        {
            if(GetPVarInt(playerid, "lesson") == 2) return 1;
            else
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "� ��� ��� ���� ��������� B!");
            }
        }
        if(IsATruck(newcar) && PlayerInfo[playerid][pLicC] != 1)
        {
            if(GetPVarInt(playerid, "lesson") == 3) return 1;
            else
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "� ��� ��� ���� ��������� C!");
            }
        }
        if(IsABus(newcar) && PlayerInfo[playerid][pLicD] != 1)
        {
            if(GetPVarInt(playerid, "lesson") == 4) return 1;
            else
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "� ��� ��� ���� ��������� D!");
            }
        }
        if(IsAPlane(newcar) && PlayerInfo[playerid][pLicFly] != 1)
        {
			ClearAnimations(playerid, true);
			return SCM(playerid, red, "� ��� ��� �������� �� �����!");
        }
	}
	#if	defined	ah__OnPlayerEnterVehicle
		return ah__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerEnterVehicle
	#undef	OnPlayerEnterVehicle
#else
	#define	_ALS_OnPlayerEnterVehicle
#endif

#define	OnPlayerEnterVehicle ah__OnPlayerEnterVehicle
#if	defined	ah__OnPlayerEnterVehicle
	forward ah__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif

public OnPlayerExitVehicle(playerid, vehicleid)
{
	new newcar = vehicleid;

	if(GetPVarInt(playerid, "lesson") > 0 && newcar == autoschool_car[playerid])
	{
		SCM(playerid, red, "� ���������, �� ��������� ������� �� ��������.");
		DisablePlayerRaceCheckpoint(playerid);
		DeletePVar(playerid, "lesson");
		DestroyVehicle(autoschool_car[playerid]);
		autoschool_car[playerid] = -1;
		SetPlayerVirtualWorld(playerid, 0);
	}
	#if	defined	ah__OnPlayerExitVehicle
		return ah__OnPlayerExitVehicle(playerid, vehicleid);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerExitVehicle
	#undef	OnPlayerExitVehicle
#else
	#define	_ALS_OnPlayerExitVehicle
#endif

#define	OnPlayerExitVehicle ah__OnPlayerExitVehicle
#if	defined	ah__OnPlayerExitVehicle
	forward ah__OnPlayerExitVehicle(playerid, vehicleid);
#endif

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	new newcar = GetPlayerVehicleID(playerid);
	if(job_car[CATEG_A_CAR][0] <= newcar <= job_car[CATEG_A_CAR][1])
	{
		if(GetPVarInt(playerid, "lesson") != 1)
		{
			ClearAnimations(playerid, true);
			return SCM(playerid, red, "���� ���������, ������������, ��� ����� �������� �� ��������� A!");
		}
		else
		{
			SetPlayerVirtualWorld(playerid, playerid + 1000);
			autoschool_car[playerid] = CreateVehicle(461, 1939.1744,2246.4094,15.3708,89.9513,3,3, 86400);
			SetVehicleVirtualWorld(autoschool_car[playerid], GetPlayerVirtualWorld(playerid));
			PutPlayerInVehicle(playerid, autoschool_car[playerid], 0);
			vehicle[ autoschool_car[playerid] ][veh_fuel] = 80.0;
			SCM(playerid, blue, "��� ����� ��������, �������� �� �������� �������� ���. ��������! �� ������� ��� ����� {"cyellow"}10 �����{"cblue"}!");
			pPressed[playerid] = 0;
			SetPlayerRaceCheckpoint(playerid, 0, coord_exam[pPressed[playerid]][0], coord_exam[pPressed[playerid]][1], coord_exam[pPressed[playerid]][2], coord_exam[pPressed[playerid]+1][0], coord_exam[pPressed[playerid]+1][1], coord_exam[pPressed[playerid]+1][2], 5.0);
			pCheckpoint[playerid] = CP_EXAM_DRIVING;
		}
	}
	if(job_car[CATEG_B_CAR][0] <= newcar <= job_car[CATEG_B_CAR][1])
	{
		if(GetPVarInt(playerid, "lesson") != 2)
		{
			ClearAnimations(playerid, true);
			return SCM(playerid, red, "���� ���������, ������������, ��� ����� �������� �� ��������� B!");
		}
		else
		{
			SetPlayerVirtualWorld(playerid, playerid + 1000);
			autoschool_car[playerid] = CreateVehicle(516, 1924.2289,2228.1021,15.7298,0.5742,3,0, 86400);
			SetVehicleVirtualWorld(autoschool_car[playerid], GetPlayerVirtualWorld(playerid));
			PutPlayerInVehicle(playerid, autoschool_car[playerid], 0);
			vehicle[ autoschool_car[playerid] ][veh_fuel] = 80.0;
			SCM(playerid, blue, "��� ����� ��������, �������� �� �������� �������� ���. ��������! �� ������� ��� ����� {"cyellow"}10 �����{"cblue"}!");
			pPressed[playerid] = 0;
			SetPlayerRaceCheckpoint(playerid, 0, coord_exam[pPressed[playerid]][0], coord_exam[pPressed[playerid]][1], coord_exam[pPressed[playerid]][2], coord_exam[pPressed[playerid]+1][0], coord_exam[pPressed[playerid]+1][1], coord_exam[pPressed[playerid]+1][2], 5.0);
			pCheckpoint[playerid] = CP_EXAM_DRIVING;
		}
	}
	if(job_car[CATEG_C_CAR][0] <= newcar <= job_car[CATEG_C_CAR][1])
	{
		if(GetPVarInt(playerid, "lesson") != 3)
		{
			ClearAnimations(playerid, true);
			return SCM(playerid, red, "���� ���������, ������������, ��� ����� �������� �� ��������� C!");
		}
		else
		{
			SetPlayerVirtualWorld(playerid, playerid + 1000);
			autoschool_car[playerid] = CreateVehicle(515, 1934.4994,2250.3352,16.3538,89.8652,3,3, 86400);
			SetVehicleVirtualWorld(autoschool_car[playerid], GetPlayerVirtualWorld(playerid));
			PutPlayerInVehicle(playerid, autoschool_car[playerid], 0);
			vehicle[ autoschool_car[playerid] ][veh_fuel] = 80.0;
			SCM(playerid, blue, "��� ����� ��������, �������� �� �������� �������� ���. ��������! �� ������� ��� ����� {"cyellow"}10 �����{"cblue"}!");
			pPressed[playerid] = 0;
			SetPlayerRaceCheckpoint(playerid, 0, coord_exam[pPressed[playerid]][0], coord_exam[pPressed[playerid]][1], coord_exam[pPressed[playerid]][2], coord_exam[pPressed[playerid]+1][0], coord_exam[pPressed[playerid]+1][1], coord_exam[pPressed[playerid]+1][2], 5.0);
			pCheckpoint[playerid] = CP_EXAM_DRIVING;
		}
	}
	if(newcar == job_car[CATEG_D_CAR][0])
	{
		if(GetPVarInt(playerid, "lesson") != 4)
		{
			ClearAnimations(playerid, true);
			return SCM(playerid, red, "���� ���������, ������������, ��� ����� �������� �� ��������� D!");
		}
		else
		{
			SetPlayerVirtualWorld(playerid, playerid + 1000);
			autoschool_car[playerid] = CreateVehicle(483, 1909.6436,2235.8845,15.9755,359.6084,3,3, 86400);
			SetVehicleVirtualWorld(autoschool_car[playerid], GetPlayerVirtualWorld(playerid));
			PutPlayerInVehicle(playerid, autoschool_car[playerid], 0);
			vehicle[ autoschool_car[playerid] ][veh_fuel] = 80.0;
			SCM(playerid, blue, "��� ����� ��������, �������� �� �������� �������� ���. ��������! �� ������� ��� ����� {"cyellow"}10 �����{"cblue"}!");
			pPressed[playerid] = 0;
			SetPlayerRaceCheckpoint(playerid, 0, coord_exam[pPressed[playerid]][0], coord_exam[pPressed[playerid]][1], coord_exam[pPressed[playerid]][2], coord_exam[pPressed[playerid]+1][0], coord_exam[pPressed[playerid]+1][1], coord_exam[pPressed[playerid]+1][2], 5.0);
			pCheckpoint[playerid] = CP_EXAM_DRIVING;
		}
	}
    if(newstate == PLAYER_STATE_PASSENGER)
    {
	    if(job_car[CATEG_A_CAR][0] <= newcar <= job_car[CATEG_A_CAR][1] || job_car[CATEG_B_CAR][0] <= newcar <= job_car[CATEG_B_CAR][1] || job_car[CATEG_C_CAR][0] <= newcar <= job_car[CATEG_C_CAR][1] || job_car[CATEG_D_CAR][0] <= newcar <= job_car[CATEG_D_CAR][1])
	    {
			RemovePlayerFromVehicle(playerid);
			return SCM(playerid, red, "���� ���������� ������������, ��� ����� �������� �� ��������!");
	    }
    }
    if(oldstate == PLAYER_STATE_DRIVER)
    {
		if(GetPVarInt(playerid, "lesson") > 0 && newcar == autoschool_car[playerid])
		{
		    SCM(playerid, red, "� ���������, �� ��������� ������� �� ��������.");
		    DisablePlayerRaceCheckpoint(playerid);
			DeletePVar(playerid, "lesson");
			DestroyVehicle(autoschool_car[playerid]);
			autoschool_car[playerid] = -1;
			SetPlayerVirtualWorld(playerid, 0);
		}
    }
    #if defined ah__OnPlayerStateChange
        return ah__OnPlayerStateChange(playerid, newstate, oldstate);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_OnPlayerStateChange
	#undef	OnPlayerStateChange
#else
	#define	_ALS_OnPlayerStateChange
#endif

#define	OnPlayerStateChange ah__OnPlayerStateChange
#if	defined	ah__OnPlayerStateChange
	forward ah__OnPlayerStateChange(playerid, newstate, oldstate); 
#endif

public OnPlayerEnterRaceCheckpoint(playerid)
{
    switch(pCheckpoint[playerid])
    {
		case CP_EXAM_DRIVING:
		{
  			pPressed[playerid]++;
  			new i = pPressed[playerid];
  			DisablePlayerRaceCheckpoint(playerid);
  			if(i != 28)
  			{
			    SetPlayerRaceCheckpoint(playerid, 0, coord_exam[i][0], coord_exam[i][1], coord_exam[i][2], coord_exam[i+1][0], coord_exam[i+1][1], coord_exam[i+1][2], 5.0);
			    pCheckpoint[playerid] = CP_EXAM_DRIVING;
			}
			else if(i == 28)
			{
				new Float: veh_health;
				GetVehicleHealth(GetPlayerVehicleID(playerid), veh_health);

				if(veh_health >= 900)
				{
					switch(GetPVarInt(playerid, "lesson"))
					{
					    case 1:
						{
						    SCM(playerid, green, "�����������! �� ������� ����� �� ����� ��������� A.");
							PlayerInfo[playerid][pLicA] = 1;
						}
						case 2:
						{
						    SCM(playerid, green, "�����������! �� ������� ����� �� ����� ��������� B.");
							PlayerInfo[playerid][pLicB] = 1;
						}
					    case 3:
						{
						    SCM(playerid, green, "�����������! �� ������� ����� �� ����� ��������� C.");
							PlayerInfo[playerid][pLicC] = 1;
						}
					    case 4:
						{
						    SCM(playerid, green, "�����������! �� ������� ����� �� ����� ��������� D.");
							PlayerInfo[playerid][pLicD] = 1;
						}
					}
				}
				else
				{
				    SCM(playerid, red, "� ��������� �� ��������� ������� �� ��������!");
				}
				SaveAccounts(playerid);
				DestroyVehicle(autoschool_car[playerid]);
				autoschool_car[playerid] = -1;
				DeletePVar(playerid, "lesson");
				SetPlayerVirtualWorld(playerid, 0);
			}
		}
    }
    #if defined ah_OnPlayerEnterRaceCheckpoint
        return ah_OnPlayerEnterRaceCheckpoint(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerEnterRaceCheckpoin || defined _ALS_OnPlayerEnterRaceCP
	#undef OnPlayerEnterRaceCheckpoint
#else
	#define _ALS_OnPlayerEnterRaceCheckpoin
	#define _ALS_OnPlayerEnterRaceCP
#endif

#define OnPlayerEnterRaceCheckpoint ah_OnPlayerEnterRaceCheckpoint
#if defined ah_OnPlayerEnterRaceCheckpoint
    forward ah_OnPlayerEnterRaceCheckpoint(playerid);
#endif