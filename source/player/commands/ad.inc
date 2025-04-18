#define MAX_AD 20

enum e_AD
{
    ad_ID,
    ad_playerid,
    ad_text[100],
    ad_edit_id,
    ad_status,
}
new AD[MAX_AD][e_AD];

new Iterator: ads<MAX_AD>;

CMD:ad(playerid, params[])
{
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, red, "� ��� ����� ���������� ����!");

    extract params -> new string: text[100]; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /ad [�����]");

    if(strlen(text) > 100 || strlen(text) < 1) return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /ad [�����]");
    new price = strlen(text) * 10;    
    if(PlayerInfo[playerid][pPhoneCash] < price) return SCM(playerid, red, "� ��� �� ���������� �����!"); 

    new all = 0;
    foreach(new i : ads)
    {
        all++;
    }
    if(all >= 20) return SCM(playerid, red, "����� ���������� �����������!");

    new string[256];
    format(string, sizeof(string), "{FFFFFF}����������: {"cblue"}%s\n\n{FFFFFF}���� ����������: {"cblue"}%d ������\n{FFFFFF}�� ������������� ������ ��������� ����������?", text, price);
    SPD(playerid, D_AD, DIALOG_STYLE_MSGBOX, "{"cblue"}����������", string, "��", "���");

    SetPVarInt(playerid, "ad_price", price);
    SetPVarString(playerid, "ad_text", text);

    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_AD:
        {
            if(!response) return 1;
            else
            {
                new i = Iter_Free(ads);
                Iter_Add(ads, i);
                AD[i][ad_ID] = i;
                AD[i][ad_playerid] = playerid;
                AD[i][ad_status] = 0;
                AD[i][ad_edit_id] = -1;
                AD[i][ad_text] = EOS;
                new text[100];
                GetPVarString(playerid, "ad_text", text, sizeof(text));
                // strcat(AD[i][ad_text], text);
                format(AD[i][ad_text], 100, "%s", text);

                PlayerInfo[playerid][pPhoneCash] -= GetPVarInt(playerid, "ad_price");
                GiveSmiMoney(GetPVarInt(playerid, "ad_price"));

                new string[144];
                format(string, sizeof(string), "�� ��������� ����������! ����� ������ ����������: %d", i+1);
                SCM(playerid, blue, string);

                format(string, sizeof(string), "[R][��� �����������]: ������ ����� ����������! �����������: /edit");
                SCMR(TEAM_SMI, green, string);

                DeletePVar(playerid, "ad_price");
                DeletePVar(playerid, "ad_text");
            }
        }
    }
	#if	defined	ad__OnDialogResponse
		return ad__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse ad__OnDialogResponse
#if	defined	ad__OnDialogResponse
	forward ad__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

stock ClearAds()
{
    foreach(new i : ads)
    {
        AD[i][ad_ID] = -1;
        AD[i][ad_playerid] = -1;
        AD[i][ad_text] = EOS;
        Iter_Remove(ads, i);
    }
    return 1;
}