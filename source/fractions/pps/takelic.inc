CMD:takelic(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3 && !IsAPolice(playerid)) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][bAdmin] < 3 && IsAPolice(playerid) && PlayerInfo[playerid][pRang] < 5) return YouCannotUseThisFunc(playerid);
    extract params -> new to_player, id; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /takelic [ID ������] [��������� 1 - A, 2 - B, 3 - C, 4 - D]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][bAdmin] >= 3 || IsAPolice(to_player)) return SCM(playerid, red, "�� �� ������ �������� �������� � ������� ������!");
    if(id < 1 || id > 4) return SCM(playerid, red, "2-�� �������� ������ ���� �� ����� 1-�� � �� ����� 4-��.");

    new string[144];
    switch(id)
    {
        case 1:
        {
            if(PlayerInfo[to_player][pLicA] < 1) return SCM(playerid, red, "� ������ ���������� �������� ������ ���������!");

            PlayerInfo[to_player][pLicA] = 0;
            format(string, sizeof(string), "�� �������� ����� ��������� A � %s", PlayerName(to_player));
            SCM(playerid, blue, string);

            format(string, sizeof(string), "%s %s ������� � ��� ����� ��������� A", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerName(playerid));
            SCM(to_player, blue, string);

            SaveAccounts(to_player);
        }
        case 2:
        {
            if(PlayerInfo[to_player][pLicB] < 1) return SCM(playerid, red, "� ������ ���������� �������� ������ ���������!");

            PlayerInfo[to_player][pLicB] = 0;
            format(string, sizeof(string), "�� �������� ����� ��������� B � %s", PlayerName(to_player));
            SCM(playerid, blue, string);

            format(string, sizeof(string), "%s %s ������� � ��� ����� ��������� B", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerName(playerid));
            SCM(to_player, blue, string);

            SaveAccounts(to_player);
        }
        case 3:
        {
            if(PlayerInfo[to_player][pLicC] < 1) return SCM(playerid, red, "� ������ ���������� �������� ������ ���������!");

            PlayerInfo[to_player][pLicC] = 0;
            format(string, sizeof(string), "�� �������� ����� ��������� C � %s", PlayerName(to_player));
            SCM(playerid, blue, string);

            format(string, sizeof(string), "%s %s ������� � ��� ����� ��������� C", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerName(playerid));
            SCM(to_player, blue, string);

            SaveAccounts(to_player);
        }
        case 4:
        {
            if(PlayerInfo[to_player][pLicD] < 1) return SCM(playerid, red, "� ������ ���������� �������� ������ ���������!");

            PlayerInfo[to_player][pLicD] = 0;
            format(string, sizeof(string), "�� �������� ����� ��������� D � %s", PlayerName(to_player));
            SCM(playerid, blue, string);

            format(string, sizeof(string), "%s %s ������� � ��� ����� ��������� D", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerName(playerid));
            SCM(to_player, blue, string);

            SaveAccounts(to_player);
        }
    }
    return 1;
}