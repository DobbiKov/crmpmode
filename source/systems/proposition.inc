// proposition Y / N
new send_proposition[MAX_PLAYERS] = {-1, ...}; // ���� � ���������
new incoming_proposition[MAX_PLAYERS] = {-1, ...}; // ��� ��� ���������
new incoming_proposition_type[MAX_PLAYERS] = {-1, ...}; // ��� ��������� �����������
new incoming_proposition_value[MAX_PLAYERS][2]; // �������� ��������� �����������

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys == KEY_YES)
	{
        cmd::yes(playerid);
	}
	if(newkeys == KEY_NO)
	{
        cmd::no(playerid);
	}
	#if	defined	prop__OnPlayerKeyStateChange
		return prop__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange prop__OnPlayerKeyStateChange
#if	defined	prop__OnPlayerKeyStateChange
	forward prop__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

stock SendProposition(playerid, to_player, type, value_1 = 0, value_2 = 0)
{
	if(incoming_proposition[to_player] != -1) return SCM(playerid, red, "� ������ ���� �������� �����������.");
	if(send_proposition[playerid] != -1) return SCM(playerid, -1, "����������� {FF9900}/cancel {FFFFFF}����� �������� ���������� �����������");
	
	send_proposition[playerid] = to_player; //���� � ���������
	incoming_proposition[to_player] = playerid; //��� ��������� ����, ���� � ��������� (������ �)
	incoming_proposition_type[to_player] = type; //��� ��������� �����������
	incoming_proposition_value[to_player][0] = value_1;
    incoming_proposition_value[to_player][1] = value_2;

	new fmt_msg[144];
	switch(type)
	{
		case PROPOSITION_TYPE_SKILL:
		{
			format(fmt_msg, sizeof fmt_msg, "%s ���������� ��� ����������� ��� ������ �������� �������.", PlayerInfo[incoming_proposition[to_player]][pName]);
			SCM(to_player, 0x3399FFFF, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof fmt_msg, "�� ���������� %s ����������� ���� ������ �������� �������.", PlayerInfo[to_player][pName]);
			SCM(playerid, 0x3399FFFF, fmt_msg);
		}
		case PROPOSITION_TYPE_REPAIR_CAR:
		{
			format(fmt_msg, sizeof fmt_msg, "%s ���������� �������� ��� ��������� �� %d ���", PlayerInfo[incoming_proposition[to_player]][pName], value_1);
			SCM(to_player, 0x3399FFFF, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof fmt_msg, "�� ���������� %s ������� ������ ���������� �� %d ���", PlayerInfo[to_player][pName], value_1);
			SCM(playerid, 0x3399FFFF, fmt_msg);
		}
		case PROPOSITION_TYPE_REFILL_CAR:
		{
			format(fmt_msg, sizeof fmt_msg, "%s ���������� ��� ��������� ��� ��������� �� %d �. �� %d ���", PlayerInfo[ incoming_proposition[to_player] ][pName], value_1, value_1 * mech_fuel_price[playerid]);
			SCM(to_player, 0x3399FFFF, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof fmt_msg, "�� ���������� %s ��������� ��� ��������� �� %d �. �� %d ���", PlayerInfo[to_player][pName], value_1, value_1 * mech_fuel_price[playerid]);
			SCM(playerid, 0x3399FFFF, fmt_msg);
		}
		case PROPOSITION_TYPE_INVITE:
		{
			format(fmt_msg, sizeof fmt_msg, "%s %s ���������� ��� �������� � \"%s\"", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerInfo[playerid][pName], GetMember[ PlayerInfo[playerid][pMember] ]);
			SCM(to_player, 0x3399FFFF, fmt_msg);
			
			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ������� ����������� ��� {FF6600}N {FFFFFF}��� ������");
		
			format(fmt_msg, sizeof fmt_msg, "�� ���������� %s �������� � \"%s\"", PlayerInfo[to_player][pName], GetMember[ PlayerInfo[playerid][pMember] ]);
			SCM(playerid, 0x3399FFFF, fmt_msg);
		}
		case PROPOSITION_TYPE_FINVITE:
		{
			new f;
			foreach(new i : AllFamilys) if(PlayerInfo[playerid][pFamID] == FamilyInfo[i][fID]) f = i;
			
			format(fmt_msg, sizeof fmt_msg, "%s ���������� ��� �������� � ����� \"%s\"", PlayerInfo[playerid][pName], FamilyInfo[f][fName]);
			SCM(to_player, 0x3399FFFF, fmt_msg);
			
			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ������� ����������� ��� {FF6600}N {FFFFFF}��� ������");
		
			format(fmt_msg, sizeof fmt_msg, "�� ���������� %s �������� � ���� �����", PlayerInfo[to_player][pName]);
			SCM(playerid, 0x3399FFFF, fmt_msg);
		}
		case PROPOSITION_TYPE_FREE:
		{
			format(fmt_msg, sizeof(fmt_msg), "%s ��������� ��� ����� �� ��� �� %d ������", PlayerInfo[incoming_proposition[to_player]][pName], value_1);
			SCM(to_player, blue, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ������� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof(fmt_msg), "�� ���������� %s ����� �� ��� �� %d ������", PlayerInfo[send_proposition[playerid]][pName], value_1);
			SCM(playerid, blue, fmt_msg);
		}
		case PROPOSITION_TYPE_HEAL:
		{
			format(fmt_msg, sizeof(fmt_msg), "%s ��������� ��� ������ ������� ���� ������� �� %d ������", PlayerInfo[incoming_proposition[to_player]][pName], value_1);
			SCM(to_player, blue, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ������� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof(fmt_msg), "�� ���������� %s ������ ������� ���� ������� �� %d ������", PlayerInfo[send_proposition[playerid]][pName], value_1);
			SCM(playerid, blue, fmt_msg);
		}
		case PROPOSITION_TYPE_SELLLIC:
		{
			format(fmt_msg, sizeof(fmt_msg), "%s ��������� ��� ���������� �������� �� %s %d ������", PlayerInfo[incoming_proposition[to_player]][pName], lic_names[value_1], lic_price[value_1]);
			SCM(to_player, blue, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ������� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof(fmt_msg), "�� ���������� %s ���������� �������� �� %s �� %d ������", PlayerInfo[send_proposition[playerid]][pName], lic_names[value_1], lic_price[value_1]);
			SCM(playerid, blue, fmt_msg);
		}
		case PROPOSITION_TYPE_SELLGUN:
		{
			format(fmt_msg, sizeof(fmt_msg), "%s ��������� ��� ������ %s � %d ��. �� %d ������", PlayerInfo[incoming_proposition[to_player]][pName], gun_name[GetPVarInt(incoming_proposition[to_player], "weapon_id")], value_1, value_2);
			SCM(to_player, blue, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ������� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof(fmt_msg), "�� ���������� %s ������ %s � %d ��. �� %d ������", PlayerInfo[send_proposition[playerid]][pName], gun_name[GetPVarInt(incoming_proposition[to_player], "weapon_id")], value_1, value_2);
			SCM(playerid, blue, fmt_msg);
		}
		case PROPOSITION_TYPE_SELLDRUGS:
		{
			format(fmt_msg, sizeof(fmt_msg), "%s ��������� ��� ������ %d ��. �� %d ������", PlayerInfo[incoming_proposition[to_player]][pName], value_1, value_2);
			SCM(to_player, blue, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ������� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof(fmt_msg), "�� ���������� %s ������ %d ��. ���������� �� %d ������", PlayerInfo[send_proposition[playerid]][pName], value_1, value_2);
			SCM(playerid, blue, fmt_msg);
		}
		case PROPOSITION_TYPE_SELLBIZ:
		{
			new i = GetPVarInt(playerid, "my_biz_id");
			format(fmt_msg, sizeof(fmt_msg), "%s ��������� ��� ������ ��� ������ %s �� %d ������", PlayerInfo[incoming_proposition[to_player]][pName], business_params[ BusinessInfo[i][bType] ][bname], value_1);
			SCM(to_player, blue, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ������� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof(fmt_msg), "�� ���������� %s ������ ��� ������ %s �� %d ������", PlayerInfo[send_proposition[playerid]][pName], business_params[ BusinessInfo[i][bType] ][bname], value_1);
			SCM(playerid, blue, fmt_msg);
		}

		case PROPOSITION_TYPE_SELLCAR:
		{
			format(fmt_msg, sizeof(fmt_msg), "%s ��������� ��� ������ ��� ��������� %s �� %d ������", PlayerInfo[incoming_proposition[to_player]][pName], GetCarName(GetVehicleModel(player_ownable_car[ incoming_proposition[to_player] ])), value_1);
			SCM(to_player, blue, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ������� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof(fmt_msg), "�� ���������� %s ������ ��� ��������� %s �� %d ������", PlayerInfo[send_proposition[playerid]][pName], GetCarName(GetVehicleModel(player_ownable_car[playerid])), value_1);
			SCM(playerid, blue, fmt_msg);
		}
		case PROPOSITION_TYPE_SELLHOUSE:
		{
			new h = value_2;
			format(fmt_msg, sizeof(fmt_msg), "%s ��������� ��� ������ ��� ��� � %d �� %d ������", PlayerInfo[incoming_proposition[to_player]][pName], HouseInfo[h][hID], value_1);
			SCM(to_player, blue, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ������� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof(fmt_msg), "�� ���������� %s ������ ��� ��� � %d �� %d ������", PlayerInfo[send_proposition[playerid]][pName], HouseInfo[h][hID], value_1);
			SCM(playerid, blue, fmt_msg);
		}
		case PROPOSITION_TYPE_DICE:
		{
			format(fmt_msg, sizeof(fmt_msg), "%s ��������� ��� ������ ����� �� %d ������", PlayerInfo[incoming_proposition[to_player]][pName], value_1);
			SCM(to_player, blue, fmt_msg);

			SCM(to_player, -1, "������� {00CC00}Y {FFFFFF}����� ������� ����������� ��� {FF6600}N {FFFFFF}��� ������");

			format(fmt_msg, sizeof(fmt_msg), "�� ���������� %s ������ ����� �� %d ������", PlayerInfo[send_proposition[playerid]][pName], value_1);
			SCM(playerid, blue, fmt_msg);
		}
	}
	return 1;
}
stock ClearProposition(playerid)
{
	send_proposition[playerid] = -1;
	incoming_proposition[playerid] = -1;
	incoming_proposition_type[playerid] = -1;
	incoming_proposition_value[playerid][0] = -1;
	incoming_proposition_value[playerid][1] = -1;

	return 1;
}

CMD:cancel(playerid)
{
	new send_to_player = send_proposition[playerid];
	if(send_to_player == -1) return SCM(playerid, 0xCECECEFF, "� ��� ��� �������� �����������");

	new player_incoming_proposition = incoming_proposition[send_to_player];
	ClearProposition(playerid);

	if(player_incoming_proposition == playerid)
	{
		ClearProposition(send_to_player);

		new fmt_msg[55];
		format(fmt_msg, sizeof fmt_msg, "%s ������� ���� �����������", PlayerInfo[playerid][pName]);
		SCM(send_to_player, 0xFF6600FF, fmt_msg);

		format(fmt_msg, sizeof fmt_msg, "�� �������� ���� ����������� ��� %s", PlayerInfo[send_to_player][pName]);
		SCM(playerid, 0xFF6600FF, fmt_msg);
	}
	else SCM(playerid, 0xFF6600FF, "�� �������� ���� ��������� �����������");

	return 1;
}
CMD:yes(playerid)
{
	new proposition = incoming_proposition[playerid];
	new type = incoming_proposition_type[playerid];
	new value_1 = incoming_proposition_value[playerid][0];
	new value_2 = incoming_proposition_value[playerid][1];

	if(proposition != -1)
	{
		ClearProposition(playerid);
		ClearProposition(proposition);
		if(!IsPlayerConnected(proposition)) return SCM(playerid, 0x999999FF, "����� ����� �� ����");

		new Float: x, Float: y, Float: z;
		GetPlayerPos(proposition, x, y, z);
		new Float: dist = GetPlayerDistanceFromPoint(playerid, x, y, z);

		if(dist > 10.0) return SCM(playerid, 0x999999FF, "����� ������� ������");

		switch(type)
		{
			case PROPOSITION_TYPE_SKILL:
			{
				new fmt_msg[65];
				format(fmt_msg, sizeof fmt_msg, "%s ���������� ���� ������ �������� �������.", PlayerInfo[proposition][pName]);
				SCM(playerid, 0x66CC00FF, fmt_msg);

				format(fmt_msg, sizeof fmt_msg, "�� �������� %s ���� ������ �������� �������.", PlayerInfo[playerid][pName], value_1);
				SCM(proposition, 0x66CC00FF, fmt_msg);

				new fmt_dialog[526];
				format
				(
					fmt_dialog, sizeof fmt_dialog,
					"{ffffff}SDPistol:\t%d / 100%%\n\
					Deagle:\t%d / 100%%\n\
					ShotGun:\t%d / 100%%\n\
					MP5:\t\t%d / 100%%\n\
					AK-47:\t\t%d / 100%%\n\
					M4A1:\t\t%d / 100%%",
					PlayerInfo[proposition][SKILL_SD_PISTOL],
					PlayerInfo[proposition][SKILL_DEAGLE],
					PlayerInfo[proposition][SKILL_SHOTGUN],
					PlayerInfo[proposition][SKILL_MP5],
					PlayerInfo[proposition][SKILL_AK_47],
					PlayerInfo[proposition][SKILL_M4]
				);
				ShowPlayerDialog
				(
					playerid, D_NULL, DIALOG_STYLE_MSGBOX,
					!"{"cblue"}������ �������� �������",
					fmt_dialog,
					!"�������", !""
				);
			}

			case PROPOSITION_TYPE_REPAIR_CAR:
			{
				new vehicleid = GetPlayerVehicleID(playerid);

				if(!vehicleid || GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SCM(playerid, 0xCECECEFF, "�� ������ ��������� �� ����� ������������� ��������!");

				if(PlayerInfo[proposition][pJob] != Job_Car || player_job_vehicle_arend[proposition] == -1) return SCM(playerid, 0xCECECEFF, "��������� �� � ������� ����������");
				

				if(PlayerInfo[playerid][pCash] < value_1)
					return SCM(playerid, red, "� ��� ������������ �����");
				if(!IsPlayerInAnyVehicle(proposition)) return SCM(playerid, red, "����� �� � ����������!");
				if(GetPlayerVehicleID(proposition) != player_job_vehicle_arend[proposition]) return SCM(playerid, red, "����� �� � ����������!");

				GiveMoney(playerid, -value_1, "������� ����������");
				GiveMoney(proposition, value_1, "������� ����������");

				RepairVehicle(vehicleid);
				SetPlayerChatBubble(playerid, "Repair", 0x3399FFFF, 10.0, 2000);

				new fmt_msg[65];
				format(fmt_msg, sizeof fmt_msg, "����������� %s ������� ��� ��������� �� %d ������", PlayerInfo[proposition][pName], value_1);
				SCM(playerid, 0x66CC00FF, fmt_msg);

				format(fmt_msg, sizeof fmt_msg, "�� �������� ��������� %s �� %d ������", PlayerInfo[playerid][pName], value_1);
				SCM(proposition, 0x66CC00FF, fmt_msg);
			}

			case PROPOSITION_TYPE_REFILL_CAR:
			{
				new vehicleid = GetPlayerVehicleID(playerid);

				if(!vehicleid || GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SCM(playerid, 0xCECECEFF, "�� ������ ��������� �� ����� ������������� ��������!");

				if(PlayerInfo[proposition][pJob] != Job_Car || player_job_vehicle_arend[proposition] == -1) return SCM(playerid, 0xCECECEFF, "��������� �� � ������� ����������");
				
				new fillPrice = value_1 * mech_fuel_price[proposition];


				if(PlayerInfo[playerid][pCash] < fillPrice)
					return SCM(playerid, red, "� ��� ������������ �����");
				if(!IsPlayerInAnyVehicle(proposition)) return SCM(playerid, red, "����� �� � ����������!");
				if(GetPlayerVehicleID(proposition) != player_job_vehicle_arend[proposition]) return SCM(playerid, red, "����� �� � ����������!");

				GiveMoney(playerid, -fillPrice, "�������� ����������");
				GiveMoney(proposition, fillPrice / 2, "�������� ����������");

				GiveBusinessMoney(mech_fuel_bizid[proposition], fillPrice / 2, playerid);

				vehicle[vehicleid][veh_fuel] += float(value_1);
				SetPlayerChatBubble(playerid, "Refill", 0x3399FFFF, 10.0, 2000);

				new fmt_msg[65];
				format(fmt_msg, sizeof fmt_msg, "����������� %s �������� ��� ��������� �� %d �. �� %d ������", PlayerInfo[proposition][pName], value_1, fillPrice);
				SCM(playerid, 0x66CC00FF, fmt_msg);

				format(fmt_msg, sizeof fmt_msg, "�� ��������� ��������� %s �� %d �. �� %d ������", PlayerInfo[playerid][pName], value_1, fillPrice);
				SCM(proposition, 0x66CC00FF, fmt_msg);
			}
			case PROPOSITION_TYPE_INVITE:
			{
				new string[128];
				format(string, sizeof(string), "%s ��������� ���� �����������", PlayerInfo[playerid][pName]);
				SCM(proposition, green, string);
				
				format(string, sizeof(string), "�����������! �� �������� � ����������� \"%s\"", GetMember[ PlayerInfo[proposition][pMember] ]);
				SCM(playerid, green, string);
				SCM(playerid, 0x3399FFFF, "����������� {FFCC00}/menu > ������� �������{3399FF}, ����� ������ � ����� ������������");	
				
				PlayerInfo[playerid][pRang] = 1;
				PlayerInfo[playerid][pMember] = PlayerInfo[proposition][pMember];
				PlayerInfo[playerid][pRang] = 1;
				PlayerInfo[playerid][pFSkin] = 1;
				SetPlayerSkin(playerid, PlayerInfo[playerid][pFSkin]);
				PlayerInfo[playerid][pJob] = 0;
				InviteMyTK(playerid);
				SaveAccounts(playerid);

				format(string, sizeof(string), "%d", playerid);
				cmd::changeskin(proposition, string);
			}

			case PROPOSITION_TYPE_FINVITE:
			{
				new string[128];
				format(string, sizeof(string), "%s ��������� ���� �����������", PlayerInfo[playerid][pName]);
				SCM(proposition, green, string);
				
				new f;
				foreach(new i : AllFamilys) if(PlayerInfo[proposition][pFamID] == FamilyInfo[i][fID]) f = i;

				format(string, sizeof(string), "�����������! �� �������� � ����� \"%s\"", FamilyInfo[f][fName]);
				SCM(playerid, green, string);
				
				PlayerInfo[playerid][pFamID] = PlayerInfo[proposition][pFamID];
				PlayerInfo[playerid][pFamRang] = 1;
				
				SaveAccounts(playerid);
			}
			case PROPOSITION_TYPE_FREE:
			{
				new string[128];
				format(string, sizeof(string), "%s ��������� ���� �����������", PlayerInfo[playerid][pName]);
				SCM(proposition, green, string);
				
				format(string, sizeof(string), "�� ����� �� ��� �� %d ������", value_1);
				SCM(playerid, blue, string);

				GiveMoney(playerid, -value_1, "����� �� ���");
				GiveMoney(proposition, value_1, "�������� �� ���");

				PlayerInfo[playerid][pKPZ] = -1;
				PlayerInfo[playerid][pJP] = 0;
				
				SetSpawnVokzal(playerid);
				SaveAccounts(playerid);
				SaveAccounts(proposition);
			}
			case PROPOSITION_TYPE_HEAL:
			{
				new string[128];
				format(string, sizeof(string), "%s ��������� ���� �����������", PlayerInfo[playerid][pName]);
				SCM(proposition, green, string);
				
				format(string, sizeof(string), "�� ������ ������� ���� ������� �� %d ������", value_1);
				SCM(playerid, blue, string);

				GiveMoney(playerid, -value_1, "���� �������");
				GiveMoney(proposition, value_1, "������� ��������");
				
				PlayerInfo[playerid][pHP] = 100.0;
				SetPlayerHealth(playerid, 100.0);
				PlayerInfo[playerid][pHOSPITAL] = 0;

				SaveAccounts(playerid);
				SaveAccounts(proposition);
			}
			case PROPOSITION_TYPE_DICE:
			{
				new b = player_in_business[playerid];
				if(BusinessInfo[b][bType] != b_type_CASINO || b == -1) return SCM(playerid, red, "�� �� ���������� � ������.");

				new rand_1 = random(6)+1, rand_2 = random(6)+1, string[144];
				new value_dice = value_1 / 10;

				if(rand_1 == rand_2)
				{					
					format(string, sizeof string, "������ %d", rand_1);

					SetPlayerChatBubble(playerid, string, blue, 10.0, 3000);
					SetPlayerChatBubble(proposition, string, blue, 10.0, 3000);
					
					format(string, sizeof string, "%s � %s ������� �����. ��������� {ffcc00}%d:%d", PlayerInfo[playerid][pName], PlayerInfo[proposition][pName], rand_1, rand_2);
					
					SCM(playerid, orange, "���� ����������� � �����");
					SCM(proposition, orange, "���� ����������� � �����");
				}
				else if(rand_1 > rand_2)
				{
					GiveMoney(playerid, value_1 - value_dice, "������� � ������");
					GiveMoney(proposition, -value_1, "�������� � ������");

					GiveBusinessMoney(b, value_dice, playerid);
					UpdateBusiness(b);

					format(string, sizeof string, "������ %d", rand_1);
					SetPlayerChatBubble(playerid, string, green, 10.0, 3000);

					format(string, sizeof string, "������ %d", rand_2);
					SetPlayerChatBubble(proposition, string, red, 10.0, 3000);

					format(string, sizeof string, "%s � %s ������� �����. ��������� {"cblue"}%d:%d", PlayerInfo[playerid][pName], PlayerInfo[proposition][pName], rand_1, rand_2);

					SCM(proposition, red, "� ���������, �� ���������");
					SCM(playerid, green, "�����������! �� ��������");
				}

				else if(rand_2 > rand_1)
				{
					GiveMoney(playerid, -value_1, "�������� � ������");
					GiveMoney(proposition, value_1 - value_dice, "������� � ������");

					GiveBusinessMoney(b, value_dice, playerid);
					UpdateBusiness(b);

					format(string, sizeof string, "������ %d", rand_1);
					SetPlayerChatBubble(proposition, string, green, 10.0, 3000);

					format(string, sizeof string, "������ %d", rand_2);
					SetPlayerChatBubble(playerid, string, red, 10.0, 3000);

					format(string, sizeof string, "%s � %s ������� �����. ��������� {"cblue"}%d:%d", PlayerInfo[playerid][pName], PlayerInfo[proposition][pName], rand_1, rand_2);

					SCM(playerid, red, "� ���������, �� ���������");
					SCM(proposition, green, "�����������! �� ��������");
				}

				ProxDetector(30.0, playerid, string, 0xc2a2daFF, 0xc2a2daFF, 0xc2a2daFF, 0xc2a2daFF, 0xc2a2daFF);
				SaveAccounts(playerid);
				SaveAccounts(proposition);
			}
			case PROPOSITION_TYPE_SELLLIC:
			{
				new string[128];
				format(string, sizeof(string), "%s ��������� ���� �����������", PlayerInfo[playerid][pName]);
				SCM(proposition, green, string);
				
				format(string, sizeof(string), "�� ������ �������� �� %s �� %d ������", lic_names[value_1], lic_price[value_1]);
				SCM(playerid, blue, string);

				GiveMoney(playerid, -lic_price[value_1], "������� ��������");
				GiveMoney(proposition, (lic_price[value_1]/2), "������� ��������");
				
				switch(value_1)
				{
					case 1: PlayerInfo[playerid][pLicBiz] = 1;
					case 2:	PlayerInfo[playerid][pLicFly] = 1;
					case 3: PlayerInfo[playerid][pLicGun] = 1;
				}

				SaveAccounts(playerid);
				SaveAccounts(proposition);
			}
			case PROPOSITION_TYPE_SELLGUN:
			{
				new string[128];
				format(string, sizeof(string), "%s ��������� ���� �����������", PlayerInfo[playerid][pName]);
				SCM(proposition, green, string);
				
				format(string, sizeof(string), "�� ������ %s � %d ��. �� %d ������", gun_name[GetPVarInt(proposition, "weapon_id")], value_1, value_2);
				SCM(playerid, blue, string);

				GiveMoney(playerid, -value_2, "������� ������");
				GiveMoney(proposition, value_2, "������� ������");
				
				GivePlayerWeaponAC(playerid, GetPVarInt(proposition, "weapon_id"), value_1);
				SetPVarInt(playerid, "ammo_count", GetPlayerAmmo(playerid));
				RemovePlayerWeapon(proposition, GetPVarInt(proposition, "weapon_id"));
				if((GetPVarInt(proposition, "ammo_count") - value_1) > 1) GivePlayerWeaponAC(proposition, GetPVarInt(proposition, "weapon_id"), GetPVarInt(proposition, "ammo_count") - value_1);

				DeletePVar(proposition, "weapon_id");
				DeletePVar(proposition, "ammo_count");

				SaveAccounts(playerid);
				SaveAccounts(proposition);
			}
			case PROPOSITION_TYPE_SELLDRUGS:
			{
				if(!CanPlayerGetAmountDrugs(playerid, value_1))
				{
					SCM(playerid, red, !"�� �� ������� ������ ������� ����������!");
					SCM(proposition, red, !"����� �� ������ ������ ������� ����������!");
					return 1;
				}
				new string[128];
				format(string, sizeof(string), "%s ��������� ���� �����������", PlayerInfo[playerid][pName]);
				SCM(proposition, green, string);
				
				format(string, sizeof(string), "�� ������ %d ��. ���������� �� %d ������", value_1, value_2);
				SCM(playerid, blue, string);

				GiveMoney(playerid, -value_2, "������� ����������");
				GiveMoney(proposition, value_2, "������� ����������");
				
				PlayerInfo[playerid][pDrugs] += value_1;
				PlayerInfo[proposition][pDrugs] -= value_1;

				SaveAccounts(playerid);
				SaveAccounts(proposition);
			}
			case PROPOSITION_TYPE_SELLBIZ:
			{
				new i = GetPVarInt(playerid, "my_biz_id");

				new string[128];
				format(string, sizeof(string), "%s ��������� ���� �����������", PlayerInfo[playerid][pName]);
				SCM(proposition, green, string);

				format(string, sizeof(string), "�� ������ ������ %s �� %d ������", business_params[ BusinessInfo[i][bType] ][bname], value_1);
				SCM(playerid, blue, string);

				PlayerInfo[playerid][pBizID] = BusinessInfo[i][bID];
				PlayerInfo[proposition][pBizID] = -1;

				BusinessInfo[i][bOwner] = EOS;
				strcat(BusinessInfo[i][bOwner], PlayerInfo[playerid][pName]);

				GiveMoney(playerid, -value_1, "������� ������� � ������");
				GiveMoney(proposition, value_1, "������� ������� ������");
				SaveAccounts(playerid);
				SaveAccounts(proposition);
				UpdateBusiness(i);
				DeletePVar(playerid, "my_biz_id");
				DeletePVar(proposition, "my_biz_id");
			}

			case PROPOSITION_TYPE_SELLCAR:
			{
				new query[256];
                format
                (
                    query, sizeof query,
                    "SELECT * FROM `ownable_cars` WHERE `owner_id` = '%d' ORDER BY id DESC",
                    PlayerInfo[playerid][pID]
                );
                mysql_tquery(connects, query, "propos_check_own_cars", "dddd", playerid, proposition, value_1, value_2);
			}
			case PROPOSITION_TYPE_SELLHOUSE:
			{
				if(PlayerInfo[playerid][pCash] < value_1)
				{
					SCM(playerid, red, "� ��� ������������ �����.");
					SCM(proposition, red, "� ������ ������������ �����.");
					return 1;
				}
				if(PlayerInfo[playerid][pHomeID] != -1)
				{
					SCM(playerid, red, "� ��� ��� ���� ���.");
					SCM(proposition, red, "� ������ ��� ���� ���.");
					return 1;
				}
				new h = value_2;

				new string[128];
				format(string, sizeof(string), "%s ��������� ���� �����������", PlayerInfo[playerid][pName]);
				SCM(proposition, green, string);

				format(string, sizeof(string), "�� ������ ��� � %d �� %d ������", HouseInfo[h][hID], value_1);
				SCM(playerid, blue, string);

				PlayerInfo[playerid][pHomeID] = HouseInfo[h][hID];
				PlayerInfo[proposition][pHomeID] = -1;

				HouseInfo[h][hOwner] = EOS;
				strcat(HouseInfo[h][hOwner], PlayerInfo[playerid][pName]);

				GiveMoney(playerid, -value_1, "������� ���� � ������");
				GiveMoney(proposition, value_1, "������� ���� ������");
				SaveAccounts(playerid);
				SaveAccounts(proposition);
				SaveHouse(h);
				BuyHouse(h);
				DestroyOwnableCar(proposition);
			}
		}
	}
	else return SCM(playerid, red, "��� ������ �� ����������!");
	return 1;
}
CMD:no(playerid)
{
	new proposition = incoming_proposition[playerid];
	if(proposition == -1) return SCM(playerid, 0x999999FF, "� ������ ������ ��� ������ �� ����������");

	if(send_proposition[proposition] == playerid)
	{
		ClearProposition(proposition);

		new fmt_msg[60];
		format(fmt_msg, sizeof fmt_msg, "%s ��������� �� ������ �����������", PlayerInfo[playerid][pName]);
		SCM(proposition, 0xFF6600FF, fmt_msg);

		format(fmt_msg, sizeof fmt_msg, "�� ���������� �� ����������� ������ %s", PlayerInfo[proposition][pName]);
		SCM(playerid, 0xFF6600FF, fmt_msg);

		GameTextForPlayer(proposition, "~r~no", 4000, 1);
	}
	else SCM(playerid, 0xFF6600FF, "�� ���������� �� ����������� ������");

	ClearProposition(playerid);
	return 1;
}

publics propos_check_own_cars(playerid, proposition, value_1, value_2)
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
		new _amount;
		for(new i = 0; i < rows; i++)
		{
			_amount++;
		}
		if(_amount >= GetAccesMaxOwnableCar(playerid))
		{
			SCM(proposition, red, !"����� ������� ������������ ����������� �����������!");
			return SCM(playerid, red, !"�� �������� ������������ ����������� �����������!");
		}
	}

	if(PlayerInfo[proposition][pCarID] != value_2)
	{
		SCM(proposition, red, !"� ��� ��� ����������, ������� �� ���������� � �������!");
		return SCM(playerid, red, !"� ������ ��� ����� ���������� � ������ ������.");
	}

	new string[128];
	format(string, sizeof(string), "%s ��������� ���� �����������", PlayerInfo[playerid][pName]);
	SCM(proposition, green, string);

	format(string, sizeof(string), "�� ������ ��������� %s �� %d ������", GetCarName(GetVehicleModel(player_ownable_car[proposition])), value_1);
	SCM(playerid, blue, string);

	PlayerInfo[playerid][pCarID] = PlayerInfo[proposition][pCarID];

	ownable_car[player_ownable_car[proposition]][oc_owner_id] = PlayerInfo[playerid][pID];
	SaveOwnableCar(proposition);

	DestroyDynamic3DTextLabel(ownable_car_label[player_ownable_car[proposition]]);
	DestroyVehicle(player_ownable_car[proposition]);
	player_ownable_car[proposition] = -1;

	GiveMoney(playerid, -value_1, "������� ���������� � ������");
	GiveMoney(proposition, value_1, "������� ���������� ������");
	SaveAccounts(playerid);
	SaveAccounts(proposition);
	new query[256];
	format
	(
		query, sizeof query,
		"SELECT * FROM `ownable_cars` WHERE `owner_id` = '%d' ORDER BY id DESC",
		PlayerInfo[proposition][pID]
	);
	mysql_tquery(connects, query, "ownable_car_get_car", "d", proposition);
	return 1;
}