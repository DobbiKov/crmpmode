CMD:me(playerid, params[])
{
    if(sscanf(params, "s[100]", params[0])) return SCM(playerid, white, "{"cblue"}� [���������]{"cwhite"}: ����������� /me [�����]");
	if(CheckAdvertOtherSource(params[0]))
	{
		SendAdminAntiAdvert(playerid, params[0]);
		return 0;
	}
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, green, !"� ������ ������ � ��� ���. ����� �� ����� ����: /time");
    new string[128];
	format(string, sizeof(string), "%s %s", PlayerName(playerid), params[0]);
	ProxDetector(30.0, playerid, string, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF);
	return SetPlayerChatBubble(playerid, params[0], 0xDD90FFFF, 30.0, 5000);
}
CMD:do(playerid, params[])
{
    if(sscanf(params, "s[100]", params[0])) return SCM(playerid, white, "{"cblue"}� [���������]{"cwhite"}: ����������� /do [�����]");
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, green, !"� ������ ������ � ��� ���. ����� �� ����� ����: /time");
	if(CheckAdvertOtherSource(params[0]))
	{
		SendAdminAntiAdvert(playerid, params[0]);
		return 0;
	}
	new string[128];
	format(string, sizeof(string), "%s (( %s ))", params[0], PlayerName(playerid));
	ProxDetector(30.0, playerid, string, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF);
	return SetPlayerChatBubble(playerid, params[0], 0xDD90FFFF, 30.0, 5000);
}
CMD:todo(playerid,params[])
{
	new Text_[60], Deistvie_[60];
	if(sscanf(params, "p<*>s[60]s[60]", Text_,Deistvie_)) return SCM(playerid, white, "{"cblue"}� [���������]{"cwhite"}: /todo [�����]*[��������]");
	if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, green, !"� ������ ������ � ��� ���. ����� �� ����� ����: /time");
	if(CheckAdvertOtherSource(params[0]))
	{
		SendAdminAntiAdvert(playerid, params[0]);
		return 0;
	}
	stringer[0] = EOS;
	format(stringer, 240, "\"{FFFFFF}%s{DD90FF}\", - ������ %s, %s",Text_, PlayerName(playerid),Deistvie_);
	ProxDetector(30.0, playerid, stringer, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF);
	return 1;
}
CMD:try(playerid, params[])
{
    if(sscanf(params, "s[82]", params[0])) return SCM(playerid, white, "{"cblue"}� [���������]{"cwhite"}: ����������� /try [�����]");
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, green, !"� ������ ������ � ��� ���. ����� �� ����� ����: /time");
	if(CheckAdvertOtherSource(params[0]))
	{
		SendAdminAntiAdvert(playerid, params[0]);
		return 0;
	}
	new string[128];
    switch(random(2))
    {
        case 0: format(string, sizeof(string), "%s %s | {FF6600}��������", PlayerName(playerid), params[0]);
        case 1: format(string, sizeof(string), "%s %s | {66CC00}������", PlayerName(playerid), params[0]);
    }
	ProxDetector(30.0, playerid, string, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF, 0xDD90FFFF);
	return 1;
}