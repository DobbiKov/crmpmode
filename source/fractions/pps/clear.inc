CMD:clear(playerid, params[])
{
    if(!IsAPolice(playerid)) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][pMember] == TEAM_PPS && PlayerInfo[playerid][pRang] < 7) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /clear [ID ������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][pWANTED] <= 0) return SCM(playerid, red, "������ ����� �� � �������!");
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID!");

    PlayerInfo[to_player][pWANTED]--;

    new string[144];
    format(string, sizeof(string), "%s %s[%d] ���� 1 ������� �������(%d) � %s[%d].", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerName(playerid), playerid, PlayerInfo[to_player][pWANTED], PlayerName(to_player), to_player);
    SCMPolice(blue, string);

    format(string, sizeof(string), "%s %s[%d] ���� � ��� 1 ������� �������", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerName(playerid), playerid);
    SCM(to_player, blue, string);

    format(string, sizeof(string), "������ ��� ������� �������: %d", PlayerInfo[to_player][pWANTED]);
    SCM(to_player, blue, string);
    return SetPlayerWantedLevel(to_player, PlayerInfo[to_player][pWANTED]);
}