CMD:mytk(playerid, params[])
{
    if(!strlen(params))
    {
        SCM(playerid, blue, "[���������]: {FFFFFF}����������� /mytk [ID ������]");
        ShowMyTk(playerid, playerid);
        return 1;
    }

    extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /mytk [ID ������]");

    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    new Float:x, Float:y, Float:z;
    GetPlayerPos(to_player, x, y, z);
    if(!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z)) return SCM(playerid, red, "����� ������ �� ���!");

    return ShowMyTk(to_player, playerid);
}