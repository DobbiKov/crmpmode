CMD:biz(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 4) return ShowCommandNotFound(playerid);
    extract params -> new id; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /biz [ID ��������]");
	
    new b = -1;
    foreach(new i : Allbusiness) 
    {
        if(BusinessInfo[i][bID] == id)
        {
            b = i; 
            break;
        }
    }
    if(b == -1)
    {
        return SCM(playerid, red, !"�������� ��� ����� ID ���!");
    }

    SetPlayerPos(playerid, 
        BusinessInfo[b][bExitX],
        BusinessInfo[b][bExitY],
        BusinessInfo[b][bExitZ]
    );

    new string[144];
    format(string, sizeof(string), "�� ����������������� � �������� �%d", id);
    SCM(playerid, lightblue, string);
    return 1;
}