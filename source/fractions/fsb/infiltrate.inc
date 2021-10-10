CMD:infiltrate(playerid, params[]){
    if(!IsAFSB(playerid)) return YouCannotUseThisFunc(playerid);
    extract params -> new rank; else return SCM(playerid, blue, "[Ïîäñêàçêà]: {FFFFFF}Èñïîëüçóéòå /infiltrate [ğàíã(1-7)]");
    if(rank > 7 || rank < 1)
        return SCM(playerid, blue, "[Ïîäñêàçêà]: {FFFFFF}Èñïîëüçóéòå /infiltrate [ğàíã(1-7)]");
    SetPVarInt(playerid, "INFILTRATE_RANK", rank);
    return ShowInfiltrateDialog(playerid);
}

stock ShowInfiltrateDialog(playerid)
{
    new string[1024] = "";
    strcat(string, !"{"cblue"}1. Âåğíóòüñÿ â ÔÑÁ\n");
    for(new i = 1; i < sizeof(GetMember); i++)
    {
        new tempString[128] = "";
        format(tempString, sizeof(tempString), "{"cblue"}%d. {ffffff}%s\n", i + 1, GetMember[i]);
        strcat(string, tempString);
    }
    return ShowPlayerDialog(playerid, D_FSB_INFILTRATE, DIALOG_STYLE_LIST, !"{"cblue"}Âíåäğåíèå â îğãàíèçàöèş", string, !"Äàëåå", !"Îòìåíà");
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
                    PlayerInfo[playerid][pMember] = TEAM_FSB;
                    SCM(playerid, blue, !"Âû óñïåøíî âåğíóëèñü â ÔÑÁ!");
                }
                else{
                    PlayerInfo[playerid][pMember] = listitem;
                    PlayerInfo[playerid][pRang] = GetPVarInt(playerid, "INFILTRATE_RANK");
                    new string[144] = "";
                    format(string, sizeof(string), "Âû óñïåøíî âíåäğèëèñü â %s.", GetMember[listitem]);
                    SCM(playerid, blue, string);

                    SCMMoreInfiltrateCommands(playerid);
                    DeletePVar(playerid, "INFILTRATE_RANK");
                }
            }
            else{
                DeletePVar(playerid, "INFILTRATE_RANK");
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