CMD:removeaccess(playerid, params[])
{
    if(!IsAFSB(playerid) || (IsAFSB(playerid) && PlayerInfo[playerid][pRang] < 5))
        return YouCannotUseThisFunc(playerid);
    
    extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /removeaccess [ID ������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(!IsPlayerInRangeOfPlayer(playerid, to_player, 7.0))
        return SCM(playerid, red, !"����� ������ �� ���!");
    if(PlayerInfo[to_player][pFSBaccess] == 0)
        return SCM(playerid, red, !"� ������ ��� ��������!");

    PlayerInfo[to_player][pFSBaccess] = 0;
    new string[144] = "";
    format(string, sizeof(string), "%s ������ � ��� ������� � ������ ���",  
    PlayerName(playerid));
    SCM(to_player, blue, string);

    format(string, sizeof(string), "�� ������� ������� � %s � ������ ���",  
    PlayerName(to_player));
    SCM(playerid, blue, string);

    format(string, sizeof(string), "[R] %s %s[%d]: ������ ������� � ������ ��� � %s[%d]", 
    PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pFSBRank] ], 
    PlayerInfo[playerid][pName], 
    playerid, 
    PlayerInfo[to_player][pName], 
    to_player);

    
    return SCMR(TEAM_FSB, green, string);
}