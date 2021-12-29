stock kick_all_players()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(PlayerInfo[i][bAdmin] < 7)
            Kick(i);
    }
    return 1;
}