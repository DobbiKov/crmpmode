CMD:unmask(playerid, params[])
{
    if(!strlen(params))
    {
        if(GetPVarInt(playerid, "pMask") != 1)
            return SCM(playerid, red, !"На вас не надета маска!");
        new string[128];
        SCM(playerid, blue, "Вы сняли с себя маску");
        
        format(string, sizeof(string), "%s снял маску с себя", PlayerInfo[playerid][pName]);
        cmd::me(playerid, string);
        return TakeOffMask(playerid);
    }

    if(!IsAPolice(playerid) && !IsAOpg(playerid)) return YouCannotUseThisFunc(playerid);
    
    extract params -> new to_player_mysql_id; else return SCM(playerid, yellow, "[Оповещение]: {FFFFFF}Используйте /unmask [ID неизвестного игрока]");
    
    if(to_player_mysql_id < 1) return SCM(playerid, yellow, "[Оповещение]: {FFFFFF}Используйте /unmask [ID неизвестного игрока]");

    new to_player = fsb_find_player_by_mysql_id(to_player_mysql_id);
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);

    new Float: x, Float: y, Float: z;
    GetPlayerPos(playerid, x, y, z);
    if(!IsPlayerInRangeOfPoint(to_player, 5.0, x, y, z)) return SCM(playerid, red, "Человек далеко от вас!");
    if(GetPVarInt(to_player, "pMask") != 1)
        return SCM(playerid, red, !"На игрока не надета маска!");

    new string[128];
    format(string, sizeof(string), "Вы сняли маску с %s", PlayerInfo[to_player][pName]);
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s снял с вас маску", PlayerInfo[playerid][pName]);
    SCM(to_player, blue, string);
    
    format(string, sizeof(string), "снял маску с %s", PlayerInfo[to_player][pName]);
    cmd::me(playerid, string);
    return TakeOffMask(to_player);
}

stock fsb_find_player_by_mysql_id(mysql_id)
{
    foreach(new i : Player)
    {
        if(PlayerInfo[i][pID] == mysql_id)
            return i;
    }
    return -1;
}