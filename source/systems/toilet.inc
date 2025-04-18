#define MAX_TOILETS 200

new player_in_toilet[MAX_PLAYERS] = -1;

enum toilet_params_info
{
	Float: exit_x,
	Float: exit_y,
	Float: exit_z,
	Float: exit_angle,
	Float: menu_x,
	Float: menu_y,
	Float: menu_z,
}

#define MAX_TOILET_PLACES 10
enum E_TOILET_PLACES{
    Float: toilet_x,
    Float: toilet_y,
    Float: toilet_z
}

new toilet_places[MAX_TOILET_PLACES][E_TOILET_PLACES] = {
    {1732.6979,1714.5021,-9.2800}, // ������ � ���� �������� ������
    {-2291.7400,361.2034,-86.4541}, // ������ � ��������
    {1593.2013,1659.0579,-1.1600}, // ������ � ���� �������� ������
    {1302.3712,1496.1536,1002.3200}, // ������ � �������
    {331.7525,1650.8275,2002.9399}, // ������ � ���� ������� ������
    {850.4100,802.4863,-73.0036}, // ������ � �� 1
    {1215.9379,1540.7635,2516.6799}, // ��� ������
    {1217.6130,1540.7649,2516.6799}, // ��� ������
    {1214.2893,1540.7565,2516.6799}, // ��� ������
    {1212.5872,1540.7538,2516.6799} // ��� ������
};

new toilet_params[1][toilet_params_info] =
{
    {-2657.8372,2243.6729,510.8259,175.1000, -2657.8291,2244.9656,510.8259}
};

new Iterator: AllToilets<MAX_TOILETS>;
enum E_TOILET_INFO
{
    tID,
    Float: tEnterX,
    Float: tEnterY,
    Float: tEnterZ,
    Text3D: tLabel,
}
new ToiletInfo[MAX_TOILETS][E_TOILET_INFO];
new totaltoilets;

publics LoadToilets()
{
	new rows, fields;
	cache_get_data(rows, fields);
    if(rows)
    {
        for(new i = 0; i < rows; i++)
        {
            ToiletInfo[i][tID] = cache_get_field_content_int(i, "tID");
            ToiletInfo[i][tEnterX] = cache_get_field_content_float(i, "tEnterX");
            ToiletInfo[i][tEnterY] = cache_get_field_content_float(i, "tEnterY");
            ToiletInfo[i][tEnterZ] = cache_get_field_content_float(i, "tEnterZ");

            ToiletInfo[i][tLabel] = CreateDynamic3DTextLabel("{"cblue"}[ ������ ]\n{"cwhite"}�������: {"cblue"}L. ALT {FFFFFF}��� � ����� � ������", 0xFFFFFFFF, ToiletInfo[i][tEnterX], ToiletInfo[i][tEnterY], ToiletInfo[i][tEnterZ]+1.0, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 100.0);

            totaltoilets++;

            Iter_Add(AllToilets, i);

        }
    }
    printf("[UNIGVA]: ����� ��������� ��������: %d", totaltoilets);
    return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024)
    {
        if(IsPlayerNearToiletPan(playerid))
        {
            if(PlayerInfo[playerid][pNeedToilet] == 100) return SCM(playerid, red, "�� �� ������ � ������!");

            PlayerInfo[playerid][pNeedToilet] = 100;
            cmd::do(playerid, "��������� ����������...");
            SCM(playerid, blue, "�� �������� �����.");
            ApplyAnimation(playerid, "PAULNMAC",			"Piss_loop",			4.0, true,  0, 0, 0, 0);
            SetTimerEx("toilet_player", 5000, false, "d", playerid);
            SaveAccounts(playerid);
        }
        if(player_in_toilet[playerid] == -1)
        {
            foreach(new i : AllToilets)
            {
                if(IsPlayerInRangeOfPoint(playerid, 1.0, ToiletInfo[i][tEnterX], ToiletInfo[i][tEnterY], ToiletInfo[i][tEnterZ]))
                {
                    if(PlayerInfo[playerid][bDeveloper] == 1)
                    {
                        new string[124] = "";
                        format(string, sizeof(string), "[Developer Mode]: ID ������� - %d", AtmInfo[i][atmID]);
                        SCM(playerid, green, string);
                    }

                    SetPlayerVirtualWorld(playerid, i);
                    SetPlayerPos(playerid, toilet_params[0][exit_x], toilet_params[0][exit_y], toilet_params[0][exit_z]);
                    FreezePlayer(playerid, 2000);
                    player_in_toilet[playerid] = i;
                    return 1;
                }
            }
        }
        else
        {
            new i = player_in_toilet[playerid];
            if(IsPlayerInRangeOfPoint(playerid, 1.0, toilet_params[0][exit_x], toilet_params[0][exit_y], toilet_params[0][exit_z]))
            {
                SetPlayerPos(playerid, ToiletInfo[i][tEnterX], ToiletInfo[i][tEnterY], ToiletInfo[i][tEnterZ]);
                SetPlayerVirtualWorld(playerid, 0);
                FreezePlayer(playerid, 2000);
                player_in_toilet[playerid] = -1;
            }
        }
    }
	#if	defined	toilet__OnPlayerKeyStateChange
		return toilet__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange toilet__OnPlayerKeyStateChange
#if	defined	toilet__OnPlayerKeyStateChange
	forward toilet__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

stock IsPlayerNearToiletPan(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 1.0, toilet_params[0][menu_x], toilet_params[0][menu_y], toilet_params[0][menu_z]))
    {
        return true;
    }
    for(new i = 0; i < MAX_TOILET_PLACES; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 1.0, toilet_places[i][toilet_x], toilet_places[i][toilet_y], toilet_places[i][toilet_z]))
        {
            return true;
        }
    }
    return false;
}

publics toilet_player(playerid)
{
    ClearAnimations(playerid);
}

