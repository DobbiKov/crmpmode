CMD:unmwarn(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] == TEAM_NONE || PlayerInfo[playerid][pRang] < 9) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /unmwarn [ID ������] [�������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][pMember] != PlayerInfo[playerid][pMember]) return SCM(playerid, red, "����� �� ������� � ����� �����������!");
    if(PlayerInfo[to_player][pRang] > PlayerInfo[playerid][pRang]) return SCM(playerid, red, "����� ���� ��� �� �����!");
    if(PlayerInfo[to_player][pWarnF] <= 0) return SCM(playerid, red, "� ������ ��� ���������!");

    PlayerInfo[to_player][pWarnF]--;

    new string[128];
    format(string, sizeof(string), "�� ����� 1 ������� � %s [%d|3].", PlayerInfo[to_player][pName], PlayerInfo[to_player][pWarnF]);
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s %s ���� � ��� 1 ������� [%d|3].", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerInfo[playerid][pName], PlayerInfo[to_player][pWarnF]);
    SCM(to_player, blue, string);
    UnMWarnMyTK(to_player);
    return 1;
}