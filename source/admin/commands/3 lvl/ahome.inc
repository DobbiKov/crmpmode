CMD:ahome(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);
    extract params -> new id; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /ahome [ID дома]");

	new text[380] = "{FFFFFF}";
	new fmt_str[50], class[32];
	
	new h;
    foreach(new i : Allhouses) if(PlayerInfo[playerid][pHomeID] == id) 
    {
        h = i; 
        break;
    }
    switch(HouseInfo[h][hType])
    {
        case 1: class = "Низкий";
        case 2: class = "Средний";
        case 3: class = "Высокий";
    }
	format(fmt_str, sizeof fmt_str, "\t{ffffff}Дом\t\t\t{"cblue"}№:%d\n\n", HouseInfo[h][hID]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}Владелец: \t\t{"cblue"}%s\n", HouseInfo[h][hOwner]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}Класс: \t\t\t{"cblue"}%s\n", class);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}Состояние:\t\t%s\n", HouseInfo[h][hLock] == 1 ? ("{ff614a}закрыт") : ("{66cc00}открыт"));
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}Оплачено:\t\t{"cblue"}%d/30\n", HouseInfo[h][hDays]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}Оплата в день:\t{"cblue"}%d рублей\n", house_params[ HouseInfo[h][hType] ][hrent]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}Патроны:\t\t{"cblue"}%d\n", HouseInfo[h][hPatron]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}Металл:\t\t{"cblue"}%d\n", HouseInfo[h][hMetall]);
	strcat(text, fmt_str);
	
	format(fmt_str, sizeof fmt_str, "\t{ffffff}Наркотики:\t\t{"cblue"}%d\n", HouseInfo[h][hDrugs]);
	strcat(text, fmt_str);
	
	SPD
	(
		playerid, D_NULL, DIALOG_STYLE_MSGBOX,
		"{"cblue"}Управление домом",
		text,
		"Закрыть", ""
	);
    return 1;
}