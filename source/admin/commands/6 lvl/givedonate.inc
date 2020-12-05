CMD:givedonate(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);
    extract params -> new to_player, donate; else return SCM(playerid, blue, !"[Подсказка]: {ffffff}используйте /givedonate [id игрока] [кол-во доната]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);

    PlayerInfo[to_player][pDonate] += donate;

    new string[144];

    format(string, sizeof(string), "{ffffff}Администратор %s выдал вам %d %d кредитов.", PlayerInfo[playerid][pName], donate);
    SCM(to_player, white, string);

    format(string, sizeof(string), "{ffffff}Вы выдали игроку %s %d кредитов.", PlayerInfo[to_player][pName], donate); 
    SCM(playerid, white, string);
    return 1;
}