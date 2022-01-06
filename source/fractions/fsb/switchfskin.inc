CMD:switchfskin(playerid)
{
	if(!IsAFSB(playerid)) return YouCannotUseThisFunc(playerid);
	if(PlayerInfo[playerid][pMember] == TEAM_FSB && PlayerInfo[playerid][pRang] < 8)
		return SCM(playerid, red, !"Вы не во внедрении!");

	// new name[MAX_PLAYER_NAME];
	new fmt_str[18];
	new text[(sizeof fmt_str) * 10];
	new old_skin;
	new org = PlayerInfo[playerid][pMember];
	new count;

	// format(name, sizeof name, "%s", PlayerInfo[to_player][pName]);

	for(new i; i < 10; i++)
	{
		if(old_skin == ChangeSkin[org][i]) continue;
		if(ChangeSkin[org][i] == EOS) continue;

		dialog_listitem_values[playerid][count] = i; 
		count++;

		old_skin = ChangeSkin[org][i];

		format(fmt_str, sizeof fmt_str, "Скин %d [%d]\n", count, old_skin);
		strcat(text, fmt_str);
	}

	ShowPlayerDialog
	(
		playerid, D_SWITCH_FSKIN, DIALOG_STYLE_LIST,
		"Смена скина внедрения",
		text,
		"Ок", "Отмена"
	);

	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
		case D_SWITCH_FSKIN:
		{
			if(response)
			{
				new team_id = PlayerInfo[playerid][pMember];
				new index = dialog_listitem_values[playerid][listitem];

				PlayerInfo[playerid][pFSkin] = ChangeSkin[team_id][index];
				SetPlayerSkin(playerid, PlayerInfo[playerid][pFSkin]);
				
                SCM(playerid, blue, "Вы сменили свою фракционную одежду");
				
                SaveAccounts(playerid);
			}
		}
    }
	#if	defined	switch_fskin__OnDialogResponse
		return switch_fskin__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse switch_fskin__OnDialogResponse
#if	defined	switch_fskin__OnDialogResponse
	forward switch_fskin__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif