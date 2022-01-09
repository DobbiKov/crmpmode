CMD:help(playerid)
{
    // return SPD(playerid, D_NULL, DIALOG_STYLE_LIST, "{"cblue"}/help - напоните", "{FFFFFF}Напомнить скриптеру сделать команду /help", "Напомню", "Не, нахуй надо");
    return SPD(playerid, 11, DIALOG_STYLE_LIST, "{"cblue"}Команды сервера", "{"cblue"}1. {FFFFFF}Команды организаций\n{"cblue"}2. {FFFFFF}Команды работ\n{"cblue"}3. {FFFFFF}Команды недвижимости\n{"cblue"}4. {FFFFFF}Команды общения\n{"cblue"}5. {FFFFFF}Команды остальные", "Далее", "Отмена");
}