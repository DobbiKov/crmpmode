CMD:setleader(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

	extract params -> new to_player, id; else
    {
        SCM(playerid, blue, "[���������] {ffffff}�������: /setleader [ID ������] [ID]");
        return SCM(playerid, blue, "[���������] {FFFFFF}: 1 - �� | 2 - ��� | 3 - ������� | 4 - �������� | 5 - ��� | 6 - ��� - � | 7 - ��� - � | 8 - ���(None)");
    }
    if(!PlayerInfo[to_player][pLogin] && !IsPlayerConnected(to_player)) return PlayerOffLine(playerid);

    if(id > 8 || id < 1) return SCM(playerid, red, "�� ����� 9 � �� ����� 1.");

    new string[128];
    if(PlayerInfo[to_player][pMember] > 0)
    {
        format(string, sizeof(string), "[A] %s[%d] ���� %s[%d] � ��������� ������ ����������� %s", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, GetMember[ PlayerInfo[to_player][pMember] ]);
        SCMA(grey, string);
        PlayerInfo[to_player][pMember] = 0;
        PlayerInfo[to_player][pRang] = 0;
        PlayerInfo[to_player][pFSkin] = -1;
        PlayerInfo[to_player][pWarnF] = 0;
        SetPlayerSkin(to_player, PlayerInfo[to_player][pChar]);
        return SaveAccounts(to_player);
    }

    PlayerInfo[to_player][pMember] = id;
    PlayerInfo[to_player][pRang] = 10;
    PlayerInfo[to_player][pFSkin] = 1;
    PlayerInfo[to_player][pJob] = 0;

    format(string, sizeof(string), "[A] %s[%d] �������� %s[%d] ������� ����������� %s", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, GetMember[id]);
    SCMA(grey, string);

    format(string, sizeof(string), "������������� %s �������� ��� ������� ����������� %s", PlayerInfo[playerid][pName], GetMember[id]);
    SCM(to_player, white, string);
    SaveAccounts(to_player);
    return 1;
}