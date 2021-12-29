CMD:removeaccess(playerid, params[])
{
    if(!IsAFSB(playerid) || (IsAFSB(playerid) && PlayerInfo[playerid][pRang] < 5))
        return YouCannotUseThisFunc(playerid);
    
    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /removeaccess [ID игрока]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(!IsPlayerInRangeOfPlayer(playerid, to_player, 7.0))
        return SCM(playerid, red, !"Игрок далеко от вас!");
    if(PlayerInfo[to_player][pFSBaccess] == 0)
        return SCM(playerid, red, !"У игрока нет пропуска!");

    PlayerInfo[to_player][pFSBaccess] = 0;
    new string[144] = "";
    format(string, sizeof(string), "[R] %s %s[%d]: забрал пропуск в здание ФСБ у %s[%d]", 
    PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pFSBRank] ], 
    PlayerInfo[playerid][pName], 
    playerid, 
    PlayerInfo[to_player][pName], 
    to_player);

    
    return SCMR(TEAM_FSB, green, string);
}