CMD:fixcar(playerid)
{
    if(PlayerInfo[playerid][pCash] < 1000)
        return SCM(playerid, red, !"� ��� ������������ �������!");
    if(PlayerInfo[playerid][pHomeID] == -1)
        return SCM(playerid, red, !"� ��� ��� ����!");

    DestroyOwnableCar(playerid);
    LoadMyCarFunc(playerid);
    GiveMoney(playerid, -1000, "/fixcar");
    return 1;
}