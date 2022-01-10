// D_SET_FSB_NUMBERS
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
        case D_FSB_ENTER_DIALOG:{
            if(!response) return 1;
            FreezePlayer(playerid, 2000);
            SetPlayerPos(playerid, fsb_office_positions[listitem][0], fsb_office_positions[listitem][1], fsb_office_positions[listitem][2]);
            SetPlayerFacingAngle(playerid,fsb_office_positions[listitem][3]);
            SetPlayerVirtualWorld(playerid, 0);
        }
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
                        if(GetPlayerWeaponAmmo(playerid, 3) >= 1)
                            return SCM(playerid, red, !"” вас уже максимальное количество патрон дл€ данного вида оружи€.");
                        GivePlayerWeaponAC(playerid, 3, 60);
                    }
                    case 1:
                    {
                        if(GetPlayerWeaponAmmo(playerid, 23) >= 10)
                            return SCM(playerid, red, !"” вас уже максимальное количество патрон дл€ данного вида оружи€.");
                        GivePlayerWeaponAC(playerid, 23, 10);
                    }
                    case 2:
                    {
                        if(GetPlayerWeaponAmmo(playerid, 24) >= 60)
                            return SCM(playerid, red, !"” вас уже максимальное количество патрон дл€ данного вида оружи€.");
                        GivePlayerWeaponAC(playerid, 24, 50);
                    }
                    case 3:
                    {
                        if(GetPlayerWeaponAmmo(playerid, 31) >= 300)
                            return SCM(playerid, red, !"” вас уже максимальное количество патрон дл€ данного вида оружи€.");
                        GivePlayerWeaponAC(playerid, 31, 150);
                    }
					case 4:{
                        if(GetPlayerWeaponAmmo(playerid, 34) >= 20)
                            return SCM(playerid, red, !"” вас уже максимальное количество патрон дл€ данного вида оружи€.");
						GivePlayerWeaponAC(playerid, 34, 10);
					}
					case 5:{
						SCM(playerid, blue, !"¬ы вз€ли бронежилет.");
						SetPlayerArmour(playerid, 100.0);
					}
					case 6:{
                        if(PlayerInfo[playerid][pMask] >= 2) return SCM(playerid, red, "¬ы не можете унести столько масок");
						SCM(playerid, blue, !"¬ы вз€ли маску.");
                        PlayerInfo[playerid][pMask]++;
					}
					case 7:{
                        if(PlayerInfo[playerid][pHeal] >= 2) return SCM(playerid, red, "¬ы не можете унести столько аптечек");
						SCM(playerid, blue, !"¬ы вз€ли аптечку.");
                        PlayerInfo[playerid][pHeal]++;
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