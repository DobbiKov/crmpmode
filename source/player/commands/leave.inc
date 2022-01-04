CMD:leave(playerid)
{
    if(PlayerInfo[playerid][pVIP] <= 0) 
        return SCM(playerid, red, !"” вас нет VIP статуса!");
    if(PlayerInfo[playerid][pMember] <= 0)
        return SCM(playerid, red, !"¬ы не состоите в организации!");
    if(PlayerInfo[playerid][pRang] >= 10)
        return SCM(playerid, red, !"¬ы €вл€етесь лидером организации!");

    new string[144];
    format(string, sizeof(string), "[R] %s[%d] покинул организацию по собственному желанию", PlayerInfo[playerid][pName], playerid);
    SCMR(PlayerInfo[playerid][pMember], 0xFF6600FF, string);
    UnInviteMyTK(playerid, PlayerInfo[playerid][pMember], "по собственному желанию");
    return UnInvite(playerid);
}