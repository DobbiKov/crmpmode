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
        { "�������", red },
        { "����-�������", lightred },
        { "�����", grey },
        { "����-�����", lightgrey },
        { "���������", orange },
        { "����-���������", lightorange },
        { "������", green },
        { "����-������", lightgreen },
        { "������", yellow },
        { "�����", blue },
        { "�������", lightblue },
        { "�����", white }

}; 

CMD:clist(playerid)
{
    if(PlayerInfo[playerid][pVIP] < 1) return YouCannotUseThisFunc(playerid);
    new string[2048] = "\
    {ffffff}1.  {"cred"}�������\n\
    {ffffff}2.  {"clred"}����-�������\n\
    {ffffff}3.  {"cgrey"}�����\n\
    {ffffff}4.  {"clgrey"}����-����\n\
    {ffffff}5.  {"corange"}���������\n\
    {ffffff}6.  {"clorange"}����-���������\n\
    {ffffff}7.  {"cgreen"}������\n\
    {ffffff}8.  {"clgreen"}����-������\n\
    {ffffff}9.  {"cyellow"}������\n\
    {ffffff}10. {"cblue"}�����\n\
    {ffffff}11. {"clblue"}�������\n\
    {ffffff}12. {"cwhite"}�����";
    // for(new i = 0; i < sizeof(clist_data); i++)
    // {
    //     new temp_string[144] = "";
    //     format(temp_string, sizeof(temp_string), "{ffffff}%d. {0x%s}%s\n", i + 1, clist_data[i][color_hex_code], clist_data[i][color_name]);
    //     strcat(string, temp_string);
    // }
    SPD(playerid, D_CHOOSE_CLIST, DIALOG_STYLE_LIST, !"{"cblue"}����� �����", string, !"�������", !"�������");
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