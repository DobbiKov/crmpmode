CMD:setskin(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);

    extract params -> new to_player, skin; else return SCM(playerid, blue, "�[���������] {ffffff}�������: /setskin [id ������] [ID �����]");

    if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][bAdmin] > PlayerInfo[playerid][bAdmin]) return 1;

    if(skin < 1 || skin > 299)
        return SCM(playerid, blue, "�[���������] {ffffff}�������: /setskin [id ������] [ID �����]");

    SetPlayerSkin(to_player, skin);

    new string[128];
    format(string, sizeof(string), "[A] %s[%d] �������� ��������� ����(%d) ������ %s[%d]", PlayerInfo[playerid][pName], playerid, skin, PlayerInfo[to_player][pName], to_player);
    SCMA(grey, string);

    format(string, sizeof(string), "������������� %s ������� ��� ����", PlayerInfo[playerid][pName]);
    SCM(to_player, white, string);
    return 1;
}