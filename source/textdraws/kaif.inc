	// ## HUD

	hud_td_money_count[playerid] = CreatePlayerTextDraw(playerid, 594.333557, 55.340751, "999999999");
	PlayerTextDrawLetterSize(playerid, hud_td_money_count[playerid], 0.191666, 0.948740);
	PlayerTextDrawAlignment(playerid, hud_td_money_count[playerid], 1);
	PlayerTextDrawColor(playerid, hud_td_money_count[playerid], -1);
	PlayerTextDrawSetShadow(playerid, hud_td_money_count[playerid], 0);
	PlayerTextDrawSetOutline(playerid, hud_td_money_count[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, hud_td_money_count[playerid], 51);
	PlayerTextDrawFont(playerid, hud_td_money_count[playerid], 3);
	PlayerTextDrawSetProportional(playerid, hud_td_money_count[playerid], 1);

	hud_td_health_line[playerid] = CreatePlayerTextDraw(playerid, 594.333312, 70.933296, "kaif:hud_health_line");
	PlayerTextDrawLetterSize(playerid, hud_td_health_line[playerid], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, hud_td_health_line[playerid], 32.666664, 4.977778);
	PlayerTextDrawAlignment(playerid, hud_td_health_line[playerid], 1);
	PlayerTextDrawColor(playerid, hud_td_health_line[playerid], -1);
	PlayerTextDrawSetShadow(playerid, hud_td_health_line[playerid], 0);
	PlayerTextDrawSetOutline(playerid, hud_td_health_line[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, hud_td_health_line[playerid], 51);
	PlayerTextDrawFont(playerid, hud_td_health_line[playerid], 4);
	PlayerTextDrawSetProportional(playerid, hud_td_health_line[playerid], 1);

	hud_td_armor_line[playerid] = CreatePlayerTextDraw(playerid, 594.333374, 83.548126, "kaif:hud_armor_line");
	PlayerTextDrawLetterSize(playerid, hud_td_armor_line[playerid], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, hud_td_armor_line[playerid], 32.666664, 4.977778);
	PlayerTextDrawAlignment(playerid, hud_td_armor_line[playerid], 1);
	PlayerTextDrawColor(playerid, hud_td_armor_line[playerid], -1);
	PlayerTextDrawSetShadow(playerid, hud_td_armor_line[playerid], 0);
	PlayerTextDrawSetOutline(playerid, hud_td_armor_line[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, hud_td_armor_line[playerid], 51);
	PlayerTextDrawFont(playerid, hud_td_armor_line[playerid], 4);
	PlayerTextDrawSetProportional(playerid, hud_td_armor_line[playerid], 1);

    hud_td_background = TextDrawCreate(555.666564, -1.659277, "kaif:hud_background");
	TextDrawLetterSize(hud_td_background, 0.449999, 1.600000);
	TextDrawTextSize(hud_td_background, 79.666702, 93.333259);
	TextDrawAlignment(hud_td_background, 1);
	TextDrawColor(hud_td_background, -1);
	TextDrawSetShadow(hud_td_background, 0);
	TextDrawSetOutline(hud_td_background, 1);
	TextDrawBackgroundColor(hud_td_background, 51);
	TextDrawFont(hud_td_background, 4);
	TextDrawSetProportional(hud_td_background, 1);

	hud_td_online_count = TextDrawCreate(615.666809, 36.503707, "1000");
	TextDrawLetterSize(hud_td_online_count, 0.158999, 0.757926);
	TextDrawAlignment(hud_td_online_count, 1);
	TextDrawColor(hud_td_online_count, -1);
	TextDrawSetShadow(hud_td_online_count, 0);
	TextDrawSetOutline(hud_td_online_count, 0);
	TextDrawBackgroundColor(hud_td_online_count, 51);
	TextDrawFont(hud_td_online_count, 3);
	TextDrawSetProportional(hud_td_online_count, 1);