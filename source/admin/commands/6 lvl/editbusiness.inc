CMD:editbusiness(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

	extract params -> new biz_id, type, amount; else
    {
        SCM(playerid, blue, "[���������] {ffffff}�������: /editbusiness [ID ��������] [��� ��������] [��������]");
        return SCM(playerid, blue, "[��� ��������]{FFFFFF}: 1 - ��� �������� | 2 - ���-�� ��������� ���� �������� | 3 - ��������� ��������");
    }

    new b = -1;
    foreach(new i : Allbusiness) 
    {
        if(BusinessInfo[i][bID] == biz_id)
        {
            b = i; 
            break;
        }
    }
    if(b == -1)
    {
        return SCM(playerid, red, !"�������� ��� ����� ID ���!");
    }

    if(type == 1)
    {
        if(amount < 1 || amount > 6)
            return SCM(playerid, red, !"�������� ���� �������� ������ ���� �� ����� 1 � �� ����� 6!");
        BusinessInfo[b][bType] = amount;
        UpdateBusiness(b);

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] ������ ��� �������� �%d �� %s", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, biz_id, business_params[amount][bname]
        );
        return SCMA(grey, string);
    }
    if(type == 2)
    {   
        if(amount < 1)
            return SCM(playerid, red, !"�������� ���-�� ���� ������ ������ ���� �� ����� 1 � �� ����� 30!");
        if(PlayerInfo[playerid][bAdmin] < 7 && amount > 30)
            return SCM(playerid, red, !"�������� ���-�� ���� ������ ������ ���� �� ����� 1 � �� ����� 30!");

        BusinessInfo[b][bDays] = amount;
        UpdateBusiness(b);

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] ��������� ���-�� ���� ������ �������� �%d �� %d", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, biz_id, amount
        );
        return SCMA(grey, string);
    }
    if(type == 3)
    {   
        if(amount < 1)
            return SCM(playerid, red, !"�������� ��������� �������� ������ ���� �� ����� 1!");

        BusinessInfo[b][bPrice] = amount;
        UpdateBusiness(b);

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] ��������� �������� ��������� �������� �%d �� %d", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, biz_id, amount
        );
        return SCMA(grey, string);
    }
    SCM(playerid, blue, "[���������] {ffffff}�������: /editbusiness [ID ��������] [��� ��������] [��������]");
    return SCM(playerid, blue, "[��� ��������]{FFFFFF}: 1 - ��� �������� | 2 - ���-�� ��������� ���� �������� | 3 - ��������� ��������");
}