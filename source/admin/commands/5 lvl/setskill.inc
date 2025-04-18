CMD:setskill(playerid, params[]){
    if(PlayerInfo[playerid][bAdmin] < 5) return ShowCommandNotFound(playerid);
    extract params -> new to_player, gun, skill; else
    {
        SCM(playerid, blue, !"[���������]: {FFFFFF}����������� /setskill [ID ������] [������(1-6)] [�����(0-100)]");
        SCM(playerid, blue, !"[������]: {FFFFFF}1 - SD Pistol | 2 - Desert Eagle | 3 - ShotGun | 4 - MP5 | 5 - AK47 | 6 - M4");
        return 1;
    }
    if(!IsPlayerConnected(to_player) || !PlayerInfo[to_player][pLogin]) return PlayerOffLine(playerid);
    if(skill > 100 || skill < 0)
        return SCM(playerid, red, "�������� [�����] ������ ���� �� ����� 0 � �� ����� 100");

    switch(gun){
        case 1:{
            PlayerInfo[to_player][SKILL_SD_PISTOL] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] ������������� %s[%d] ����� ������ %s[%d] %d ��������� ������� �������� ������� SD Pistol.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "������������� %s ����� ��� %d ��������� ������� �������� ������� SD Pistol.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "�� ������ ������ %s %d ��������� ������� �������� ������� SD Pistol", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        case 2:{
            PlayerInfo[to_player][SKILL_DEAGLE] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] ������������� %s[%d] ����� ������ %s[%d] %d ��������� ������� �������� ������� Desert Eagle.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "������������� %s ����� ��� %d ��������� ������� �������� ������� Desert Eagle.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "�� ������ ������ %s %d ��������� ������� �������� ������� Desert Eagle", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        case 3:{
            PlayerInfo[to_player][SKILL_SHOTGUN] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] ������������� %s[%d] ����� ������ %s[%d] %d ��������� ������� �������� ������� ShotGun.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "������������� %s ����� ��� %d ��������� ������� �������� ������� ShotGun.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "�� ������ ������ %s %d ��������� ������� �������� ������� ShotGun", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        case 4:{
            PlayerInfo[to_player][SKILL_MP5] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] ������������� %s[%d] ����� ������ %s[%d] %d ��������� ������� �������� ������� ��-74�.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "������������� %s ����� ��� %d ��������� ������� �������� ������� ��-74�.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "�� ������ ������ %s %d ��������� ������� �������� ������� ��-74�", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        case 5:{
            PlayerInfo[to_player][SKILL_AK_47] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] ������������� %s[%d] ����� ������ %s[%d] %d ��������� ������� �������� ������� AK-47.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "������������� %s ����� ��� %d ��������� ������� �������� ������� AK-47.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "�� ������ ������ %s %d ��������� ������� �������� ������� AK-47", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        case 6:{
            PlayerInfo[to_player][SKILL_M4] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] ������������� %s[%d] ����� ������ %s[%d] %d ��������� ������� �������� ������� M4.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "������������� %s ����� ��� %d ��������� ������� �������� ������� M4.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "�� ������ ������ %s %d ��������� ������� �������� ������� M4", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        default:{
            return SCM(playerid, red, "�������� [������] ������ ���� �� ����� 1 � �� ����� 6.");
        }
    }
    return 1;
}