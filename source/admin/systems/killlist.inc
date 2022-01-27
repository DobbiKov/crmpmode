stock SendKillList(color, string[])
{
    foreach(new i : Player)
    {
        if(PlayerInfo[i][bAdmin] < 1 || !PlayerInfo[i][isKillList])
            continue;
        SCM(i, color, string);
    }
    return 1;
}