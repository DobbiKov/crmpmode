ALT:w:whisper;
CMD:w(playerid,params[])
{
    if(sscanf(params,"s[100]",params[0])) return SCM(playerid, white, "{"cblue"}� [���������]{"cwhite"}: /w(hisper) [���������]");
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, green, !"� ������ ������ � ��� ���. ����� �� ����� ����: /time");
	if(CheckAdvertOtherSource(params[0]))
	{
		SendAdminAntiAdvert(playerid, params[0]);
		return 0;
	}
    stringer[0] = EOS;
	format(stringer, 144, "%s[%d] ������: %s", PlayerInfo[playerid][pName],playerid, params[0]);
 	ProxDetector(30.0, playerid, stringer, 0x6E6E6E6E, 0x6E6E6E6E, 0x6E6E6E6E, 0x6E6E6E6E, 0x6E6E6E6E);
	return 1;
}