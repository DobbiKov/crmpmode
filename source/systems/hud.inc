new Text: hud_td_background,
	Text: hud_td_online_count,
	PlayerText: hud_td_money_count[MAX_PLAYERS],
	PlayerText: hud_td_health_line[MAX_PLAYERS],
	PlayerText: hud_td_armor_line[MAX_PLAYERS];

new g_players_count = 0;

stock ShowPlayerHudInterface(playerid)
{
	TextDrawShowForPlayer(playerid, hud_td_background);
	TextDrawShowForPlayer(playerid, hud_td_online_count);

	PlayerTextDrawShow(playerid, hud_td_money_count[playerid]);
	PlayerTextDrawShow(playerid, hud_td_health_line[playerid]);
	PlayerTextDrawShow(playerid, hud_td_armor_line[playerid]);
}

stock HidePlayerHudInterface(playerid)
{
	TextDrawHideForPlayer(playerid, hud_td_background);
	TextDrawHideForPlayer(playerid, hud_td_online_count);

	PlayerTextDrawHide(playerid, hud_td_money_count[playerid]);
	PlayerTextDrawHide(playerid, hud_td_health_line[playerid]);
	PlayerTextDrawHide(playerid, hud_td_armor_line[playerid]);
}

stock UpdatePlayerMoneyInHud(playerid)
{

	new string[144];
	format(string, sizeof string, "%d", PlayerInfo[playerid][pCash]);
	PlayerTextDrawSetString(playerid, hud_td_money_count[playerid], string);

	PlayerTextDrawShow(playerid, hud_td_money_count[playerid]);

	return 1;
}

stock UpdatePlayerHealthInHud(playerid)
{

	new Float: health;
	GetPlayerHealth(playerid, health);

	new Float: count = health / 100.0 * 32.666664;

	PlayerTextDrawTextSize(playerid, hud_td_health_line[playerid], count, 4.977778);
	PlayerTextDrawShow(playerid, hud_td_health_line[playerid]);

	return 1;
}

stock UpdatePlayerArmourInHud(playerid)
{

	new Float: armour;
	GetPlayerArmour(playerid, armour);

	new Float: count = armour / 100.0 * 32.666664;

	PlayerTextDrawTextSize(playerid, hud_td_armor_line[playerid], count, 4.977778);
	PlayerTextDrawShow(playerid, hud_td_armor_line[playerid]);

	return 1;
}

stock AddPlayerInHudCount()
{
	g_players_count ++;

	new string[144];

	format(string, sizeof string, "%d", g_players_count);
	TextDrawSetString(hud_td_online_count, string);
}

stock RemovePlayerInHudCount()
{
	g_players_count --;

	new string[144];

	format(string, sizeof string, "%d", g_players_count);
	TextDrawSetString(hud_td_online_count, string);
}

public OnPlayerUpdate(playerid)
{
    if(PlayerInfo[playerid][pLogin] == true) 
	{
		UpdatePlayerHealthInHud(playerid);
		UpdatePlayerArmourInHud(playerid);
	}
	#if defined hud_OnPlayerUpdate
		return hud_OnPlayerUpdate(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate hud_OnPlayerUpdate
#if defined hud_OnPlayerUpdate
	forward hud_OnPlayerUpdate(playerid);
#endif