CMD:settempnick(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

	extract params -> new to_player, string:name[40]; else return SCM(playerid, blue, "[Подсказка] {FFFFFF}/settempnick [ID игрока] [NickName]");

    if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

    SetPlayerName(to_player, name);
    new string[256] = "";
    format(string, sizeof(string), "[A]: %s[%d] установил %s[%d] временный никнейм: %s", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, name);
    SCMA(grey, string);

    format(string, sizeof(string), "Администратор %s установил вам временный никнейм: %s", PlayerInfo[playerid][pName], name);
    SCM(to_player, white, string);
    SaveAccounts(to_player);
    return 1;
}