CMD:b(playerid, params[])
    return cmd::n(playerid, params);
CMD:n(playerid, params[])
{
    if(sscanf(params, "s[100]", params[0])) return SCM(playerid, white, "{"cblue"}� [���������]{"cwhite"}: ����������� /b [�����]");
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, green, !"� ������ ������ � ��� ���. ����� �� ����� ����: /time");
	
	if(CheckAdvertOtherSource(params[0]))
	{
		SendAdminAntiAdvert(playerid, params[0]);
		return 0;
	}

	new string[128];
	format(string, sizeof(string), "(( %s[%d]: %s ))", PlayerName(playerid), playerid, params[0]);
	ProxDetector(30.0, playerid, string, 0xCCCC99FF, 0xCCCC99FF, 0xCCCC99FF, 0xCCCC99FF, 0xCCCC99FF);
	
	format(string, sizeof(string), "(( %s ))", params[0]);
	SetPlayerChatBubble(playerid, string, 0xCCCC99FF, 30.0, 5000);
	return 1;
}