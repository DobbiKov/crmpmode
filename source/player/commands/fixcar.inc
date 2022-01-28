CMD:fixcar(playerid)
{
    if(PlayerInfo[playerid][pCash] < 1000)
        return SCM(playerid, red, !"У Вас недостаточно средств!");
    if(PlayerInfo[playerid][pHomeID] == -1)
        return SCM(playerid, red, !"У Вас нет дома!");

    DestroyOwnableCar(playerid);
    LoadMyCarFunc(playerid);
    GiveMoney(playerid, -1000, "/fixcar");
    return 1;
}