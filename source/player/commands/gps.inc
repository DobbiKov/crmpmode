enum gps_struct { //структура массивам 
    gps_name[128],
    Float: gps_x,
    Float: gps_y,
    Float: gps_z
}
new gps_publicplaces[6][gps_struct] = { //заполняем массивы данными, главное, что б они соотвествовали enum'у
    {"Администрация поселка", 1826.0516,2095.8135,15.8505},    // Мэрия
    {"Автошкола", 1902.7854,2227.7236,15.7135},    // Автошкола
    {"Военкомат", 1894.5282,2298.3740,15.8627},    // Военкомат
    {"Автосалон", 2010.9583,1894.1467,15.6600},    // Автосалон
    {"Ж/Д Вокзал г. Южный", 2522.8638,-2129.4233,21.9700},    // Ж/Д Вокзал г. Южный
    {"Банк", 1849.6559,2045.5410,15.8850}        // Банк
};
new gps_jobs[4][gps_struct] = { //заполняем массивы данными
    {"Грузчик", 2353.1272,-263.8854,2.7890},    // Грузчик
    {"Шахтер", 2345.2053,2006.3165,15.9900},    // Шахтёр
    {"Водолаз", 2817.3772,-1369.1652,2.9151},     // Водолаз
    {"Уборщик улиц", 1826.7554,2250.5266,15.2729}
};
new gps_entertainment[2][gps_struct] = { //заполняем массивы данными
    {"Казино", 2333.1096,1757.6904,1.0400},    // Казино
    {"Пейнтбол", 2219.9290,1367.8815,11.5600}
};
new gps_stateorganizations[5][gps_struct] = { //заполняем массивы данными
    {"Администрация области", 1826.0516,2095.8135,15.8505},    // Администрация области
    {"Больница", 1978.3701,1602.6826,15.7700},    // Больница
    {"ППС", 1908.7045,2183.2463,15.7060},    // ППС
    {"ВДВ", 1900.4652,1722.9036,15.9379},     // ВДВ
    {"СМИ", 1794.6233,2047.6736,15.8741}     // СМИ
}; 
new gps_gangs[2][gps_struct] = { //заполняем массивы данными
    {"ОПГ Ореховские", 2620.9275,1787.5305,2.5600},    // Орех
    {"ОПГ Солнцевские", 1714.9672,1337.8615,12.88001}     // Солнц
};



CMD:gps(playerid) { //команда, в игре будет так: /gps
    if(GetPVarInt(playerid, "loader_job") == 1 || GetPVarInt(playerid, "diver_job") == 1 || GetPVarInt(playerid, "miner_job") == 1) return SCM(playerid, red, !"Вы не можете использовать навигатор, пока работаете на подработках.");
    ShowGpsDialog(playerid);
    return 1;
}
stock ShowGpsDialog(playerid) {
    ShowPlayerDialog(playerid, D_GPS, DIALOG_STYLE_LIST, "{"cblue"}Навигатор", "\
    {"cblue"}1. {FFFFFF}Общественные места\n\
    {"cblue"}2. {FFFFFF}Подработки\n\
    {"cblue"}3. {FFFFFF}Развлечения\n\
    {"cblue"}4. {FFFFFF}Организации\n\
    {"cblue"}5. {FFFFFF}Нелегальные организации\n\
    {"cblue"}6. {FFFFFF}Бизнесы", "Далее", "Отмена"); // функция, которая выводит игроку диалог. 
    //1-ый параметр(playerid) - id игрока, которому нужно вывести диалог
    //2-ой (D_GPS) - идентификатор диалога, id грубо говоря
    //3-ий (DIALOG_STYLE_LIST) - Тип диалога
    //4-ый - заголовок диалога
    //5-ый - содержание диалога
    //6-ой - первая кнопка
    //7-ой - вторая кнопка
}
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) //функция, которая вызывается автоматически, когда человек использовал диалог
{
    switch(dialogid)//перебираем диалоги, можно вместо него использовать if'ы
    {
        case D_GPS_PUBLICPLACES: { //по идентификатору
            if (!response) ShowGpsDialog(playerid); //если игрок нажал вторую кнопку if(!response) - то выводим старый диалог
            else { //если первую, то ставим метку
                SetPlayerCheckpoint(playerid, gps_publicplaces[listitem][gps_x], gps_publicplaces[listitem][gps_y], gps_publicplaces[listitem][gps_z], 3.0); //функция которая ставит метку в определенном месте определенного размера
                SCM(playerid, blue, "Место отмечено красным маркером у Вас на миникарте"); //функция которая выводит сообщение в чат
                pCheckpoint[playerid] = CP_GPS;
            }
        }
        case D_GPS_JOBS: {
            if (!response) ShowGpsDialog(playerid);
            else {
                SetPlayerCheckpoint(playerid, gps_jobs[listitem][gps_x], gps_jobs[listitem][gps_y], gps_jobs[listitem][gps_z], 3.0);
                SCM(playerid, blue, "Место отмечено красным маркером у Вас на миникарте");
                pCheckpoint[playerid] = CP_GPS;
            }
        }
        case D_GPS_ENTERTAINMENTS: {
            if (!response) ShowGpsDialog(playerid);
            else {
                SetPlayerCheckpoint(playerid, gps_entertainment[listitem][gps_x], gps_entertainment[listitem][gps_y], gps_entertainment[listitem][gps_z], 3.0);
                SCM(playerid, blue, "Место отмечено красным маркером у Вас на миникарте");
                pCheckpoint[playerid] = CP_GPS;
            }
        }
        case D_GPS_STATEORGANIZATIONS: {
            if (!response) ShowGpsDialog(playerid);
            else {
                SetPlayerCheckpoint(playerid, gps_stateorganizations[listitem][gps_x], gps_stateorganizations[listitem][gps_y], gps_stateorganizations[listitem][gps_z], 3.0);
                SCM(playerid, blue, "Место отмечено красным маркером у Вас на миникарте");
                pCheckpoint[playerid] = CP_GPS;
            }
        }
        case D_GPS_GANGS: {
            if (!response) ShowGpsDialog(playerid);
            else {
                SetPlayerCheckpoint(playerid, gps_gangs[listitem][gps_x], gps_gangs[listitem][gps_y], gps_gangs[listitem][gps_z], 3.0);
                SCM(playerid, blue, "Место отмечено красным маркером у Вас на миникарте");
                pCheckpoint[playerid] = CP_GPS;
            }
        }
        case D_GPS_BUSINESS: {
            if (!response) ShowGpsDialog(playerid);
            else {
                SetPlayerCheckpoint(playerid, BusinessInfo[listitem][bExitX], BusinessInfo[listitem][bExitY], BusinessInfo[listitem][bExitZ], 3.0);
                SCM(playerid, blue, "Место отмечено красным маркером у Вас на миникарте");
                pCheckpoint[playerid] = CP_GPS;
            }
        }
        case D_GPS: {
            if (response) { // если нажал первую кнопку
                switch(listitem) {//перебираем, на какую строку нажал игрок
                    case 0: {
                        new str[1024] = ""; //объявляем переменную
                        new string[128]; //объявляем переменную
                        for (new i = 0; i < 6; i++) { //перебираем, по размерности массива
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, gps_publicplaces[i][gps_name]); //устонваливаем значение переменной string
                            strcat(str, string); //ставим в конец cтроки переменной str строку переменной string
                        }
                        ShowPlayerDialog(playerid, D_GPS_PUBLICPLACES, DIALOG_STYLE_LIST, "{"cblue"}Навигатор", str, "Далее", "Назад");
                    }
                    case 1: {
                        new str[1024] = "";
                        new string[128];
                        for (new i = 0; i < 4; i++) {
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, gps_jobs[i][gps_name]);
                            strcat(str, string);
                        }
                        ShowPlayerDialog(playerid, D_GPS_JOBS, DIALOG_STYLE_LIST, "{"cblue"}Навигатор", str, "Далее", "Назад");
                    }
                    case 2: {
                        new str[1024] = "";
                        new string[128];
                        for (new i = 0; i < 2; i++) {
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, gps_entertainment[i][gps_name]);
                            strcat(str, string);
                        }
                        ShowPlayerDialog(playerid, D_GPS_ENTERTAINMENTS, DIALOG_STYLE_LIST, "{"cblue"}Навигатор", str, "Далее", "Назад");
                    }
                    case 3: {
                        new str[1024] = "";
                        new string[128];
                        for (new i = 0; i < 5; i++) {
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, gps_stateorganizations[i][gps_name]);
                            strcat(str, string);
                        }
                        ShowPlayerDialog(playerid, D_GPS_STATEORGANIZATIONS, DIALOG_STYLE_LIST, "{"cblue"}Навигатор", str, "Далее", "Назад");
                    }
                    case 4: {
                        new str[1024] = "";
                        new string[128];
                        for (new i = 0; i < 2; i++) {
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, gps_gangs[i][gps_name]);
                            strcat(str, string);
                        }
                        ShowPlayerDialog(playerid, D_GPS_GANGS, DIALOG_STYLE_LIST, "{"cblue"}Навигатор", str, "Далее", "Назад");
                    }
                    case 5:{
                        new str[2048];
                        new string[128];
                        foreach(new i : Allbusiness)
                        {
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, business_params[ BusinessInfo[i][bType] ][bname]);
                            strcat(str, string);
                        }
                        SPD(playerid, D_GPS_BUSINESS, DIALOG_STYLE_LIST, !"{"cblue"}Навигатор", str, !"Далее", !"Назад");
                    }
                }
            }
        }
    }
    #if    defined    gps__OnDialogResponse
        return gps__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
    #else
        return 1;
    #endif
}
#if    defined    _ALS_OnDialogResponse
    #undef    OnDialogResponse
#else
    #define    _ALS_OnDialogResponse
#endif

#define    OnDialogResponse gps__OnDialogResponse
#if    defined    gps__OnDialogResponse
    forward gps__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif



public OnPlayerEnterCheckpoint(playerid) //функция которая автоматически вызывается, когда игрок становится на checkpoint
{
    switch(pCheckpoint[playerid])
    {
        case CP_GPS: 
        {
            DisablePlayerCheckpoint(playerid); //убираем чекпоинт
            SCM(playerid, blue, "Вы прибыли на место назначения"); //сообщение в чат
        }
    }
    #if defined gps__OnPlayerEnterCheckpoint
        return gps__OnPlayerEnterCheckpoint(playerid);
    #else
        return 1;
    #endif
}
#if    defined    _ALS_OnPlayerEnterCheckpoint
    #undef    OnPlayerEnterCheckpoint
#else
    #define    _ALS_OnPlayerEnterCheckpoint
#endif

#define    OnPlayerEnterCheckpoint gps__OnPlayerEnterCheckpoint
#if    defined    gps__OnPlayerEnterCheckpoint
    forward gps__OnPlayerEnterCheckpoint(playerid);
#endif