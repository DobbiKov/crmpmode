public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	
    if(newkeys == 1024)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1230.8363,1514.2933,2516.6799) && IsAFSB(playerid))
        {
			SPD(playerid, D_GUN_FSB, DIALOG_STYLE_LIST, "{"cblue"}��� | ������", "\
			{"cblue"}1. {FFFFFF}�������\n\
			{"cblue"}2. {FFFFFF}������������\n\
			{"cblue"}3. {FFFFFF}Desert Eagle\n\
			{"cblue"}4. {FFFFFF}�4-�1\n\
			{"cblue"}5. {FFFFFF}����������� ��������\n\
			{"cblue"}6. {FFFFFF}����������\n\
			{"cblue"}7. {FFFFFF}�����\n\
            {"cblue"}8. {FFFFFF}�������", "�����", "�������");
        }

        if(IsPlayerInRangeOfPoint(playerid, 3.0, 1210.27, 1524.17, 2515.68)) //3
		{
			if(!IsAFSB(playerid)) 
                return SCM(playerid, red, !"� ��� ��� ��������!");

			if(fsb_dopros_door_3_status == false)
			{
				SCM(playerid, green, !"�� ������� �����");
				MoveObject(fsb_dopros_door_3, 1210.27, 1524.17, 2515.68, 0.16,  0.02, 0.00, 0.00);
				fsb_dopros_door_3_status = true;
			}
			else if(fsb_dopros_door_3_status == true)
			{
				SCM(playerid, red, "�� ������� �����");
				MoveObject(fsb_dopros_door_3, 1210.27, 1524.17, 2515.68, 0.16, 0.02, 0.00, 90.00);
				fsb_dopros_door_3_status = false;
			}

		}
        if(IsPlayerInRangeOfPoint(playerid, 5.0, 2395.02, -1792.44, 22.44)) //������ ������ ����� ���
		{
			CloseOpenIndoorVorota(playerid);
		}

        if(IsPlayerInRangeOfPoint(playerid, 5.0, 2445.66, -1795.02, 22.42)) //������ ������� ����� ���
		{
			CloseOpenOutdoorVorota(playerid);
		}
        
    }
    if(newkeys == KEY_CROUCH)
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
            new vehicleid = GetPlayerVehicleID(playerid);

            if(job_car[TEAM_FSB_CAR][0] <= vehicleid <= job_car[TEAM_FSB_CAR][1])
            {
                if(IsPlayerInRangeOfPoint(playerid, 5.0, 2428.5806,-1832.4991,19.0850) && IsAFSB(playerid))
                {
                    SPD(playerid, D_SET_FSB_NUMBERS, DIALOG_STYLE_MSGBOX, "{"cblue"}��������� �������", "{FFFFFF}�� ������� ���������� ������ �� ��������� ���?", "��", "���");
                }
            }
        }

        if(IsPlayerInRangeOfPoint(playerid, 5.0, 2395.02, -1792.44, 22.44)) //������ ������ ����� ���
		{
			CloseOpenIndoorVorota(playerid);
		}

        if(IsPlayerInRangeOfPoint(playerid, 5.0, 2445.66, -1795.02, 22.42)) //������ ������� ����� ���
		{
			CloseOpenOutdoorVorota(playerid);
		}
    }
	#if	defined	fsb__OnPlayerKeyStateChange
		return fsb__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange fsb__OnPlayerKeyStateChange
#if	defined	fsb__OnPlayerKeyStateChange
	forward fsb__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

stock CloseOpenIndoorVorota(playerid)
{
    if(!IsAFSB(playerid)) return 1;

    if(fsb_vorota_1_status == false)
    {
        SCM(playerid, green, !"�� ������� ������");
        MoveObject(fsb_vorota_1, 2395.02, -1792.44, 25.70, 4.0,  0.00, 0.00, 0.00);
        fsb_vorota_1_status = true;
    }
    else if(fsb_vorota_1_status == true)
    {
        SCM(playerid, red, "�� ������� ������");
        MoveObject(fsb_vorota_1, 2395.02, -1792.44, 22.44, 4.0,  0.00, 0.00, 0.00);
        fsb_vorota_1_status = false;
    }   
    return 1; //I wrote this return, to disable "warning" from PAWN.
}
stock CloseOpenOutdoorVorota(playerid)
{
    if(!IsAFSB(playerid)) return 1;

    if(fsb_vorota_2_status == false)
    {
        SCM(playerid, green, !"�� ������� ������");
        MoveObject(fsb_vorota_2, 2445.66, -1795.02, 25.68, 4.0,  0.00, 0.00, 90.00);
        fsb_vorota_2_status = true;
    }
    else if(fsb_vorota_2_status == true)
    {
        SCM(playerid, red, !"�� ������� ������");
        MoveObject(fsb_vorota_2, 2445.66, -1795.02, 22.42, 4.0,  0.00, 0.00, 90.00);
        fsb_vorota_2_status = false;
    }
    return 1; //I wrote this return, to disable "warning" from PAWN.
}