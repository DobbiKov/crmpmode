CMD:freeze(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 1) return ShowCommandNotFound(playerid);

	extract params -> new to_player; else return SCM(playerid, yellow, !"[���������]: {FFFFFF}����������� /freeze [ID ������]");

	if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);
	if(PlayerInfo[to_player][bAdmin] > PlayerInfo[playerid][bAdmin]) return 1;

	new string[256];
	format(string, sizeof(string), "[A] %s[%d] ��������� ������ %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
	SCMA(grey, string);
	
	format(string, sizeof(string), "������������� %s[%d] ��������� ���!", PlayerInfo[playerid][pName], playerid);
	SCM(to_player, white, string);
	
	TogglePlayerControllable(to_player, 0);
	return 1;
}