CMD:mwarn(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] == TEAM_NONE) return YouCannotUseThisFunc(playerid);
    if(IsAFSB(playerid) && PlayerInfo[playerid][pFSBRank] < 5) return YouCannotUseThisFunc(playerid);
    else if(PlayerInfo[playerid][pMember] == TEAM_ADM && PlayerInfo[playerid][pRang] < 8) return YouCannotUseThisFunc(playerid);
    else if(!IsAFSB(playerid) && PlayerInfo[playerid][pRang] < 9) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player, string: reason[128]; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /mwarn [ID ������] [�������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(!IsAFSB(playerid) && PlayerInfo[playerid][pMember] != TEAM_ADM && PlayerInfo[to_player][pMember] != PlayerInfo[playerid][pMember]) 
        return SCM(playerid, red, "����� �� ������� � ����� �����������!");
    if(!IsAFSB(playerid) && IsAFSB(to_player))
        return SCM(playerid, red, "�� �� ������ ������ ������� ������� ������!");
    if(PlayerInfo[to_player][pRang] > PlayerInfo[playerid][pRang]) return SCM(playerid, red, "����� ���� ��� �� �����!");
    if(PlayerInfo[to_player][pRang] == 10) 
        return SCM(playerid, red, "�� �� ������ ������ ������� ������!");
    if(PlayerInfo[to_player][pMember] <= 0)
        return SCM(playerid, red, !"����� �� ������� � �����������!");

    PlayerInfo[to_player][pWarnF]++;

    new string[128];
    format(string, sizeof(string), "�� ������� ������� %s [%d|3]. �������: %s", PlayerInfo[to_player][pName], PlayerInfo[to_player][pWarnF], reason);
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s %s ������ ��� ������� [%d|3]. �������: %s", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerInfo[playerid][pName], PlayerInfo[to_player][pWarnF], reason);
    SCM(to_player, blue, string);

    format(string, sizeof(string), "%d", to_player);

    MWarnMyTK(to_player, PlayerInfo[to_player][pMember], reason);
    if(PlayerInfo[to_player][pWarnF] >= 3) 
    {
        format(string, sizeof(string), "%s ��� ������ �� ����� �����������. �������: 3 ��������", PlayerInfo[to_player][pName]);
        SCM(playerid, blue, string);

        format(string, sizeof(string), "�� ���� ������� �� ����������� \"%s\". �������: 3 ��������", GetMember[ PlayerInfo[to_player][pMember] ]);
        SCM(to_player, blue, string);
        UnInviteMyTK(to_player, PlayerInfo[to_player][pMember], "��������� ���������� (��� ��������)");
        UnInvite(to_player);
    }
    SaveAccounts(to_player);
    return 1;
}