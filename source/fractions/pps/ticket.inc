CMD:ticket(playerid, params[])
{
    if(!IsAPolice(playerid) && PlayerInfo[playerid][bAdmin] < 2) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player, cash, string: reason[50]; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /ticket [ID ������] [�����] [�������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID.");
    if(cash > 50000 || cash <= 0) return SCM(playerid, red, "����� ������ �� ����� 0 � �� ����� 50 �����.");
    if(!strlen(reason) || strlen(reason) > 50) return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /ticket [ID ������] [�����] [�������]");

    new Float:pos[3];
    GetPlayerPos(to_player, pos[0], pos[1], pos[2]);
    if(!IsPlayerInRangeOfPoint(playerid, 5.0, pos[0], pos[1], pos[2])) return SCM(playerid, red, "����� ������ �� ���");
    if(PlayerInfo[to_player][pFines] >= 30) return SCM(playerid, red, "� ������� ������ ��� 30 �������.");

    new fine = cash;

    PlayerInfo[to_player][pFines]++;
    PlayerInfo[to_player][pSumFines] += fine;

    if(PlayerInfo[to_player][pFines] >= 30)
    {
        PlayerInfo[to_player][pLicA] = 0;
        PlayerInfo[to_player][pLicB] = 0;
        PlayerInfo[to_player][pLicC] = 0;
        PlayerInfo[to_player][pLicD] = 0;

        SCM(to_player, red, "�� ���� ������ ������������ ���� �� �������� 30 �������.");
        SCM(to_player, blue, "�������� ������ �� ������ � ����� ���������. �������� �������: /tickets");
    }
    else
    {
        new hours, minutes, sec;
        gettime(hours, minutes, sec);

        static const fmt_query[] = "INSERT INTO `fines` (`account_id`, `fined`, `fine`, `date`, `reason`) VALUES ('%d', '%s', '%d', '%s %02d:%02d:%02d', '%s')";
        new query[sizeof(fmt_query)+(-2+3)+(-2+MAX_PLAYER_NAME)+(-2+6)+(-2+30)+(-2+30)];
        format(query, sizeof(query), fmt_query, PlayerInfo[to_player][pID], PlayerInfo[playerid][pName], fine, date("%dd.%mm.%yyyy", gettime()), hours, minutes, sec, reason);
        mysql_tquery(connects, query, "", "");

        new string[144];
        format(string, sizeof(string), "%s %s ������� ��� ����� �� ����� %d ���. �������: %s", GetPlayerRank(playerid), PlayerName(playerid), fine, reason);
        SCM(to_player, blue, string);

        format(string, sizeof(string), "�� �������� ����� %s �� ����� %d ���. �������: %s", PlayerName(to_player), fine, reason);
        SCM(playerid, blue, string);

        format(string, sizeof(string), "�������(-�) ����� %s", PlayerName(to_player));
        cmd::me(playerid, string);

        PlayerInfo[playerid][pFines]++;

        static const fmt_msg[] = "���������� �������: %d/30 �� ������� ������������ ����";
        format(string, sizeof(string), fmt_msg, PlayerInfo[playerid][pFines]);
        SCM(to_player, blue, string);
    }
    SaveAccounts(playerid);
    SaveAccounts(to_player);
    return 1;
}