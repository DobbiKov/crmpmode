public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	
    if(newkeys == 1024)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 2400.3328,-1825.6747,32.5537) && IsAFSB(playerid))
        {
			SPD(playerid, D_GUN_FSB, DIALOG_STYLE_LIST, "{"cblue"}ФСБ | Оружие", "\
			{"cblue"}1. {FFFFFF}Дубинка\n\
			{"cblue"}2. {FFFFFF}Электрошокер\n\
			{"cblue"}3. {FFFFFF}Desert Eagle\n\
			{"cblue"}4. {FFFFFF}М4-А1\n\
			{"cblue"}5. {FFFFFF}Снайперская Винтовка\n\
			{"cblue"}6. {FFFFFF}Бронежилет\n\
			{"cblue"}7. {FFFFFF}Маска", "Далее", "Закрыть");
        }
        if(IsPlayerInRangeOfPoint(playerid, 5.0, 2413.72, -1841.33, 21.79))
		{
			if(!IsAFSB(playerid) && PlayerInfo[playerid][pFSBaccess] == 0) 
                return SCM(playerid, red, !"У вас нет пропуска!");

			if(fsb_door_status == false)
			{
				SCM(playerid, green, !"Вы открыли дверь");
				MoveObject(fsb_door, 2413.72, -1841.33, 21.79, 4.00,  0.00, 0.00, 90.00);
				fsb_door_status = true;
			}
			else if(fsb_door_status == true)
			{
				SCM(playerid, red, "Вы закрыли дверь");
				MoveObject(fsb_door, 2413.96, -1841.27, 21.79, 4.0,  0.00, 0.00, 180.00);
				fsb_door_status = false;
			}

		}
        if(IsPlayerInRangeOfPoint(playerid, 5.0, 2395.02, -1792.44, 22.44)) //ворота внутри двора ФСБ
		{
			CloseOpenIndoorVorota(playerid);
		}

        if(IsPlayerInRangeOfPoint(playerid, 5.0, 2445.66, -1795.02, 22.42)) //ворота снаружи двора ФСБ
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
                    SPD(playerid, D_SET_FSB_NUMBERS, DIALOG_STYLE_MSGBOX, "{"cblue"}Установка номеров", "{FFFFFF}Вы желаете установить номера на транспорт ФСБ?", "Да", "Нет");
                }
            }
        }

        if(IsPlayerInRangeOfPoint(playerid, 5.0, 2395.02, -1792.44, 22.44)) //ворота внутри двора ФСБ
		{
			CloseOpenIndoorVorota(playerid);
		}

        if(IsPlayerInRangeOfPoint(playerid, 5.0, 2445.66, -1795.02, 22.42)) //ворота снаружи двора ФСБ
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
        SCM(playerid, green, !"Вы открыли ворота");
        MoveObject(fsb_vorota_1, 2395.02, -1792.44, 25.70, 4.0,  0.00, 0.00, 0.00);
        fsb_vorota_1_status = true;
    }
    else if(fsb_vorota_1_status == true)
    {
        SCM(playerid, red, "Вы закрыли ворота");
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
        SCM(playerid, green, !"Вы открыли ворота");
        MoveObject(fsb_vorota_2, 2445.66, -1795.02, 25.68, 4.0,  0.00, 0.00, 90.00);
        fsb_vorota_2_status = true;
    }
    else if(fsb_vorota_2_status == true)
    {
        SCM(playerid, red, !"Вы закрыли ворота");
        MoveObject(fsb_vorota_2, 2445.66, -1795.02, 22.42, 4.0,  0.00, 0.00, 90.00);
        fsb_vorota_2_status = false;
    }
    return 1; //I wrote this return, to disable "warning" from PAWN.
}