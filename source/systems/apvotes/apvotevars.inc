#define MAX_APVOTEVARS MAX_APVOTES*10

enum apvotevar
{
	voteVarID,
	voteVarVoteID,
	voteVarName[32]
}
new VoteVarInfo[MAX_APVOTES][MAX_APVOTEVARS][apvotevar];
new Iterator: AllVoteVars<MAX_APVOTEVARS>;
new totalvotevars;
new vote_totalvotevars[MAX_APVOTES];

publics LoadAPVoteVars(vote_i)
{
	new rows, fields;
	cache_get_data(rows, fields);
    if(rows)
    {
        totalvotevars -= vote_totalvotevars[vote_i];
        vote_totalvotevars[vote_i] = 0;
        for(new i = 0; i < rows; i++)
        {
            new idx = i;
            VoteVarInfo[vote_i][idx][voteVarID] = cache_get_field_content_int(i, "id");
            VoteVarInfo[vote_i][idx][voteVarVoteID] = cache_get_field_content_int(i, "vote_id");
            cache_get_field_content(i, "var_name", VoteVarInfo[vote_i][idx][voteVarName], connects, 32);

            totalvotevars++;
            vote_totalvotevars[vote_i]++;

            Iter_Add(AllVoteVars, idx);
        }
    }
    printf("[UNIGVA]: Всего загружено АП ответов голосований: %d", 1);
    return 1;
}

stock ClearAPVoteVars(vote_i)
{
    for(new i = 0; i < MAX_APVOTEVARS; i++)
    {
        if(VoteVarInfo[vote_i][i][voteVarVoteID] != VoteInfo[vote_i][voteID])
            continue;
        VoteVarInfo[vote_i][i][voteVarVoteID] = 0;
        VoteVarInfo[vote_i][i][voteVarID] = 0;
        VoteVarInfo[vote_i][i][voteVarName] = EOS;
    }
    return 1;
}

stock SaveAPVoteVars(vote_i)
{
    new sql[256];
    for(new i = 0; i < MAX_APVOTEVARS; i++)
    {
        if(VoteVarInfo[vote_i][i][voteVarVoteID] != VoteInfo[vote_i][voteID])
            continue;

        format
        (
            sql, sizeof(sql), 
            "UPDATE `apvotevars` SET `vote_id` = '%d', `var_name` = '%s' WHERE `id` = '%d'",
            VoteVarInfo[vote_i][i][voteVarVoteID],
            VoteVarInfo[vote_i][i][voteVarName],
            VoteVarInfo[vote_i][i][voteVarID]
        );
        mysql_tquery(connects, sql, "", "");
    }
    return 1;
}