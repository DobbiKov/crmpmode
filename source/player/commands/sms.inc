CMD:sms(playerid, params[])
{
    if(GetPVarInt(playerid, "tied") == 1 || GetPVarInt(playerid, "cuffed") == 1)
        return SCM(playerid, red, !"В данный момент Вы связаны!");
    extract params -> new number, string: text[128]; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /sms [номер абонента] [текст]");
    if(PlayerInfo[playerid][pPhone] < 1 || PlayerInfo[playerid][pPhoneNumber] < 1) return SCM(playerid, red, "У Вас нет телефона.");
    if(PlayerInfo[playerid][pPhoneNumber] < 1) return SCM(playerid, red, "У Вас нет телефона, или сим-карты.");
    if(PlayerInfo[playerid][pPhoneCash] < 5) return SCM(playerid, red, "На балансе телефона недостаточно средств.");
    if(PlayerInfo[playerid][pPhoneStatus] == 1) return SCM(playerid, red, "Ваш телефон выключен.");
    if(number == PlayerInfo[playerid][pPhoneNumber]) return SCM(playerid, red, "Вы ввели свой номер телефона.");

    foreach(new i : Player)
    {
        if(IsPlayerConnected(i) && PlayerInfo[i][pLogin] != false)
        {
            if(number == PlayerInfo[i][pPhoneNumber] && PlayerInfo[i][pPhone] >= 1 && PlayerInfo[i][pPhoneNumber] > 0)
            {
                PlayerInfo[playerid][pPhoneCash] -= 5;
                
                new string[144];
                format(string, sizeof(string), "SMS: %s | Отправитель: %s[т. %d]", text, PlayerInfo[playerid][pName], PlayerInfo[playerid][pPhoneNumber]);
                SCM(i, yellow, string);

                format(string, sizeof(string), "SMS: %s | Получатель: %s[т. %d]", text, PlayerInfo[i][pName], PlayerInfo[i][pPhoneNumber]);
                SCM(playerid, yellow, string);

                format(string, sizeof(string), "[SMS]: %s | От %s[%d] для %s[%d]", text, PlayerInfo[playerid][pName], playerid, PlayerInfo[i][pName], i);
                foreach(new j : Player)
                {
                    if(PlayerInfo[j][pReadsms] == 1)
                    {
                        SCM(j, green, string);
                    }
                }
                return 1;
            }
        }
    }
    return SCM(playerid, red, "Телефон вне зоны действия.");
}