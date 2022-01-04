CMD:mytk(playerid, params[])
{
    if(!strlen(params))
    {
        SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /mytk [ID игрока]");
        ShowMyTk(playerid, playerid);
        return 1;
    }

    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /mytk [ID игрока]");

    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    new Float:x, Float:y, Float:z;
    GetPlayerPos(to_player, x, y, z);
    if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z)) return SCM(playerid, red, "Игрок далеко от вас!");

    return ShowMyTk(to_player, playerid);
}