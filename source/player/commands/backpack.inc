CMD:backpack(playerid)
{
    if(PlayerInfo[playerid][pBackPack] < 1) return SCM(playerid, red, !"� ��� ��� �������!");

    PlayerInfo[playerid][pBackPack] = 0;
    SCM(playerid, blue, !"�� ����� � ��������� ������.");
    RemovePlayerAttachedObject(playerid, 1);
    return SaveAccounts(playerid);
}