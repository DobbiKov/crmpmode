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

stock AC_MODE_RemovePlayerFromVehicle(playerid)
{
	return CallRemoteFunction("AC_RemovePlayerFromVehicle","i",playerid);
}
#define RemovePlayerFromVehicle AC_MODE_RemovePlayerFromVehicle

stock AC_MODE_SpawnPlayer(playerid)
{
	return CallRemoteFunction("AC_SpawnPlayer","i",playerid);
}
#define SpawnPlayer(%0) AC_MODE_SpawnPlayer(%0)

stock AC_MODE_TogglePlayerSpectating(playerid,toggle)
{
	return CallRemoteFunction("AC_TogglePlayerSpectating","ii",playerid,toggle);
}
#define TogglePlayerSpectating AC_MODE_TogglePlayerSpectating

stock AC_MODE_GivePlayerWeapon(playerid,weaponid,rammo)
{
	return CallRemoteFunction("AC_GivePlayerWeapon","iii",playerid,weaponid,rammo);
}
#define GivePlayerWeapon AC_MODE_GivePlayerWeapon

stock AC_MODE_SetPlayerPos(playerid,Float:x,Float:y,Float:z)
{
	return CallRemoteFunction("AC_SetPlayerPos","dfff",playerid,x,y,z);
}
#define SetPlayerPos AC_MODE_SetPlayerPos

stock AC_MODE_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
	return CallRemoteFunction("AC_PutPlayerInVehicle","ddd",playerid, vehicleid, seatid);
}
#define PutPlayerInVehicle AC_MODE_PutPlayerInVehicle

forward OnPlayerCheat(playerid,parametr,code);



/*
Инструкция по установке Perfect Guard:

1.Если у вас замененная функция PutPlayerInVehicle добавьте следующее в замененную функцию:

SetPVarInt(playerid,"cheat_info_veh",vehicleid); и удалите первый stock инклуда

Так - же добавьте пвар SetPVarInt(playerid,"AFK_PLAYER",1) если игрок АФКшит, и DeletePvar(playerid,"AFK_PLAYER") когда выходит из афк.
Так - же если игрок администратор выставляет значение SetPVarInt(playerid,"ADMIN_PLAYER",1)

2.Добавьте в конец мода:

public OnPlayerCheat(playerid,parametr,code)
{
	new string[200];
	if(GetPVarInt(playerid,"USE_CRASHER") > 0)
	{
		if(GetPVarInt(playerid,"mankicknut") == 1) return 1;
		
		ResetPlayerWeaponsAC(playerid);
		
		format(string,144,"[PGUARD-CRASH] Вы были кикнуты по подозрению в краш-атаке (#%d)",code);
		SendClientMessage(playerid,COLOR_LIME,string);
		
		SetPVarInt(playerid,"mankicknut",1);
		SetTimerEx("DisconnectPlayer",100,0,"i", playerid);
		return 1;
	}
	
	if(parametr == 1)
	{
		if(GetPVarInt(playerid,"mankicknut") == 1) return 1;
		
		ResetPlayerWeaponsAC(playerid);
		
		format(string,144,"[PGUARD-CHEAT] Вы были кикнуты по подозрению в читерстве (#%d)",code);
		SendClientMessage(playerid,COLOR_LIME,string);
		
		SetPVarInt(playerid,"mankicknut",1);
		if(code == 777) SetTimerEx("DisconnectPlayer",100,0,"i", playerid);
		else SetTimerEx("DisconnectPlayer",500,0,"i", playerid);
	}
	if(parametr == 2)
	{
		switch(code)
		{
		case 5556: { format(string, 144, "[WARNING PGUARD]:{5CACEE} %s[%d] подозревается в читерстве(#GunCheat)",PI[playerid][pName],playerid); }
		case 7991: format(string, 144, "[WARNING PGUARD]:{5CACEE} %s[%d] подозревается в читерстве(#AntiPosition-1)",PI[playerid][pName],playerid);
		case 7992: format(string, 144, "[WARNING PGUARD]:{5CACEE} %s[%d] подозревается в читерстве(#AntiPosition-2)",PI[playerid][pName],playerid);
		case 8880: format(string, 144, "[WARNING PGUARD]:{5CACEE} %s[%d] подозревается в читерстве(#CarShotS-DRIVER)",PI[playerid][pName],playerid);
		case 8881: format(string, 144, "[WARNING PGUARD]:{5CACEE} %s[%d] подозревается в читерстве(#CarShotS-PASSENGER)",PI[playerid][pName],playerid);
		default: format(string, 144, "[WARNING PGUARD]:{5CACEE} %s[%d] подозревается в читерстве(#%d)",PI[playerid][pName],playerid,code);
		}
		SendAdminMessage(COLOR_REDD, string);
	}
	return 1;
}
3.В моде после include 'a_samp' добавьте #include perfectguard

4.В server.cfg добавьте: bind IPСЕРВЕРА

5.Желательно удаление всех ваших античитов из мода.

Perfect Guard is made Perfect Community in 2017
Powered by Feliks Macalister(vk.com/tperfectrpcom)
*/