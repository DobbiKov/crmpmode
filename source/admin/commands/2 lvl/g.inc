CMD:goto(playerid, params[])
    return cmd::g(playerid, params);
CMD:g(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] == 0) return ResultMessageCheat(playerid, 6);
    if(PlayerInfo[playerid][bAdmin] < 2) return ShowCommandNotFound(playerid);

    extract params -> new to_player; else return SCM(playerid, yellow, "[���������]: {FFFFFF}������� /goto [id ������]");

    if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

    new Float:px, Float:py, Float:pz, string[120+MAX_PLAYER_NAME*2], vw, int;
    GetPlayerPos(to_player, px, py, pz);
    vw = GetPlayerVirtualWorld(to_player);
    int = GetPlayerInterior(to_player);
    SetPlayerPos(playerid, px, py, pz);
    SetPlayerVirtualWorld(playerid, vw);
    SetPlayerInterior(playerid, int);

    format(string, sizeof(string), "{"cgrey"}[A] %s[%d] ���������������� � ������ %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
    SCMA(grey, string);
	return 1;
}