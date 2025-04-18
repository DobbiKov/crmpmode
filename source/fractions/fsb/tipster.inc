CMD:tipster(playerid, params[]){
    if(!IsAFSB(playerid) && PlayerInfo[playerid][bAdmin] < 2) return YouCannotUseThisFunc(playerid);
    if(IsAFSB(playerid) && PlayerInfo[playerid][pFSBRank] < 4)
        return YouCannotUseThisFunc(playerid);

    ShowTipsterDialog(playerid);
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case D_CHOOSE_TIPSTER_TYPE:{
            if(response)
            {
                switch(listitem)
                {
                    case 0:{
                        ShowTipsterFractionsDialog(playerid);
                    }
                    case 1:{
                        ShowTipsterJobsDialog(playerid);
                    }
                    case 2:{
                        cmd::me(playerid, "��������� ��������� �����");
                        SCM(playerid, blue, "�� ���������� ������������ �����.");
                        PlayerInfo[playerid][pTipster] = 0;
                        PlayerInfo[playerid][pJobTipster] = 0;
                    }
                    case 3:{
                        if(PlayerInfo[playerid][pTipster] == -1)
                        {
                            PlayerInfo[playerid][pTipster] = 0;
                        }
                        else
                        {
                            PlayerInfo[playerid][pTipster] = -1;
                        }
                    }
                }
            }
        }
        case D_CHOOSE_TIPSTER_FRACTION:
        {
            if(!response)
                return ShowTipsterDialog(playerid);
            PlayerInfo[playerid][pTipster] = listitem + 1;

            new string[256] = "";
            format(string, sizeof(string), "�� ������ ������������ ����������� %s.", GetMember[listitem + 1]);
            SCM(playerid, blue, string);
        }
        case D_CHOOSE_TIPSTER_JOB:
        {
            if(!response)
                return ShowTipsterDialog(playerid);
            PlayerInfo[playerid][pJobTipster] = listitem + 1;

            new string[256] = "";
            format(string, sizeof(string), "�� ������ ������������ ������ %s.", jobs_name[listitem + 1]);
            SCM(playerid, blue, string);
        }
	}
	#if	defined	tipster__OnDialogResponse
		return tipster__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse tipster__OnDialogResponse
#if	defined	tipster__OnDialogResponse
	forward tipster__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

stock ShowTipsterDialog(playerid)
{
    new string[512] = 
        !"{"cblue"}1. {ffffff}��������� �����������\n\
        {"cblue"}2. {ffffff}��������� �������\n\
        {"cblue"}3. {ffffff}���������� ���������\n";
    if(PlayerInfo[playerid][bAdmin] > 2)
    {
        new tempString[128] = "";
        format(
            tempString, 
            sizeof(tempString), 
            "{"cblue"}4. {ffffff}��������� ���� ����� {ffffff}[%s{ffffff}]\n", 
            (PlayerInfo[playerid][pTipster] == -1 ? "{"cgreen"}�������" : "{"cred"}��������")
            );

        strcat(string, tempString);
    }

    ShowPlayerDialog
    (
        playerid, 
        D_CHOOSE_TIPSTER_TYPE, 
        DIALOG_STYLE_LIST, 
        !"����� ���� ���������", 
        string, 
        !"�����",
        !"������"
    );
    return 1;
}

stock ShowTipsterFractionsDialog(playerid)
{
    new string[512] = "";
    
    for(new i = 1; i < sizeof(GetMember); i++)
    {
        new tempString[128] = "";
        format(tempString, sizeof(tempString), "{"cblue"}%d. {ffffff}%s\n", i, GetMember[i]);
        strcat(string, tempString);
    }
    return ShowPlayerDialog(playerid, D_CHOOSE_TIPSTER_FRACTION, DIALOG_STYLE_LIST, !"����� ����������� ��� ���������", string, !"�����", !"������");
}

stock ShowTipsterJobsDialog(playerid)
{
    new string[512] = "";
    for(new i = 1; i < sizeof(jobs_name); i++)
    {
        new tempString[128] = "";
        format(tempString, sizeof(tempString), "{"cblue"}%d. {ffffff}%s\n", i, jobs_name[i]);
        strcat(string, tempString);
    }
    return ShowPlayerDialog(playerid, D_CHOOSE_TIPSTER_JOB, DIALOG_STYLE_LIST, !"����� ������ ��� ���������", string, !"�����", !"������");
}

