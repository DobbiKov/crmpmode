CMD:offget(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);

    extract params -> new string: to_player[24]; else return SCM(playerid, blue, "[Подсказка] {FFFFFF}Используйте: /offget [NICK игрока]");

    for(new i = 0; i < sizeof(SuperNick_S); i++) if(!strcmp(to_player, SuperNick_S[i], true)) return SCM(playerid, red, "Вы не можете посмотреть статистику данного игрока!");

    foreach(new i : Player)
    {
        if(!strcmp(PlayerInfo[i][pName], to_player))
        {
            return SCM(playerid, red, "Игрок на сервере! {FFFFFF}Используйте /stat [ID игрока]");
        }
    }

    new string[128];
    format(string, sizeof(string), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    mysql_tquery(connects, string, "OffGet", "ds", playerid, to_player);
    return 1;
}

publics OffGet(playerid, to_player[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
    {
        new ip[16], regip[16];

        
        new lvl = cache_get_field_content_int(0, "pLVL");
        new exp = cache_get_field_content_int(0, "pExp");
        new cash = cache_get_field_content_int(0, "pCash");
        new bmoney = cache_get_field_content_int(0, "pBCash");
        new phonecash = cache_get_field_content_int(0, "pPhoneCash");
        new phonenumber = cache_get_field_content_int(0, "pPhoneNumber");
        new wanted = cache_get_field_content_int(0, "pWANTED");
        new drugs = cache_get_field_content_int(0, "pDrugs");
        new patr = cache_get_field_content_int(0, "pPatr");
        new metall = cache_get_field_content_int(0, "pMetall");
        new lomka = cache_get_field_content_int(0, "pLomka");
        new sex = cache_get_field_content_int(0, "pSex");

        new homeid = cache_get_field_content_int(0, "pHomeID");
        new podid = cache_get_field_content_int(0, "pPodID");
        new kvartid = cache_get_field_content_int(0, "pKvartID");
        

        new member = cache_get_field_content_int(0, "pMember");
        new job = cache_get_field_content_int(0, "pJob");
        new rang = cache_get_field_content_int(0, "pRang");
        new voen = cache_get_field_content_int(0, "pVoen");
        cache_get_field_content(0, "pLastIP", ip, connects, 144);
        cache_get_field_content(0, "pRegIP", regip, connects, 144);

        /**/
        stringer[0] = EOS;
        new string_last[256];
        format(string_last, sizeof(string_last), "{FFFFFF}Имя: \t\t\t\t{"cblue"}%s{FFFFFF}\n", to_player);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Уровень: \t\t\t%d\n", lvl);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Очки опыта: \t\t\t%d/%d\n", exp,(lvl)*4);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Деньги: \t\t\t%d\n", cash);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Деньги в банке: \t\t%d\n", bmoney);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Мобильный счет: \t\t%d\n", phonecash);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Номер телефона: \t\t%d\n", phonenumber);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Уровень розыска: \t\t%d\n", wanted);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Наркотики: \t\t\t%d\n", drugs);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Патроны: \t\t\t%d\n", patr);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Металл: \t\t\t%d\n", metall);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Наркозависимость: \t\t%d\n", lomka);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Пол: \t\t\t\t%s\n", (sex) ? ("Мужской") : ("Женский"));
        strcat(stringer,string_last);
        
        new live[144] = "";
        if(homeid > -1)
            format(live, sizeof(live), "Дом №%d", homeid);
        else if(kvartid > -1)
            format(live, sizeof(live), "Подъезд №%d, квартира №%d", podid, kvartid);
        else
            format(live, sizeof(live), "%s", "Бездомный");

        
        format(string_last, sizeof(string_last), "Проживание: \t\t\t%s\n\n", live);
        strcat(stringer,string_last);
        
        format(string_last, sizeof(string_last), "Организация: \t\t\t%s\n", GetMember[member]);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Работа / должность: \t\t%s\n", (job >= 1) ? (jobs_name[job]) : (PlayerRank[ member ][ rang ]));
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Ранг: \t\t\t\t%d\n", rang);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Военный билет: \t\t%s\n\n", voen == 1 ? ("Есть") : ("Нет"));
        strcat(stringer,string_last);

        format(string_last, sizeof(string_last), "Last IP: \t\t\t%s\n", ip);
        strcat(stringer,string_last);
        format(string_last, sizeof(string_last), "Reg IP: \t\t\t\t%s\n", regip);
        strcat(stringer,string_last);
        /**/ 

        SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}Статистика игрока OffLine", stringer, "Закрыть", "");
    }
    else
    {
        SCM(playerid, red, "Такого игрока нет!");
    }
}

