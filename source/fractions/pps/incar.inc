CMD:incar(playerid, params[])
{
    if(!IsAPolice(playerid) && !IsAOpg(playerid)) return YouCannotUseThisFunc(playerid);
    
    extract params -> new to_player, place; else return SCM(playerid, yellow, "[����������]: {FFFFFF}����������� /incar [ID ������] [����� (1-3)]");
    
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(!IsPlayerInRangeOfPoint(to_player, 5.0, x, y, z)) return SCM(playerid, red, "������� ������ �� ���!");
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID!");
    if(GetPVarInt(to_player, "cuffed") != 1 && GetPVarInt(to_player, "tied") != 1) return SCM(playerid, red, "������� �� ������!");
    if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, red, "�� �� ������ � ����!");
    if(IsPlayerInAnyVehicle(to_player)) return SCM(playerid, red, "������� ���������� � ����������!");
    if(place < 1 || place > 3) return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /incar [ID ������] [����� (1-3)]"); 

    new string[128];
    format(string, sizeof(string), "�� �������� %s � ������!", PlayerName(to_player));
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s ������� ��� � ������!", PlayerName(playerid));
    SCM(to_player, blue, string);

    format(string, sizeof(string), "������� � ������ %s", PlayerName(to_player));
    cmd::me(playerid, string);
    func_ungotome(playerid, to_player);
    PutPlayerInVehicle(to_player, GetPlayerVehicleID(playerid), place);
    return FreezePlayer(to_player, 5*60000); 
}