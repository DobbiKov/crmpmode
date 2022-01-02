const
    CLIST_DIALOG = 1500,
    MAX_COLOR_NAME = 16;

enum
    e_CLIST_INFO
    {
        color_name[MAX_COLOR_NAME],
        color_hex_code
    };

static const
    clist_data[][e_CLIST_INFO] =
    {
        { "Красный", red },
        { "Ярко-красный", lightred },
        { "Серый", grey },
        { "Ярко-серый", lightgrey },
        { "Оранжевый", orange },
        { "Ярко-оранжевый", lightorange },
        { "Зелёный", green },
        { "Ярко-зелёный", lightgreen },
        { "Желтый", yellow },
        { "Синий", blue },
        { "Голубой", lightblue },
        { "Белый", white }

}; 

CMD:clist(playerid)
{
    if(PlayerInfo[playerid][pVIP] < 1) return YouCannotUseThisFunc(playerid);
    new string[2048] = "\
    {ffffff}1.  {"cred"}Красный\n\
    {ffffff}2.  {"clred"}Ярко-красный\n\
    {ffffff}3.  {"cgrey"}Серый\n\
    {ffffff}4.  {"clgrey"}Ярко-серы\n\
    {ffffff}5.  {"corange"}Оранжевый\n\
    {ffffff}6.  {"clorange"}Ярко-оранжевый\n\
    {ffffff}7.  {"cgreen"}Зелёный\n\
    {ffffff}8.  {"clgreen"}Ярко-зелёный\n\
    {ffffff}9.  {"cyellow"}Желтый\n\
    {ffffff}10. {"cblue"}Синий\n\
    {ffffff}11. {"clblue"}Голубой\n\
    {ffffff}12. {"cwhite"}Белый";
    // for(new i = 0; i < sizeof(clist_data); i++)
    // {
    //     new temp_string[144] = "";
    //     format(temp_string, sizeof(temp_string), "{ffffff}%d. {0x%s}%s\n", i + 1, clist_data[i][color_hex_code], clist_data[i][color_name]);
    //     strcat(string, temp_string);
    // }
    SPD(playerid, D_CHOOSE_CLIST, DIALOG_STYLE_LIST, !"{"cblue"}Выбор цвета", string, !"Выбрать", !"Закрыть");
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_CHOOSE_CLIST:
        {
            if(!response) return 1;
            return SetPlayerColor(playerid, clist_data[listitem][color_hex_code]);
        }
    }
	#if	defined	clist__OnDialogResponse
		return clist__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse clist__OnDialogResponse
#if	defined	clist__OnDialogResponse
	forward clist__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif