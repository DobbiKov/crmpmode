CMD:guninvite(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] != TEAM_ADM && !IsAFSB(playerid)) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][pMember] == TEAM_ADM && PlayerInfo[playerid][pRang] < 8) return YouCannotUseThisFunc(playerid);
    if(IsAFSB(playerid) && PlayerInfo[playerid][pRang] < 5) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player, string: reason[128]; else return SCM(playerid, yellow, "[Подсказка]: {FFFFFF}Используйте /guninvite [ID игрока] [причина]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(to_player == playerid) return SCM(playerid, red, "Вы указали свой ID!");
    if(PlayerInfo[to_player][pRang] > PlayerInfo[playerid][pRang]) return SCM(playerid, red, "Игрок выше Вас по рангу!");
    if(PlayerInfo[playerid][pMember] == PlayerInfo[to_player][pMember]) return SCM(playerid, red, "Игрок состоит в вашей организаации!");
    if(IsAOpg(to_player))
        return SCM(playerid, red, !"Игрок состоит в криминальной организации!");
    if(IsAFSB(to_player))
        return SCM(playerid, red, "Игрок выше Вас по рангу!");
    if(PlayerInfo[to_player][pRang] == 10) 
        return SCM(playerid, red, "Вы не можете уволить лидера!");
    if(PlayerInfo[to_player][pMember] <= 0)
        return SCM(playerid, red, !"Игрок не состоит в организации!");

    new string[128];
    format(string, sizeof(string), "Вы уволили %s из организации. Причина: %s", PlayerInfo[to_player][pName], reason);
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s уволил Вас из организации \"%s\". Причина: %s", PlayerInfo[playerid][pName], GetMember[ PlayerInfo[to_player][pMember] ], reason);
    SCM(to_player, blue, string);

    UnInviteMyTK(to_player, PlayerInfo[to_player][pMember], reason);

    UnInvite(to_player);
    SaveAccounts(to_player);
    return 1;
}