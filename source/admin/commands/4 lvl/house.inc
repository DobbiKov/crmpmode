CMD:house(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 4) return ShowCommandNotFound(playerid);
    extract params -> new id; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /house [ID ����]");
	
	new h = -1;
    foreach(new i : Allhouses) if(HouseInfo[i][hID] == id) 
    {
        h = i; 
        break;
    }
	if(h == -1)
		return SCM(playerid, red, !"������ ���� ���!");

    SetPlayerPos(playerid, 
        HouseInfo[h][hExitX],
        HouseInfo[h][hExitY],
        HouseInfo[h][hExitZ]
    );

    new string[144];
    format(string, sizeof(string), "�� ����������������� � ���� �%d", id);
    SCM(playerid, lightblue, string);
    return 1;
}