CMD:uncuff(playerid, params[])
{
    if(!IsAPolice(playerid) && PlayerInfo[playerid][pMember] != TEAM_ADM) return YouCannotUseThisFunc(playerid);
    
    extract params -> new to_player; else return SCM(playerid, yellow, "[����������]: {FFFFFF}����������� /uncuff [ID ������]");
    
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(!IsPlayerInRangeOfPoint(to_player, 5.0, x, y, z)) return SCM(playerid, red, "������� ������ �� ���!");
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID!");
    if(GetPVarInt(to_player, "cuffed") != 1 && GetPVarInt(playerid, "tied") != 1) return SCM(playerid, red, "������� �� � ����������!");

    SetPlayerSpecialAction(to_player, SPECIAL_ACTION_NONE);
    DeletePVar(to_player, "cuffed");
    DeletePVar(to_player, "tied");

    new string[128];
    format(string, sizeof(string), "�� ����� ��������� � %s", PlayerName(to_player));
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s ���� � ��� ���������", PlayerName(playerid));
    SCM(to_player, blue, string);
    
    format(string, sizeof(string), "������� ��������� � %s", PlayerName(to_player));
    cmd::me(playerid, string);
    func_ungotome(playerid, to_player);
    return UnFreezePlayer(to_player);
}