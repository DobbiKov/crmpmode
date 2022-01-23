#define MAX_APVOTES 1

enum apvote
{
	voteID,
	voteName[64],
    voteIsOpen,
    voteLvlAccess,
    Float:vote_X,
    Float:vote_Y,
    Float:vote_Z,
    Text3D:voteLabel
}
new VoteInfo[MAX_APVOTES][apvote];


publics LoadAPVotes()
{
	new rows, fields;
	cache_get_data(rows, fields);
    if(rows)
    {
        for(new i = 0; i < rows; i++)
        {
            new idx = i;
            VoteInfo[idx][voteID] = cache_get_field_content_int(i, "id");
            VoteInfo[idx][voteIsOpen] = cache_get_field_content_int(i, "is_open");
            VoteInfo[idx][voteLvlAccess] = cache_get_field_content_int(i, "lvl_access");
            cache_get_field_content(i, "vote_name", VoteInfo[idx][voteName], connects, 64);

            VoteInfo[idx][vote_X] = cache_get_field_content_float(i, "pos_x");
            VoteInfo[idx][vote_Y] = cache_get_field_content_float(i, "pos_y");
            VoteInfo[idx][vote_Z] = cache_get_field_content_float(i, "pos_z");

            new query[144];
            format(query, sizeof(query), "SELECT * FROM `apvotevars` WHERE `vote_id` = '%d'", VoteInfo[idx][voteID]);
            mysql_tquery(connects, query, "LoadAPVoteVars", "i", idx);

            SaveAPVotes(idx);
        }
    }
    printf("[UNIGVA]: Всего загружено АП голосований: %d", 1);
    return 1;
}

stock SaveAPVotes(i)
{
    new sql[1024];
    format
    (
        sql, sizeof(sql), 
        "UPDATE `apvote` SET `is_open` = '%d', `lvl_access` = '%d', `pos_x` = '%f', `pos_y` = '%f', `pos_z` = '%f', `vote_name` = '%s'",
        VoteInfo[i][voteIsOpen],
        VoteInfo[i][voteLvlAccess],
        VoteInfo[i][vote_X],
        VoteInfo[i][vote_Y],
        VoteInfo[i][vote_Z],
        VoteInfo[i][voteName]
    );
    mysql_tquery(connects, sql, "", "");
    SaveAPVoteVars(i);
    return UpdateAPVotes(i);
}

stock UpdateAPVotes(i)
{
    Delete3DTextLabel(VoteInfo[i][voteLabel]);
    VoteInfo[i][voteLabel] = Create3DTextLabel("Нажмите {"cblue"}L.ALT {ffffff}что бы проголосовать", white, VoteInfo[i][vote_X], VoteInfo[i][vote_Y], VoteInfo[i][vote_Z], 10.0, 0);
    return 1;
}