CMD:nick(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 2) return ShowCommandNotFound(playerid);

    extract params -> new to_player; else return SCM(playerid, yellow, "[���������]: {FFFFFF}�����������: /nick [ID ������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][bAdmin] > PlayerInfo[playerid][bAdmin]) return SCM(playerid, red, "������ ������� ��������������.");

    new string[128];
    if(PlayerInfo[to_player][pLVL] == 1)
    {
        format(string, sizeof(string), "������������� %s ������ ������ %s. �������: NonRP ���-����", PlayerInfo[playerid][pName], PlayerInfo[to_player][pName]);
        SCMTA(0xFF4530FF, string);
        
        format(string, sizeof(string), "{FFFFFF}�� ���� ������� � �������, ��� ��� � ��� NonRP ���-����!\n{FFFFFF}��������� ��� � ����� ������� �� ������.\n{FFFFFF}������ NickName'a: {"cblue"}Name_Surname\n{FFFFFF}������: {"cblue"}Eduard_Dobbikov{FFFFFF}, {"cblue"}Tatiana_Pilipiuk\n\n{FFFFFF}��� � ����� � �������, �������� ������� {"cblue"}/q");
        SPD(to_player, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}UNIGVA | Kick", string, "�������", "");
    }
    else
    {
        format(string, sizeof(string), "[A] %s[%d] �������� ������ %s[%d] ������� NickName", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
        SCMA(grey, string);

        format(string, sizeof(string), "������������� %s �������� ��� ������� NonRP NickName!");
        SCM(to_player, white, string);

        format(string, sizeof(string), "{FFFFFF}��� ������� ������� NonRP ���-����!\n{FFFFFF}��� � ������� ������� - ������� ������� /menu, ����� �������� ����� '������� NickName'.\n{FFFFFF}������ NickName'a: {"cblue"}Name_Surname\n{FFFFFF}������: {"cblue"}Eduard_Dobbikov{FFFFFF}, {"cblue"}Tatiana_Pilipiuk\n\n{FFFFFF}��� � ����� � �������, �������� ������� {"cblue"}/q");
        SPD(to_player, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}UNIGVA | NonRP NickName", string, "�����", "");
    }
    return 1;
}