CMD:kills(playerid)
{
    if(PlayerInfo[playerid][bAdmin] < 1) return ShowCommandNotFound(playerid);

    PlayerInfo[playerid][isKillList] = !PlayerInfo[playerid][isKillList];
    if(PlayerInfo[playerid][isKillList])
        return SCM(playerid, lightblue, !"Вы включили информацию об убийствах. Информация будет выводиться только Вам");
    return SCM(playerid, lightblue, !"Вы выключили информацию об убийствах. Информация больше не будет Вам выводиться");
}