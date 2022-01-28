CMD:backpack(playerid)
{
    if(PlayerInfo[playerid][pBackPack] < 1) return SCM(playerid, red, !"У Вас нет рюкзака!");

    PlayerInfo[playerid][pBackPack] = 0;
    SCM(playerid, blue, !"Вы сняли и выбросили рюкзак.");
    RemovePlayerAttachedObject(playerid, 1);
    return SaveAccounts(playerid);
}