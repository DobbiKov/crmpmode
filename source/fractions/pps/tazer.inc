CMD:tazer(playerid, params[])
{
    if(!IsAPolice(playerid) && PlayerInfo[playerid][pMember] != TEAM_ADM) return YouCannotUseThisFunc(playerid);
    
    extract params -> new to_player; else return SCM(playerid, yellow, "[����������]: {FFFFFF}����������� /tazer [ID ������]");
    
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    new Float: x, Float: y, Float: z;
    GetPlayerPos(playerid, x, y, z);
    if(!IsPlayerInRangeOfPoint(to_player, 5.0, x, y, z)) return SCM(playerid, red, "������� ������ �� ���!");

    new string[128];
    format(string, sizeof(string), "�� ������� %s ��������������", PlayerName(to_player));
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s ������ ��� ��������������", PlayerName(playerid));
    SCM(to_player, blue, string);
    return FreezePlayer(to_player, 5000);
}