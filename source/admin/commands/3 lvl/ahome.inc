CMD:ahome(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);
    extract params -> new id; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /ahome [ID ����]");

	new text[380] = "{FFFFFF}";
	new fmt_str[50], class[32];
	
	new h = -1;
    foreach(new i : Allhouses) if(HouseInfo[i][hID] == id) 
    {
        h = i; 
        break;
    }
	if(h == -1)
		return SCM(playerid, red, !"������ ���� ���!");
    switch(HouseInfo[h][hType])
    {
        case 1: class = "������";
        case 2: class = "�������";
        case 3: class = "�������";
    }
	format(fmt_str, sizeof fmt_str, "\t{ffffff}���\t\t\t{"cblue"}�:%d\n\n", HouseInfo[h][hID]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}��������: \t\t{"cblue"}%s\n", HouseInfo[h][hOwner]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}�����: \t\t\t{"cblue"}%s\n", class);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}���������:\t\t%s\n", HouseInfo[h][hLock] == 1 ? ("{ff614a}������") : ("{66cc00}������"));
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}��������:\t\t{"cblue"}%d/30\n", HouseInfo[h][hDays]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}������ � ����:\t\t{"cblue"}%d ������\n", house_params[ HouseInfo[h][hType] ][hrent]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}�������:\t\t{"cblue"}%d\n", HouseInfo[h][hPatron]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}������:\t\t{"cblue"}%d\n", HouseInfo[h][hMetall]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}���������:\t\t{"cblue"}%d\n", HouseInfo[h][hDrugs]);
	strcat(text, fmt_str);
	
	SPD
	(
		playerid, D_NULL, DIALOG_STYLE_MSGBOX,
		"{"cblue"}���������� �����",
		text,
		"�������", ""
	);
    return 1;
}