CMD:house(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 4) return ShowCommandNotFound(playerid);
    extract params -> new id; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /house [ID дома]");
	
	new h = -1;
    foreach(new i : Allhouses) if(HouseInfo[i][hID] == id) 
    {
        h = i; 
        break;
    }
	if(h == -1)
		return SCM(playerid, red, !"Такого дома нет!");

    SetPlayerPos(playerid, 
        HouseInfo[h][hExitX],
        HouseInfo[h][hExitY],
        HouseInfo[h][hExitZ]
    );

    new string[144];
    format(string, sizeof(string), "Вы телепортировались к дому №%d", id);
    SCM(playerid, lightblue, string);
    return 1;
}