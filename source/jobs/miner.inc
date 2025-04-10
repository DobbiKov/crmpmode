static
	Float: MinerCheckPoint[][3] =
	{
		{2315.9495,1650.7670,-38.0456},
		{2329.4937,1652.6265,-37.9036},
		{2324.4185,1658.5243,-37.6845}
	};


public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if((newkeys & KEY_JUMP) && !(oldkeys & KEY_JUMP) || (newkeys & KEY_FIRE))
    {
		if(GetPVarInt(playerid, "miner_job") == 1)
		{
		    if(GetPVarInt(playerid, "gruz_mine") == 1)
		    {
				if(IsPlayerAttachedObjectSlotUsed(playerid,1)) RemovePlayerAttachedObject(playerid,1);// ������� �����
				if(IsPlayerAttachedObjectSlotUsed(playerid,2)) RemovePlayerAttachedObject(playerid,2);// ������� �����
				if(IsPlayerAttachedObjectSlotUsed(playerid,3)) RemovePlayerAttachedObject(playerid,3);// ������� ������

				SetPlayerAttachedObject(playerid, 1, 18634, 6, 0.075000,0.002999,0.154000, 98.399978,-69.600013,1.100000);

				ClearAnimations(playerid);

				SetPVarInt(playerid, "gruz_mine", 0);

				DisablePlayerCheckpoint(playerid);
				new rand = random(3);
				SetPlayerCheckpoint(playerid, MinerCheckPoint[rand][0], MinerCheckPoint[rand][1], MinerCheckPoint[rand][2], 2.5);
				pCheckpoint[playerid] = CP_GET_MINE;
				
				SCM(playerid, red, "�� ������� ������� � �����! ����� ������� � �������� ���� ������!");
		    }
		}
    }
    if(newkeys == 1024)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 2283.6631,1660.1389,-39.7354))
        {
            if(GetPVarInt(playerid, "miner_job") == 1)
            {
                SPD(playerid, D_MINER_JOB, DIALOG_STYLE_MSGBOX, "{"cblue"}������ | �����", "{FFFFFF}�� ������ ��� ������ ��������� � ������ ������?", "��", "���");
            }
            else
            {
                new string[256];
                format(string, sizeof(string), "{FFFFFF}������! �� ������ ����������?\n\n���� ����� ����� �������� ���� � ������ � � �������.\n�� 1 �� ���� �� ������ �������� %d ������!", (miner_zp));
                SPD(playerid, D_MINER_JOB, DIALOG_STYLE_MSGBOX, "{"cblue"} ������ | �����", string, "��", "���");
            }
        }
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 2355.9548,2025.2953,15.9900))
		{
			SPD(playerid, D_BUY_METALL, DIALOG_STYLE_INPUT, "{"cblue"}������� �������", "{FFFFFF}1 ��. ������� ����� 20 ������.\n������� ���������� �������, ������� �� ������� ����������:", "�����", "�������");
		}
    }
	#if	defined	miner__OnPlayerKeyStateChange
		return miner__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange miner__OnPlayerKeyStateChange
#if	defined	miner__OnPlayerKeyStateChange
	forward miner__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
		case D_MINER_JOB:
		{
		    if(GetPVarInt(playerid, "miner_job") == 1)
		    {
		        if(!response) SCM(playerid, green, "�� ���������� ������ ������!");
		        else
		        {
					PayJob[playerid] = (kolvo_job[playerid]*miner_zp*XDay);
					GiveMoney(playerid, PayJob[playerid], "�������� ������");
		            SaveAccounts(playerid);
		            DeletePVar(playerid, "miner_job");

					DeletePVar(playerid, "gruz_mine");
					if(IsPlayerAttachedObjectSlotUsed(playerid,1)) RemovePlayerAttachedObject(playerid,1);// ������� �����
					if(IsPlayerAttachedObjectSlotUsed(playerid,2)) RemovePlayerAttachedObject(playerid,2);// ������� �����
					if(IsPlayerAttachedObjectSlotUsed(playerid,3)) RemovePlayerAttachedObject(playerid,3);// ������� ������

					DisablePlayerCheckpoint(playerid);
					
					new string[256];
					format(string, sizeof(string), "�� ��������� ������! �� �������� {"cyellow"}%d {"cblue"}������ �� {"cyellow"}%d {"cblue"}��. {"cblue"}�������.", PayJob[playerid], kolvo_job[playerid]);
					SCM(playerid, blue, string);

     				PayJob[playerid] = 0;
		            kolvo_job[playerid] = 0;
					ClearAnimations(playerid);
		            if(PlayerInfo[playerid][pMember] > 0) SetPlayerSkin(playerid, PlayerInfo[playerid][pFSkin]);
		            else SetPlayerSkin(playerid, PlayerInfo[playerid][pChar]);
		        }
		    }
		    else
		    {
		        if(!response) return SCM(playerid, blue, "�� ���������� �� ������ ������!");
		        else
		        {
					SCM(playerid, blue, "�� ������ ������ ������!");
					SCM(playerid, yellow, "��������������� ���� �������� �� ����� ������� ����������.");
					SCM(playerid, yellow, "������� ����� �������� � �������.");
					SCM(playerid, yellow, "���� �� ����� ������ �� ����� ������, �� ���� �������� �����������.");

					SetPlayerSkin(playerid, 16);
					SetPVarInt(playerid, "miner_job", 1);

					SetPlayerAttachedObject(playerid, 1, 18634, 6, 0.075000,0.002999,0.154000, 98.399978,-69.600013,1.100000);

					new rand = random(3);
					SetPlayerCheckpoint(playerid, MinerCheckPoint[rand][0], MinerCheckPoint[rand][1], MinerCheckPoint[rand][2], 2.5);
					pCheckpoint[playerid] = CP_GET_MINE;
				}
		    }
		}
		case D_BUY_METALL:
		{
			if(!response) return 1;
			else
			{
				if(!strlen(inputtext)) return SPD(playerid, D_BUY_METALL, DIALOG_STYLE_INPUT, "{"cblue"}������� �������", "{FFFFFF}1 ��. ������� ����� 20 ������.\n������� ���������� �������, ������� �� ������� ����������:", "�����", "�������");
				if(!IsNumeric(inputtext)) return SPD(playerid, D_BUY_METALL, DIALOG_STYLE_INPUT, "{"cblue"}������� �������", "{FFFFFF}1 ��. ������� ����� 20 ������.\n������� ���������� �������, ������� �� ������� ����������:", "�����", "�������");
				if(PlayerInfo[playerid][pMetall] + strval(inputtext) > 100)
				{
					SCM(playerid, red, "�� �� ������� ������ ������� �������!");
					return SPD(playerid, D_BUY_METALL, DIALOG_STYLE_INPUT, "{"cblue"}������� �������", "{FFFFFF}1 ��. ������� ����� 20 ������.\n������� ���������� �������, ������� �� ������� ����������:", "�����", "�������");
				} 
				if(PlayerInfo[playerid][pCash] < strval(inputtext) * 20)
				{
					SCM(playerid, red, "� ��� ��� ������� �����!");
					return SPD(playerid, D_BUY_METALL, DIALOG_STYLE_INPUT, "{"cblue"}������� �������", "{FFFFFF}1 ��. ������� ����� 20 ������.\n������� ���������� �������, ������� �� ������� ����������:", "�����", "�������");
				}

				PlayerInfo[playerid][pMetall] += strval(inputtext);
				GiveMoney(playerid, -strval(inputtext)*20, "������� �������");
				SaveAccounts(playerid);
			}
		}
    }
	#if	defined	miner__OnDialogResponse
		return miner__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse miner__OnDialogResponse
#if	defined	miner__OnDialogResponse
	forward miner__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER)
    {
		if(GetPVarInt(playerid, "miner_job") == 1)
		{
		    if(GetPVarInt(playerid, "gruz_mine") == 1)
		    {
				if(IsPlayerAttachedObjectSlotUsed(playerid,1)) RemovePlayerAttachedObject(playerid,1);// ������� �����
				if(IsPlayerAttachedObjectSlotUsed(playerid,2)) RemovePlayerAttachedObject(playerid,2);// ������� �����
				if(IsPlayerAttachedObjectSlotUsed(playerid,3)) RemovePlayerAttachedObject(playerid,3);// ������� ������

				SetPlayerAttachedObject(playerid, 1, 18634, 6, 0.075000,0.002999,0.154000, 98.399978,-69.600013,1.100000);

				ClearAnimations(playerid);

				SetPVarInt(playerid, "gruz_mine", 0);
				DisablePlayerCheckpoint(playerid);
				new rand = random(3);
				SetPlayerCheckpoint(playerid, MinerCheckPoint[rand][0], MinerCheckPoint[rand][1], MinerCheckPoint[rand][2], 2.5);
				pCheckpoint[playerid] = CP_GET_MINE;

				SCM(playerid, red, "�� ������� ������� � �����! ����� ������� � �������� ���� ������!");
		    }
		}
    }
    if(newstate == PLAYER_STATE_PASSENGER)
    {
		if(GetPVarInt(playerid, "miner_job") == 1)
		{
		    if(GetPVarInt(playerid, "gruz_mine") == 1)
		    {
				if(IsPlayerAttachedObjectSlotUsed(playerid,1)) RemovePlayerAttachedObject(playerid,1);// ������� �����
				if(IsPlayerAttachedObjectSlotUsed(playerid,2)) RemovePlayerAttachedObject(playerid,2);// ������� �����
				if(IsPlayerAttachedObjectSlotUsed(playerid,3)) RemovePlayerAttachedObject(playerid,3);// ������� ������

				SetPlayerAttachedObject(playerid, 1, 18634, 6, 0.075000,0.002999,0.154000, 98.399978,-69.600013,1.100000);

				ClearAnimations(playerid);

				SetPVarInt(playerid, "gruz_mine", 0);
				DisablePlayerCheckpoint(playerid);
				new rand = random(3);
				SetPlayerCheckpoint(playerid, MinerCheckPoint[rand][0], MinerCheckPoint[rand][1], MinerCheckPoint[rand][2], 2.5);
				pCheckpoint[playerid] = CP_GET_MINE;

				SCM(playerid, red, "�� ������� ������� � �����! ����� ������� � �������� ���� ������!");
		    }
		}
    }
    #if defined miner__OnPlayerStateChange
        return miner__OnPlayerStateChange(playerid, newstate, oldstate);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_OnPlayerStateChange
	#undef	OnPlayerStateChange
#else
	#define	_ALS_OnPlayerStateChange
#endif

#define	OnPlayerStateChange miner__OnPlayerStateChange
#if	defined	miner__OnPlayerStateChange
	forward miner__OnPlayerStateChange(playerid, newstate, oldstate); 
#endif


public OnPlayerEnterCheckpoint(playerid)
{
    switch(pCheckpoint[playerid])
    {
		case CP_GET_MINE:
		{
		    FreezePlayer(playerid, 15700);
			ApplyAnimation(playerid, "BASEBALL", "Bat_4", 4.1, 1, 1, 1, 1, 0);
			DisablePlayerCheckpoint(playerid);
			SetTimerEx("GivePlayerOre", 9800, false, "i", playerid);
		}
		case CP_PUT_MINE:
		{
			if(IsPlayerAttachedObjectSlotUsed(playerid,1)) RemovePlayerAttachedObject(playerid,1);// ������� �����
			if(IsPlayerAttachedObjectSlotUsed(playerid,2)) RemovePlayerAttachedObject(playerid,2);// ������� �����
			if(IsPlayerAttachedObjectSlotUsed(playerid,3)) RemovePlayerAttachedObject(playerid,3);// ������� ������

			new pay = 15 + random(20);
			kolvo_job[playerid] += pay;

			SetPlayerAttachedObject(playerid, 1, 18634, 6, 0.075000,0.002999,0.154000, 98.399978,-69.600013,1.100000);

			static const fmt_msg[] = "�� ��������� � ������� {"cyellow"}%d ��. {"cblue"}����.";
			new string[sizeof(fmt_msg)+(-2+3)];
			format(string, sizeof(string), fmt_msg, pay);
			SCM(playerid, blue, string);

			static const fmt_msg1[] = "����� ���������: {"cyellow"}%d ��. {"cblue"}����";
			new string1[sizeof(fmt_msg1)+(-2+3)];
			format(string1, sizeof(string1), fmt_msg1, kolvo_job[playerid]);
			SCM(playerid, blue, string1);

			ClearAnimations(playerid);

			SetPVarInt(playerid, "gruz_mine", 0);

			new rand = random(3);
			SetPlayerCheckpoint(playerid, MinerCheckPoint[rand][0], MinerCheckPoint[rand][1], MinerCheckPoint[rand][2], 2.5);
			pCheckpoint[playerid] = CP_GET_MINE;
		}
    }
    #if defined miner__OnPlayerEnterCheckpoint
        return miner__OnPlayerEnterCheckpoint(playerid);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_OnPlayerEnterCheckpoint
	#undef	OnPlayerEnterCheckpoint
#else
	#define	_ALS_OnPlayerEnterCheckpoint
#endif

#define	OnPlayerEnterCheckpoint miner__OnPlayerEnterCheckpoint
#if	defined	miner__OnPlayerEnterCheckpoint
	forward miner__OnPlayerEnterCheckpoint(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "miner_job") == 1)
    {
		if(IsPlayerAttachedObjectSlotUsed(playerid,1)) RemovePlayerAttachedObject(playerid,1);// ������� �����
		if(IsPlayerAttachedObjectSlotUsed(playerid,2)) RemovePlayerAttachedObject(playerid,2);// ������� �����
		if(IsPlayerAttachedObjectSlotUsed(playerid,3)) RemovePlayerAttachedObject(playerid,3);// ������� ������
		ClearAnimations(playerid);
		
		PayJob[playerid] = (kolvo_job[playerid]*miner_zp*XDay);
		GiveMoney(playerid, PayJob[playerid], "�������� ������");
		PayJob[playerid] = 0;
		kolvo_job[playerid] = 0;

		DeletePVar(playerid, "gruz_mine");
		DeletePVar(playerid, "miner_job");
		DisablePlayerCheckpoint(playerid);
    }

	#if defined miner__OnPlayerDisconnect
		return miner__OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else 
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect miner__OnPlayerDisconnect
#if defined miner__OnPlayerDisconnect
	forward miner__OnPlayerDisconnect(playerid, reason);
#endif

publics GivePlayerOre(playerid)
{
	if(IsPlayerAttachedObjectSlotUsed(playerid, 1))
	    RemovePlayerAttachedObject(playerid, 1);

	SetPlayerAttachedObject(playerid, 2, 905, 5, 0.020944, 0.039285, -0.035010, 0.000000, 0.000000, 0.000000, 0.301603, 0.125763, 0.233199);
	SetPlayerAttachedObject(playerid, 3, 906, 6, -0.032336, 0.111448, 0.001745, 0.000000, 0.000000, 0.000000, 0.026124, 0.048238, 0.048593);

	SetTimerEx("GivePlayerTeleg", 5700, false, "i", playerid);
	ApplyAnimation(playerid, "PED", "IDLE_chat", 4.100, 1, 1, 1, 1, 1, 0);

	return 1;
}

publics GivePlayerTeleg(playerid)
{
	if(IsPlayerAttachedObjectSlotUsed(playerid, 2)) RemovePlayerAttachedObject(playerid, 2);
	if(IsPlayerAttachedObjectSlotUsed(playerid, 3)) RemovePlayerAttachedObject(playerid, 3);

	SetPlayerAttachedObject(playerid, 2, 1458, 1, -1.034844, 1.116571, -0.065124, 76.480148, 75.781570, 280.952545, 0.575599, 0.604554, 0.624122);
	SetPlayerAttachedObject(playerid, 3, 905, 1, -0.275758, 1.305280, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);

	SetPlayerCheckpoint(playerid, 2295.0640,1660.5531,-39.4518, 2.0);
	pCheckpoint[playerid] = CP_PUT_MINE;

	SetPVarInt(playerid, "gruz_mine", 1);

	ClearAnimations(playerid);
	ApplyAnimation(playerid, "GHANDS", "gsign3LH", 4.1, 1, 1, 1, 1, 2250, 0);

	return 1;
}

public OnPlayerUpdate(playerid)
{
	if(!IsPlayerInRangeOfPoint(playerid, 80.0, 2295.0640,1660.5531,-39.4518))
	{
		if(GetPVarInt(playerid, "miner_job") == 1)
		{
			if(IsPlayerAttachedObjectSlotUsed(playerid,1)) RemovePlayerAttachedObject(playerid,1);// ������� �����
			if(IsPlayerAttachedObjectSlotUsed(playerid,2)) RemovePlayerAttachedObject(playerid,2);// ������� �����
			if(IsPlayerAttachedObjectSlotUsed(playerid,3)) RemovePlayerAttachedObject(playerid,3);// ������� ������
			
			PayJob[playerid] = (kolvo_job[playerid]*miner_zp*XDay);
			GiveMoney(playerid, PayJob[playerid], "�������� ������");
			PayJob[playerid] = 0;
			kolvo_job[playerid] = 0;
			SaveAccounts(playerid);

			ClearAnimations(playerid);

			DeletePVar(playerid, "gruz_mine");
			DeletePVar(playerid, "miner_job");
	
            if(PlayerInfo[playerid][pMember] > 0) SetPlayerSkin(playerid, PlayerInfo[playerid][pFSkin]);
            else SetPlayerSkin(playerid, PlayerInfo[playerid][pChar]);

			DisablePlayerCheckpoint(playerid);

			SCM(playerid, red, "�� ���� ������� ������ �� ������ ����� ������ � ���� �� ��� �������!");
		}
	}
	#if defined miner__OnPlayerUpdate
		return miner__OnPlayerUpdate(playerid);
	#else 
		return 1;
	#endif
}
#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate miner__OnPlayerUpdate
#if defined miner__OnPlayerUpdate
	forward miner__OnPlayerUpdate(playerid);
#endif