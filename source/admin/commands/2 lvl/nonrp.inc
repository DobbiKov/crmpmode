CMD:nrp(playerid, params[])
    return cmd::nonrp(playerid, params);
CMD:nonrp(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 2) return ShowCommandNotFound(playerid);

	extract params -> new to_player; else return SCM(playerid, yellow, !"[���������]: {FFFFFF}����������� /nonrp [ID ������]");

	if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);
	if(PlayerInfo[to_player][pJail] > 0) return SCM(playerid, red, "����� ��� ����� � ���������.");

	PlayerInfo[to_player][pJail] = nonrp*60;
	PlayerInfo[playerid][bJail]++;
	SaveAccounts(to_player);
	SaveAccounts(playerid);

	new fmt_query[256];

	format(fmt_query, sizeof fmt_query, "������������� %s ������� ������ %s. �������: NonRP", PlayerInfo[playerid][pName], PlayerInfo[to_player][pName]);
	SCMTA(0xFF4530FF, fmt_query);

	format(fmt_query, sizeof fmt_query, "[A] %s[%d] ������� � �������� %s[%d] �� %d ����� (NonRP)", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, nonrp);
	SCMA(grey, fmt_query);

	SCM(to_player, grey, "�� ���� �������� � �������� �� ��������� ������. ���������� ����� �� ������: /time");

	new string[256], sql_str[256];
	new day, month, year, hour, minute, second;
	getdate(day, month, year);
	gettime(hour, minute, second);
	format(string, sizeof(string), "%d/%d/%d - %d:%d:%d", day, month, year, hour, minute, second);

	mysql_format(connects, sql_str, sizeof(sql_str), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', 'NonRP', 'jail')", 
		PlayerInfo[playerid][pName], 
		PlayerInfo[to_player][pName], 
		PlayerInfo[playerid][pID], 
		PlayerInfo[to_player][pID], 
		string, 
		nonrp);
	mysql_tquery(connects, sql_str, "", "");

	return PlayerPutInDemorgan(to_player);
}