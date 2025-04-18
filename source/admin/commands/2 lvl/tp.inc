enum
	E_TELEPORT_STRUCT
{
	t_name[30],
	Float: t_pos_x,
	Float: t_pos_y,
	Float: t_pos_z,
	Float: t_pos_angle
};
new teleport_list[][E_TELEPORT_STRUCT] =
{
	{"�����",			2551.1570,-2191.6599,21.9763, 0.0},
	{"�������", 		165.1793,782.6835,12.1488, 0.0},
	{"��������", 		1852.0474,2043.1450,15.8850, 0.0},
	{"��������", 		2285.7148,1361.7365,11.3845, 180.0},
	{"������", 			2653.6628,-219.9818,3.6465, 180.0},
	{"�����", 			-2377.4541,2661.3210,38.3081, 0.0},
	{"�������", 		-514.9366,-1653.4915,40.9104, 0.0},
	{"��������", 		484.8798,-1230.8750,40.2449, 0.0},
	{"���������", 		-2344.5933,244.0051,22.0450, 0.0},
	{"������", 			-2408.0625,1621.4037,52.5694, 0.0},
	{"��������", 		1977.4965,1602.5913,15.7700, 0.0},
	{"���", 			1474.9066,1679.6301,15.3236, 0.0},
	{"�������", 		1916.0072,2183.2778,15.7060, 0.0},
	{"���", 			1795.1090,2044.3909,15.8694, 0.0},
	{"�������������", 	1826.9989,2096.1633,15.8418, 0.0},
	{"���", 			2409.9321,-1848.1312,21.8572, 0.0},
	{"��� ������", 		1726.5911,1324.5173,12.8800, 0.0},
	{"��� �����", 		2621.1550,1780.7661,2.5600, 0.0},
	{"���������", 		1899.4329,2227.4734,15.7086, 0.0},
	{"�����", 			2356.3523,2009.2196,15.9900, 0.0},
	{"��������", 		2334.0618,-258.3684,1.8390, 0.0},
	{"��������", 		2813.1179,-1352.1519,2.9151, 0.0},
	{"�������� ����", 	1826.0836,2252.0735,15.2729, 0.0},
	{"�����������", 	1751.6907,2465.2742,15.4400, 0.0},
	{"��������", 		1975.9448,1931.4481,15.5100, 0.0},
	{"��������", 		1876.4078,2253.3743,15.2882, 0.0},
	{"�������������", 	1754.9402,2255.4050,15.8620, 0.0},
	{"�����", 			1819.2732,2526.2100,15.6825, 0.0},
	{"���������", 		1914.7023,2301.4160,15.5697, 0.0},
	{"���������", 		2221.6316,-1972.9662,18.9225, 0.0},
	{"��������(������)",2296.6064,-664.5921,12.0909, 0.0},
	{"������", 			2475.8674,-729.1703,12.3000, 0.0},
	{"��������", 		2738.5396,-2275.8987,17.9269, 0.0},
	{"���������", 		2954.5000,2213.7671,6.8685, 0.0},
	{"���������", 		2016.1731,1889.0742,15.6600, 0.0},
	{"�����", 			1912.3955,-1915.2959,56.5126, 0.0},
	{"����", 			2675.1560,2049.5361,7.0135, 0.0},
	{"���(��������)", 	1900.4652,1722.9036,15.9379, 0.0},

	{"���", 			1801.7988,2096.9988,191.8281, 0.0},
	{"�� ������� �� �������", 	5500.2280,-2553.4182,12.2379, 0.0},
	{"����� � ����", 	3497.9509,2041.7993,17.2144, 0.0}
};


CMD:tp(playerid)
{
	if(PlayerInfo[playerid][bAdmin] < 2 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);

	return ShowTeleportList(playerid);
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case D_TELEPORT_LIST:
		{
			if(response)
			{
				if(!(0 <= listitem <= sizeof teleport_list - 1)) return 1;

				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 0);
				if(IsPlayerInAnyVehicle(playerid))
				{
				    new vehid = GetPlayerVehicleID(playerid);
					new player_state = GetPlayerVehicleSeat(playerid);
				    SetVehiclePos(vehid, teleport_list[listitem][t_pos_x], teleport_list[listitem][t_pos_y], teleport_list[listitem][t_pos_z]);
					FreezePlayer(playerid, 3000);
				    PutPlayerInVehicle(playerid, vehid, player_state);
				}
				else
				{
				    SetPlayerPos(playerid, teleport_list[listitem][t_pos_x], teleport_list[listitem][t_pos_y], teleport_list[listitem][t_pos_z]);
					FreezePlayer(playerid, 3000);
				}

			}
		}
    }
	#if	defined	cmd_tp_OnDialogResponse
		return cmd_tp_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse cmd_tp_OnDialogResponse
#if	defined	cmd_tp_OnDialogResponse
	forward cmd_tp_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif


stock ShowTeleportList(playerid)
{
	new list_text[30 * (sizeof teleport_list)];
	new dest[30];

	for(new i; i < sizeof teleport_list; i ++)
	{
		format(dest, sizeof dest, "%s\n", teleport_list[i][t_name]);
		strcat(list_text, dest);
	}


	ShowPlayerDialog
	(
		playerid, D_TELEPORT_LIST, DIALOG_STYLE_LIST,
		"{"cblue"}�������� ����",
		list_text,
		"�������", "������"
	);
	return 1;
}
// - [ TP ] -
CMD:up(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 2 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);
	if(!strlen(params))
	{
		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(playerid))
		{
			new vehid = GetPlayerVehicleID(playerid);
			new player_state = GetPlayerVehicleSeat(playerid);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x, y, z+2);
			PutPlayerInVehicle(playerid, vehid, player_state);
		}
		else
		{
			GetPlayerPos(playerid, x, y, z);
			SetPlayerPos(playerid, x, y, z+2);
			FreezePlayer(playerid, 1000);
		}
	}
	else
	{
		extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /up [ID ������]");
		if(!PlayerInfo[to_player][pLogin] || !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(to_player))
		{
			new vehid = GetPlayerVehicleID(to_player);
			new player_state = GetPlayerVehicleSeat(to_player);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x, y, z+2);
			PutPlayerInVehicle(to_player, vehid, player_state);
		}
		else
		{
			GetPlayerPos(to_player, x, y, z);
			SetPlayerPos(to_player, x, y, z+2);
			FreezePlayer(to_player, 1000);
		}
	}
	return 1;
}
CMD:down(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 2 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);

	if(!strlen(params))
	{
		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(playerid))
		{
			new vehid = GetPlayerVehicleID(playerid);
			new player_state = GetPlayerVehicleSeat(playerid);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x, y, z-2);
			PutPlayerInVehicle(playerid, vehid, player_state);
		}
		else
		{
			GetPlayerPos(playerid, x, y, z);
			SetPlayerPos(playerid, x, y, z-2);
			FreezePlayer(playerid, 1000);
		}
	}
	else
	{
		extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /up [ID ������]");
		if(!PlayerInfo[to_player][pLogin] || !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(to_player))
		{
			new vehid = GetPlayerVehicleID(to_player);
			new player_state = GetPlayerVehicleSeat(to_player);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x, y, z-2);
			PutPlayerInVehicle(to_player, vehid, player_state);
		}
		else
		{
			GetPlayerPos(to_player, x, y, z);
			SetPlayerPos(to_player, x, y, z-2);
			FreezePlayer(to_player, 1000);
		}
	}
	return 1;
}
CMD:left(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 2 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);

	if(!strlen(params))
	{
		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(playerid))
		{
			new vehid = GetPlayerVehicleID(playerid);
			new player_state = GetPlayerVehicleSeat(playerid);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x, y-2, z);
			PutPlayerInVehicle(playerid, vehid, player_state);
		}
		else
		{
			GetPlayerPos(playerid, x, y, z);
			SetPlayerPos(playerid, x, y-2, z);
			FreezePlayer(playerid, 1000);
		}
	}
	else
	{
		extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /up [ID ������]");
		if(!PlayerInfo[to_player][pLogin] || !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(to_player))
		{
			new vehid = GetPlayerVehicleID(to_player);
			new player_state = GetPlayerVehicleSeat(to_player);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x, y-2, z);
			PutPlayerInVehicle(to_player, vehid, player_state);
		}
		else
		{
			GetPlayerPos(to_player, x, y, z);
			SetPlayerPos(to_player, x, y-2, z);
			FreezePlayer(to_player, 1000);
		}
	}
	return 1;
}
CMD:right(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 2 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);

	if(!strlen(params))
	{
		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(playerid))
		{
			new vehid = GetPlayerVehicleID(playerid);
			new player_state = GetPlayerVehicleSeat(playerid);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x, y+2, z);
			PutPlayerInVehicle(playerid, vehid, player_state);
		}
		else
		{
			GetPlayerPos(playerid, x, y, z);
			SetPlayerPos(playerid, x, y+2, z);
			FreezePlayer(playerid, 1000);
		}
	}
	else
	{
		extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /up [ID ������]");
		if(!PlayerInfo[to_player][pLogin] || !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(to_player))
		{
			new vehid = GetPlayerVehicleID(to_player);
			new player_state = GetPlayerVehicleSeat(to_player);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x, y+2, z);
			PutPlayerInVehicle(to_player, vehid, player_state);
		}
		else
		{
			GetPlayerPos(to_player, x, y, z);
			SetPlayerPos(to_player, x, y+2, z);
			FreezePlayer(to_player, 1000);
		}
	}
	return 1;
}
CMD:before(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 2 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);

	if(!strlen(params))
	{
		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(playerid))
		{
			new vehid = GetPlayerVehicleID(playerid);
			new player_state = GetPlayerVehicleSeat(playerid);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x+2, y, z);
			PutPlayerInVehicle(playerid, vehid, player_state);
		}
		else
		{
			GetPlayerPos(playerid, x, y, z);
			SetPlayerPos(playerid, x+2, y, z);
			FreezePlayer(playerid, 1000);
		}
	}
	else
	{
		extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /up [ID ������]");
		if(!PlayerInfo[to_player][pLogin] || !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(to_player))
		{
			new vehid = GetPlayerVehicleID(to_player);
			new player_state = GetPlayerVehicleSeat(to_player);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x+2, y, z);
			PutPlayerInVehicle(to_player, vehid, player_state);
		}
		else
		{
			GetPlayerPos(to_player, x, y, z);
			SetPlayerPos(to_player, x+2, y, z);
			FreezePlayer(to_player, 1000);
		}
	}
	return 1;
}
CMD:after(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 2 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);

	if(!strlen(params))
	{
		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(playerid))
		{
			new vehid = GetPlayerVehicleID(playerid);
			new player_state = GetPlayerVehicleSeat(playerid);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x-2, y, z);
			PutPlayerInVehicle(playerid, vehid, player_state);
		}
		else
		{
			GetPlayerPos(playerid, x, y, z);
			SetPlayerPos(playerid, x-2, y, z);
			FreezePlayer(playerid, 1000);
		}
	}
	else
	{
		extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /up [ID ������]");
		if(!PlayerInfo[to_player][pLogin] || !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

		new Float:x, Float:y, Float:z;
		if(IsPlayerInAnyVehicle(to_player))
		{
			new vehid = GetPlayerVehicleID(to_player);
			new player_state = GetPlayerVehicleSeat(to_player);
			GetVehiclePos(vehid, x, y, z);

			SetVehiclePos(vehid, x-2, y, z);
			PutPlayerInVehicle(to_player, vehid, player_state);
		}
		else
		{
			GetPlayerPos(to_player, x, y, z);
			SetPlayerPos(to_player, x-2, y, z);
			FreezePlayer(to_player, 1000);
		}
	}
	return 1;
}