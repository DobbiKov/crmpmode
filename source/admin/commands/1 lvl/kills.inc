CMD:kills(playerid)
{
    if(PlayerInfo[playerid][bAdmin] < 1) return ShowCommandNotFound(playerid);

    PlayerInfo[playerid][isKillList] = !PlayerInfo[playerid][isKillList];
    if(PlayerInfo[playerid][isKillList])
        return SCM(playerid, lightblue, !"�� �������� ���������� �� ���������. ���������� ����� ���������� ������ ���");
    return SCM(playerid, lightblue, !"�� ��������� ���������� �� ���������. ���������� ������ �� ����� ��� ����������");
}