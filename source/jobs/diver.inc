




public OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "diver_job") == 1)
    {
		PayJob[playerid] = (kolvo_job[playerid]*diver_zp*XDay);
		GiveMoney(playerid, PayJob[playerid], "�������� ��������");

		PayJob[playerid] = 0;
		kolvo_job[playerid] = 0;

		DeletePVar(playerid, "diver_job");
		DeletePVar(playerid, "gruz_diver_1");
		DeletePVar(playerid, "gruz_diver_2");

		RemovePlayerAttachedObject(playerid,0);
		RemovePlayerAttachedObject(playerid,1);
		RemovePlayerAttachedObject(playerid,2);
		RemovePlayerAttachedObject(playerid,8);
		RemovePlayerAttachedObject(playerid,5);
    }
    #if defined diver__OnPlayerDisconnect
        return diver__OnPlayerDisconnect(playerid, reason);
    #else 
        return 1;
    #endif
}
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else   
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect diver__OnPlayerDisconnect
#if defined diver__OnPlayerDisconnect
    forward diver__OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 2813.1321,-1356.1815,4.0903))
        {
			if(PlayerInfo[playerid][pLVL] < 2) return SCM(playerid, red, "�� ������ ������ ����� �������� ������ �� 2-�� ������!");
            if(GetPVarInt(playerid, "diver_job") == 1)
            {
                SPD(playerid, D_DIVER_JOB, DIALOG_STYLE_MSGBOX, "{"cblue"}������ | �������", "{FFFFFF}�� ������ ��� ������ ��������� � ������ ��������?", "��", "���");
            }
            else
            {
                new string[256];
                format(string, sizeof(string), "{FFFFFF}������! �� ������ ����������?\n\n���� ����� ����� ������� 2 ����� �� ����������� ������.\n�� 1 ���� �� ������ �������� %d ������!", (diver_zp));
                SPD(playerid, D_DIVER_JOB, DIALOG_STYLE_MSGBOX, "{"cblue"} ������ | �������", string, "��", "���");
            }
        }
    }
	#if	defined	diver__OnPlayerKeyStateChange
		return diver__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange diver__OnPlayerKeyStateChange
#if	defined	diver__OnPlayerKeyStateChange
	forward diver__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
		case D_DIVER_JOB:
		{
		    if(GetPVarInt(playerid, "diver_job") == 1)
		    {
		        if(!response) SCM(playerid, green, "�� ���������� ������ ��������!");
				else
				{
					PayJob[playerid] = (kolvo_job[playerid]*diver_zp*XDay);
					GiveMoney(playerid, PayJob[playerid], "�������� ��������");
					
					new string[128];
					format(string, sizeof(string), "����� ����������: {"cyellow"}%d {"cblue"}������.", PayJob[playerid]);
					SCM(playerid, blue, string);
					
					format(string, sizeof(string), "����� ������ ����������: {"cyellow"}%d", kolvo_job[playerid]);
					SCM(playerid, blue, string);
					
					PayJob[playerid] = 0;
					kolvo_job[playerid] = 0;
					
					DeletePVar(playerid, "diver_job");
					DeletePVar(playerid, "gruz_diver_1");
					DeletePVar(playerid, "gruz_diver_2");
					
					RemovePlayerAttachedObject(playerid,0);
					RemovePlayerAttachedObject(playerid,1);
					RemovePlayerAttachedObject(playerid,2);
					RemovePlayerAttachedObject(playerid,8);
					RemovePlayerAttachedObject(playerid,5);
					SetPlayerHealth(playerid, PlayerInfo[playerid][pHP]);
					
					if(PlayerInfo[playerid][pMember] > 0) SetPlayerSkin(playerid, PlayerInfo[playerid][pFSkin]);
					else SetPlayerSkin(playerid, PlayerInfo[playerid][pChar]);
				}
			}
			else
			{
			    if(!response) return SCM(playerid, blue, "�� ���������� �� ������ ��������!");
			    else
			    {
			        GetPlayerHealth(playerid, PlayerInfo[playerid][pHP]);
					if(PlayerInfo[playerid][pSex]) SetPlayerSkin(playerid, 154);
					else SetPlayerSkin(playerid, 140);

					SetPlayerHealth(playerid, 100000000.0);

					SCM(playerid, blue, "�� ������ ������ ��������!");
					SCM(playerid, yellow, "����� ��������� � ���������� ������ ����� ������.");
					SCM(playerid, yellow, "�������� ����� �������� �� �����.");
					SCM(playerid, yellow, "���� �� ����� ������ �� ����� ������ ��, ���� �������� �����������.");

					SetPVarInt(playerid, "diver_job", 1);

					SetPlayerAttachedObject(playerid, 0, 18843, 2, 0.05, 0.0, 0.0, 0.0, 0.0, 0.004, 0.004, 0.004, 0.004);

					SetPlayerAttachedObject(playerid, 5, 1010, 1, -0.023000,-0.071999,-0.020999,-84.700012,176.299942,1.700001,1.000000,1.000000,1.000000);
			    }
			}
		}
    }
	#if	defined	diver__OnDialogResponse
		return diver__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse diver__OnDialogResponse
#if	defined	diver__OnDialogResponse
	forward diver__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif


public OnPlayerEnterCheckpoint(playerid)
{
    switch(pCheckpoint[playerid])
    {
		case CP_PUT_DIVE:
		{
		    if(GetPVarInt(playerid, "diver_job") != 1) return 1;
		    
		    SetPVarInt(playerid, "gruz_diver_1", 0);
		    SetPVarInt(playerid, "gruz_diver_2", 0);
		    DisablePlayerCheckpoint(playerid);
			SetPlayerHealth(playerid, 100000000.0);
		    
			RemovePlayerAttachedObject(playerid,1);
			RemovePlayerAttachedObject(playerid,2);
			RemovePlayerAttachedObject(playerid,8);
			
			kolvo_job[playerid] += 2;
			
			SCM(playerid, yellow, "�� ������� ���� �� ����������� ������.");
			SCM(playerid, yellow, "������ �� ������ ������� ��� ����, ���� ��������� ������.");
			new string[128];
			format(string, sizeof(string), "����� ������ ����������: {"cyellow"}%d", kolvo_job[playerid]);
			SCM(playerid, blue, string);
		}
    }
    #if defined diver__OnPlayerEnterCheckpoint
        return diver__OnPlayerEnterCheckpoint(playerid);
    #else
        return 1;
    #endif
}
#if	defined	_ALS_OnPlayerEnterCheckpoint
	#undef	OnPlayerEnterCheckpoint
#else
	#define	_ALS_OnPlayerEnterCheckpoint
#endif

#define	OnPlayerEnterCheckpoint diver__OnPlayerEnterCheckpoint
#if	defined	diver__OnPlayerEnterCheckpoint
	forward diver__OnPlayerEnterCheckpoint(playerid);
#endif

public OnPlayerPickUpPickup(playerid, pickupid)
{
	if(pickupid == DIVER_PICK_1)
	{
	    if(GetPVarInt(playerid, "diver_job") != 1) return SCM(playerid, red, "�� �� ��������� ���������!");
		if(GetPVarInt(playerid, "gruz_diver_1") == 1) return SCM(playerid, red, "�� ��� ��������� ���� ����!");

		SetPVarInt(playerid, "gruz_diver_1", 1);

		SetPlayerAttachedObject(playerid,1, 1279, 5,0.273000,0.039999,-0.011000,61.400001,6.000006,10.100000,1.000000,1.000000,1.000000);

		SCM(playerid, yellow, "�� ������� ���������� ����");
		if(GetPVarInt(playerid, "gruz_diver_1") == 1 && GetPVarInt(playerid, "gruz_diver_2") == 1)
		{
		    SCM(playerid, yellow, "�� ������� ��� �����, ������ �������� �� �� �����!");
		}
	}
	if(pickupid == DIVER_PICK_2)
	{
	    if(GetPVarInt(playerid, "diver_job") != 1) return SCM(playerid, red, "�� �� ��������� ���������!");
		if(GetPVarInt(playerid, "gruz_diver_1") != 1) return SCM(playerid, red, "�� ��� �� ��������� ���� �� ������ ����� ������!");
		if(GetPVarInt(playerid, "gruz_diver_2") == 1) return SCM(playerid, red, "�� ��� ��������� ���� ����!");

		SetPVarInt(playerid, "gruz_diver_2", 1);

		SetPlayerAttachedObject(playerid,2, 1279, 6,0.330999,0.065999,0.072999,94.600006,-3.500000,11.500000,1.000000,1.000000,1.000000);

        SetPlayerCheckpoint(playerid, 2815.9971, -1380.4711, 2.9151, 3.0);
		pCheckpoint[playerid] = CP_PUT_DIVE;

		SCM(playerid, yellow, "�� ������� ���������� ����");
		if(GetPVarInt(playerid, "gruz_diver_1") == 1 && GetPVarInt(playerid, "gruz_diver_2") == 1)
		{
		    SCM(playerid, yellow, "�� ������� ��� �����, ������ �������� �� �� �����!");
		}
	}
    #if defined diver__OnPlayerPickUpPickup
        return diver__OnPlayerPickUpPickup(playerid, pickupid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerPickUpPickup
    #undef OnPlayerPickUpPickup
#else 
    #define _ALS_OnPlayerPickUpPickup
#endif

#define OnPlayerPickUpPickup diver__OnPlayerPickUpPickup
#if defined diver__OnPlayerPickUpPickup
    forward diver__OnPlayerPickUpPickup(playerid, pickupid);
#endif

public OnPlayerUpdate(playerid)
{
	if(!IsPlayerInRangeOfPoint(playerid, 300.0, 2815.9971,-1380.4711,2.9151))
	{
	    if(GetPVarInt(playerid, "diver_job") == 1)
	    {
			PayJob[playerid] = (kolvo_job[playerid]*diver_zp*XDay);
			GiveMoney(playerid, PayJob[playerid], "�������� ��������");

			SCM(playerid, red, "�� ���� ������� ������ �� ������ ����� ������ � ���� ������� �� ���!");

			PayJob[playerid] = 0;
			kolvo_job[playerid] = 0;

			DeletePVar(playerid, "diver_job");
			DeletePVar(playerid, "gruz_diver_1");
			DeletePVar(playerid, "gruz_diver_2");

			RemovePlayerAttachedObject(playerid,0);
			RemovePlayerAttachedObject(playerid,1);
			RemovePlayerAttachedObject(playerid,2);
			RemovePlayerAttachedObject(playerid,8);
			RemovePlayerAttachedObject(playerid,5);
			
			SetPlayerHealth(playerid, PlayerInfo[playerid][pHP]);

			if(PlayerInfo[playerid][pMember] > 0) SetPlayerSkin(playerid, PlayerInfo[playerid][pFSkin]);
			else SetPlayerSkin(playerid, PlayerInfo[playerid][pChar]);
	    }
	}
	#if defined diver__OnPlayerUpdate
		return diver__OnPlayerUpdate(playerid);
	#else 
		return 1;
	#endif
}
#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate diver__OnPlayerUpdate
#if defined diver__OnPlayerUpdate
	forward diver__OnPlayerUpdate(playerid);
#endif