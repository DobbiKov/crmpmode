stock ShowDonatePhoneNumberDialog(playerid)
{
    new string[256];
    format(string, sizeof(string), "{ffffff}�� ������� ���������� ����� �������� �� {"cblue"}500 {ffffff}��������?");
    ShowPlayerDialog
    (
        playerid, 
        D_DONATE_PHONE_NUMBER, 
        DIALOG_STYLE_MSGBOX, 
        !"{"cblue"}����� ��������", 
        string, 
        !"��", 
        !"���"
    );
    return 1;
}

stock ShowDonatPhoneNumberInputDialog(playerid, error = 0)
{
    new string[256] = "";
    switch(error)
    {
        case 1: format(string, sizeof(string), "{"cred"}�������� ������!\n\n");
        case 2: format(string, sizeof(string), "{"cred"}������ ����� ��� ���-�� �����!\n\n");
    }
    new temp_string[256];
    format(temp_string, sizeof(temp_string), 
    "{FFFFFF}������� ����� ����� � ���� ����\n\n\
    {FF6600}����������:\n\
    {FFCC00}- ����� ������ ���� ���, ������, ��� �����������.\n\
    ��������: 333, 4444, 55555\n\
    - ����� �� ������ ���������� � 0"
    );
    strcat(string, temp_string);
    ShowPlayerDialog
    (
        playerid, 
        D_DONATE_INPUT_PHONE_NUMBER, 
        DIALOG_STYLE_INPUT, 
        !"{"cblue"}����� ��������", 
        string, 
        !"�����", 
        !"�����"
    );
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case D_DONATE_PHONE_NUMBER:
		{
			if(!response) return ShowDonateListDialog(playerid);
            if(PlayerInfo[playerid][pPhone] == 0) return SCM(playerid, red, "� ��� ��� ��������!"); 
			return ShowDonatPhoneNumberInputDialog(playerid);
		}
        case D_DONATE_INPUT_PHONE_NUMBER:
        {
            if(!response) return ShowDonateListDialog(playerid);
            
            if(strlen(inputtext) < 3 || strlen(inputtext) > 5 || !IsNumeric(inputtext) || inputtext[0] == '0')
            {
                return ShowDonatPhoneNumberInputDialog(playerid, 1);
            }

            new query[144];
            format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pPhoneNumber` = '%d'", strval(inputtext));
            return mysql_tquery(connects, query, "DonatePhoneNumberCheckAbility", "idi", playerid, strval(inputtext), 0);
        }
        case D_DONATE_PHONE_NUMBER_SURE:
        {
            new number = GetPVarInt(playerid, "donate_buy_phone_number");
            DeletePVar(playerid, "donate_buy_phone_number");
            if(!response) return ShowDonatPhoneNumberInputDialog(playerid);
            
            new query[144];
            format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pPhoneNumber` = '%d'", number);
            return mysql_tquery(connects, query, "DonatePhoneNumberCheckAbility", "idi", playerid, number, 1);
        }
	}
	#if	defined	donate_cpn__OnDialogResponse
		return donate_cpn__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse donate_cpn__OnDialogResponse
#if	defined	donate_cpn__OnDialogResponse
	forward donate_cpn__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

publics DonatePhoneNumberCheckAbility(playerid, newNumber, times)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
        return ShowDonatPhoneNumberInputDialog(playerid, 2);
    
    if(times == 0)
    {
        new string[144];
        format(string, sizeof(string), "{ffffff}�� ������� ���������� �������� {"cblue"}[%d] {ffffff}�� 500 ��������?", newNumber);
        ShowPlayerDialog(playerid, D_DONATE_PHONE_NUMBER_SURE, DIALOG_STYLE_MSGBOX, !"����� ��������", string, !"�����", !"�����");
        return SetPVarInt(playerid, "donate_buy_phone_number", newNumber);
    }

    new number = newNumber;

    if(PlayerInfo[playerid][pDonate] < 500) return SCM(playerid, red, !"� ��� ������������ ��������.");
    
    PlayerInfo[playerid][pDonate] -= 500;

    PlayerInfo[playerid][pPhoneNumber] = number;
    SaveAccounts(playerid);

    new fmt_msg[180];

    format
    (
        fmt_msg, sizeof fmt_msg,
        "{ffffff}�� �������� ����� �������� ����� �����\n\
        ������ � ���� ����� ��������� �� ������ {"cblue"}%d",
        PlayerInfo[playerid][pPhoneNumber]
    );

    ShowPlayerDialog
    (
        playerid, 0, DIALOG_STYLE_MSGBOX,
        "{"cblue"}��������� ������",
        fmt_msg,
        "�������", ""
    );  
    return 1;
}