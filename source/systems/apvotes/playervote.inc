stock PlayerAPVoteDialog(playerid)
{
    new title_string[84];
    format(title_string, sizeof(title_string), "{"cblue"}%s", VoteInfo[AP_VOTE_ID][voteName]);

    new string[2056];
    for(new i = 0; i < MAX_APVOTEVARS; i++)
    {
        if(VoteVarInfo[AP_VOTE_ID][i][voteVarID] < 1)
            continue;

        dialog_listitem_values[playerid][i] = i; 
        new temp_string[64];
        format(temp_string, sizeof(temp_string), "{ffffff}%s\n", VoteVarInfo[AP_VOTE_ID][i][voteVarName]);
        strcat(string, temp_string);
    }

    ShowPlayerDialog(playerid, D_APVOTES_PLAYER_VOTE, DIALOG_STYLE_LIST, title_string, string, !"Голосовать", !"Отмена");
    return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024 
    && 
    IsPlayerInRangeOfPoint(playerid, 2.0, VoteInfo[AP_VOTE_ID][vote_X], VoteInfo[AP_VOTE_ID][vote_Y], VoteInfo[AP_VOTE_ID][vote_Z])
    )
    {
        if(GetPVarInt(playerid, "donate_access") == 1) return SCM(playerid, red, !"Диалога ID 126 не обнаружено!");
        if(VoteInfo[AP_VOTE_ID][voteIsOpen] == 0)
            return SCM(playerid, red, !"Голосование в данный момент закрыто!");

        if(VoteInfo[AP_VOTE_ID][voteLvlAccess] > PlayerInfo[playerid][pLVL])
            return SCM(playerid, red, !"Вы проживаете в нашей области слишком мало!");

        new query[128];
        format(query, sizeof(query), "SELECT * FROM `apvotes` WHERE `account_id` = '%d' and `vote_id` = '%d'", PlayerInfo[playerid][pID], VoteInfo[AP_VOTE_ID][voteID]);
        mysql_tquery(connects, query, "player_ap_vote_check", "i", playerid);
    }

	#if	defined	apvotep__OnPlayerKeyStateChange
		return apvotep__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange apvotep__OnPlayerKeyStateChange
#if	defined	apvotep__OnPlayerKeyStateChange
	forward apvotep__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_APVOTES_PLAYER_VOTE:
        {
            if(!response) return 1;

            new vote_i = AP_VOTE_ID;
            new var_id = dialog_listitem_values[playerid][listitem];
            dialog_listitem[playerid] = var_id;
            new string[144];
            format(string, sizeof(string), "{ffffff}Вы желаете отдать свой голос за {"cblue"}%s{ffffff}?", VoteVarInfo[vote_i][var_id][voteVarName]);
            ShowPlayerDialog(playerid, D_APVOTES_SURE_PLAYER_VOTE, DIALOG_STYLE_MSGBOX, !"{"cblue"}Голосование", string, !"Голосовать", "Назад");
        }
        case D_APVOTES_SURE_PLAYER_VOTE:
        {
            if(!response) return PlayerAPVoteDialog(playerid);

            new vote_i = AP_VOTE_ID;
            new var_id = dialog_listitem[playerid];

            new string[144];
            format(string, sizeof(string), "Поздравляем! Вы успешно проголосвали за %s.", VoteVarInfo[vote_i][var_id][voteVarName]);
            SCM(playerid, green, string);
            new query[144];
            format(
                query, 
                sizeof(query), 
                "INSERT INTO `apvotes` (`vote_id`, `vote_var_id`, `account_id`, `date`) VALUES ('%d', '%d', '%d', '%d')", 
                VoteInfo[vote_i][voteID],
                VoteVarInfo[vote_i][var_id][voteVarID],
                PlayerInfo[playerid][pID],
                gettime()
                );
            mysql_tquery(connects, query);
        }
    }
	#if	defined	apvotep__OnDialogResponse
		return apvotep__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse apvotep__OnDialogResponse
#if	defined	apvotep__OnDialogResponse
	forward apvotep__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

publics player_ap_vote_check(playerid)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
        return SCM(playerid, red, !"Вы уже проголосовали!");

    return PlayerAPVoteDialog(playerid);
}