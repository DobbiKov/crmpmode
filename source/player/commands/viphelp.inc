CMD:viphelp(playerid)
{
    new string[2048] = "";

    new temp_string[144] = "{"cred"}У Вас нет VIP!\n\n";
    if(PlayerInfo[playerid][pVIP] <= 0)
        strcat(string, temp_string);

    format(temp_string, sizeof(temp_string), "{"cblue"}Возможности VIP игроков:\n\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- просмотр админов в сети (/admins)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- создание оружия (/makegun)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- продажа оружия (/sellgun)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- продажа наркотиков (/selldrugs)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- выключение телефона (/togphone)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- передача 50.000 руб. вместо 10.000 (/pay)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- возможность сменить цвет ника (/clist)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- возможность покинуть организацию самостоятельно (/leave)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- воровство патрон на складе ВДВ\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- увеличенная вместимость инвентаря\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- время предупреждения 3 дня, вместо 7 в случае получения(warn)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- возможность иметь три транспорта вместо двух\n");
    strcat(string, temp_string);
    return SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, !"{"cblue"}Возможности VIP игроков", string, !"Закрыть", !"");
}