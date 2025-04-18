CMD:apanel(playerid)
    return cmd::adminpanel(playerid);
CMD:adminpanel(playerid)
{
	if(PlayerInfo[playerid][bAdmin] < 1) return ShowCommandNotFound(playerid);

	return ShowAdminPanel(playerid);
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case D_ADMIN_PANEL:{
            if(response)
            {
                switch(listitem)
                {
                    case 0: return ShowAdminsOnline(playerid);
                    case 1:
                    {
                        ChangeStreamerMode(playerid);
                        ShowAdminPanel(playerid);
                    }
                    case 2:
                    {
                        cmd::tipster(playerid, "");
                    }
                    case 3:
					{ 
						if(PlayerInfo[playerid][bAdmin] >= 2) return ShowTeleportList(playerid);
						return ShowApanel(playerid);
					}                    
                    case 4:
                    {
                        if(PlayerInfo[playerid][bAdmin] < 7)
                        {
                            return SCM(playerid, red, !"��� �� �������� ������ �������!");
                        }
                        ChangeDeveloperMode(playerid);
                        ShowAdminPanel(playerid);
                    }
                }
            }
        }
	}
	#if	defined	adminpanel__OnDialogResponse
		return adminpanel__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse adminpanel__OnDialogResponse
#if	defined	adminpanel__OnDialogResponse
	forward adminpanel__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif //D_ADMIN_PANEL

stock ShowAdminPanel(playerid)
{
    new string[256] = "";
    new developerMode[24] = "";
    new streamerMode[24] = "";
    developerMode = (PlayerInfo[playerid][bDeveloper] == 1 ? "{"cgreen"}�������" : "{"cred"}��������");
    streamerMode = (PlayerInfo[playerid][bStreamerMode] == 1 ? "{"cgreen"}�������" : "{"cred"}��������");
    format(string, sizeof(string), 
        "{"cblue"}1. {"cwhite"}��� �������������� [������]\n\
        {"cblue"}2. {FFFFFF}����� �������-������� {ffffff}[%s{ffffff}]\n\
        {"cblue"}3. {FFFFFF}���������\n\
        {"cblue"}4. {ffffff}��������\n\
        {"cblue"}5. {FFFFFF}����� ������������ {ffffff}[%s{ffffff}]",
        streamerMode,
        developerMode);
    return ShowPlayerDialog(playerid, D_ADMIN_PANEL, DIALOG_STYLE_LIST, !"{"cblue"}����� ������", string, !"�����", !"������");
}

stock ChangeDeveloperMode(playerid)
{
    if(PlayerInfo[playerid][bAdmin] < 7)
    {
        return 0;
    }
    PlayerInfo[playerid][bDeveloper] = PlayerInfo[playerid][bDeveloper] == 1 ? 0 : 1;
    return SaveAccounts(playerid);
}

stock ChangeStreamerMode(playerid)
{
    if(PlayerInfo[playerid][bStreamerMode] == 1)
    {
        SCM(playerid, blue, !"�� ��������� ����� �������-�������.");
        PlayerInfo[playerid][bStreamerMode] = 0;
    }
    else
    {
        SCM(playerid, blue, !"�� �������� ����� �������-�������.");
        PlayerInfo[playerid][bStreamerMode] = 1;
    }
    return 1;
}