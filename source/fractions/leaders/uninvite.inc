CMD:uninvite(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] == TEAM_NONE || PlayerInfo[playerid][pRang] < 9) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player, string: reason[128]; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /uninvite [ID ������] [�������]");
    if(to_player == playerid) return SCM(playerid, red, "�� �� ������ ������� ����!");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(!IsAFSB(playerid) && IsAFSB(to_player))
        return SCM(playerid, red, "����� �� ������� � ����� �����������!");
    if(PlayerInfo[to_player][pMember] != PlayerInfo[playerid][pMember]) return SCM(playerid, red, "����� �� ������� � ����� �����������!");
    if(PlayerInfo[to_player][pRang] >= PlayerInfo[playerid][pRang]) return SCM(playerid, red, "����� ���� ��� �� �����!"); 

    new string[128];
    format(string, sizeof(string), "�� ������� %s �� �����������. �������: %s", PlayerInfo[to_player][pName], reason);
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s ������ ��� �� ����������� \"%s\". �������: %s", PlayerInfo[playerid][pName], GetMember[ PlayerInfo[to_player][pMember] ], reason);
    SCM(to_player, blue, string);

    UnInviteMyTK(to_player, PlayerInfo[to_player][pMember], reason);

    return UnInvite(to_player);
}