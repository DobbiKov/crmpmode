CMD:settempnick(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

	extract params -> new to_player, string:name[40]; else return SCM(playerid, blue, "[���������] {FFFFFF}/settempnick [ID ������] [NickName]");

    if(!PlayerInfo[to_player][pLogin] || !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

    SetPlayerName(to_player, name);
    new string[256] = "";
    format(string, sizeof(string), "[A] %s[%d] ��������� %s[%d] ��������� �������: %s", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, name);
    SCMA(grey, string);

    format(string, sizeof(string), "������������� %s ��������� ��� ��������� �������: %s", PlayerInfo[playerid][pName], name);
    SCM(to_player, white, string);
    SaveAccounts(to_player);
    return 1;
}