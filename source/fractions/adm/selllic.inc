CMD:selllic(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] != TEAM_ADM) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][pRang] < 3) return SCM(playerid, red, "������ ������� ����� ������������ � 3-�� �����!");

    extract params -> new to_player, type; else{
         SCM(playerid, blue, "[���������]: {FFFFFF}����������� /selllic [ID ������] [��� ��������]");
         return SCM(playerid, white, "[���]: ��������: 1 - �� ������� | 2 - �� ������ | 3 - �� ������");
    }
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    if(type > 3 || type < 1) return SCM(playerid, red, "�� ������ 3 � �� ����� 1!");
    if(PlayerInfo[to_player][pCash] < lic_price[type]) return SCM(playerid, red, "� ������ ������������ �����!");
    if(playerid == to_player) return SCM(playerid, red, "�� ������� ���� ID!");

    return SendProposition(playerid, to_player, PROPOSITION_TYPE_SELLLIC, type);
}