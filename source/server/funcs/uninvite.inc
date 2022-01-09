stock UnInvite(playerid)
{
    PlayerInfo[playerid][pMember] = 0;
    PlayerInfo[playerid][pWarnF] = 0;
    PlayerInfo[playerid][pRang] = 0;
    PlayerInfo[playerid][pFSkin] = -1;
    PlayerInfo[playerid][pIsFSB] = 0;
    PlayerInfo[playerid][pFSBRank] = 0;
    ResetPlayerWeaponsAC(playerid);
    SetPlayerSkin(playerid, PlayerInfo[playerid][pChar]);
    return SaveAccounts(playerid);
}