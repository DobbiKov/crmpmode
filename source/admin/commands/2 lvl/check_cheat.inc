CMD:check_cheat(playerid, params[])

{

	new str[800], string[800];

	if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid); //меняем на свою переменную

    extract params -> new to_player; else return SCM(playerid, blue, !"[Подсказка]: {FFFFFF}Используйте /check_cheat [ID игрока]");

    if(!IsPlayerConnected(to_player)) return SendClientMessage(playerid, red,"Неверный ID");

    new speed = SpeedVehicle(to_player);

    //

    new podoz = gettime();

    new result = podoz - time_podoz;

    if(result >= 10000000) result = 0;

    //

    new pick = gettime();

    new result1 = pick - time_pick;

    if(result1 >= 10000000) result1 = 0;

    //

    new spawn = gettime();

    new result2 = spawn - time_lspawn;

    if(result2 >= 10000000) result2 = 0;

    //

    new vhcar = gettime();

    new result3 = vhcar - time_vcar;

    if(result3 >= 10000000) result3 = 0;

    //

    new zohcar = gettime();

    new result4 = zohcar - time_zcar;

    if(result4 >= 10000000) result4 = 0;

    //

	format(str,sizeof(str),"{ffffff}Имя игрока: %s[%d]\n",PlayerInfo[to_player][pName],to_player); //меняем на свои переменные

	strcat(string,str);

	format(str,sizeof(str),"{ffffff}Подозревался: %d сек. назад\n", result);

	strcat(string,str);

	if(addchet[to_player] > 0)
	{

		if(GetPlayerState(to_player) != 2) strcat(string,"{ffffff}Причина подозрения: Пешком: слабый телепорт/летун/airbrake\n\n");

		else strcat(string,"{ffffff}Причина подозрения: Машина: speed-hack/слабый телепорт\n\n");

	}

	else strcat(string,"{ffffff}Причина подозрения: Игрок не подозревался\n\n");

	strcat(string,"{ffffff}Доказательства предоставлены античитом:\n");

	format(str,sizeof(str),"{ffffff}- За 1-ну секунду переместился на %d метров\n\n", speed);

	strcat(string,str);

	format(str,sizeof(str),"{ffffff}- Последний легальный телепорт(пикап/мп/админ): %d сек. назад\n", result1);

	strcat(string,str);

	format(str,sizeof(str),"{ffffff}- Последний раз залазил в машину: %d сек. назад\n", result4);

	strcat(string,str);

	format(str,sizeof(str),"{ffffff}- Последний выход из машины: %d сек. назад\n", result3);

	strcat(string,str);

	format(str,sizeof(str),"{ffffff}- Последний легальный спавн: %d сек. назад\n\n", result2);

	strcat(string,str);

	strcat(string,"{BE2D2D}Гайд. Следите за 2-ой строкой и строкой которая отображает последний лог действий.\n");

	strcat(string,"{BE2D2D}Она поможет Вам понять: {ffffff}'Правдлива ли информация античита'.\n\n\n\n");

	if(addchet[to_player]==1) strcat(string,"Приговор вторичного античита: {248daa}ЧИТЕР или ПОСТРАДАВШИЙ ОТ ЧИТЕРА [Нужно еще последить]\n");

	else if(addchet[to_player]==2) strcat(string,"Приговор вторичного античита: {248daa}ЧИТЕР [80 процентов]\n");

	else if(result>300) strcat(string,"Приговор вторичного античита: Скорее всего нет!\n");

	else strcat(string,"Приговор вторичного античита: {248daa}Игрок не подозревался\n");

    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, !"{"cblue"}Античит UN-AC", string, "Принять","");

	return true;

}