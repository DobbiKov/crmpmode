CMD:leave(playerid)
{
    if(PlayerInfo[playerid][pVIP] <= 0) 
        return SCM(playerid, red, !"� ��� ��� VIP �������!");
    if(PlayerInfo[playerid][pMember] <= 0)
        return SCM(playerid, red, !"�� �� �������� � �����������!");
    if(PlayerInfo[playerid][pRang] >= 10)
        return SCM(playerid, red, !"�� ��������� ������� �����������!");

    new string[144];
    format(string, sizeof(string), "[R] %s[%d] ������� ����������� �� ������������ �������", PlayerInfo[playerid][pName], playerid);
    SCMR(PlayerInfo[playerid][pMember], 0xFF6600FF, string);
    UnInviteMyTK(playerid, PlayerInfo[playerid][pMember], "�� ������������ �������");
    return UnInvite(playerid);
}