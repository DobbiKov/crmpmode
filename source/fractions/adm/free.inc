CMD:free(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] != TEAM_ADM) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][pRang] < 5) return SCM(playerid, red, "������ ������� ����� ������������ � 5-�� �����!");

    extract params -> new to_player, price; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /free [ID ������] [����]");

    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(price < 5000 || price > 50000) return SCM(playerid, red, "���� �� ����� 5000 � �� ����� 50000!");
    if(PlayerInfo[to_player][pKPZ] == -1) return SCM(playerid, red, "��������� �� ����� � ���!");
    if(PlayerInfo[to_player][pCash] < price) return SCM(playerid, red, "� ������ ��� ������� �����!");
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID!");

    return SendProposition(playerid, to_player, PROPOSITION_TYPE_FREE, price);
}