new ClothesShopState[MAX_PLAYERS];
enum ClothesParametersEnum{
    clothesId,
    clothesSkinId,
    clothesPrice
}
const MaxClothesShopSkins = 10;
new ClothesParameters[MaxClothesShopSkins][ClothesParametersEnum] = {
    {0, 1, 1000},
    {1, 14, 1000},
    {2, 15, 2000},
    {3, 16, 2000},
    {4, 17, 2000},
    {5, 18, 2000},
    {6, 19, 2000},
    {7, 20, 2000},
    {8, 21, 2000},
    {9, 22, 2000}
};

new bool: IsBuyClothes[MAX_PLAYERS];

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1945.6965, 2069.1343, 16.1989)){
            SetPlayerPos(playerid, 576.9778, 2121.6274, 1551.4600);
            FreezePlayer(playerid, 2000);
        }
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 576.9778, 2121.6274, 1551.4600)){
            SetPlayerPos(playerid, 1945.6965, 2069.1343, 16.1989);
            FreezePlayer(playerid, 2000);
        }
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 571.0848, 2121.6147, 1551.4600)){
            ShowPlayerDialog
            (
                playerid, D_BUY_CLOTHES, DIALOG_STYLE_MSGBOX,
                !"{"cblue"}Покупка одежды",
                !"Вы желаете посмотреть одежду?",
                !"Да", !"Нет"
            );
        }
    }
	#if	defined	odezhda__OnPlayerKeyStateChange
		return odezhda__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange odezhda__OnPlayerKeyStateChange
#if	defined	odezhda__OnPlayerKeyStateChange
	forward odezhda__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_BUY_CLOTHES:
        {
            if(!response) return true; else{
                SetBuyClothes(playerid);
            }
        }
    }
	#if	defined	odezhda__OnDialogResponse
		return odezhda__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse odezhda__OnDialogResponse
#if	defined	odezhda__OnDialogResponse
	forward odezhda__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == Text:INVALID_TEXT_DRAW) // отмена
    {
        if(IsBuyClothes[playerid] == true){
            ExitBuyClothes(playerid);
        }
    }
    if(clickedid == BuyClothes_TD[4]) //next
    {
        ClothesShopState[playerid]++;
        if(ClothesShopState[playerid] >= MaxClothesShopSkins) ClothesShopState[playerid] = 1;
        new string[144];
        format(string, sizeof(string), "%d rub", ClothesParameters[ClothesShopState[playerid]][clothesPrice]);
        PlayerTextDrawSetString(playerid, BuyClothes_PTD[0][playerid], string);
        SetPlayerSkin(playerid, ClothesParameters[ClothesShopState[playerid]][clothesSkinId]);  
    }
    if(clickedid == BuyClothes_TD[5]) //back
    {
        ClothesShopState[playerid]--;
        if(ClothesShopState[playerid] < 1) ClothesShopState[playerid] = MaxClothesShopSkins-1;
        new string[144];
        format(string, sizeof(string), "%d rub", ClothesParameters[ClothesShopState[playerid]][clothesPrice]);
        PlayerTextDrawSetString(playerid, BuyClothes_PTD[0][playerid], string);
        SetPlayerSkin(playerid, ClothesParameters[ClothesShopState[playerid]][clothesSkinId]);  
    }
    if(clickedid == BuyClothes_TD[6]) //buy
    { 
        if(PlayerInfo[playerid][pCash] < ClothesParameters[ClothesShopState[playerid]][clothesPrice]) return SCM(playerid, red, !"У вас недостаточно средств.");
        PlayerInfo[playerid][pChar] = ClothesParameters[ClothesShopState[playerid]][clothesSkinId];

        new string[144];
        format(string, sizeof(string), "Вы успешно приобрели скин за %d рублей.", ClothesParameters[ClothesShopState[playerid]][clothesPrice]);
        SCM(playerid, blue, string);
        if(PlayerInfo[playerid][pMember] > 0) SCM(playerid, blue, !"Примечание! Так как вы состоите в организации, у вас будет франкциооный скин.");
        ExitBuyClothes(playerid);
        SaveAccounts(playerid);
    }
    #if defined odezhda__OnPlayerClickTextDraw
        return odezhda__OnPlayerClickTextDraw(playerid, Text:clickedid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerClickTextDraw
    #undef OnPlayerClickTextDraw
#else
    #define _ALS_OnPlayerClickTextDraw
#endif

#define OnPlayerClickTextDraw odezhda__OnPlayerClickTextDraw
#if defined odezhda__OnPlayerClickTextDraw
    forward odezhda__OnPlayerClickTextDraw(playerid, Text:clickedid);
#endif

stock SetBuyClothes(playerid){
    IsBuyClothes[playerid] = true;
    ClothesShopState[playerid] = 1;

    SetPlayerPos(playerid, 560.5141, 2136.6279, 1551.4860);
    SetPlayerFacingAngle(playerid, 268.1223);
    SetPlayerVirtualWorld(playerid, playerid+20);
    SetPlayerCameraPos(playerid, 562.5885, 2136.6760, 1551.4860);
    SetPlayerCameraLookAt(playerid, 560.5141,2136.6279,1551.4860);
    SetPlayerSkin(playerid, ClothesParameters[ClothesShopState[playerid]][clothesSkinId]);

    for (new i = 0; i < 7; i++)
        TextDrawShowForPlayer(playerid, BuyClothes_TD[i]);

    PlayerTextDrawShow(playerid, BuyClothes_PTD[0][playerid]);

    new string[144];
    format(string, sizeof(string), "%d rub", ClothesParameters[ClothesShopState[playerid]][clothesPrice]);
    PlayerTextDrawSetString(playerid, BuyClothes_PTD[0][playerid], string);
    SelectTextDraw(playerid, white);
    TogglePlayerControllable(playerid, false);
    SCM(playerid, blue, "Что б отменить покупку - нажмите клавишу \"ESC\"");
}

stock ExitBuyClothes(playerid){
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerPos(playerid, 568.6680,2125.7913,1551.4600);
    SetPlayerFacingAngle(playerid, 265.5347);
    SetCameraBehindPlayer(playerid);
    for (new i = 0; i < 7; i++)
        TextDrawHideForPlayer(playerid, BuyClothes_TD[i]);
    PlayerTextDrawHide(playerid, BuyClothes_PTD[0][playerid]);
    ClothesShopState[playerid] = 1;

    SetPlayerSkin(playerid, PlayerInfo[playerid][pMember] > 0 ? PlayerInfo[playerid][pFSkin] : PlayerInfo[playerid][pChar]);
    IsBuyClothes[playerid] = false;
    CancelSelectTextDraw(playerid);
    FreezePlayer(playerid, 2000);
}