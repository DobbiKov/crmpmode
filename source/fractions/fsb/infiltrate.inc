CMD:infiltrate(playerid, params[]){
    if(!IsAFSB(playerid) || PlayerInfo[playerid][pFSBRank] < 4) return YouCannotUseThisFunc(playerid);
    return ShowInfiltrateDialog(playerid);
}

stock ShowInfiltrateDialog(playerid)
{
    new string[1024] = "";
    strcat(string, !"{"cblue"}1. Вернуться в ФСБ\n");
    for(new i = 1; i < sizeof(GetMember); i++)
    {
        new tempString[128] = "";
        format(tempString, sizeof(tempString), "{"cblue"}%d. {ffffff}%s\n", i + 1, GetMember[i]);
        strcat(string, tempString);
    }
    return ShowPlayerDialog(playerid, D_FSB_INFILTRATE, DIALOG_STYLE_LIST, !"{"cblue"}Внедрение в организацию", string, !"Далее", !"Отмена");
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case D_FSB_INFILTRATE:{
            if(response)
            {
                if(listitem == 0)
                {
                    PlayerInfo[playerid][pRang] = PlayerInfo[playerid][pFSBRank];
                    PlayerInfo[playerid][pMember] = TEAM_FSB;
                    return SCM(playerid, blue, !"Вы успешно вернулись в ФСБ!");

                    
                }
                else if(listitem == TEAM_FSB)
                {
                    SCM(playerid, red, !"Вы не можете внедриться в ФСБ!");
                    return ShowInfiltrateDialog(playerid);
                }
                else{
                    PlayerInfo[playerid][pMember] = listitem;
                    PlayerInfo[playerid][pRang] = 1;

                    new string[1024] = "";
                    for(new i = 1; i < 8; i++)
                    {
                        new temp_str[144] = "";
                        format(temp_str, sizeof(temp_str), "{"cblue"}%d. {ffffff}%s\n", i, PlayerRank[listitem][i]);
                        strcat(string, temp_str);
                    }
                    return SPD(playerid, D_FSB_INFILTRATE_RANK, DIALOG_STYLE_LIST, !"{"cblue"}Выбор ранга", string, "Выбрать", "");
                }
            }
        }
		case D_FSB_INFILTRATE_RANK:{
            if(response)
            {
                PlayerInfo[playerid][pRang] = listitem + 1;

                new string[144] = "";
                format(string, sizeof(string), "Вы успешно внедрились в %s на должность %s.", GetMember[ PlayerInfo[playerid][pMember] ], PlayerRank[ PlayerInfo[playerid][pMember] ][listitem + 1]);
                SCM(playerid, blue, string);

                return SCMMoreInfiltrateCommands(playerid);
            }
            else{
                new string[144] = "";
                format(string, sizeof(string), "Вы успешно внедрились в %s на должность %s.", GetMember[ PlayerInfo[playerid][pMember] ], PlayerRank[ PlayerInfo[playerid][pMember] ][1]);
                SCM(playerid, blue, string);

                return SCMMoreInfiltrateCommands(playerid);
            }
        }
	}
	#if	defined	infiltrate__OnDialogResponse
		return infiltrate__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse infiltrate__OnDialogResponse
#if	defined	infiltrate__OnDialogResponse
	forward infiltrate__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif