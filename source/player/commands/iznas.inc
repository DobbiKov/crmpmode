new iznas_timer[MAX_PLAYERS];
new isCanIznas[MAX_PLAYERS];

CMD:iznas(playerid, params[])
{
    if(PlayerInfo[playerid][pLVL] < 4)
        return SCM(playerid, red, !"�� ������ ��������� ����� 4-�� ��� � �������!");

    if(!isCanIznas[playerid]) 
    { 
        return SCM(playerid, red, !"�� ��������!");
    }
    extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /iznas [ID ������]");
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID!");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);

    if(!IsPlayerInRangeOfPlayer(playerid, to_player, 4.0))
        return SCM(playerid, red, !"����� ������ �� ���!");

    if(PlayerInfo[to_player][pLVL] < 4)
        return SCM(playerid, red, !"����� ������ ��������� ����� 4-�� ��� � �������!");
    if(PlayerInfo[to_player][bAdmin] > PlayerInfo[playerid][bAdmin])
        return SCM(playerid, red, !"�� �� ������ ������������ ������� ������.");

    SCM(playerid,blue,"�� ������������ ��������");
    SCM(to_player,blue,"��� ������������!");
    ApplyAnimation(to_player,"SNM","SPANKINGW",4.1,0,1,1,1,1, 1);
    ApplyAnimation(playerid,"SNM","SPANKEDW",4.1,0,1,1,1,1, 1);

    new string[144];
    format(string, sizeof(string), "�����������(-�) %s", PlayerName(to_player));
    cmd::me(playerid, string);

    if(PlayerInfo[playerid][pWANTED] < 6)
        PlayerInfo[playerid][pWANTED]++;
    SetPlayerWantedLevel(playerid, PlayerInfo[playerid][pWANTED]);

    format(string, sizeof(string), "[��������] %s �������� ������������ ������������ ��������� � ��������� %s � ��� �������� � ������.", PlayerInfo[playerid][pName], PlayerInfo[to_player][pName]);
    SCMR(TEAM_PPS, blue, string);
    SCMR(TEAM_FSB, blue, string);

    isCanIznas[playerid] = false;
    iznas_timer[playerid] = SetTimerEx("IsCanIznasTimer", 5 * 60 * 1000, false, "i", playerid);
    return 1;
}

publics IsCanIznasTimer(playerid)
{
    isCanIznas[playerid] = true;
    return isCanIznas[playerid];
}