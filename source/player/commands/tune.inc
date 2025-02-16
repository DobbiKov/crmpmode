enum e_DISKS_INFO
{
    diskName[50],
    diskID,
};

new stock disk_tune[][e_DISKS_INFO] = 
{
    {"Shadow", 1073},
    {"Mega", 1074},
    {"Wires", 1076},
    {"Classic", 1077},
    {"Twist", 1078},
    {"Cutter", 1079},
    {"Grove", 1081},
    {"Atomic", 1085},
    {"Dollar", 1083},
    {"Switch", 1080}
};

CMD:tune(playerid)
{
    if(player_in_business[playerid] == -1) return SCM(playerid, red, "�� �� ���������� � ���!");
    if(!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SCM(playerid, red, "�� ������ ��������� �� ����� ����������!");
    new i = player_in_business[playerid];
    if(BusinessInfo[i][bType] != b_type_REPAIR) return SCM(playerid, red, "�� �� ���������� � ���!");
    if(IsPlayerInRangeOfPoint(playerid, 10.0, business_params[ BusinessInfo[i][bType] ][coord_menu_x], business_params[ BusinessInfo[i][bType] ][coord_menu_y], business_params[ BusinessInfo[i][bType] ][coord_menu_z]))
    {
        new fmt_dialog[528];
        format(fmt_dialog, sizeof(fmt_dialog), "\
        {"cblue"}1. {FFFFFF}��������� ����  {"cblue"}5000 ������\n\
        {"cblue"}2. {FFFFFF}��������� �����  {"cblue"}4000 ������\n\
        {"cblue"}3. {FFFFFF}����������� ����  {"cblue"}1000 ������\n\
        {"cblue"}4. {FFFFFF}������ ������ � ���� {"cblue"}1500 ������\n\
        {"cblue"}5. {FFFFFF}��������������� ����  {"cblue"}%d ������", BusinessInfo[i][bRepairPrice]);
        SPD(playerid, D_TUNE, DIALOG_STYLE_LIST, "{"cblue"}���", fmt_dialog, "�����", "�������");
    }
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_TUNE_DISKS:
        {
            if(!response) return cmd::tune(playerid);
            else
            {
                if(PlayerInfo[playerid][pCash] < 4000) return SCM(playerid, red, "� ��� �� ���������� �����.");

                ownable_car[GetPlayerVehicleID(playerid)][tun_weels] = disk_tune[listitem][diskID];
                AddVehicleComponent(GetPlayerVehicleID(playerid),ownable_car[GetPlayerVehicleID(playerid)][tun_weels]);
                SaveOwnableCar(playerid);
                GiveMoney(playerid, -4000, "������� ������ ���");
                GiveBusinessMoney(player_in_business[playerid], 4000, playerid);
                return SCM(playerid, blue, "�� ��������� {"cyellow"}����� {"cblue"}�� {"cyellow"}4000 ������{"cblue"}.");
            }
        }
        case D_TUNE_CHANGE_COLOR:
        {
            if(!response) return cmd::tune(playerid);
            else
            {
				new color[2];
				
				if(sscanf(inputtext, "p<,>d, d", color[0], color[1]))
                {
                    ShowPlayerDialog
                    (
                        playerid, D_TUNE_CHANGE_COLOR, DIALOG_STYLE_INPUT,
                        "{"cblue"}���������� ����",
                        "{ffffff}������� ���� � �������: ����, ����. ������: 1, 1",
                        "�����������", "������"
                    );  
                    return 1;
                }
				
				new vehicleid = GetPlayerVehicleID(playerid);
				
				if(player_ownable_car[playerid] != vehicleid) return SCM(playerid, red, "�� ������ ���������� � ���� ������ ����.");
						
				if(PlayerInfo[playerid][pCash] < 1000) return SCM(playerid, red, "� ��� �� ���������� �����.");
				
				
				if(!(0 <= color[0] <= 255) || !(0 <= color[1] <= 255))
				{
					SCM(playerid, red, "ID ����� �� 0 �� 255.");
					
                    ShowPlayerDialog
                    (
                        playerid, D_TUNE_CHANGE_COLOR, DIALOG_STYLE_INPUT,
                        "{"cblue"}���������� ����",
                        "{ffffff}������� ���� � �������: ����, ����. ������: 1, 1",
                        "�����������", "������"
                    );  
					return 1;
				}

                GiveMoney(playerid, -1000, "���������� ���� � ���");
				GiveBusinessMoney(player_in_business[playerid], 1000, playerid);
				UpdateBusiness(player_in_business[playerid]);
				
				ownable_car[vehicleid][oc_color_1] = color[0];
				ownable_car[vehicleid][oc_color_2] = color[1];
				
				ChangeVehicleColor(vehicleid, color[0], color[1]);
				SCM(playerid, blue, "�� ������� ����������� ��� ���� �� {"cyellow"}1000 ������{"cblue"}.");
            }
        }
		case D_TUNE:
		{
            if(!response) return 1;
            else
            {
                switch(listitem)
                {
                    case 0:
                    {
                        if(GetPlayerVehicleID(playerid) != player_ownable_car[playerid]) return SCM(playerid, red, "�� ������ ��������� � ������ ����������.");
                        if(PlayerInfo[playerid][pCash] < 5000) return SCM(playerid, red, "� ��� �� ���������� �����.");

                        GiveMoney(playerid, -5000, "������� ������ ���");
                        GiveBusinessMoney(player_in_business[playerid], 5000, playerid);

                        AddVehicleComponent(GetPlayerVehicleID(playerid),1010);
                        ownable_car[GetPlayerVehicleID(playerid)][tun_nitro] = 1010;
                        SaveOwnableCar(playerid);
                        return SCM(playerid, blue, "�� ������ {"cyellow"}Nitro {"cblue"}�� {"cyellow"}5000 ������{"cblue"}.");
                    }
                    case 1:
                    {
                        if(GetPlayerVehicleID(playerid) != player_ownable_car[playerid]) return SCM(playerid, red, "�� ������ ��������� � ������ ����������.");

                        new fmt_dialog[528], string[180];
                        for(new i = 0; i < sizeof(disk_tune); i++)
                        {
                            format(string, sizeof(string), "{"cblue"}%d. {FFFFFF}%s\n", i+1, disk_tune[i][diskName]);
                            strcat(fmt_dialog, string);
                        }

                        SPD
                        (
                            playerid, D_TUNE_DISKS, DIALOG_STYLE_LIST,
                            "{"cblue"}������ | �����",
                            fmt_dialog,
                            "�����", "������"
                        );
                    }
                    case 2:
                    {
                        if(GetPlayerVehicleID(playerid) != player_ownable_car[playerid]) return SCM(playerid, red, "�� ������ ��������� � ������ ����������.");

						ShowPlayerDialog
						(
							playerid, D_TUNE_CHANGE_COLOR, DIALOG_STYLE_INPUT,
							"{"cblue"}���������� ����",
							"{ffffff}������� ���� � �������: ����, ����. ������: 1, 1",
							"�����������", "������"
						);                       
                    }
                    case 3: 
                    {
                        if(GetPlayerVehicleID(playerid) != player_ownable_car[playerid]) return SCM(playerid, red, "�� ������ ��������� � ������ ����������.");
                        if(PlayerInfo[playerid][pCash] < 1500) return SCM(playerid, red, "� ��� �� ���������� �����.");

                        GiveMoney(playerid, -1500, "������� ������ ���");
                        GiveBusinessMoney(player_in_business[playerid], 1500, playerid);

						if(ownable_car[GetPlayerVehicleID(playerid)][tun_weels] != 0) RemoveVehicleComponent(GetPlayerVehicleID(playerid), ownable_car[GetPlayerVehicleID(playerid)][tun_weels]), ownable_car[GetPlayerVehicleID(playerid)][tun_weels] = 0;
						if(ownable_car[GetPlayerVehicleID(playerid)][tun_nitro] != 0) RemoveVehicleComponent(GetPlayerVehicleID(playerid), ownable_car[GetPlayerVehicleID(playerid)][tun_nitro]), ownable_car[GetPlayerVehicleID(playerid)][tun_nitro] = 0;

                        SaveOwnableCar(playerid);

                        return SCM(playerid, blue, "�� ������ ������ � ������ ���������� �� {"cyellow"}1500 ������{"cblue"}.");
                    }
                    case 4:
                    {
                        if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, red, "�� ������ ��������� � ����.");
                        if(PlayerInfo[playerid][pCash] < BusinessInfo[ player_in_business[playerid] ][bRepairPrice]) return SCM(playerid, red, "� ��� �� ���������� �����!");

                        GiveMoney(playerid, -BusinessInfo[ player_in_business[playerid] ][bRepairPrice], "������ ���� � ���!");
                        GiveBusinessMoney(player_in_business[playerid], BusinessInfo[ player_in_business[playerid] ][bRepairPrice], playerid);
                        SCM(playerid, blue, "�� ��������������� ���� ����.");
                        RepairVehicle(GetPlayerVehicleID(playerid));
                    }
                }
            }
		}
    }
	#if	defined	tune__OnDialogResponse
		return tune__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse tune__OnDialogResponse
#if	defined	tune__OnDialogResponse
	forward tune__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif