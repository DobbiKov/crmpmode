#define MAX_ATMS 100

new Iterator: AllATMs<MAX_ATMS>;
enum E_ATM_INFO
{
    atmID,
    Float: atmX,
    Float: atmY,
    Float: atmZ,
    Text3D: atmLabel,
}
new AtmInfo[MAX_ATMS][E_ATM_INFO];
new totalatm;

publics LoadAtm()
{
	new rows, fields;
	cache_get_data(rows, fields);
    if(rows)
    {
        for(new i = 0; i < rows; i++)
        {
            AtmInfo[i][atmID] = cache_get_field_content_int(i, "atmID");
            AtmInfo[i][atmX] = cache_get_field_content_float(i, "atmX");
            AtmInfo[i][atmY] = cache_get_field_content_float(i, "atmY");
            AtmInfo[i][atmZ] = cache_get_field_content_float(i, "atmZ");

            AtmInfo[i][atmLabel] = CreateDynamic3DTextLabel("{"cblue"}��������\n\n{"cwhite"}�������: {"cblue"}L. ALT", 0xFFFFFFFF, AtmInfo[i][atmX], AtmInfo[i][atmY], AtmInfo[i][atmZ]+1.0, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 100.0);

            totalatm++;

            Iter_Add(AllATMs, i);

        }
    }
    printf("[UNIGVA]: ����� ��������� ����������: %d", totalatm);
    return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024)
    {
        foreach(new i : AllATMs)
        {
            if(IsPlayerInRangeOfPoint(playerid, 1.0, AtmInfo[i][atmX], AtmInfo[i][atmY], AtmInfo[i][atmZ]))
            {
                if(PlayerInfo[playerid][bDeveloper] == 1)
                {
                    new string[124] = "";
                    format(string, sizeof(string), "[Developer Mode]: ID ��������� - %d", AtmInfo[i][atmID]);
                    SCM(playerid, green, string);
                }
                ShowAtmDialog(playerid);
            }
        }
    }
	#if	defined	atm__OnPlayerKeyStateChange
		return atm__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange atm__OnPlayerKeyStateChange
#if	defined	atm__OnPlayerKeyStateChange
	forward atm__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

stock ShowAtmDialog(playerid)
{
    SPD
    (
        playerid, D_ATM, DIALOG_STYLE_LIST,
        "{"cblue"}��������",
        "\
        {"cblue"}1. {FFFFFF}����� � ����������� �����\n\
        {"cblue"}2. {FFFFFF}�������� �� ���������� ����\n\
        {"cblue"}3. {FFFFFF}������ ���������� �����\n\
        {"cblue"}4. {FFFFFF}�������� �����\n\
        {"cblue"}5. {FFFFFF}�������� ��� ������\n\
        {"cblue"}6. {FFFFFF}��������� ���� ����������\
        ",
        "�������", "������"
    );
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_ATM_GET:
        {
            if(!response) return ShowAtmDialog(playerid);
            else
            {
                if(!IsNumeric(inputtext) || PlayerInfo[playerid][pBCash] < strval(inputtext))
                {
                    SPD
                    (
                        playerid, D_ATM_GET, DIALOG_STYLE_INPUT,
                        !"{"cblue"}��������",
                        !"{FFFFFF}������� �����, ������� �� ������� ����� � ������ ����������� �����:",
                        !"�����", !"�����"
                    );                    
                    return 1;
                }

                GiveMoney(playerid, strval(inputtext), "������ ����� � ���������");
                GiveBankMoney(playerid, -strval(inputtext), "������ ����� � ���������");

                new string[144];
                format(string, sizeof(string), "�� ����� � ����������� ����� %d ���.", strval(inputtext));
                return SCM(playerid, blue, string);
            }
        }
        case D_ATM_PUT:
        {
            if(!response) return ShowAtmDialog(playerid);
            else
            {
                if(!IsNumeric(inputtext) || PlayerInfo[playerid][pCash] < strval(inputtext))
                {
                    SPD
                    (
                        playerid, D_ATM_PUT, DIALOG_STYLE_INPUT,
                        !"{"cblue"}��������",
                        !"{FFFFFF}������� �����, ������� �� ������� �������� �� ��� ���������� ����:",
                        !"��������", !"�����"
                    );                  
                    return 1;
                }

                GiveMoney(playerid, -strval(inputtext), "������� ������ � ���������");
                GiveBankMoney(playerid, strval(inputtext), "������� ������ � ���������");

                new string[144];
                format(string, sizeof(string), "�� �������� �� ��� ��������� ���� %d ���.", strval(inputtext));
                return SCM(playerid, blue, string);
            }
        }
        case D_ATM_BALANCE:
        {
            if(!response) ShowAtmDialog(playerid);
            else ShowAtmDialog(playerid);
        }
        case D_ATM:
        {
            if(!response) return 1;
            else
            {
                switch(listitem)
                {
                    case 0:
                    {
                        SPD
                        (
                            playerid, D_ATM_GET, DIALOG_STYLE_INPUT,
                            !"{"cblue"}��������",
                            !"{FFFFFF}������� �����, ������� �� ������� ����� � ������ ����������� �����:",
                            !"�����", !"�����"
                        );
                    }
                    case 1:
                    {
                        SPD
                        (
                            playerid, D_ATM_PUT, DIALOG_STYLE_INPUT,
                            !"{"cblue"}��������",
                            !"{FFFFFF}������� �����, ������� �� ������� �������� �� ��� ���������� ����:",
                            !"��������", !"�����"
                        );
                    }
                    case 2:
                    {
                        new string[256];
                        format(string, sizeof(string), "{FFFFFF}�� ����� ���������� ����� %d ���.", PlayerInfo[playerid][pBCash]);
                        SPD
                        (
                            playerid, D_ATM_BALANCE, DIALOG_STYLE_MSGBOX,
                            !"{"cblue"}��������",
                            string,
                            !"�����", !""
                        );
                    }
                    case 3:
                    {
                        SPD
                        (
                            playerid, D_ATM_PAY_FINE, DIALOG_STYLE_INPUT,
                            !"{"cblue"}������ ������:",
                            !"{"cblue"}������� ����� ������.\n\n\
                            ��� �� ������ ����� ������, �������: /tickets",
                            !"�����", !"�����"
                        );
                    }
                    case 4:
                    {
                        if(PlayerInfo[playerid][pFines] < 1) return SCM(playerid, red, "� ��� ��� ����������� �������.");
                        new string[256];
                        format
                        (
                            string, sizeof(string), 
                            "{FFFFFF}\
                            ���������� �������:\t{"cblue"}%d{FFFFFF}\n\
                            ����� �����:\t\t\t{"cblue"}%d ���.{FFFFFF}\n\n\
                            �� ������� �������� ��� ������?",
                            PlayerInfo[playerid][pFines], PlayerInfo[playerid][pSumFines]
                        );
                        SPD
                        (
                            playerid, D_ATM_PAY_ALL_FINES, DIALOG_STYLE_MSGBOX,
                            !"{"cblue"}������ �������",
                            string,
                            !"��������", !"�����"
                        );
                    }
                    case 5:
                    {
                        if(PlayerInfo[playerid][pPhone] <= 0 || PlayerInfo[playerid][pPhoneNumber] <= 0) return SCM(playerid, red, "� ��� ��� ��������, ���� ���-�����. ������ �� � ��������� 24/7.");
                        SPD
                        (
                            playerid, D_ATM_PAY_PHONE_CASH, DIALOG_STYLE_INPUT,
                            !"{"cblue"}��������",
                            !"{FFFFFF}������� �����, �� ������� �� ������ ��������� ������ ��������:",
                            !"���������", !"�����"
                        );
                    }
                }
            }
        }
        case D_ATM_PAY_FINE:
        {
            if(!response) return ShowAtmDialog(playerid);
            else
            {
                if(!IsNumeric(inputtext))
                {
                    SPD
                    (
                        playerid, D_ATM_PAY_FINE, DIALOG_STYLE_INPUT,
                        !"{"cblue"}������ ������:",
                        !"{"cblue"}������� ����� ������.\n\n\
                        ��� �� ������ ����� ������, �������: /tickets",
                        !"�����", !"�����"
                    );
                    return 1;
                }

                new sql[144];
                format(sql, sizeof(sql), "SELECT * FROM `fines` WHERE `account_id` = '%d' AND `fine_id` = '%d'", PlayerInfo[playerid][pID], strval(inputtext));
                mysql_tquery(connects, sql, "PaymentFine", "i", playerid);
            }
        }
        case D_ATM_PAY_PHONE_CASH:
        {
            if(!response) return ShowAtmDialog(playerid);
            else
            {
                if(PlayerInfo[playerid][pBCash] < strval(inputtext)) return SCM(playerid, red, !"�� ����� ���������� ����� ������������ �������.");

                if(!IsNumeric(inputtext))
                {
                    SPD
                    (
                        playerid, D_ATM_PAY_PHONE_CASH, DIALOG_STYLE_INPUT,
                        !"{"cblue"}��������",
                        !"{FFFFFF}������� �����, �� ������� �� ������ ��������� ������ ��������:",
                        !"���������", !"�����"
                    );  
                    return 1;                  
                }

                PlayerInfo[playerid][pPhoneCash] += strval(inputtext);
                GiveBankMoney(playerid, -strval(inputtext), "���������� ������� ��������");
                
                new string[144];
                format(string, sizeof(string), "�� ��������� ������ �������� �� %d ���.", strval(inputtext));
                SCM(playerid, blue, string);
                return SaveAccounts(playerid);
            }
        }
        case D_ATM_PAY_ALL_FINES:
        {
            if(!response) ShowAtmDialog(playerid);
            else
            {
                if(PlayerInfo[playerid][pCash] < PlayerInfo[playerid][pSumFines]) return SCM(playerid, red, !"� ��� ������������ �������.");

                GiveMoney(playerid, -PlayerInfo[playerid][pSumFines], "������ ���� �������");
                PlayerInfo[playerid][pFines] = 0;
                PlayerInfo[playerid][pSumFines] = 0;

                SaveAccounts(playerid);

                new sql[144];
                format(sql, sizeof(sql), "DELETE FROM `fines` WHERE `account_id` = '%d'", PlayerInfo[playerid][pID]);
                mysql_tquery(connects, sql, "", "");

                return SCM(playerid, blue, !"�� ������� �������� ��� ������.");
            }
        }
        case D_PAYMENT_FINE:
        {
            if(!response)
            {
                DeletePVar(playerid, "fine_id");
                DeletePVar(playerid, "fine");

                SPD
                (
                    playerid, D_ATM_PAY_FINE, DIALOG_STYLE_INPUT,
                    !"{"cblue"}������ ������:",
                    !"{"cblue"}������� ����� ������.\n\n\
                    ��� �� ������ ����� ������, �������: /tickets",
                    !"�����", !"�����"
                );
                return 1;
            }
            else
            {
                new fine_id = GetPVarInt(playerid, "fine_id");
                new fine = GetPVarInt(playerid, "fine"); 

                if(PlayerInfo[playerid][pCash] < fine) return SCM(playerid, red, !"� ��� ������������ �������.");

                GiveMoney(playerid, -fine, "������ ������");
                PlayerInfo[playerid][pFines]--;
                PlayerInfo[playerid][pSumFines] -= fine;

                SaveAccounts(playerid);

                new sql[180];
                format(sql, sizeof(sql), "DELETE FROM `fines` WHERE `fine_id` = '%d'", fine_id);
                mysql_tquery(connects, sql, "", "");

                DeletePVar(playerid, "fine_id");
                DeletePVar(playerid, "fine");

                return SCM(playerid, blue, "�� ������� �������� �����.");
            }
        }
    }
	#if	defined	atm__OnDialogResponse
		return atm__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse atm__OnDialogResponse
#if	defined	atm__OnDialogResponse
	forward atm__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

publics PaymentFine(playerid)
{
    static rows[2], fine_id, fined[MAX_PLAYER_NAME], fine, reason[40];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        fine_id = cache_get_field_content_int(0, "fine_id");
        fine = cache_get_field_content_int(0, "fine");
        cache_get_field_content(0, "fined", fined, connects, sizeof(fined));
        cache_get_field_content(0, "reason", reason, connects, sizeof(reason));

		SetPVarInt(playerid, "fine_id", fine_id);
		SetPVarInt(playerid, "fine", fine);

	    new fmt_dialog[180];
		format
		(
			fmt_dialog, sizeof fmt_dialog,
			"{FFFFFF}����� \t\t{"cblue"}�%d\n\n\
		    {FFFFFF}�������: \t\t{"cblue"}%s\n\
			{FFFFFF}�����: \t\t{"cblue"}%d ������\n\
			{FFFFFF}�������: \t\t{"cblue"}%s",
			fine_id,
			fined,
			fine,
			reason

		);

		ShowPlayerDialog
		(
			playerid, D_PAYMENT_FINE, DIALOG_STYLE_MSGBOX,
			"{"cblue"}������ ������:",
			fmt_dialog,
			"��������", "�����"
		);
    }
    else SCM(playerid, red, "����� �� ������.");
    return 1;
}