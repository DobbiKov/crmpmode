CMD:mute(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 2) return ShowCommandNotFound(playerid);

	extract params -> new to_player, time, string: reason[80]; else return SCM(playerid, yellow, !"[���������]: {FFFFFF}����������� /mute [ID ������] [�����] [�������]");

	if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

	if(!strlen(reason)) return SCM(playerid, yellow, !"[���������]: {FFFFFF}����������� /mute [ID ������] [������] [�������]");

	if( time < 1 ||  time > 280 ) return SCM(playerid, blue, "[A] ����� ������ ���� �� ������ 280 � �� ������ 1!");

	if(PlayerInfo[to_player][pMute] > 0) return SCM(playerid, red, "� ������ ��� ����� �������.");

	PlayerInfo[to_player][pMute] = time*60;
	PlayerInfo[playerid][bMute]++;
	SaveAccounts(to_player);
	SaveAccounts(playerid);

	new fmt_query[256];

	format(fmt_query, sizeof fmt_query, "������������� %s �������� ������� %s �� %d �����. �������: %s", PlayerInfo[playerid][pName], PlayerInfo[to_player][pName], time, reason);
	SCMTA(0xFF4530FF, fmt_query);

	format(fmt_query, sizeof fmt_query, "[A] %s[%d] �������� ������� %s[%d] �� %d ����� (%s)", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, time, reason);
	SCMA(grey, fmt_query);

	SCM(to_player, grey, "��� ��������� ������� �� ��������� ������ �������. ���������� ����� �� ������: /time");

	new string[256], sql_str[256];
	new day, month, year, hour, minute, second;
	getdate(day, month, year);
	gettime(hour, minute, second);
	format(string, sizeof(string), "%d/%d/%d - %d:%d:%d", day, month, year, hour, minute, second);

	mysql_format(connects, sql_str, sizeof(sql_str), "INSERT INTO `nakazania` (`AdminName`, `Name`, `AdminId`, `AccountId`, `Date`, `Time`, `Reason`, `Type`) VALUES ('%s', '%s', '%d', '%d', '%s', '%d', '%s', 'mute')", 
		PlayerInfo[playerid][pName], 
		PlayerInfo[to_player][pName], 
		PlayerInfo[playerid][pID], 
		PlayerInfo[to_player][pID], 
		string, 
		mg,
		reason);	
	mysql_tquery(connects, sql_str, "", "");

	return 1;
}