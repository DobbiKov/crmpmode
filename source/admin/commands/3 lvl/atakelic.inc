CMD:atakelic(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3 && !IsAPolice(playerid)) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][bAdmin] < 3 && IsAPolice(playerid) && PlayerInfo[playerid][pRang] < 5) return YouCannotUseThisFunc(playerid);
    extract params -> new to_player, id; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /atakelic [ID игрока] [категория 1 - A, 2 - B, 3 - C, 4 - D, 5 - бизнесс, 6 - полёты, 7 - оружие]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][bAdmin] >= 3) return SCM(playerid, red, "Вы не можете отобрать лицензии у данного игрока!");
    if(id < 1 || id > 7) return SCM(playerid, red, "2-ое значение должно быть не менее 1-го и не более 7-ми.");

    new string[144];
    switch(id)
    {
        case 1:
        {
            if(PlayerInfo[to_player][pLicA] < 1) return SCM(playerid, red, "У игрока отсутсвует лицензия данной категории!");

            PlayerInfo[to_player][pLicA] = 0;
            format(string, sizeof(string), "Вы отобрали права категории A у %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "Администратор %s отобрал у Вас права категории A", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] отобрал права категории A у %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 2:
        {
            if(PlayerInfo[to_player][pLicB] < 1) return SCM(playerid, red, "У игрока отсутсвует лицензия данной категории!");

            PlayerInfo[to_player][pLicB] = 0;
            format(string, sizeof(string), "Вы отобрали права категории B у %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "Администратор %s отобрал у Вас права категории B", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] отобрал права категории B у %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 3:
        {
            if(PlayerInfo[to_player][pLicC] < 1) return SCM(playerid, red, "У игрока отсутсвует лицензия данной категории!");

            PlayerInfo[to_player][pLicC] = 0;
            format(string, sizeof(string), "Вы отобрали права категории C у %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "Администратор %s отобрал у Вас права категории C", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] отобрал права категории C у %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 4:
        {
            if(PlayerInfo[to_player][pLicD] < 1) return SCM(playerid, red, "У игрока отсутсвует лицензия данной категории!");

            PlayerInfo[to_player][pLicD] = 0;
            format(string, sizeof(string), "Вы отобрали права категории D у %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "Администратор %s отобрал у Вас права категории D", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] отобрал права категории D у %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 5:
        {
            if(PlayerInfo[to_player][pLicBiz] < 1) return SCM(playerid, red, "У игрока отсутсвует лицензия данной категории!");

            PlayerInfo[to_player][pLicBiz] = 0;
            format(string, sizeof(string), "Вы отобрали лицензию на бизнесс у %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "Администратор %s отобрал у Вас лицензию на бизнесс", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] отобрал лицензию на бизнесс у %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 6:
        {
            if(PlayerInfo[to_player][pLicFly] < 1) return SCM(playerid, red, "У игрока отсутсвует лицензия данной категории!");

            PlayerInfo[to_player][pLicFly] = 0;
            format(string, sizeof(string), "Вы отобрали лицензию на полёты у %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "Администратор %s отобрал у Вас лицензию на полёты", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] отобрал лицензию на полёты у %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
        case 7:
        {
            if(PlayerInfo[to_player][pLicGun] < 1) return SCM(playerid, red, "У игрока отсутсвует лицензия данной категории!");

            PlayerInfo[to_player][pLicGun] = 0;
            format(string, sizeof(string), "Вы отобрали лицензию на оружие у %s", PlayerInfo[to_player][pName]);
            SCM(playerid, blue, string);

            format(string, sizeof(string), "Администратор %s отобрал у Вас лицензию на оружие", PlayerInfo[playerid][pName]);
            SCM(to_player, blue, string);

            format(string, sizeof(string), "[A] %s[%d] отобрал лицензию на оружие у %s[%d]", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player);
            SCMA(grey, string);

            SaveAccounts(to_player);
        }
    }
    return 1;
}