CMD:crashplayer(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);
    extract params -> new to_player; else return SCM(playerid, blue, "[���������]: /crashplayer [ID ������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(PlayerInfo[playerid][bAdmin] < PlayerInfo[to_player][bAdmin]) return 1;

    SetPlayerSkin(to_player, 300);
    return 1;
}