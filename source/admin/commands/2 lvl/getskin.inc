CMD:getskin(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 2 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);
    
    extract params -> new skinid; else return SCM(playerid, yellow, "[���������] {FFFFFF}�����������: /getskin [ID �����]");

    if(skinid < 1 || skinid > 299)
        return SCM(playerid, blue, "�[���������] {ffffff}�������: /getskin [ID �����]");
    
    SetPlayerSkin(playerid, skinid);
    SCM(playerid, blue, "�� ������ ���� ��������� ����!");
	return 1;
}