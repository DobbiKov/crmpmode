CMD:check_cheat(playerid, params[])

{

	new str[800], string[800];

	if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid); //������ �� ���� ����������

    extract params -> new to_player; else return SCM(playerid, blue, !"[���������]: {FFFFFF}����������� /check_cheat [ID ������]");

    if(!IsPlayerConnected(to_player)) return SendClientMessage(playerid, red,"�������� ID");

    new speed = SpeedVehicle(to_player);

    //

    new podoz = gettime();

    new result = podoz - time_podoz;

    if(result >= 10000000) result = 0;

    //

    new pick = gettime();

    new result1 = pick - time_pick;

    if(result1 >= 10000000) result1 = 0;

    //

    new spawn = gettime();

    new result2 = spawn - time_lspawn;

    if(result2 >= 10000000) result2 = 0;

    //

    new vhcar = gettime();

    new result3 = vhcar - time_vcar;

    if(result3 >= 10000000) result3 = 0;

    //

    new zohcar = gettime();

    new result4 = zohcar - time_zcar;

    if(result4 >= 10000000) result4 = 0;

    //

	format(str,sizeof(str),"{ffffff}��� ������: %s[%d]\n",PlayerInfo[to_player][pName],to_player); //������ �� ���� ����������

	strcat(string,str);

	format(str,sizeof(str),"{ffffff}������������: %d ���. �����\n", result);

	strcat(string,str);

	if(addchet[to_player] > 0)
	{

		if(GetPlayerState(to_player) != 2) strcat(string,"{ffffff}������� ����������: ������: ������ ��������/�����/airbrake\n\n");

		else strcat(string,"{ffffff}������� ����������: ������: speed-hack/������ ��������\n\n");

	}

	else strcat(string,"{ffffff}������� ����������: ����� �� ������������\n\n");

	strcat(string,"{ffffff}�������������� ������������� ���������:\n");

	format(str,sizeof(str),"{ffffff}- �� 1-�� ������� ������������ �� %d ������\n\n", speed);

	strcat(string,str);

	format(str,sizeof(str),"{ffffff}- ��������� ��������� ��������(�����/��/�����): %d ���. �����\n", result1);

	strcat(string,str);

	format(str,sizeof(str),"{ffffff}- ��������� ��� ������� � ������: %d ���. �����\n", result4);

	strcat(string,str);

	format(str,sizeof(str),"{ffffff}- ��������� ����� �� ������: %d ���. �����\n", result3);

	strcat(string,str);

	format(str,sizeof(str),"{ffffff}- ��������� ��������� �����: %d ���. �����\n\n", result2);

	strcat(string,str);

	strcat(string,"{BE2D2D}����. ������� �� 2-�� ������� � ������� ������� ���������� ��������� ��� ��������.\n");

	strcat(string,"{BE2D2D}��� ������� ��� ������: {ffffff}'��������� �� ���������� ��������'.\n\n\n\n");

	if(addchet[to_player]==1) strcat(string,"�������� ���������� ��������: {248daa}����� ��� ������������ �� ������ [����� ��� ���������]\n");

	else if(addchet[to_player]==2) strcat(string,"�������� ���������� ��������: {248daa}����� [80 ���������]\n");

	else if(result>300) strcat(string,"�������� ���������� ��������: ������ ����� ���!\n");

	else strcat(string,"�������� ���������� ��������: {248daa}����� �� ������������\n");

    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, !"{"cblue"}������� UN-AC", string, "�������","");

	return true;

}