CMD:setvw(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);

	extract params -> new to_player, interior; else return SCM(playerid, blue, "[���������] {ffffff}�������: /setvw [id ������] [����. ���]");
	if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][bAdmin] > PlayerInfo[playerid][bAdmin]) return 1;

	SetPlayerVirtualWorld(to_player, interior);

    new string[144];
    format(string, sizeof(string), "[A] %s[%d] ��������� ����������� ��� �� %d %s[%d]", PlayerInfo[playerid][pName], playerid, interior, PlayerInfo[to_player][pName], to_player);
    SCMA(grey, string);

    format(string, sizeof(string), "�� �������� ����������� ��� ������ %s", PlayerInfo[to_player][pName]);
    SCM(playerid, white, string);

    format(string, sizeof(string), "������������� %s ������� ��� ����������� ���.", PlayerInfo[playerid][pName]);
    SCM(to_player, white, string);


	return 1;
}