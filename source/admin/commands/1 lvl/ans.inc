CMD:ans(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 1) return ShowCommandNotFound(playerid);

	extract params -> new to_player, string: message[80]; else return SCM(playerid, yellow, !"[���������]: {FFFFFF}����������� /ans [ID ������] [�����]");

	if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

	new string[256];
	format(string, sizeof(string), "������������� %s[%d] ��� %s[%d]: %s", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, message);
	SCMA(orange, string);
	SCM(to_player, orange, string);
	PlayerInfo[playerid][bAns]++;
	return SaveAccounts(playerid);
}