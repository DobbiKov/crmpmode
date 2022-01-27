CMD:givedaccess(playerid, params[])
{
    if(!CheckFD(playerid)) return ShowCommandNotFound(playerid);

    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /givedaccess [ID игрока]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);

    new string[144];
    format(string, sizeof(string), "Вы выдали донат доступ %s", PlayerInfo[to_player][pName]);
    SCM(playerid, white, string);
    return SetPVarInt(to_player, "donate_access", 1);
}

CMD:removedaccess(playerid, params[])
{
    if(!CheckFD(playerid)) return ShowCommandNotFound(playerid);

    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /removedaccess [ID игрока]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);

    new string[144];
    format(string, sizeof(string), "Вы забрали донат доступ %s", PlayerInfo[to_player][pName]);
    SCM(playerid, white, string);
    return DeletePVar(to_player, "donate_access");
}