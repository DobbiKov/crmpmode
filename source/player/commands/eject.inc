CMD:eject(playerid, params[])
{
    if(!IsPlayerInAnyVehicle(playerid) || GetPlayerVehicleSeat(playerid) != 0) return SCM(playerid, red, "�� �� ������ �� ����!");

    extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /eject [ID ������]");
    
    if(GetPlayerVehicleID(playerid) != GetPlayerVehicleID(to_player) || !IsPlayerInAnyVehicle(to_player)) return SCM(playerid, red, "������� �� ��������� � ����� ����!");

    new string[144];
    format(string, sizeof(string), "�������-(�) �� ���������� %s", PlayerInfo[to_player][pName]);
    cmd::me(playerid, string);
    RemovePlayerFromVehicle(to_player);
    return UnFreezePlayer(to_player);
}