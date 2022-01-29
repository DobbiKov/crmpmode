CMD:editbusiness(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

	extract params -> new biz_id, type, amount; else
    {
        SCM(playerid, blue, "[ѕодсказка] {ffffff}¬ведите: /editbusiness [ID бизнесса] [тип действи€] [значение]");
        return SCM(playerid, blue, "[тип действи€]{FFFFFF}: 1 - тип бизнесса | 2 - кол-во оплаченых дней бизнесса | 3 - стоимость бизнесса");
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
        return SCM(playerid, red, !"Ѕизнесса под таким ID нет!");
    }

    if(type == 1)
    {
        if(amount < 1 || amount > 6)
            return SCM(playerid, red, !"«начение типа бизнесса должно быть не менее 1 и не более 6!");
        BusinessInfo[b][bType] = amount;
        UpdateBusiness(b);

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] сменил тип бизнесса є%d на %s", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, biz_id, business_params[amount][bname]
        );
        return SCMA(grey, string);
    }
    if(type == 2)
    {   
        if(amount < 1)
            return SCM(playerid, red, !"«начение кол-ва дней оплаты должно быть не менее 1 и не более 30!");
        if(PlayerInfo[playerid][bAdmin] < 7 && amount > 30)
            return SCM(playerid, red, !"«начение кол-ва дней оплаты должно быть не менее 1 и не более 30!");

        BusinessInfo[b][bDays] = amount;
        UpdateBusiness(b);

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] установил кол-во дней оплаты бизнесса є%d на %d", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, biz_id, amount
        );
        return SCMA(grey, string);
    }
    if(type == 3)
    {   
        if(amount < 1)
            return SCM(playerid, red, !"«начение стоимости бизнесса должно быть не менее 1!");

        BusinessInfo[b][bPrice] = amount;
        UpdateBusiness(b);

        new string[144];
        format(string, sizeof(string), "[A] %s %s[%d] установил значение стоимости бизнесса є%d на %d", 
            GetRangAdmin[ PlayerInfo[playerid][bAdmin] ], PlayerInfo[playerid][pName], playerid, biz_id, amount
        );
        return SCMA(grey, string);
    }
    SCM(playerid, blue, "[ѕодсказка] {ffffff}¬ведите: /editbusiness [ID бизнесса] [тип действи€] [значение]");
    return SCM(playerid, blue, "[тип действи€]{FFFFFF}: 1 - тип бизнесса | 2 - кол-во оплаченых дней бизнесса | 3 - стоимость бизнесса");
}