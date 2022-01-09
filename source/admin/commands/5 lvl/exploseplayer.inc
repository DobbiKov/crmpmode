CMD:exploseplayer(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 5) return ShowCommandNotFound(playerid);

    extract params -> new to_player; else return SCM(playerid, yellow, "[Подсказка]: {FFFFFF}Используйте /exploseplayer [ID игрока]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(!CheckFD(playerid) && CheckFD(to_player))
        return PlayerOffLine(playerid);

    new string[144];
    format(string, sizeof(string), "[A] Администратор %s[%d] взорвал игрока %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
    if(!CheckFD(playerid))
        SCMA(grey, string);

    new Float:_x, Float:_y, Float:_z;
    GetPlayerPos(to_player, _x, _y, _z);

    format(string, sizeof(string), "Вы взорвали игрока %s[%d]", PlayerInfo[to_player][pName], to_player);
    SCM(to_player, white, string);
    return CreateExplosion(_x, _y, _z, 0, 10.0); //2
}