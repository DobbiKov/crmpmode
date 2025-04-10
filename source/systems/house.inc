#define MAX_HOUSES 1000

#define h_type_bad      1
#define h_type_norm     2
#define h_type_good     3

// new player_in_house[MAX_PLAYERS] = -1;
new TotalFreeHouses;

enum house_params_info
{
	htype[12],
	hint,
	Float:exit_x,
	Float:exit_y,
	Float:exit_z,
	Float:exit_angle,
	hrent,
	Float:store_pos_x,
	Float:store_pos_y,
	Float:store_pos_z
}

new house_params[4][house_params_info] =
{
	{"", 0, 0.0, 0.0, 0.0, 0.0, 0, 0.0, 0.0, 0.0},
	{"", 1, 329.8673,1636.0161,2002.9399,93.9317, 3000, 344.5776,1633.6987,2002.9399},
	{"", 2, 1740.0901, 1730.1829, -9.2800, 178.5623, 4000, 1741.1776, 1726.0455, -9.2800},
	{"", 3, 1583.3467, 1640.8302, -1.1800, 196.0333, 5000, 1600.3223, 1627.0465, -1.1800}
};

new Iterator: Allhouses<MAX_HOUSES>;
enum house
{
	hID,
	Float:hExitX,
	Float:hExitY,
	Float:hExitZ,
	hOwned,
	hOwner[24],
	hPrice,
	hPickup,
	hIcon,
	hType,
	hDays,
	hLock,
	Float:car_pos_x,
	Float:car_pos_y,
	Float:car_pos_z,
	Float:car_pos_a,
	Text3D:storetext,
	hPatron,
	hDrugs,
    hMetall
}
new HouseInfo[MAX_HOUSES][house];
new totalhouses;

publics LoadHouses()
{
	new rows, fields;
	cache_get_data(rows, fields);
    if(rows)
    {
        for(new i = 0; i < rows; i++)
        {
            new idx = i + 1;
            HouseInfo[idx][hID] = cache_get_field_content_int(i, "hID");
            HouseInfo[idx][hOwned] = cache_get_field_content_int(i, "hOwned");
            HouseInfo[idx][hPrice] = cache_get_field_content_int(i, "hPrice");
            HouseInfo[idx][hType] = cache_get_field_content_int(i, "hType");
            HouseInfo[idx][hDays] = cache_get_field_content_int(i, "hDays");
            HouseInfo[idx][hLock] = cache_get_field_content_int(i, "hLock");

            HouseInfo[idx][hPatron] = cache_get_field_content_int(i, "hPatron");
            HouseInfo[idx][hDrugs] = cache_get_field_content_int(i, "hDrugs");
            HouseInfo[idx][hMetall] = cache_get_field_content_int(i, "hMetall");

            HouseInfo[idx][hExitX] = cache_get_field_content_float(i, "hExitX");
            HouseInfo[idx][hExitY] = cache_get_field_content_float(i, "hExitY");
            HouseInfo[idx][hExitZ] = cache_get_field_content_float(i, "hExitZ");

            HouseInfo[idx][car_pos_x] = cache_get_field_content_float(i, "car_pos_x");
            HouseInfo[idx][car_pos_y] = cache_get_field_content_float(i, "car_pos_y");
            HouseInfo[idx][car_pos_z] = cache_get_field_content_float(i, "car_pos_z");
            HouseInfo[idx][car_pos_a] = cache_get_field_content_float(i, "car_pos_a");
            cache_get_field_content(i, "hOwner", HouseInfo[idx][hOwner], connects, MAX_PLAYER_NAME);

            HouseInfo[idx][storetext] = CreateDynamic3DTextLabel("___", 0xFFFFFFFF, house_params[ HouseInfo[idx][hType] ][store_pos_x], house_params[ HouseInfo[idx][hType] ][store_pos_y], house_params[ HouseInfo[idx][hType] ][store_pos_z], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, idx, -1, -1, 100.0);
            
            if(HouseInfo[idx][hOwned] == 0) TotalFreeHouses++;
            totalhouses++;

            Iter_Add(Allhouses, idx);


            SaveHouse(idx);
            BuyHouse(idx);
        }
    }
    printf("[UNIGVA]: ����� ��������� �����: %d", totalhouses);
    return 1;
}

stock SaveHouse(i)
{
    new sql[1024];
    format
    (
        sql, sizeof(sql), 
        "UPDATE `houses` SET `hOwned` = '%d', `hPrice` = '%d', `hType` = '%d', `hDays` = '%d', `hLock` = '%d', `hPatron` = '%d', `hDrugs` = '%d', `hMetall` = '%d', `hExitX` = '%f', `hExitY` = '%f', `hExitZ` = '%f', `car_pos_x` = '%f', `car_pos_y` = '%f', `car_pos_z` = '%f', `car_pos_a` = '%f', `hOwner` = '%s' WHERE `hID` = '%d'",
        HouseInfo[i][hOwned],
        HouseInfo[i][hPrice],
        HouseInfo[i][hType],
        HouseInfo[i][hDays],
        HouseInfo[i][hLock],
        HouseInfo[i][hPatron],
        HouseInfo[i][hDrugs],
        HouseInfo[i][hMetall],
        HouseInfo[i][hExitX],
        HouseInfo[i][hExitY],
        HouseInfo[i][hExitZ],
        HouseInfo[i][car_pos_x],
        HouseInfo[i][car_pos_y],
        HouseInfo[i][car_pos_z],
        HouseInfo[i][car_pos_a],
        HouseInfo[i][hOwner],
        HouseInfo[i][hID]
    );
    mysql_tquery(connects, sql, "", "");
    return UpdateHouse(i);
}

stock UpdateHouse(i)
{
    new fmt_msg[128];
    format
    (
        fmt_msg, sizeof(fmt_msg), 
        "{"cblue"}����\n\n\
        {FFFFFF}�������: {"cblue"}%d/3000\n\
        {ffffff}������: {"cblue"}%d/1000\n\
        {FFFFFF}���������: {"cblue"}%d/1500",
        HouseInfo[i][hPatron], HouseInfo[i][hMetall], HouseInfo[i][hDrugs]
    );
    UpdateDynamic3DTextLabelText(HouseInfo[i][storetext], 0xFFCC00FF, fmt_msg);
    return 1;
}

stock BuyHouse(i)
{
	if(HouseInfo[i][hOwned] == 0)
	{
	    DestroyDynamicMapIcon(HouseInfo[i][hIcon]);
	    DestroyDynamicPickup(HouseInfo[i][hPickup]);
	    HouseInfo[i][hPickup] = CreateDynamicPickup(1273, 23, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ], -1);
	    HouseInfo[i][hIcon] = CreateDynamicMapIcon(HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ], 31, 0, -1, -1, -1, 180);
	    return 1;
	}
	if(HouseInfo[i][hOwned] == 1)
	{
	    DestroyDynamicMapIcon(HouseInfo[i][hIcon]);
	    DestroyDynamicPickup(HouseInfo[i][hPickup]);
	    HouseInfo[i][hPickup] = CreateDynamicPickup(1272, 23, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ], -1);
	    HouseInfo[i][hIcon] = CreateDynamicMapIcon(HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ], 32, 0, -1, -1, -1, 180);
	    return 1;
	}    
    return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024)
    {
        if(player_in_house[playerid] != 0)
        {
            new h = player_in_house[playerid];
            if(IsPlayerInRangeOfPoint(playerid, 2.0, house_params[ HouseInfo[h][hType] ][exit_x], house_params[ HouseInfo[h][hType] ][exit_y], house_params[ HouseInfo[h][hType] ][exit_z]))
            {
                SetPlayerPos(playerid, HouseInfo[h][hExitX], HouseInfo[h][hExitY], HouseInfo[h][hExitZ]);
                SetPlayerVirtualWorld(playerid, 0);
                return player_in_house[playerid];
            }
        }
        foreach(new i : Allhouses)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
            {
                SetPVarInt(playerid, "house_id", i);
                new fmt_dialog[256], class[32];
                switch(HouseInfo[i][hType])
                {
                    case 1: class = "������";
                    case 2: class = "�������";
                    case 3: class = "�������";
                }
                if(HouseInfo[i][hOwned] == 0)
                {
                    format
                    (
                        fmt_dialog, sizeof(fmt_dialog), 
                        "{ffffff}���:\t\t\t{"cblue"}�: %d\n\
                        {ffffff}��������:\t\t{"cblue"}�����������\n\
                        {ffffff}�����:\t\t\t{"cblue"}%s\n\
                        {ffffff}���������: \t\t{"cblue"}%d ������\n\
                        {ffffff}������ � ����:\t\t{"cblue"}%d ������\n\n\
                        {ffffff}�� �������, ��� ������ ������ ���?",
                        HouseInfo[i][hID], class, HouseInfo[i][hPrice], house_params[ HouseInfo[i][hType] ][hrent]                
                    );
                    SPD
                    (
                        playerid, D_BUY_HOUSE, DIALOG_STYLE_MSGBOX,
                        "{"cblue"}������� ����", fmt_dialog, "������", "������"
                    );
                }
                else if(HouseInfo[i][hOwned] == 1)
                {
                    format
                    (
                        fmt_dialog, sizeof(fmt_dialog), 
                        "{ffffff}���:\t\t\t{"cblue"}� %d\n\
                        {ffffff}��������:\t\t{"cblue"}%s\n\
                        {ffffff}�����:\t\t\t{"cblue"}%s\n\
                        {ffffff}���������: \t\t{"cblue"}%d ������\n\
                        {ffffff}������ � ����:\t\t{"cblue"}%d ������",
                        HouseInfo[i][hID], HouseInfo[i][hOwner], class, HouseInfo[i][hPrice], house_params[ HouseInfo[i][hType] ][hrent]                
                    );
                    SPD
                    (
                        playerid, D_ENTER_HOUSE, DIALOG_STYLE_MSGBOX,
                        "{"cblue"}���� �����", fmt_dialog, "�����", "������"
                    );
                }
                return 1;
            }
        }
    }
	#if	defined	home__OnPlayerKeyStateChange
		return home__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange home__OnPlayerKeyStateChange
#if	defined	home__OnPlayerKeyStateChange
	forward home__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_BUY_HOUSE:
        {
            if(!response) return 0;
            else
            {
                new h = GetPVarInt(playerid, "house_id");
                if(PlayerInfo[playerid][pHomeID] != -1 || PlayerInfo[playerid][pKvartID] != -1) return SCM(playerid, red, "� ��� ��� ������� �����.");
                if(HouseInfo[h][hOwned] == 1) return SCM(playerid, red, "������ ����� ��� ���-�� �������.");
                if(PlayerInfo[playerid][pCash] < HouseInfo[h][hPrice]) return SCM(playerid, red, "� ��� ������������ �����.");

                GiveMoney(playerid, -HouseInfo[h][hPrice], "������� ����");
                PlayerInfo[playerid][pHomeID] = HouseInfo[h][hID];

                HouseInfo[h][hOwned] = 1;
                HouseInfo[h][hOwner] = EOS;
                strcat(HouseInfo[h][hOwner], PlayerInfo[playerid][pName]);

                SPD
                (
                    playerid, D_NULL, DIALOG_STYLE_MSGBOX,
                    "{"cblue"}������� ����", "{ffffff}����������� ��� � �������� �������� ����!", "�������", ""
                );

                SaveHouse(h);
                SaveAccounts(playerid);
                BuyHouse(h);
                return TotalFreeHouses--;
            }
        }
        case D_ENTER_HOUSE:
        {
            if(!response) return 0;
            else
            {
                new h = GetPVarInt(playerid, "house_id");
                if(HouseInfo[h][hLock] == 1) return GameTextForPlayer(playerid, "~r~��� ������", 3000, 1);



                SetPlayerPos(playerid, house_params[ HouseInfo[h][hType] ][exit_x], house_params[ HouseInfo[h][hType] ][exit_y], house_params[ HouseInfo[h][hType] ][exit_z]);
                SetPlayerFacingAngle(playerid, house_params[ HouseInfo[h][hType] ][exit_angle]);
                SetPlayerVirtualWorld(playerid, h);
                FreezePlayer(playerid, 2000);

                DeletePVar(playerid, "house_id");
            }
        }
        case D_SELLHOME:
        {
            if(!response) DeletePVar(playerid, "my_house_id");
            else
            {
                new h = GetPVarInt(playerid, "my_house_id");

                GiveMoney(playerid, (HouseInfo[h][hPrice]/10)*8, "������� ���� � ����");

                HouseInfo[h][hOwned] = 0;
                HouseInfo[h][hDays] = 3;
                HouseInfo[h][hOwner] = EOS;
                strcat(HouseInfo[h][hOwner], "None");
                PlayerInfo[playerid][pHomeID] = -1;
                BuyHouse(h);
                SaveAccounts(playerid);
                SaveHouse(h);
                DestroyOwnableCar(playerid);
                return TotalFreeHouses++;
            }
        }
        case D_CMD_USE:
        {
            if(!response) return DeletePVar(playerid, "my_house_id");
            else
            {
                switch(listitem)
                {
                    case 0: SPD(playerid, D_CMD_USE_PATRON, DIALOG_STYLE_LIST, "{"cblue"}���� | �������", "{"cblue"}1. {FFFFFF}�����\n{"cblue"}2. {FFFFFF}��������", "�����", "������");
                    case 1: SPD(playerid, D_CMD_USE_METALL, DIALOG_STYLE_LIST, "{"cblue"}���� | ������", "{"cblue"}1. {FFFFFF}�����\n{"cblue"}2. {FFFFFF}��������", "�����", "������");
                    case 2: SPD(playerid, D_CMD_USE_DRUGS, DIALOG_STYLE_LIST, "{"cblue"}���� | ���������", "{"cblue"}1. {FFFFFF}�����\n{"cblue"}2. {FFFFFF}��������", "�����", "������");
                }
            }
        }

        case D_CMD_USE_PATRON:
        {
            if(!response) return DeletePVar(playerid, "my_house_id");
            else
            {
                switch(listitem)
                {
                    case 0: SPD(playerid, D_CMD_USE_PATRON_GET, DIALOG_STYLE_INPUT, "{"cblue"}���� | �������", "������� ���������� ��������, ������� ������ �����:", "�����", "�������");
                    case 1: SPD(playerid, D_CMD_USE_PATRON_PUT, DIALOG_STYLE_INPUT, "{"cblue"}���� | �������", "������� ���������� ��������, ������� ������ ��������:", "�����", "�������");
                }
            }
        }
        case D_CMD_USE_METALL:
        {
            if(!response) return DeletePVar(playerid, "my_house_id");
            else
            {
                switch(listitem)
                {
                    case 0: SPD(playerid, D_CMD_USE_METALL_GET, DIALOG_STYLE_INPUT, "{"cblue"}���� | ������", "������� ���������� ��. �������, ������� ������ �����:", "�����", "�������");
                    case 1: SPD(playerid, D_CMD_USE_METALL_PUT, DIALOG_STYLE_INPUT, "{"cblue"}���� | ������", "������� ���������� ��. �������, ������� ������ ��������:", "�����", "�������");
                }
            }
        }
        case D_CMD_USE_DRUGS:
        {
            if(!response) return DeletePVar(playerid, "my_house_id");
            else
            {
                switch(listitem)
                {
                    case 0: SPD(playerid, D_CMD_USE_DRUGS_GET, DIALOG_STYLE_INPUT, "{"cblue"}���� | ���������", "������� ���������� ��. ����������, ������� ������ �����:", "�����", "�������");
                    case 1: SPD(playerid, D_CMD_USE_DRUGS_PUT, DIALOG_STYLE_INPUT, "{"cblue"}���� | ���������", "������� ���������� ��. ����������, ������� ������ ��������:", "�����", "�������");
                }
            }
        }
        case D_CMD_USE_PATRON_GET:
        {
            if(!response) return DeletePVar(playerid, "my_house_id");
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext) || strval(inputtext) < 0) return SPD(playerid, D_CMD_USE_PATRON_GET, DIALOG_STYLE_INPUT, "{"cblue"}���� | �������", "������� ���������� ��������, ������� ������ �����:", "�����", "�������");
                new h = GetPVarInt(playerid, "my_house_id");
                new patr = strval(inputtext);

                if(HouseInfo[h][hPatron] < patr) return SCM(playerid, red, "� ����� ���� ��� ������� ��������.");

                if(PlayerInfo[playerid][pVIP] > 0) if(PlayerInfo[playerid][pPatr] + patr > 600) return SCM(playerid, red, "�� �� ������� ������ ������� ������.");
                else if(PlayerInfo[playerid][pPatr] + patr > 400) return SCM(playerid, red, "�� �� ������� ������ ������� ������.");

                HouseInfo[h][hPatron] -= patr;
                PlayerInfo[playerid][pPatr] += patr;

                new string[144];
                format(string, sizeof(string), "�� ����� �� ����� ���� {"cyellow"}%d ��.", patr);
                SCM(playerid, blue, string);
                SaveHouse(h);
                return DeletePVar(playerid, "my_house_id");
            }
        }
        case D_CMD_USE_METALL_GET:
        {
            if(!response) return DeletePVar(playerid, "my_house_id");
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext) || strval(inputtext) < 0) return SPD(playerid, D_CMD_USE_METALL_GET, DIALOG_STYLE_INPUT, "{"cblue"}���� | ������", "������� ���������� ��. �������, ������� ������ �����:", "�����", "�������");
                new h = GetPVarInt(playerid, "my_house_id");
                new metall = strval(inputtext);

                if(HouseInfo[h][hMetall] < metall) return SCM(playerid, red, "� ����� ���� ��� ������� �������.");

                if(PlayerInfo[playerid][pMetall] + metall > 100) return SCM(playerid, red, "�� �� ������� ������ ������� �������.");

                HouseInfo[h][hMetall] -= metall;
                PlayerInfo[playerid][pMetall] += metall;

                new string[144];
                format(string, sizeof(string), "�� ����� �� ����� ���� {"cyellow"}%d ��. �������.", metall);
                SCM(playerid, blue, string);
                SaveHouse(h);
                return DeletePVar(playerid, "my_house_id");
            }
        }
        case D_CMD_USE_DRUGS_GET:
        {
            if(!response) return DeletePVar(playerid, "my_house_id");
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext) || strval(inputtext) < 0) return SPD(playerid, D_CMD_USE_DRUGS_GET, DIALOG_STYLE_INPUT, "{"cblue"}���� | ���������", "������� ���������� ��. ����������, ������� ������ �����:", "�����", "�������");
                new h = GetPVarInt(playerid, "my_house_id");
                new drugs = strval(inputtext);

                if(!CanPlayerGetAmountDrugs(playerid, drugs))
                    return SCM(playerid, red, !"�� �� ������ ������ ������� ����������!");

                if(HouseInfo[h][hDrugs] < drugs) return SCM(playerid, red, "� ����� ���� ��� ������� ����������.");

                HouseInfo[h][hDrugs] -= drugs;
                PlayerInfo[playerid][pDrugs] += drugs;

                new string[144];
                format(string, sizeof(string), "�� ����� �� ����� ���� {"cyellow"}%d �. ����������.", drugs);
                SCM(playerid, blue, string);
                SaveHouse(h);
                return DeletePVar(playerid, "my_house_id");
            }
        }
        case D_CMD_USE_PATRON_PUT:
        {
            if(!response) return DeletePVar(playerid, "my_house_id");
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext) || strval(inputtext) < 0) return SPD(playerid, D_CMD_USE_PATRON_PUT, DIALOG_STYLE_INPUT, "{"cblue"}���� | �������", "������� ���������� ��������, ������� ������ ��������:", "�����", "�������");
                new h = GetPVarInt(playerid, "my_house_id");
                new patr = strval(inputtext);  

                if(PlayerInfo[playerid][pPatr] < patr) return SCM(playerid, red, "� ��� ��� ������� ��.");
                if(HouseInfo[h][hPatron] + patr > 3000) return SCM(playerid, red, "� ���� ���� �� ���������� ������� ��.");    

                HouseInfo[h][hPatron] += patr;
                PlayerInfo[playerid][pPatr] -= patr;

                new string[144];
                format(string, sizeof(string), "�� �������� � ���� ���� {"cyellow"}%d ��.", patr);
                SCM(playerid, blue, string);
                SaveHouse(h);
                return DeletePVar(playerid, "my_house_id");  
            }
        }
        case D_CMD_USE_METALL_PUT:
        {
            if(!response) return DeletePVar(playerid, "my_house_id");
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext) || strval(inputtext) < 0) return SPD(playerid, D_CMD_USE_METALL_PUT, DIALOG_STYLE_INPUT, "{"cblue"}���� | ������", "������� ���������� ��. �������, ������� ������ ��������:", "�����", "�������");
                new h = GetPVarInt(playerid, "my_house_id");
                new metall = strval(inputtext);  

                if(PlayerInfo[playerid][pMetall] < metall) return SCM(playerid, red, "� ��� ��� ������� �������");
                if(HouseInfo[h][hMetall] + metall > 1000) return SCM(playerid, red, "� ���� ���� �� ���������� ������� �������");    

                HouseInfo[h][hMetall] += metall;
                PlayerInfo[playerid][pMetall] -= metall;

                new string[144];
                format(string, sizeof(string), "�� �������� � ���� ���� {"cyellow"}%d ��. �������", metall);
                SCM(playerid, blue, string);
                SaveHouse(h);
                return DeletePVar(playerid, "my_house_id");  
            }
        }
        case D_CMD_USE_DRUGS_PUT:
        {
            if(!response) return DeletePVar(playerid, "my_house_id");
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext) || strval(inputtext) < 0) return SPD(playerid, D_CMD_USE_DRUGS_PUT, DIALOG_STYLE_INPUT, "{"cblue"}���� | ���������", "������� ���������� ��. ����������, ������� ������ ��������:", "�����", "�������");
                new h = GetPVarInt(playerid, "my_house_id");
                new drugs = strval(inputtext);  

                if(PlayerInfo[playerid][pDrugs] < drugs) return SCM(playerid, red, "� ��� ��� ������� ����������");
                if(HouseInfo[h][hDrugs] + drugs > 1500) return SCM(playerid, red, "� ���� ���� �� ���������� ������� ����������");    

                HouseInfo[h][hDrugs] += drugs;
                PlayerInfo[playerid][pDrugs] -= drugs;

                new string[144];
                format(string, sizeof(string), "�� �������� � ���� ���� {"cyellow"}%d ��. ����������", drugs);
                SCM(playerid, blue, string);
                SaveHouse(h);
                return DeletePVar(playerid, "my_house_id");  
            }
        }
    }
	#if	defined	home__OnDialogResponse
		return home__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse home__OnDialogResponse
#if	defined	home__OnDialogResponse
	forward home__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

CMD:home(playerid)
{
    if(PlayerInfo[playerid][pHomeID] == -1) return SCM(playerid, red, "� ��� ��� ����.");

	new text[380] = "{FFFFFF}";
	new fmt_str[50], class[32];
	
	new h;
    foreach(new i : Allhouses) if(PlayerInfo[playerid][pHomeID] == HouseInfo[i][hID]) 
    {
        h = i; 
        break;
    }
    switch(HouseInfo[h][hType])
    {
        case 1: class = "������";
        case 2: class = "�������";
        case 3: class = "�������";
    }
	format(fmt_str, sizeof fmt_str, "\t{ffffff}���\t\t\t{"cblue"}�:%d\n\n", HouseInfo[h][hID]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}��������: \t\t{"cblue"}%s\n", HouseInfo[h][hOwner]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}�����: \t\t\t{"cblue"}%s\n", class);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}���������:\t\t%s\n", HouseInfo[h][hLock] == 1 ? ("{ff614a}������") : ("{66cc00}������"));
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}��������:\t\t{"cblue"}%d/30\n", HouseInfo[h][hDays]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}������ � ����:\t\t{"cblue"}%d ������\n", house_params[ HouseInfo[h][hType] ][hrent]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}�������:\t\t{"cblue"}%d\n", HouseInfo[h][hPatron]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}������:\t\t{"cblue"}%d\n", HouseInfo[h][hMetall]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}���������:\t\t{"cblue"}%d\n", HouseInfo[h][hDrugs]);
	strcat(text, fmt_str);
	
	SPD
	(
		playerid, D_NULL, DIALOG_STYLE_MSGBOX,
		"{"cblue"}���������� �����",
		text,
		"�������", ""
	);
    return 1;
}

CMD:hclose(playerid)
{
	if(PlayerInfo[playerid][pHomeID] == -1) return SCM(playerid, red, "� ��� ��� ����.");
	
    new h;
    foreach(new i : Allhouses) if(PlayerInfo[playerid][pHomeID] == HouseInfo[i][hID]) 
    {
        h = i; 
        break;
    }
	
	if(IsPlayerInRangeOfPoint(playerid, 5.0, HouseInfo[h][hExitX], HouseInfo[h][hExitY], HouseInfo[h][hExitZ]) || IsPlayerInRangeOfPoint(playerid, 2.0, house_params[ HouseInfo[h][hType] ][exit_x], house_params[ HouseInfo[h][hType] ][exit_y], house_params[ HouseInfo[h][hType] ][exit_z]) )
	{
		HouseInfo[h][hLock] = 1;
		GameTextForPlayer(playerid, "~w~��� ~r~������", 2000, 5);
		SaveHouse(h);
        return 1;
	}
	
	return SCM(playerid, red, "�� ������ ��������� � ������ ����.");
}
CMD:hopen(playerid)
{
	if(PlayerInfo[playerid][pHomeID] == -1) return SCM(playerid, red, "� ��� ��� ����.");
	
    new h;
    foreach(new i : Allhouses) if(PlayerInfo[playerid][pHomeID] == HouseInfo[i][hID]) 
    {
        h = i; 
        break;
    }
	
	if(IsPlayerInRangeOfPoint(playerid, 5.0, HouseInfo[h][hExitX], HouseInfo[h][hExitY], HouseInfo[h][hExitZ]) || IsPlayerInRangeOfPoint(playerid, 2.0, house_params[ HouseInfo[h][hType] ][exit_x], house_params[ HouseInfo[h][hType] ][exit_y], house_params[ HouseInfo[h][hType] ][exit_z]))
	{
		HouseInfo[h][hLock] = 0;
		GameTextForPlayer(playerid, "~w~��� ~g~������", 2000, 5);
		SaveHouse(h);
        return 1;
	}
	return SCM(playerid, red, "�� ������ ��������� � ������ ����.");
}

CMD:sellhome(playerid)
{
	if(PlayerInfo[playerid][pHomeID] == -1) return SCM(playerid, red, "� ��� ��� ����");

    new h;
    foreach(new i : Allhouses) if(PlayerInfo[playerid][pHomeID] == HouseInfo[i][hID])
    {
        h = i;
        break;
    }
    SetPVarInt(playerid, "my_house_id", h);
	
	SPD
	(
		playerid, D_SELLHOME, DIALOG_STYLE_MSGBOX, 
		"{"cblue"}������� ����", 
		"{FFFFFF}�� ������� ��� ������ ������� ���� ��� �����������?\n\n\
		��� ����� ���������� ��� ��������� �� ������� 20 ���������.\n\n\
		���� �� ������ ������� ��� ������� ������,\n\
		����������� ������� /sellmyhouse", 
		"��", "���"
	);
	
	return 1;
}
CMD:sellmyhouse(playerid, params[])
{
    if(PlayerInfo[playerid][pHomeID] == -1) return SCM(playerid, red, "� ��� ��� ����.");
    extract params -> new to_player, cash; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /sellmyhouse [ID ������] [����]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);

    new h;
    foreach(new i : Allhouses) if(HouseInfo[i][hID] == PlayerInfo[playerid][pHomeID]) 
    {
        h = i;
        break;
    }
    if(!IsPlayerInRangeOfPoint(playerid, 5.0, HouseInfo[h][hExitX], HouseInfo[h][hExitY], HouseInfo[h][hExitZ])) return SCM(playerid, red, "�� ������ ��������� � ������ ����.");
    if(!IsPlayerInRangeOfPoint(to_player, 5.0, HouseInfo[h][hExitX], HouseInfo[h][hExitY], HouseInfo[h][hExitZ])) return SCM(playerid, red, "����� ������ �� ���.");


    if(PlayerInfo[to_player][pHomeID] != -1) return SCM(playerid, red, "� ������ ��� ���� ���.");
    if(PlayerInfo[to_player][pCash] < cash) return SCM(playerid, red, "� ������ ������������ �����.");

    return SendProposition(playerid, to_player, PROPOSITION_TYPE_SELLHOUSE, cash, h);
}

CMD:use(playerid)
{
    if(PlayerInfo[playerid][pHomeID] == -1) return SCM(playerid, red, "� ��� ��� ����.");

    new h;
    foreach(new i : Allhouses) if(HouseInfo[i][hID] == PlayerInfo[playerid][pHomeID])
    {
        h = i;
        break;
    }
    if(player_in_house[playerid] != h) return SCM(playerid, red, "�� ������ ��������� � ����� ����.");
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, house_params[ HouseInfo[h][hType] ][store_pos_x], house_params[ HouseInfo[h][hType] ][store_pos_y], house_params[ HouseInfo[h][hType] ][store_pos_z])) return SCM(playerid, red, "�� ������ ��������� � ������ �����.");

    SPD
    (
        playerid, D_CMD_USE, DIALOG_STYLE_LIST,
        "{"cblue"}����",
        "\
        {"cblue"}1. {FFFFFF}�������\n\
        {"cblue"}2. {FFFFFF}������\n\
        {"cblue"}3. {FFFFFF}���������",
        "�����", "������"
    );
    SetPVarInt(playerid, "my_house_id", h);
    return 1;
}

publics minuteupdate()
{
    new hour, minute, second;
    gettime(hour, minute, second);
    if(hour == 00 && minute == 20)
    {
        TimeSletHouse();
    }
	#if	defined	house__minuteupdate
		return house__minuteupdate();
	#else
		return 1;
	#endif
}
#if	defined	_ALS_minuteupdate
	#undef	minuteupdate
#else
	#define	_ALS_minuteupdate
#endif

#define	minuteupdate house__minuteupdate
#if	defined	house__minuteupdate
	forward house__minuteupdate();
#endif

stock TimeSletHouse()
{
    foreach(new i : Allhouses) if(HouseInfo[i][hOwned] == 1)
    {
        HouseInfo[i][hDays]--;
        SaveHouse(i);
        if(HouseInfo[i][hDays] <= 0)
        {
            foreach(new j : Player)
            {
                if(PlayerInfo[j][pHomeID] == HouseInfo[i][hID])
                {
                    SCM(j, green, "��� ��� ��� ������ ����������� �� ��������. �� �������� 80 ��������� �� ���. ���������.");

                    GiveBankMoney(j, (HouseInfo[i][hPrice] / 10) * 8, "�������� ���� � � ����.");
                    PlayerInfo[j][pHomeID] = -1;

                    HouseInfo[i][hOwned] = 0;
                    HouseInfo[i][hDays] = 3;
                    HouseInfo[i][hOwner] = EOS;
                    format(HouseInfo[i][hOwner], MAX_PLAYER_NAME, "None");
                    SaveAccounts(j);
                    SaveHouse(i);
                    return BuyHouse(i);
                }
            }
            HouseInfo[i][hDays] = 3;
            HouseInfo[i][hOwned] = 0;
            HouseInfo[i][hOwner] = EOS;
            format(HouseInfo[i][hOwner], MAX_PLAYER_NAME, "None");
            SaveHouse(i);
            BuyHouse(i);

            new sql[144];
            format(sql, sizeof(sql), "SELECT * FROM `accounts` WHERE `pHomeID` = '%d'", HouseInfo[i][hID]);
            return mysql_tquery(connects, sql, "SletHouse", "i", i);
        }
    }
    return 0;
}

publics SletHouse(i)
{
    static rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        new bmoney, player_id;
        player_id = cache_get_field_content_int(0, "pID");
        bmoney = cache_get_field_content_int(0, "pBCash");
        bmoney += (HouseInfo[i][hPrice]/10) * 8;

        new houseoffmess[144] = "��� ��� ��� ������ �����������, �� ��������. �� �������� 80 ��������� �� ����. ��������� ����.";

        new sql[1024];
        format(sql, sizeof(sql), "UPDATE `accounts` SET `pHomeID` = '-1', `pHouseOffMess` = '%s', `pBCash` = '%d' WHERE `pID` = '%d'", houseoffmess, bmoney, player_id);
        mysql_tquery(connects, sql, "", "");
    }
    else
    {
        printf("������ (����)");
    }
    return 1;
}