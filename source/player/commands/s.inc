CMD:s(playerid, params[])
{
    if(sscanf(params, "s[87]", params[0])) return SCM(playerid, white, "{"cblue"}� [���������]{"cwhite"}: ����������� /s [�����]");
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, green, !"� ������ ������ � ��� ���. ����� �� ����� ����: /time");
	if(CheckAdvertOtherSource(params[0]))
	{
		SendAdminAntiAdvert(playerid, params[0]);
		return 0;
	}
    new string[128];
    format(string, sizeof(string), "%s[%d] �������: %s", PlayerInfo[playerid][pName], playerid, params[0]);
	ProxDetector(30.0, playerid, string, white, white, white, white, white);
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) ApplyAnimation(playerid,"ON_LOOKERS","shout_01",4.1,0,0,0,0,0);
	return 1;
}