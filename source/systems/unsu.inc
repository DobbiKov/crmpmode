public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1924.8105,-1907.2042,32.0061))
        {
			SPD(playerid, D_CLEAR_SU, DIALOG_STYLE_MSGBOX, 
            "{"cblue"}������ �������", 
            "\
			{ffffff}�� ��������� �� ������ �����.\n\n\
			{ffffff}����������� ������ ������� {"cblue"}70% \n\
			{ffffff}��������� ������ ������� {"cblue"}100 000 ���.\n\n\
			{ffffff}�������� �� ��������� ������������ ������ �������?", 
            "��", "���");
        }
    }
	#if	defined	unsu__OnPlayerKeyStateChange
		return unsu__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange unsu__OnPlayerKeyStateChange
#if	defined	unsu__OnPlayerKeyStateChange
	forward unsu__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
		case D_CLEAR_SU:
		{
		    if(!response) return 1;

            if(PlayerInfo[playerid][pWANTED] < 1)
                return SCM(playerid, red, !"�� �� ���������� � �������!");
            if(PlayerInfo[playerid][pCash] < 100000)
                return SCM(playerid, red, !"� ��� ������������ �������!");

            GiveMoney(playerid, -100000, "������ ������� �� ������");
            new rand = random(11);
            if(rand % 3 == 0)
            {
                PlayerInfo[playerid][pWANTED] = 0;
                SetPlayerWantedLevel(playerid, PlayerInfo[playerid][pWANTED]);
                SCM(playerid, green, !"������ ������ �������! � ��� ��� ���� ������.");
                return SaveAccounts(playerid);
            }
            SCM(playerid, red, !"������ �� �����!");
            return SaveAccounts(playerid);
		}
    }
	#if	defined	unsu__OnDialogResponse
		return unsu__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse unsu__OnDialogResponse
#if	defined	unsu__OnDialogResponse
	forward unsu__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif