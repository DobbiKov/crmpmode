public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid)
{
	if(IsAPolice(playerid))
	{
		if(weaponid == 3)
		{
			new string[128];
			format(string, sizeof(string), "�� �������� %s �� 5 ������", PlayerInfo[damagedid][pName]);
			SCM(playerid, blue, string);

			format(string, sizeof(string), "%s ������� ��� �� 5 ������", PlayerInfo[playerid][pName]);
			SCM(damagedid, blue, string);
			return FreezePlayer(damagedid, 5000);
		}
		if(weaponid == 23)
		{
			new string[128];
			format(string, sizeof(string), "�� �������� %s ��������������", PlayerInfo[damagedid][pName]);
			SCM(playerid, blue, string);

			format(string, sizeof(string), "%s ������� ��� ��������������", PlayerInfo[playerid][pName]);
			SCM(damagedid, blue, string);
			return FreezePlayer(damagedid, 10000);
		}
	}
	#if	defined	pps__OnPlayerGiveDamage
		return pps__OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerGiveDamage
	#undef	OnPlayerGiveDamage
#else
	#define	_ALS_OnPlayerGiveDamage
#endif

#define	OnPlayerGiveDamage pps__OnPlayerGiveDamage
#if	defined	pps__OnPlayerGiveDamage
	forward pps__OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid);
#endif

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
        if(job_car[TEAM_PPS_CAR][0] <= vehicleid <= job_car[TEAM_PPS_CAR][1])
        {
            if(!IsAPolice(playerid))
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "� ��� ��� ������ �� ����� ����������!");
            }
        }
	}
	#if	defined	pps__OnPlayerEnterVehicle
		return pps__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerEnterVehicle
	#undef	OnPlayerEnterVehicle
#else
	#define	_ALS_OnPlayerEnterVehicle
#endif

#define	OnPlayerEnterVehicle pps__OnPlayerEnterVehicle
#if	defined	pps__OnPlayerEnterVehicle
	forward pps__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_GUN_PPS:
        {
            if(!response) return 1;
            else
            {
                switch(listitem)
                {
                    case 0:
                    {
						if(GetPlayerWeaponAmmo(playerid, 23) >= 10)
                            return SCM(playerid, red, !"� ��� ��� ������������ ���������� ������ ��� ������� ���� ������.");
                        GivePlayerWeaponAC(playerid, 23, 10);
                    }
                    case 1:
                    {
						if(GetPlayerWeaponAmmo(playerid, 30) >= 240)
                            return SCM(playerid, red, !"� ��� ��� ������������ ���������� ������ ��� ������� ���� ������.");
                        GivePlayerWeaponAC(playerid, 30, 120);
                    }
                    case 2:
                    {
						if(GetPlayerWeaponAmmo(playerid, 3) >= 1)
                            return SCM(playerid, red, !"� ��� ��� ������������ ���������� ������ ��� ������� ���� ������.");
                        GivePlayerWeaponAC(playerid, 3, 1);
                    }
                    case 3:
                    {
                        SCM(playerid, blue, !"�� ����� ����. ������������: /stopcar");
                        SetPVarInt(playerid, "zhezl", 1);
                        SetPlayerAttachedObject(playerid, 1, 1214, 6, -0.040454, 0.028840, -0.012862, 2.521301, 76.277267, 70.163467, 0.300000, 0.300000, 0.500000);
                    }
					case 4:{
						SCM(playerid, blue, !"�� ����� ����������.");
						SetPlayerArmour(playerid, 100.0);
					}
                }
            }
        }
    }
	#if	defined	pps__OnDialogResponse
		return pps__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse pps__OnDialogResponse
#if	defined	pps__OnDialogResponse
	forward pps__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 2567.2139,-2416.3386,22.3545) && IsAPolice(playerid))
        {
			SPD(playerid, D_GUN_PPS, DIALOG_STYLE_LIST, "{"cblue"}��� | ������", "\
			{"cblue"}1. {FFFFFF}������������\n\
			{"cblue"}2. {FFFFFF}��-74�\n\
			{"cblue"}3. {FFFFFF}�������\n\
			{"cblue"}4. {FFFFFF}����\n\
			{"cblue"}5. {FFFFFF}����������", "�����", "�������");
        }
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 2759.7024, -1385.3208, 24.1169))
		{
			if(!IsAPolice(playerid) && PlayerInfo[playerid][bAdmin] < 3) return 1;

			if(post_dps_1_status == false)
			{
				SCM(playerid, red, !"�� ������� ��������");
				MoveObject(post_dps_1, 2747.48, -1382.81, 23.44, 4.0,  0.00, 90.00, 0.00);
				post_dps_1_status = true;
			}
			else if(post_dps_1_status == true)
			{
				SCM(playerid, green, !"�� ������� ��������");
				MoveObject(post_dps_1, 2747.48, -1382.81, 23.44, 4.0, 0.00, 0.00, 0.00);
				post_dps_1_status = false;
			}

		}
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 2735.4485, -1380.7979, 24.1169))
		{
			if(!IsAPolice(playerid) && PlayerInfo[playerid][bAdmin] < 3) return 1;

			if(post_dps_2_status == false)
			{
				SCM(playerid, red, !"�� ������� ��������");
				MoveObject(post_dps_2, 2746.83, -1382.82, 23.37, 4.0, 0.00, -90.00, 0.00);
				post_dps_2_status = true;
			}
			else if(post_dps_2_status == true)
			{
				SCM(playerid, green, !"�� ������� ��������");
				MoveObject(post_dps_2, 2746.83, -1382.82, 23.37, 4.0, 0.00, 0.00, 0.00);//2
				post_dps_2_status = false;
			}

		}

		if(IsPlayerInRangeOfPoint(playerid, 2.0, 1539.4611,2968.5437,12.6569))
		{
			if(!IsAPolice(playerid) && PlayerInfo[playerid][bAdmin] < 3) return 1;

			if(post_batyrevo_arzamas_1_status == false)
			{
				SCM(playerid, red, !"�� ������� ��������");
				MoveObject(post_batyrevo_arzamas_1, 1553.36, 2967.01, 11.69, 4.00, 0.00, -90.00, 90.00);
				post_batyrevo_arzamas_1_status = true;
			}
			else if(post_batyrevo_arzamas_1_status == true)
			{
				SCM(playerid, green, !"�� ������� ��������");
				MoveObject(post_batyrevo_arzamas_1,  1553.36, 2967.01, 11.69, 4.00, 0.00, 0.00, 90.00);//2
				post_batyrevo_arzamas_1_status = false;
			}

		}

		if(IsPlayerInRangeOfPoint(playerid, 2.0, 1538.7238,2951.9695,12.6569))
		{
			if(!IsAPolice(playerid) && PlayerInfo[playerid][bAdmin] < 3) return 1;

			if(post_batyrevo_arzamas_2_status == false)
			{
				SCM(playerid, red, !"�� ������� ��������");
				MoveObject(post_batyrevo_arzamas_2,   1524.45, 2952.78, 11.69, 4.00, 0.00, 90.00, 90.00);
				post_batyrevo_arzamas_2_status = true;
			}
			else if(post_batyrevo_arzamas_2_status == true)
			{
				SCM(playerid, green, !"�� ������� ��������");
				MoveObject(post_batyrevo_arzamas_2,  1524.45, 2952.78, 11.69, 4.00, 0.00, 0.00, 90.00);//2
				post_batyrevo_arzamas_2_status = false;
			}

		}
    }
	if(newkeys == KEY_CROUCH)
	{
		cmd::open(playerid);
	}
	#if	defined	pps__OnPlayerKeyStateChange
		return pps__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange pps__OnPlayerKeyStateChange
#if	defined	pps__OnPlayerKeyStateChange
	forward pps__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif