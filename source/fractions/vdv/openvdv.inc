CMD:openvdv(playerid)
{
	if(!IsPlayerInRangeOfPoint(playerid, 10.0, 1892.1500, 1722.0699, 15.6500)) return 1;
	
	if(PlayerInfo[playerid][pMember] != TEAM_VDV && !IsAFSB(playerid))
		return SCM(playerid, red, "��� ���������� ������ �����������");
	
	if(PlayerInfo[playerid][pMember] == TEAM_VDV && PlayerInfo[playerid][pRang] < 3)
		return SCM(playerid, red, "��� ���������� ������ �����������");
	
	switch(open_vdv_status)
	{
		case 0:
		{
			MoveObject(open_vdv, 1892.1500, 1717.0699, 15.65, 3.0);
			
			open_vdv_status = 1;
			
			SCM(playerid, green, !"�� ������� ������");
			
			SetPlayerChatBubble(playerid,"��������� ������",blue,30.0,10000);
		}
		case 1:
		{
			MoveObject(open_vdv, 1892.15, 1722.07, 15.65, 3.0);
			
			open_vdv_status = 0;
			
			SCM(playerid, red, !"�� ������� ������");
			
			SetPlayerChatBubble(playerid,"��������� ������",red,30.0,10000);
		}
	}
	return 1;
}