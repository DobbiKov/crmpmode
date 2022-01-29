CMD:edithouse(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

	extract params -> new home_id, type, amount; else
    {
        SCM(playerid, blue, "[���������] {ffffff}�������: /edithouse [ID ����] [��� ��������] [��������]");
        return SCM(playerid, blue, "[��� ��������]{FFFFFF}: 1 - ����� ���� | 2 - ���-�� ��������� ���� ���� | 3 - ��������� ����");
    }

	new h = -1;
    foreach(new i : Allhouses) if(HouseInfo[i][hID] == home_id) 
    {
        h = i; 
        break;
    }
	if(h == -1)
		return SCM(playerid, red, !"������ ���� ���!");

    if(type == 1)
    {
        if(amount < 1 || amount > 3)
            return SCM(playerid, red, !"�������� ������ ���� ������ ���� �� ����� 1 � �� ����� 3!");
        HouseInfo[h][hType] = amount;
        SaveHouse(h);

        new class[10];
        switch(amount)
        {
            case 1: class = "������";
            case 2: class = "�������";
            case 3: class = "�������";
        }

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] ������ ����� ���� �%d �� %s", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, home_id, class
        );
        return SCMA(grey, string);
    }
    if(type == 2)
    {   
        if(amount < 1)
            return SCM(playerid, red, !"�������� ���-�� ���� ������ ������ ���� �� ����� 1 � �� ����� 30!");
        if(PlayerInfo[playerid][bAdmin] < 7 && amount > 30)
            return SCM(playerid, red, !"�������� ���-�� ���� ������ ������ ���� �� ����� 1 � �� ����� 30!");

        HouseInfo[h][hDays] = amount;
        SaveHouse(h);

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] ��������� ���-�� ���� ������ ���� �%d �� %d", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, home_id, amount
        );
        return SCMA(grey, string);
    }
    if(type == 3)
    {   
        if(amount < 1)
            return SCM(playerid, red, !"�������� ��������� ���� ������ ���� �� ����� 1!");

        HouseInfo[h][hPrice] = amount;
        SaveHouse(h);

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] ��������� ��������� ���� �%d �� %d", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, home_id, amount
        );
        return SCMA(grey, string);
    }
    SCM(playerid, blue, "[���������] {ffffff}�������: /edithouse [ID ����] [��� ��������] [��������]");
    return SCM(playerid, blue, "[��� ��������]{FFFFFF}: 1 - ����� ���� | 2 - ���-�� ��������� ���� ���� | 3 - ��������� ����");
}