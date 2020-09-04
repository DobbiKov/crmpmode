BuyClothes_TD[0] = TextDrawCreate(145.500000, 129.677780, "usebox");
TextDrawLetterSize(BuyClothes_TD[0], 0.000000, 11.967905);
TextDrawTextSize(BuyClothes_TD[0], 22.500000, 0.000000);
TextDrawAlignment(BuyClothes_TD[0], 1);
TextDrawColor(BuyClothes_TD[0], 0);
TextDrawUseBox(BuyClothes_TD[0], true);
TextDrawBoxColor(BuyClothes_TD[0], 41215);
TextDrawSetShadow(BuyClothes_TD[0], 0);
TextDrawSetOutline(BuyClothes_TD[0], 0);
TextDrawFont(BuyClothes_TD[0], 0);

BuyClothes_TD[1] = TextDrawCreate(42.000000, 130.044418, "Buy Clothes");
TextDrawLetterSize(BuyClothes_TD[1], 0.527000, 2.004445);
TextDrawTextSize(BuyClothes_TD[1], 12.000000, 21.777776);
TextDrawAlignment(BuyClothes_TD[1], 1);
TextDrawColor(BuyClothes_TD[1], -1);
TextDrawSetShadow(BuyClothes_TD[1], 0);
TextDrawSetOutline(BuyClothes_TD[1], 1);
TextDrawBackgroundColor(BuyClothes_TD[1], 51);
TextDrawFont(BuyClothes_TD[1], 0);
TextDrawSetProportional(BuyClothes_TD[1], 1);

BuyClothes_TD[2] = TextDrawCreate(33.000000, 167.377777, "Price");
TextDrawLetterSize(BuyClothes_TD[2], 0.449999, 1.600000);
TextDrawAlignment(BuyClothes_TD[2], 1);
TextDrawColor(BuyClothes_TD[2], -1);
TextDrawSetShadow(BuyClothes_TD[2], 0);
TextDrawSetOutline(BuyClothes_TD[2], 1);
TextDrawBackgroundColor(BuyClothes_TD[2], 51);
TextDrawFont(BuyClothes_TD[2], 1);
TextDrawSetProportional(BuyClothes_TD[2], 1);

BuyClothes_TD[3] = TextDrawCreate(144.500000, 206.833343, "usebox");
TextDrawLetterSize(BuyClothes_TD[3], 0.000000, -0.247531);
TextDrawTextSize(BuyClothes_TD[3], 22.000000, 0.000000);
TextDrawAlignment(BuyClothes_TD[3], 1);
TextDrawColor(BuyClothes_TD[3], 0);
TextDrawUseBox(BuyClothes_TD[3], true);
TextDrawBoxColor(BuyClothes_TD[3], -1);
TextDrawSetShadow(BuyClothes_TD[3], 0);
TextDrawSetOutline(BuyClothes_TD[3], 0);
TextDrawFont(BuyClothes_TD[3], 0);

BuyClothes_TD[4] = TextDrawCreate(30.000000, 212.800048, "Next");
TextDrawLetterSize(BuyClothes_TD[4], 0.287500, 1.967111);
TextDrawTextSize(BuyClothes_TD[4], 60.500000, 53.511127);
TextDrawAlignment(BuyClothes_TD[4], 1);
TextDrawColor(BuyClothes_TD[4], -1);
TextDrawUseBox(BuyClothes_TD[4], true);
TextDrawBoxColor(BuyClothes_TD[4], 41215);
TextDrawSetShadow(BuyClothes_TD[4], 0);
TextDrawSetOutline(BuyClothes_TD[4], 1);
TextDrawBackgroundColor(BuyClothes_TD[4], 51);
TextDrawFont(BuyClothes_TD[4], 2);
TextDrawSetProportional(BuyClothes_TD[4], 1);
TextDrawSetSelectable(BuyClothes_TD[4], true);

BuyClothes_TD[5] = TextDrawCreate(101.000000, 213.422241, "BACK");
TextDrawLetterSize(BuyClothes_TD[5], 0.348500, 2.048000);
TextDrawTextSize(BuyClothes_TD[5], 137.000000, 4.977777);
TextDrawAlignment(BuyClothes_TD[5], 1);
TextDrawColor(BuyClothes_TD[5], -1);
TextDrawUseBox(BuyClothes_TD[5], true);
TextDrawBoxColor(BuyClothes_TD[5], 41215);
TextDrawSetShadow(BuyClothes_TD[5], 0);
TextDrawSetOutline(BuyClothes_TD[5], 1);
TextDrawBackgroundColor(BuyClothes_TD[5], 51);
TextDrawFont(BuyClothes_TD[5], 2);
TextDrawSetProportional(BuyClothes_TD[5], 1);
TextDrawSetSelectable(BuyClothes_TD[5], true);

BuyClothes_TD[6] = TextDrawCreate(66.500000, 212.177795, "Buy");
TextDrawLetterSize(BuyClothes_TD[6], 0.376499, 2.222223);
TextDrawTextSize(BuyClothes_TD[6], 95.500000, 9.955555);
TextDrawAlignment(BuyClothes_TD[6], 1);
TextDrawColor(BuyClothes_TD[6], -1);
TextDrawUseBox(BuyClothes_TD[6], true);
TextDrawBoxColor(BuyClothes_TD[6], 41215);
TextDrawSetShadow(BuyClothes_TD[6], 0);
TextDrawSetOutline(BuyClothes_TD[6], 1);
TextDrawBackgroundColor(BuyClothes_TD[6], 51);
TextDrawFont(BuyClothes_TD[6], 2);
TextDrawSetProportional(BuyClothes_TD[6], 1);
TextDrawSetSelectable(BuyClothes_TD[6], true);


//Player Textdraws:
BuyClothes_PTD[0][playerid] = CreatePlayerTextDraw(playerid, 33.500000, 184.800018, "1000000 rub");
PlayerTextDrawLetterSize(playerid, BuyClothes_PTD[0][playerid], 0.449999, 1.600000);
PlayerTextDrawAlignment(playerid, BuyClothes_PTD[0][playerid], 1);
PlayerTextDrawColor(playerid, BuyClothes_PTD[0][playerid], -1);
PlayerTextDrawSetShadow(playerid, BuyClothes_PTD[0][playerid], 0);
PlayerTextDrawSetOutline(playerid, BuyClothes_PTD[0][playerid], 1);
PlayerTextDrawBackgroundColor(playerid, BuyClothes_PTD[0][playerid], 51);
PlayerTextDrawFont(playerid, BuyClothes_PTD[0][playerid], 1);
PlayerTextDrawSetProportional(playerid, BuyClothes_PTD[0][playerid], 1);