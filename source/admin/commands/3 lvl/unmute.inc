CMD:unmute(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);

	extract params -> new to_player; else return SCM(playerid, yellow, !"[���������]: {FFFFFF}����������� /unmute [ID ������]");

	if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

	if(PlayerInfo[to_player][pMute] == -1) return SCM(playerid, red, "����� � ������ ��� �������.");

	PlayerInfo[to_player][pMute] = -1;

    new string[256], data[64], year, month, day, hour, minute, second;

    gettime(hour, minute, second);
    getdate(year, month, day);
    format(data, sizeof(data), "%d/%d/%d -- %d:%d:%d", year, month, day, hour, minute, second);

	mysql_format(connects, string, sizeof(string), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', 'unmute', 'unmute')", 
		PlayerInfo[playerid][pName], 
		PlayerInfo[to_player][pName], 
		PlayerInfo[playerid][pID], 
		PlayerInfo[to_player][pID], 
		data, 
		0);
	mysql_tquery(connects, string, "", "");

	new fmt_query[256];

	format(fmt_query, sizeof fmt_query, "������������� %s ���� ������� � ������ %s", PlayerInfo[playerid][pName], PlayerInfo[to_player][pName]);
	SCMTA(0xFF4530FF, fmt_query);

	format(fmt_query, sizeof fmt_query, "������������� %s ���� � ��� �������", PlayerInfo[playerid][pName]);
	SCM(to_player, green, fmt_query);

	SaveAccounts(playerid);
	SaveAccounts(to_player);
	return 1;
}