new TMask[MAX_PLAYERS];

CMD:mask(playerid)
{
    if(PlayerInfo[playerid][pMask] <= 0) return SCM(playerid, red, "У Вас нет маски!");
    if(GetPVarInt(playerid, "pMask") == 1) return SCM(playerid, red, "На Вас уже надета маска!");

    PlayerInfo[playerid][pMask]--;
    SetPlayerColor(playerid, 0xFFFFFF00);
    ApplyAnimation(playerid, "SHOP","ROB_Shifty", 4.0, false, 0, 0, 0, 0);
    cmd::me(playerid, "надел маску");
    SetPVarInt(playerid, "pMask", 1);

    new name[144] = "";
    format(name, sizeof(name), "UNKNOWN[%d]", PlayerInfo[playerid][pID]);
    SetPlayerName(playerid, name);

    SCM(playerid, blue, "Вы надели маску! Ваше местоположение скрыто.");
    // TMask[playerid] = SetTimerEx("PlayerMask", 1000*60*10, false, "i", playerid);
    return 1;
}

// publics PlayerMask(playerid)
// {
//     SCM(playerid, blue, "10 минут прошло, с Вас была снята маска.");
//     return TakeOffMask(playerid);
// }

stock TakeOffMask(playerid)
{
    SetPlayerColor(playerid, 0xFFFFFFFF);
    DeletePVar(playerid, "pMask");
    SetPlayerName(playerid, PlayerInfo[playerid][pName]);
    return 1;
}