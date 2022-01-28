CMD:getip(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);
	extract params -> new to_player; else return SCM(playerid, yellow, "[Подсказка] {FFFFFF}Используйте: /getip [ID игрока]");
	if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
	if(PlayerInfo[to_player][bAdmin] > PlayerInfo[playerid][bAdmin]) return SCM(playerid, red, "Вы не моежете посмотреть IP у Администратора!");
	new string[256];
	format(string, sizeof(string), "[Player - %s[%d]] [IP: %s] [Last IP: %s] [REG IP: %s]", PlayerInfo[to_player][pName], to_player, PlayerInfo[to_player][pNewIp], PlayerInfo[to_player][pLastIP], PlayerInfo[to_player][pRegIP]);
	SCM(playerid, blue, string);
	// GetPlayerGeoInfoGetIP(playerid, PlayerInfo[to_player][pNewIp]);
	return 1;
}

// stock GetPlayerGeoInfoGetIP(playerid, IP[])
// {
// 	new string[50];
// 	format(string, sizeof(string), "ip=%s", IP);
// 	HTTP(playerid,HTTP_POST,"other.pawno-rus.ru/geobase.php", string,"ResponseGeoInfoGetIP");
// 	return 1;
// }

// publics ResponseGeoInfoGetIP(playerid, response_code, data[])
// {
// 	new country[5], city[20], obl[40], district[80], str[sizeof(country)+sizeof(city)+sizeof(obl)+sizeof(district)+23+1]; // создаем переменные под страну, город, область, округ
// 	if(response_code != 200) return SendClientMessage(playerid, red, "Возникла ошибка, попробуйте позднее!"); // если ответ от веб-сервера не 200 (OK)
// 	if(!strcmp(data, "fail", true)) return SendClientMessage(playerid, red, "IP-адрес не европейский и не российский!");
// 	sscanf(data, "p<|>s[5]s[20]s[40]s[80]", country); // с помощью sscanf'a разделяем данные и записываем в раннее созданные переменные
// 	format(str, sizeof(str), "Страна: %s", country); // форматируем строку
// 	SCM(playerid, blue, str);
// 	format(str, sizeof(str), "Город: %s", city); // форматируем строку
// 	SCM(playerid, blue, str);
// 	format(str, sizeof(str), "Область: %s", obl); // форматируем строку
// 	SCM(playerid, blue, str);
// 	format(str, sizeof(str), "Округ: %s", district); // форматируем строку
// 	SCM(playerid, blue, str);
// 	return 1;
// }
