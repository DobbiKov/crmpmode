CMD:deject(playerid, params[])
{
    if(!IsAPolice(playerid)) return YouCannotUseThisFunc(playerid);
    
    extract params -> new to_player; else return SCM(playerid, yellow, "[����������]: {FFFFFF}����������� /deject [ID ������]");
    
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(!IsPlayerInRangeOfPoint(to_player, 5.0, x, y, z)) return SCM(playerid, red, "������� ������ �� ���!");
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID!");
    if(!IsPlayerInAnyVehicle(to_player)) return SCM(playerid, red, "������� �� ���������� � ����������!");

    new string[144];
    format(string, sizeof(string), "�� �������� %s �� ����", PlayerName(to_player));
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s ������� ��� �� ����", PlayerName(playerid));
    SCM(to_player, blue, string);

    format(string, sizeof(string), "������� ����� ����������");
    cmd::me(playerid, string);
    UnFreezePlayer(to_player);
    return RemovePlayerFromVehicle(to_player);
}