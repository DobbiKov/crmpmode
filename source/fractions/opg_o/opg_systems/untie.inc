CMD:untie(playerid, params[])
{
    if(!IsAOpg(playerid)) return YouCannotUseThisFunc(playerid);
    
    extract params -> new to_player; else return SCM(playerid, yellow, "[����������]: {FFFFFF}����������� /untie [ID ������]");
    
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(!IsPlayerInRangeOfPoint(to_player, 5.0, x, y, z)) return SCM(playerid, red, "������� ������ �� ���!");
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID!");
    if(GetPVarInt(to_player, "tied") != 1) return SCM(playerid, red, "� ������� �������� �� ������� ����!");

    SetPlayerSpecialAction(to_player, SPECIAL_ACTION_NONE);
    DeletePVar(to_player, "tied");

    new string[128];
    format(string, sizeof(string), "�� ��������� ���� %s", PlayerName(to_player));
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s �������� ��� ����", PlayerName(playerid));
    SCM(to_player, blue, string);
    
    format(string, sizeof(string), "����������� ���� %s", PlayerName(to_player));
    cmd::me(playerid, string);
    return 1;
}