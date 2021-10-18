stock kick_all_players()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        Kick(i);
    }
    return 1;
}