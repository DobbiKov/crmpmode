CMD:giveaccess(playerid, params[])
{
    if(!IsAFSB(playerid) || (IsAFSB(playerid) && PlayerInfo[playerid][pRang] < 5))
        return YouCannotUseThisFunc(playerid);
    
    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /giveaccess [ID игрока]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(!IsPlayerInRangeOfPlayer(playerid, to_player, 7.0))
        return SCM(playerid, red, !"Игрок далеко от вас!");
    if(PlayerInfo[to_player][pFSBaccess] == 1 || IsAFSB(to_player))
        return SCM(playerid, red, !"У игрока уже есть пропуск!");

    PlayerInfo[to_player][pFSBaccess] = 1;
    new string[144] = "";
    format(string, sizeof(string), "%s выдал Вам пропуск в здание ФСБ",  
    PlayerName(playerid));
    SCM(to_player, blue, string);

    format(string, sizeof(string), "Вы выдали пропуск %s в здание ФСБ",  
    PlayerName(to_player));
    SCM(playerid, blue, string);

    format(string, sizeof(string), "[R] %s %s[%d]: выдал пропуск в здание ФСБ %s[%d]", 
    PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pFSBRank] ], 
    PlayerInfo[playerid][pName], 
    playerid, 
    PlayerInfo[to_player][pName], 
    to_player);

    
    return SCMR(TEAM_FSB, green, string);
}