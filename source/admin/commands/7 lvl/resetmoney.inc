CMD:resetmoney(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);

    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /resetmoney [ID игрока]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][bAdmin] > PlayerInfo[playerid][bAdmin]) return 1;

    new string[144];
    format(string, sizeof(string), "[A] %s[%d] забрал все деньги у игрока %s[%d] (%d)", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, PlayerInfo[to_player][pCash]);
    SCMA(grey, string);
    format(string, sizeof(string), "Администратор %s аннулировал Вам деньги", PlayerInfo[playerid][pName]);
    SCM(to_player, white, string);
    GiveMoney(to_player, -PlayerInfo[to_player][pCash], "Reset Money");
    return 1;
}