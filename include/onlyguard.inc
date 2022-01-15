stock AC_MODE_PutPlayerInVehicle(playerid,vehicleid,seatid)
{
	SetPVarInt(playerid,"cheat_info_veh",vehicleid);
	return PutPlayerInVehicle(playerid,vehicleid,seatid);
}
#define PutPlayerInVehicle AC_MODE_PutPlayerInVehicle

stock AC_MODE_SetVehiclePos(vehicleid,Float:x,Float:y,Float:z)
{
	return CallRemoteFunction("AC_SetVehiclePos","ifff",vehicleid,x,y,z);
}
#define SetVehiclePos AC_MODE_SetVehiclePos

stock AC_MODE_ResetPlayerWeapons(playerid)
{
	return CallRemoteFunction("AC_ResetPlayerWeapons","i",playerid);
}
#define ResetPlayerWeapons AC_MODE_ResetPlayerWeapons

forward OnPlayerCheat(playerid,code);



/*
Инструкция по установке Perfect Guard:

1.Если у вас замененная функция PutPlayerInVehicle добавьте следующее в замененную функцию:

SetPVarInt(playerid,"cheat_info_veh",vehicleid);

Если же у вас нету замененной функции и используется стандартная раскоментируйте начало include.

2.Добавьте в конец мода:

public OnPlayerCheat(playerid,code)
{
	if(PlayerInfo[playerid][pAdmin] >= 4) return 1; //замените уровень и переменную под свою дабы не кикало администраторов
	if(GetPVarInt(playerid,"mankicknut") == 1) return 1;//опять же чтоб не флудило киками
	new ipstr[16],string[200],nameplayer[24];//переменные
	GetPlayerIp(playerid, ipstr, 16);//Получение IP функцией,дабы вы не затруднялись
	GetPlayerName(playerid,nameplayer,24);//Получения ника функцией,дабы вы не затруднялись
	
	format(string, 144, "[PAC GUARD]:{5CACEE} %s[%d] был кикнут по подозрению в читерстве(#%d)",nameplayer,playerid,code);//уведомления для администраторов,уберите если не хотите делать под себя
	SendAdminMessage(COLOR_REDD, string); //уведомления для администраторов,уберите если не хотите делать под себя,цвет ставьте свой если у вас нету макросов
	
	format(string,144,"[PAC GUARD] Вы были кикнуты по подозрению в читерстве (#%d)",code);
	SendClientMessage(playerid,COLOR_LIME,string);//цвет ставьте свой если у вас нету макросов
	
	printf("[DEBUG AC] Сработал PAC GUARD: [NAME: %s | ID: %d | IP: %s | CODE: %d]",nameplayer,playerid,ipstr,code); //Заменяйте каждую переменную под свою
	SetPVarInt(playerid,"mankicknut",1);//Это чтоб не флудило киками
	SetTimerEx("PlayerKick",100,0,"i", playerid); //Ваш таймер или ваша функция на кик(например: KickEx(playerid))
	return 1;
}
3.В моде после include 'a_samp' добавьте #include perfectguard

4.В server.cfg добавьте: bind IPСЕРВЕРА

5.Желательно удаление всех ваших античитов из мода.

Perfect Guard is made Perfect Community in 2017
Powered by Feliks Macalister(vk.com/tperfectrpcom)
*/