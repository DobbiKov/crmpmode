// D_SET_FSB_NUMBERS
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case D_SET_FSB_NUMBERS:{
            new vehicleid = GetPlayerVehicleID(playerid);
            if(response)
            {
                new number[32];
                for(new i = 0; i != 6; i++)
                {
                    if(!i) number[i] = random('M' - 'A') + 'A';
                    if(i >= 1 && i <= 3) number[i] = random('9' - '0') + '0';
                    if(i > 3) number[i] = random('M' - 'A') + 'A';
                }
                DestroyDynamic3DTextLabel(fsb_car_number_labels[vehicleid]);
                fsb_car_number_labels[vehicleid] = CreateDynamic3DTextLabel(number, 0xFFFFFFFF, 0.0, 0.0, 0.0, 15.0, INVALID_PLAYER_ID, vehicleid);
            }
            else{
                DestroyDynamic3DTextLabel(fsb_car_number_labels[vehicleid]);
            }
        }
		case D_GUN_FSB:{
            if(response)
            {
                switch(listitem)
                {
                    case 0:
                    {
                        GivePlayerWeaponAC(playerid, 3, 60);
                    }
                    case 1:
                    {
                        GivePlayerWeaponAC(playerid, 23, 120);
                    }
                    case 2:
                    {
                        GivePlayerWeaponAC(playerid, 24, 50);
                    }
                    case 3:
                    {
                        GivePlayerWeaponAC(playerid, 31, 150);
                    }
					case 4:{
						GivePlayerWeaponAC(playerid, 34, 10);
					}
					case 5:{
						SCM(playerid, blue, !"Вы взяли бронежилет.");
						SetPlayerArmour(playerid, 100.0);
					}
					case 6:{
                        if(PlayerInfo[playerid][pMask] >= 2) return SCM(playerid, red, "Вы не можете унести столько масок");
						SCM(playerid, blue, !"Вы взяли маску.");
                        PlayerInfo[playerid][pMask]++;
					}
                }
            }
        }
	}
	#if	defined	fsb__OnDialogResponse
		return fsb__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse fsb__OnDialogResponse
#if	defined	fsb__OnDialogResponse
	forward fsb__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif