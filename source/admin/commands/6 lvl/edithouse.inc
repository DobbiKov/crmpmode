CMD:edithouse(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

	extract params -> new home_id, type, amount; else
    {
        SCM(playerid, blue, "[ѕодсказка] {ffffff}¬ведите: /edithouse [ID дома] [тип действи€] [значение]");
        return SCM(playerid, blue, "[тип действи€]{FFFFFF}: 1 - класс дома | 2 - кол-во оплаченых дней дома | 3 - стоимость дома");
    }

	new h = -1;
    foreach(new i : Allhouses) if(HouseInfo[i][hID] == home_id) 
    {
        h = i; 
        break;
    }
	if(h == -1)
		return SCM(playerid, red, !"“акого дома нет!");

    if(type == 1)
    {
        if(amount < 1 || amount > 3)
            return SCM(playerid, red, !"«начение класса дома должно быть не менее 1 и не более 3!");
        HouseInfo[h][hType] = amount;
        SaveHouse(h);

        new class[10];
        switch(amount)
        {
            case 1: class = "Ќизкий";
            case 2: class = "—редний";
            case 3: class = "¬ысокий";
        }

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] сменил класс дома є%d на %s", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, home_id, class
        );
        return SCMA(grey, string);
    }
    if(type == 2)
    {   
        if(amount < 1)
            return SCM(playerid, red, !"«начение кол-ва дней оплаты должно быть не менее 1 и не более 30!");
        if(PlayerInfo[playerid][bAdmin] < 7 && amount > 30)
            return SCM(playerid, red, !"«начение кол-ва дней оплаты должно быть не менее 1 и не более 30!");

        HouseInfo[h][hDays] = amount;
        SaveHouse(h);

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] установил кол-во дней оплаты дома є%d на %d", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, home_id, amount
        );
        return SCMA(grey, string);
    }
    if(type == 3)
    {   
        if(amount < 1)
            return SCM(playerid, red, !"«начение стоимости дома должно быть не менее 1!");

        HouseInfo[h][hPrice] = amount;
        SaveHouse(h);

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] установил стоимость дома є%d на %d", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, home_id, amount
        );
        return SCMA(grey, string);
    }
    SCM(playerid, blue, "[ѕодсказка] {ffffff}¬ведите: /edithouse [ID дома] [тип действи€] [значение]");
    return SCM(playerid, blue, "[тип действи€]{FFFFFF}: 1 - класс дома | 2 - кол-во оплаченых дней дома | 3 - стоимость дома");
}