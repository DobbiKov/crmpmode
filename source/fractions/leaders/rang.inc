CMD:rang(playerid,params[])
{
	if(PlayerInfo[playerid][pMember] == TEAM_NONE || PlayerInfo[playerid][pRang] < 9) return YouCannotUseThisFunc(playerid);
		
    extract params -> new to_player, string: rang[2]; else return SCM(playerid, 0xFFCC00AA, "�[���������] {ffffff}�������: /rang [ID ������] [+/-]");
		
	if(playerid == to_player)
		return SCM(playerid, red, "�� ������� ���� ID!");
		
 	if(PlayerInfo[playerid][pMember] != PlayerInfo[to_player][pMember]) return SCM(playerid, red, "����� �� �������� ������ ����� �����������!");
	if(PlayerInfo[playerid][pMember] == TEAM_VDV && PlayerInfo[to_player][pVoen] < 1) return SCM(playerid, red, "� ������ ��� �������� ������!");
	
    switch(rang[0])
    {
		case '+':
		{
			if(PlayerInfo[to_player][pRang] >= (PlayerInfo[playerid][pRang] - 1))
				return SCM(playerid, red, "�� ������ 1 � �� ������ 9!");

	        PlayerInfo[to_player][pRang]++;
	        
			new string[128];
			format(string, sizeof(string), "�� �������� %s[%d] �� %s (%d)", PlayerInfo[to_player][pName], to_player, PlayerRank[ PlayerInfo[to_player][pMember] ][ PlayerInfo[to_player][pRang] ], PlayerInfo[to_player][pRang]);
			SCM(playerid, blue, string);
	        
			format(string, sizeof(string), "��� ���� � ����������� ��� ������� �� %s (%d)", PlayerRank[ PlayerInfo[to_player][pMember] ][ PlayerInfo[to_player][pRang] ], PlayerInfo[to_player][pRang]);
			SCM(to_player, blue, string);
			RangUpMyTK(to_player);
            SaveAccounts(to_player);
		}
		case '-':
		{
			if(PlayerInfo[to_player][pRang] >= PlayerInfo[playerid][pRang]) return SCM(playerid, red, "�� �� ������ �������� ����� ������!");
			   
			if(PlayerInfo[to_player][pRang] == 1)
				return SCM(playerid, 0xFFCC00AA, "�[���������] {ffffff}�������: /uninvite [�� ������] [�������]");
				
            PlayerInfo[to_player][pRang]--;
				
			new string[128];
			format(string, sizeof(string), "�� �������� %s[%d] �� %s (%d)", PlayerInfo[to_player][pName], to_player, PlayerRank[ PlayerInfo[to_player][pMember] ][ PlayerInfo[to_player][pRang] ], PlayerInfo[to_player][pRang]);
			SCM(playerid, blue, string);
	        
			format(string, sizeof(string), "��� ���� � ����������� ��� ������� �� %s (%d)", PlayerRank[ PlayerInfo[to_player][pMember] ][ PlayerInfo[to_player][pRang] ], PlayerInfo[to_player][pRang]);
			SCM(to_player, blue, string);

			RangDownMyTK(to_player);
            SaveAccounts(to_player);
		}
        default: return SCM(playerid, 0xFFCC00AA, "�[���������] {ffffff}�������: /rang [ID ������] [+/-]"); 
	}
    
    return 1;
}