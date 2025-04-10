public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
        if(job_car[TEAM_OREX_CAR][0] <= vehicleid <= job_car[TEAM_OREX_CAR][1])
        {
            if(PlayerInfo[playerid][pMember] != TEAM_OREX && !IsAFSB(playerid))
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "� ��� ��� ������ �� ����� ����������!");
            }
        }
        if(job_car[TEAM_SUN_CAR][0] <= vehicleid <= job_car[TEAM_SUN_CAR][1])
        {
            if(PlayerInfo[playerid][pMember] != TEAM_SUN && !IsAFSB(playerid))
            {
                ClearAnimations(playerid, true);
                return SCM(playerid, red, "� ��� ��� ������ �� ����� ����������!");
            }
        }
	}
	#if	defined	opg__OnPlayerEnterVehicle
		return opg__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerEnterVehicle
	#undef	OnPlayerEnterVehicle
#else
	#define	_ALS_OnPlayerEnterVehicle
#endif

#define	OnPlayerEnterVehicle opg__OnPlayerEnterVehicle
#if	defined	opg__OnPlayerEnterVehicle
	forward opg__OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif


public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 2610.9668,1767.7485,10.2175))
        {
            if(PlayerInfo[playerid][pMember] != TEAM_OREX) return YouCannotUseThisFunc(playerid);
            if(OPG_O_STATUS == 0) return SCM(playerid, red, "� ������ ������ ����� ������!");

            ShowSkladOpg(playerid);
        }
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1705.9067,1337.9858,26.0344))
        {
            if(PlayerInfo[playerid][pMember] != TEAM_SUN) return YouCannotUseThisFunc(playerid);
            if(OPG_S_STATUS == 0) return SCM(playerid, red, "� ������ ������ ����� ������!");

            ShowSkladOpg(playerid);
        }
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 2927.5752,994.5273,3.8847))
        {
            if(!IsAOpg(playerid)) return YouCannotUseThisFunc(playerid);
            SPD(playerid, D_BUY_DRUGS, DIALOG_STYLE_INPUT, "{"cblue"}������� ����������", "{"cblue"}1 ��. {FFFFFF}���������� ����� {"cblue"}500 ������{FFFFFF}.\n����� ���������� ���������� �� ������ ������?", "�����", "������");
        }

        if(IsPlayerInRangeOfPoint(playerid, 3.0,  1706.90, 1330.35, 12.72)){ // ����� ��� ������
            if(PlayerInfo[playerid][pMember] == TEAM_SUN){
                switch(OpgDoorsStatus[OPG_S_DOOR]){
                    case false: {//�������
                        SCM(playerid, green, !"�� ������� �����.");
                        MoveObject(OpgDoors[OPG_S_DOOR], 1706.90, 1330.35, 12.72, 5.0, 0.00, 0.00, 290.59);
                        OpgDoorsStatus[OPG_S_DOOR] = true;
                    }
                    case true:{
                        SCM(playerid, red, !"�� ������� �����.");
                        MoveObject(OpgDoors[OPG_S_DOOR], 1706.93, 1330.34, 12.76, 5.0, 0.00, 0.00, 0.00);
                        OpgDoorsStatus[OPG_S_DOOR] = false;                       
                    }
                }
            }
        }
        if(IsPlayerInRangeOfPoint(playerid, 3.0,  2601.98, 1769.14, 2.51)){ // ����� ��� �����
            if(PlayerInfo[playerid][pMember] == TEAM_OREX){
                switch(OpgDoorsStatus[OPG_O_DOOR]){
                    case false: {//�������
                        SCM(playerid, green, !"�� ������� �����.");
                        MoveObject(OpgDoors[OPG_O_DOOR], 2601.98, 1769.14, 2.51, 5.0, 0.00, 0.00, 88.75);
                        OpgDoorsStatus[OPG_O_DOOR] = true;
                    }
                    case true:{
                        SCM(playerid, red, !"�� ������� �����.");
                        MoveObject(OpgDoors[OPG_O_DOOR], 2601.98, 1769.14, 2.51, 5.0, 0.00, 0.00, 0.00);
                        OpgDoorsStatus[OPG_O_DOOR] = false;                       
                    }
                }
            }
        }
    }
	#if	defined	opg__OnPlayerKeyStateChange
		return opg__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange opg__OnPlayerKeyStateChange
#if	defined	opg__OnPlayerKeyStateChange
	forward opg__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif



public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_BUY_DRUGS:
        {
            if(!response) return 1;
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext)) return SPD(playerid, D_BUY_DRUGS, DIALOG_STYLE_INPUT, "{"cblue"}������� ����������", "{"cblue"}1 ��. {FFFFFF}���������� ����� {"cblue"}500 ������{FFFFFF}.\n����� ���������� ���������� �� ������ ������?", "�����", "������");
                if(ALL_NARKO < strval(inputtext)) return SCM(playerid, red, "� ����� ��� ������� ����������!");
                if(PlayerInfo[playerid][pCash] < strval(inputtext)*500) return SCM(playerid, red, "� ��� ��� ������� �����!");
                if(strval(inputtext) < 1) return SPD(playerid, D_BUY_DRUGS, DIALOG_STYLE_INPUT, "{"cblue"}������� ����������", "{"cblue"}1 ��. {FFFFFF}���������� ����� {"cblue"}500 ������{FFFFFF}.\n����� ���������� ���������� �� ������ ������?", "�����", "������");
                
                if(!CanPlayerGetAmountDrugs(playerid, strval(inputtext)))
                    return SCM(playerid, red, !"�� �� ������ ������ ������� ����������!");

                GiveMoney(playerid, -(strval(inputtext)*500), "������� ���������� � �����");
                PlayerInfo[playerid][pDrugs] += strval(inputtext);
                ALL_NARKO -= strval(inputtext);
                new string[144];
                format(string, sizeof(string), "�� ������ %d ��. ����������!", strval(inputtext));
                SCM(playerid, blue, string); 
                SaveAccounts(playerid);
                SaveRepository();
            }
        }
        case D_SKLAD_OPG:
        {
            if(!response) return 1;
            else
            {
                switch(listitem)
                {
                    case 0: return SPD(playerid, D_SKLAD_OPG_TAKE_PATR, DIALOG_STYLE_INPUT, "{"cblue"}����� | �������", "{FFFFFF}������� ���������� ��������, ����� �� ������ �����:", "�����", "�����");
                    case 1: return SPD(playerid, D_SKLAD_OPG_PUT_PATR, DIALOG_STYLE_INPUT, "{"cblue"}����� | �������", "{FFFFFF}������� ���������� ��������, ����� �� ������ ��������:", "�����", "�����");
                    case 2: return SPD(playerid, D_SKLAD_OPG_TAKE_MET, DIALOG_STYLE_INPUT, "{"cblue"}����� | ������", "{FFFFFF}������� ���������� ��������, ����� �� ������ �����:", "�����", "�����");
                    case 3: return SPD(playerid, D_SKLAD_OPG_PUT_MET, DIALOG_STYLE_INPUT, "{"cblue"}����� | ������", "{FFFFFF}������� ���������� ��������, ����� �� ������ ��������:", "�����", "�����");
                    case 4: return SPD(playerid, D_SKLAD_OPG_TAKE_DRUGS, DIALOG_STYLE_INPUT, "{"cblue"}����� | ���������", "{FFFFFF}������� ���������� ��������, ����� �� ������ �����:", "�����", "�����");
                    case 5: return SPD(playerid, D_SKLAD_OPG_PUT_DRUGS, DIALOG_STYLE_INPUT, "{"cblue"}����� | ���������", "{FFFFFF}������� ���������� ��������, ����� �� ������ ��������:", "�����", "�����");
                    case 6: 
                    {
                        if(PlayerInfo[playerid][pRang] < 10) return YouCannotUseThisFunc(playerid);
                        return SPD(playerid, D_SKLAD_OPG_TAKE_MONEY, DIALOG_STYLE_INPUT, "{"cblue"}����� | ������", "{FFFFFF}������� ���������� �����, ����� �� ������ �����:", "�����", "�����");
                    }
                    case 7: return SPD(playerid, D_SKLAD_OPG_PUT_MONEY, DIALOG_STYLE_INPUT, "{"cblue"}����� | ������", "{FFFFFF}������� ���������� �����, ����� �� ������ ��������:", "�����", "�����");
                }
            }
        }
        case D_SKLAD_OPG_TAKE_PATR:
        {
            if(!response) return ShowSkladOpg(playerid);
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext)) return SPD(playerid, D_SKLAD_OPG_TAKE_PATR, DIALOG_STYLE_INPUT, "{"cblue"}����� | �������", "{FFFFFF}������� ���������� ��������, ����� �� ������ �����:", "�����", "�����");
                if((PlayerInfo[playerid][pPatr] + strval(inputtext)) > 600) return SCM(playerid, red, "�� �� ������� ������� ��������!");

                if(PlayerInfo[playerid][pMember] == TEAM_OREX)
                {
                    if(OPG_O_PATRON < strval(inputtext)) return SCM(playerid, red, "�� ������ ��� ������� ��������!");

                    OPG_O_PATRON -= strval(inputtext);
                } 
                else if(PlayerInfo[playerid][pMember] == TEAM_SUN)
                {
                    if(OPG_S_PATRON < strval(inputtext)) return SCM(playerid, red, "�� ������ ��� ������� ��������!");

                    OPG_S_PATRON -= strval(inputtext);
                }
                new string[144];
                format(string, sizeof(string), "[R] %s %s[%d] ���� �� ������ ����������� %d ��.", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid, strval(inputtext));
                SCMR(PlayerInfo[playerid][pMember], green, string);
                PlayerInfo[playerid][pPatr] += strval(inputtext);
                SaveAccounts(playerid);
                SaveRepository();
            }
        }
        case D_SKLAD_OPG_TAKE_MET:
        {
            if(!response) return ShowSkladOpg(playerid);
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext)) return SPD(playerid, D_SKLAD_OPG_TAKE_MET, DIALOG_STYLE_INPUT, "{"cblue"}����� | �������", "{FFFFFF}������� ���������� �������, ����� �� ������ �����:", "�����", "�����");
                if((PlayerInfo[playerid][pMetall] + strval(inputtext)) > 100) return SCM(playerid, red, "�� �� ������� ������� �������!");

                if(PlayerInfo[playerid][pMember] == TEAM_OREX)
                {
                    if(OPG_O_METALL < strval(inputtext)) return SCM(playerid, red, "�� ������ ��� ������� �������!");

                    OPG_O_METALL -= strval(inputtext);
                } 
                else if(PlayerInfo[playerid][pMember] == TEAM_SUN)
                {
                    if(OPG_S_METALL < strval(inputtext)) return SCM(playerid, red, "�� ������ ��� ������� �������!");

                    OPG_S_METALL -= strval(inputtext);
                }
                new string[144];
                format(string, sizeof(string), "[R] %s %s[%d] ���� �� ������ ����������� %d ��. �������", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid, strval(inputtext));
                SCMR(PlayerInfo[playerid][pMember], green, string);
                PlayerInfo[playerid][pMetall] += strval(inputtext);
                SaveAccounts(playerid);
                SaveRepository();
            }
        }
        case D_SKLAD_OPG_TAKE_DRUGS:
        {
            if(!response) return ShowSkladOpg(playerid);
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext)) return SPD(playerid, D_SKLAD_OPG_TAKE_DRUGS, DIALOG_STYLE_INPUT, "{"cblue"}����� | �������", "{FFFFFF}������� ���������� ����������, ����� �� ������ �����:", "�����", "�����");

                if(!CanPlayerGetAmountDrugs(playerid, strval(inputtext)))
                    return SCM(playerid, red, !"�� �� ������ ������ ������� ����������!");

                if(PlayerInfo[playerid][pMember] == TEAM_OREX)
                {
                    if(OPG_O_DRUGS < strval(inputtext)) return SCM(playerid, red, "�� ������ ��� ������� ����������!");

                    OPG_O_DRUGS -= strval(inputtext);
                } 
                else if(PlayerInfo[playerid][pMember] == TEAM_SUN)
                {
                    if(OPG_S_DRUGS < strval(inputtext)) return SCM(playerid, red, "�� ������ ��� ������� ����������!");

                    OPG_S_DRUGS -= strval(inputtext);
                }
                new string[144];
                format(string, sizeof(string), "[R] %s %s[%d] ���� �� ������ ����������� %d ��. ����������", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid, strval(inputtext));
                SCMR(PlayerInfo[playerid][pMember], green, string);
                PlayerInfo[playerid][pDrugs] += strval(inputtext);
                SaveAccounts(playerid);
                SaveRepository();
            }
        }
        case D_SKLAD_OPG_TAKE_MONEY:
        {
            if(!response) return ShowSkladOpg(playerid);
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext)) return SPD(playerid, D_SKLAD_OPG_TAKE_MONEY, DIALOG_STYLE_INPUT, "{"cblue"}����� | �������", "{FFFFFF}������� ���������� �����, ����� �� ������ �����:", "�����", "�����");

                if(PlayerInfo[playerid][pMember] == TEAM_OREX)
                {
                    if(OPG_O_MONEY < strval(inputtext)) return SCM(playerid, red, "�� ������ ��� ������� �����!");

                    OPG_O_MONEY -= strval(inputtext);
                } 
                else if(PlayerInfo[playerid][pMember] == TEAM_SUN)
                {
                    if(OPG_S_MONEY < strval(inputtext)) return SCM(playerid, red, "�� ������ ��� ������� �����!");

                    OPG_S_MONEY -= strval(inputtext);
                }
                new string[144];
                format(string, sizeof(string), "[R] %s %s[%d] ���� �� ������ ����������� %d ���.", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid, strval(inputtext));
                SCMR(PlayerInfo[playerid][pMember], green, string);
                GiveMoney(playerid, strval(inputtext), "�� ������ ����");
                SaveAccounts(playerid);
                SaveRepository();
            }
        }
        case D_SKLAD_OPG_PUT_PATR:
        {
            if(!response) return ShowSkladOpg(playerid);
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext)) return SPD(playerid, D_SKLAD_OPG_PUT_PATR, DIALOG_STYLE_INPUT, "{"cblue"}����� | �������", "{FFFFFF}������� ���������� ��������, ����� �� ������ ��������:", "�����", "�����");
                if(PlayerInfo[playerid][pPatr] < strval(inputtext)) return SCM(playerid, red, "� ��� ��� ������� ��������!");

                if(PlayerInfo[playerid][pMember] == TEAM_OREX) OPG_O_PATRON += strval(inputtext);
                else if(PlayerInfo[playerid][pMember] == TEAM_SUN) OPG_S_PATRON += strval(inputtext);
                PlayerInfo[playerid][pPatr] -= strval(inputtext);
                new string[144];
                format(string, sizeof(string), "[R] %s %s[%d] ������� �� ����� ����������� %d ��.", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid, strval(inputtext));
                SCMR(PlayerInfo[playerid][pMember], green, string);
                SaveAccounts(playerid);
                SaveRepository();
            }
        }
        case D_SKLAD_OPG_PUT_MET:
        {
            if(!response) return ShowSkladOpg(playerid);
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext)) return SPD(playerid, D_SKLAD_OPG_PUT_MET, DIALOG_STYLE_INPUT, "{"cblue"}����� | �������", "{FFFFFF}������� ���������� �������, ����� �� ������ ��������:", "�����", "�����");
                if(PlayerInfo[playerid][pMetall] < strval(inputtext)) return SCM(playerid, red, "� ��� ��� ������� �������!");

                if(PlayerInfo[playerid][pMember] == TEAM_OREX) OPG_O_METALL += strval(inputtext);
                else if(PlayerInfo[playerid][pMember] == TEAM_SUN) OPG_S_METALL += strval(inputtext);
                new string[144];
                format(string, sizeof(string), "[R] %s %s[%d] ������� �� ����� ����������� %d ��. �������", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid, strval(inputtext));
                SCMR(PlayerInfo[playerid][pMember], green, string);
                PlayerInfo[playerid][pMetall] -= strval(inputtext);
                SaveAccounts(playerid);
                SaveRepository();
            }
        }
        case D_SKLAD_OPG_PUT_DRUGS:
        {
            if(!response) return ShowSkladOpg(playerid);
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext)) return SPD(playerid, D_SKLAD_OPG_PUT_DRUGS, DIALOG_STYLE_INPUT, "{"cblue"}����� | �������", "{FFFFFF}������� ���������� ����������, ����� �� ������ ��������:", "�����", "�����");
                if(PlayerInfo[playerid][pDrugs] < strval(inputtext)) return SCM(playerid, red, "� ��� ��� ������� ����������!");

                if(PlayerInfo[playerid][pMember] == TEAM_OREX) OPG_O_DRUGS += strval(inputtext);
                else if(PlayerInfo[playerid][pMember] == TEAM_SUN) OPG_S_DRUGS += strval(inputtext);
                new string[144];
                format(string, sizeof(string), "[R] %s %s[%d] ������� �� ����� ����������� %d ��. ����������", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid, strval(inputtext));
                SCMR(PlayerInfo[playerid][pMember], green, string);
                PlayerInfo[playerid][pDrugs] -= strval(inputtext);
                SaveAccounts(playerid);
                SaveRepository();
            }
        }
        case D_SKLAD_OPG_PUT_MONEY:
        {
            if(!response) return ShowSkladOpg(playerid);
            else
            {
                if(!strlen(inputtext) || !IsNumeric(inputtext)) return SPD(playerid, D_SKLAD_OPG_PUT_MONEY, DIALOG_STYLE_INPUT, "{"cblue"}����� | �������", "{FFFFFF}������� ���������� �����, ����� �� ������ ��������:", "�����", "�����");
                if(PlayerInfo[playerid][pCash] < strval(inputtext)) return SCM(playerid, red, "� ��� ��� ������� �����!");

                if(PlayerInfo[playerid][pMember] == TEAM_OREX) OPG_O_MONEY += strval(inputtext);
                else if(PlayerInfo[playerid][pMember] == TEAM_SUN) OPG_S_MONEY += strval(inputtext);
                new string[144];
                format(string, sizeof(string), "[R] %s %s[%d] ������� �� ����� ����������� %d ���.", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid, strval(inputtext));
                SCMR(PlayerInfo[playerid][pMember], green, string);
                GiveMoney(playerid, -strval(inputtext), "�� ������ ����");
                SaveAccounts(playerid);
                SaveRepository();
            }
        }
    }
	#if	defined	opg__OnDialogResponse
		return opg__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse opg__OnDialogResponse
#if	defined	opg__OnDialogResponse
	forward opg__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

stock ShowSkladOpg(playerid)
{
    SPD
    (
        playerid, D_SKLAD_OPG, DIALOG_STYLE_LIST, "{"cblue"}����� �����������", "\
        {"cblue"}1. {FFFFFF}����� �������\n\
        {"cblue"}2. {FFFFFF}�������� �������\n\
        {"cblue"}3. {FFFFFF}����� ������\n\
        {"cblue"}4. {FFFFFF}�������� ������\n\
        {"cblue"}5. {FFFFFF}����� ���������\n\
        {"cblue"}6. {FFFFFF}�������� ���������\n\
        {"cblue"}7. {FFFFFF}����� ������\n\
        {"cblue"}8. {FFFFFF}�������� ������", "�����", "������"
    );
    return 1;
}