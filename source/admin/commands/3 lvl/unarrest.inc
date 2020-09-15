CMD:unarrest(playerid, params[]){
    if(PlayerInfo[playerid][bAdmin] < 3) 
        return ShowCommandNotFound(playerid);
    extract params -> new to_player; else return SCM(playerid, blue, !"[Подсказка]: {FFFFFF}Используйте /unarrest [ID игрока]");
    if(!IsPlayerConnected(to_player) || !PlayerInfo[to_player][pLogin])
        return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][pKPZ] < 1)
        return SCM(playerid, red, !"Данный игрок не находится в КПЗ.");

    PlayerInfo[to_player][pKPZ] = -1;
    SaveAccounts(to_player);
    SetSpawnVokzal(to_player);

    new string[144];
    format(string, sizeof(string), "Администратор %s выпустил вас досрочно из КПЗ.", PlayerInfo[playerid][pName]);
    SCM(to_player, white, string);

    format(string, sizeof(string), "Вы выпустили игрока %s из КПЗ досрочно.", PlayerInfo[to_player][pName]);
    SCM(to_player, white, string);

    format(string, sizeof(string), "[A] Администратор %s[%d] выпустил досрочно игрока %s[%d] из КПЗ.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
    SCMA(grey, string);
    return 1;
}