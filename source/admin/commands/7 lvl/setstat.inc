CMD:setstat(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);

    extract params -> new to_player, what, count; else
	{
	    SCM(playerid, blue, "�[���������] {ffffff}�������: /setstat [id ������] [�����] [��������]");
	    SCM(playerid, white, "[�����]: 1 - ������; 2 - ����� � �����; 3 - ��� �������������; 4 - ���;");
 		return 1;
	}
	
    if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);
	if(PlayerInfo[to_player][bAdmin] > PlayerInfo[playerid][bAdmin]) return 1;
    
    switch(what)
    {
		case 1:
		{
			ResetPlayerMoney(to_player);
			PlayerInfo[to_player][pCash] = 0;
			GiveMoney(to_player, count, "/setstat");
			new string[128];
			format(string, sizeof(string), "�� ���������� %d ����� ������ %s[%d]", count, PlayerInfo[to_player][pName], to_player);
			SCM(playerid, white, string);
			
			format(string, sizeof(string), "������������� %s[%d] ��������� ��� %d ������", PlayerInfo[playerid][pName], playerid, count);
			SCM(to_player, white, string);
		}
		case 2:
		{
			PlayerInfo[to_player][pBCash] = count;
			new string[128];
			format(string, sizeof(string), "�� ���������� %d ����� � ����� ������ %s[%d]", count, PlayerInfo[to_player][pName], to_player);
			SCM(playerid, white, string);

			format(string, sizeof(string), "������������� %s[%d] ��������� ��� %d ������ � �����", PlayerInfo[playerid][pName], playerid, count);
			SCM(to_player, white, string);
		}
		case 3:
		{
			PlayerInfo[to_player][pTruckLVL] = count;
			new string[128];
			format(string, sizeof(string), "�� ���������� %d LVL ������������� ������ %s[%d]", count, PlayerInfo[to_player][pName], to_player);
			SCM(playerid, white, string);

			format(string, sizeof(string), "������������� %s[%d] ��������� ��� %d ������� �������������", PlayerInfo[playerid][pName], playerid, count);
			SCM(to_player, white, string);
		}
		case 4:
		{
			PlayerInfo[to_player][pLVL] = count;
			new string[128];
			format(string, sizeof(string), "�� ���������� %d LVL ������ %s[%d]", count, PlayerInfo[to_player][pName], to_player);
			SCM(playerid, white, string);

			format(string, sizeof(string), "������������� %s[%d] ��������� ��� %d �������", PlayerInfo[playerid][pName], playerid, count);
			SCM(to_player, white, string);
		}
		default:
		{
  			SCM(playerid, blue, "�[���������] {ffffff}�������: /setstat [id ������] [�����] [��������]");
		    SCM(playerid, blue, "[�����]: 1 - ������; 2 - ����� � �����; 3 - ��� �������������; 4 - ���;");
	 		return 1;
		}
    }
    SaveAccounts(playerid);
    SaveAccounts(to_player);
	return 1;
}