CMD:atakelic(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3 && !IsAPolice(playerid)) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][bAdmin] < 3 && IsAPolice(playerid) && PlayerInfo[playerid][pRang] < 5) return YouCannotUseThisFunc(playerid);
    extract params -> new to_player, id; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /atakelic [ID ������] [��������� 1 - A, 2 - B, 3 - C, 4 - D, 5 - �������, 6 - �����, 7 - ������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][bAdmin] >= 3) return SCM(playerid, red, "�� �� ������ �������� �������� � ������� ������!");
    if(id < 1 || id > 7) return SCM(playerid, red, "2-�� �������� ������ ���� �� ����� 1-�� � �� ����� 7-��.");

    new string[144];
    switch(id)
    {
        case 1:
        {
            if(PlayerInfo[to_player][pLicA] < 1) return SCM(playerid, red, "� ������ ���������� �������� ������ ���������!");

            PlayerInfo[to_player][pLicA] = 0;
            format(string, sizeof(string), "�� �������� ����� ��������� A � %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "������������� %s ������� � ��� ����� ��������� A", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] ������� ����� ��������� A � %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 2:
        {
            if(PlayerInfo[to_player][pLicB] < 1) return SCM(playerid, red, "� ������ ���������� �������� ������ ���������!");

            PlayerInfo[to_player][pLicB] = 0;
            format(string, sizeof(string), "�� �������� ����� ��������� B � %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "������������� %s ������� � ��� ����� ��������� B", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] ������� ����� ��������� B � %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 3:
        {
            if(PlayerInfo[to_player][pLicC] < 1) return SCM(playerid, red, "� ������ ���������� �������� ������ ���������!");

            PlayerInfo[to_player][pLicC] = 0;
            format(string, sizeof(string), "�� �������� ����� ��������� C � %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "������������� %s ������� � ��� ����� ��������� C", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] ������� ����� ��������� C � %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 4:
        {
            if(PlayerInfo[to_player][pLicD] < 1) return SCM(playerid, red, "� ������ ���������� �������� ������ ���������!");

            PlayerInfo[to_player][pLicD] = 0;
            format(string, sizeof(string), "�� �������� ����� ��������� D � %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "������������� %s ������� � ��� ����� ��������� D", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] ������� ����� ��������� D � %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 5:
        {
            if(PlayerInfo[to_player][pLicBiz] < 1) return SCM(playerid, red, "� ������ ���������� �������� ������ ���������!");

            PlayerInfo[to_player][pLicBiz] = 0;
            format(string, sizeof(string), "�� �������� �������� �� ������� � %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "������������� %s ������� � ��� �������� �� �������", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] ������� �������� �� ������� � %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 6:
        {
            if(PlayerInfo[to_player][pLicFly] < 1) return SCM(playerid, red, "� ������ ���������� �������� ������ ���������!");

            PlayerInfo[to_player][pLicFly] = 0;
            format(string, sizeof(string), "�� �������� �������� �� ����� � %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "������������� %s ������� � ��� �������� �� �����", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] ������� �������� �� ����� � %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 7:
        {
            if(PlayerInfo[to_player][pLicGun] < 1) return SCM(playerid, red, "� ������ ���������� �������� ������ ���������!");

            PlayerInfo[to_player][pLicGun] = 0;
            format(string, sizeof(string), "�� �������� �������� �� ������ � %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "������������� %s ������� � ��� �������� �� ������", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] ������� �������� �� ������ � %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
    }
    return 1;
}