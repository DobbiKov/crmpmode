


//******************************************************************** */

stock ResultCheat(p, r)
{

    new fmt_dialog[300], result[10], string[144];

    format(result, sizeof(result), "#%s", AC_CODE[r]);

	new Year, Month, Day;
	getdate(Year, Month, Day);

	new Hour, Minute;
	gettime(Hour, Minute);

	format
	(
		fmt_dialog, sizeof fmt_dialog,
		"{"cred"}��������! {FFFFFF}�� ���� ������� �� ���������� � ���������!\n"\
		"���: {"cblue"}%s\n"\
		"{FFFFFF}����: {"cblue"}%d-%02d-%02d %d:%02d\n"\
		"{FFFFFF}��� ����: {"cblue"}%d\n\n"\
		"{FFFFFF}�����: {"cblue"}forum.unigva-rp.ru\n"\
		"{FFFFFF}����������� �� ��������� �������� ����� �������� �� ������.",
        result, Day, Month, Year, Hour, Minute, GetPlayerPing(p)
	);

    if(PlayerInfo[p][bAdmin] < 3)
	{
        ShowPlayerDialog
        (
            p, D_NULL, DIALOG_STYLE_MSGBOX,
            "{"cblue"}�������",
            fmt_dialog,
            "�������", ""
        );

        format(string, sizeof(string), "{"cgrey"}[{"cred"}����-���{"cgrey"}] <%s> ������������� %s(ID: %d) ��� ������ �� ���������� � ��������� [%s]", result, PlayerInfo[p][pName], p, AC_CODE_NAME[r]);
        SCMA(red, string);
        NewKick(p);
	}
    return true;
}
stock ResultMessageCheat(p, r)
{
    new result[10], string[144];
    format(result, sizeof(result), "#%s", AC_CODE[r]);

	format(string, sizeof(string), "{"cgrey"}[{"cred"}����-���{"cgrey"}] <%s> ������������� %s(ID: %d) [%s]", result, PlayerInfo[p][pName], p, AC_CODE_NAME[r]);
	
    if(PlayerInfo[p][bAdmin] < 3)
        SCMA(red, string);

    return true;
}

// publics OnCheatDetected(playerid, ip_address[], type, code)
// {
// 	new string[144];
// 	format(string, sizeof(string), "ac: type - %d | code - %d", type, code);
// 	// return SCMTA(red, string);
// 	return ResultMessageCheat(playerid, code);
// }

publics OnCheatDetected(playerid, ip_address[], type, code)
{
	// if(PlayerInfo[playerid][bAdmin] > 1) return 1; 
    if(type == AC_GLOBAL_TRIGGER_TYPE_PLAYER)
    {
        switch(code)
        {
            // case 5, 6, 11, 22:
            // {
            //     return ResultMessageCheat(playerid, code);
            // }
            case 32: // CarJack
            {
                new
                    Float:x,
                    Float:y,
                    Float:z;

                AntiCheatGetPos(playerid, x, y, z);
                return SetPlayerPos(playerid, x, y, z);
            }
            // case 40: // Sandbox
            // {
            //     SendClientMessage(playerid, -1, MAX_CONNECTS_MSG);
            //     return AntiCheatKickWithDesync(playerid, code);
            // }
            case 41: // Invalid Version
            {
                SendClientMessage(playerid, -1, UNKNOWN_CLIENT_MSG);
                return AntiCheatKickWithDesync(playerid, code);
            }
            case 43,45,46,47: //�������
            {
                Kick(playerid); //������ ������������� ������ ��� ��������, ����� ��� ������ �������� �������
                return 1;
            }
            default:
            {
                if(gettime() - pAntiCheatLastCodeTriggerTime[playerid][code] < AC_TRIGGER_ANTIFLOOD_TIME)
                    return 1;

                pAntiCheatLastCodeTriggerTime[playerid][code] = gettime();
                AC_CODE_TRIGGERED_COUNT[code]++;

                // new
                    // string[88 - 10 + MAX_PLAYER_NAME + 5 + AC_MAX_CODE_NAME_LENGTH + AC_MAX_CODE_LENGTH];
                new trigger_type = AC_CODE_TRIGGER_TYPE[code];

                if(trigger_type == AC_CODE_TRIGGER_TYPE_WARNING)
                {
                    ResultMessageCheat(playerid, code);
                    // format(string, sizeof(string), "[A] %s[%d] ������������� � ������������� ���-��������: {FFFFFF}%s {FF8A30}���: {FFFFFF}[%03d]", pData[playerid][pNickname], playerid, AC_CODE_NAME[code], code);
                    // AdminChat(CR, string);
                }
                else // AC_CODE_TRIGGER_TYPE_KICK
                {
                    ResultCheat(playerid, code);
                    // format(string, sizeof(string), "[A] ����� %s[%d] ��� ������ �� ����. {FFFFFF}%s ���: [%03d]", pData[playerid][pNickname], playerid, AC_CODE_NAME[code], code);
                    // AdminChat(CR, string);
                    // format(string, sizeof(string), "�� ���� ������� �� ���������� � ���������. {FFFFFF}%s {FF8A30}���: {FFFFFF}[%d]. {AA3333}�������� ������������� ���� ��� ��������.", AC_CODE_NAME[code], code);
                    // SendClientMessage(playerid, CR, string);
                    // AntiCheatKickWithDesync(playerid, code);
                }
            }
        }
    }
    else // AC_GLOBAL_TRIGGER_TYPE_IP
    {
        AC_CODE_TRIGGERED_COUNT[code]++;
        new string[58 - 8 + 16 + AC_MAX_CODE_NAME_LENGTH + AC_MAX_CODE_LENGTH];
        format(string, sizeof(string), "[UN-AC]BAN-IP IP-����� %s ��� ������������: {FFFFFF}%s {FF8A30}���: {FFFFFF}[%03d].", "127.0.0.1", AC_CODE_NAME[code], code);
        SCMA(grey, string);
        // BlockIpAddress(ip_address, 0);
    }
    return 1;
}


stock UploadAntiCheatSettings()
{
    new
        Cache:cache = mysql_query(connects, "SELECT * FROM "AC_TABLE_SETTINGS" ORDER BY "AC_TABLE_FIELD_CODE""),
        rows,
        fields,
        tick = GetTickCount();

    cache_get_data(rows, fields);

    if(rows > 0)
    {
        for(new i = 0; i < AC_MAX_CODES; i++)
        {
            AC_CODE_TRIGGER_TYPE[i] = cache_get_field_content_int(i, ""AC_TABLE_FIELD_TRIGGER"");

            if(AC_CODE_TRIGGER_TYPE[i] == AC_CODE_TRIGGER_TYPE_DISABLED)
                EnableAntiCheat(i, 0);
        }

        printf("[�������� MYSQL]: ��������� ����-���� ������� ��������� (%d). ���������: %d��.", rows, GetTickCount() - tick);
    }
    else
    {
        print("[�������� MYSQL]: ��������� ����-���� �� ������� � ���� ������. �������� ���� ����������� - ��������� ����-���.");
        return GameModeExit();
    }

    cache_delete(cache);
    return 1;
}

// ACLoad(playerid)
// {
//     if(pData[playerid][pAdmin] > 0)
// 	{
// 		if(GetPVarInt(playerid,"AdminLogin") > 0)
//  		for(new i;i<10;i++) TextDrawShowForPlayer(playerid, CheatText[0][i]),TextDrawShowForPlayer(playerid, CheatText[1][i]);
//  		if(pData[playerid][pAdmin] >= 2) // � ������ ��� ��������� ������������ ���� == 3
//         {
//             SendClientMessage(playerid, CYELLOW, "[AC] {ffffff}�������� ��� ���.");
//             for(new i = 1;i<52;i++) EnableAntiCheatForPlayer(playerid, i, 0); // ��������� ��� 52 ��������.
//         }
//         return true;
//     }
//     return true;
// }
// AddCheater(playerid, strokaID)
// {
//     new str[3];
//     if(strokaID == 1)
//     {
//         if(Cheatp[playerid][0] != 255) return true;
//         format(str, sizeof(str), "%d", playerid);
//         TextDrawSetString(CheatText[strokaID][Cheat[0]], str);
//         Cheatp[playerid][0] = Cheat[0];
//         Cheat[0] ++;
//         if(Cheat[0] > 8) Cheat[0] = 0;
//     }
//     else
//     {
//         if(Cheatp[playerid][1] != 255) return true;
//         format(str, sizeof(str), "%d", playerid);
//         TextDrawSetString(CheatText[strokaID][Cheat[1]], str);
//         Cheatp[playerid][1] = Cheat[1];
//         Cheat[1] ++;
//         if(Cheat[1] > 8) Cheat[1] = 0;
//     }
//     return 1;
// }

public OnPlayerConnect(playerid)
{
    for(new i = 0; i < AC_MAX_CODES; i++) 
        pAntiCheatLastCodeTriggerTime[playerid][i] = -1; 
    pAntiCheatSettingsPage{playerid} = 0; // ����������� �������� 0 ����������, �������� ����� �������� �������� ����-����, �� ������� ��������� ����� 
    pAntiCheatSettingsEditCodeId[playerid] = -1; // ����������� ����������, �������� ������������� (ID) ���� ����-����, ������� ����������� �����, �������� -1 return 1;


	#if	defined	new_ac__OnPlayerConnect
		return new_ac__OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerConnect
	#undef	OnPlayerConnect
#else
	#define	_ALS_OnPlayerConnect
#endif

#define	OnPlayerConnect new_ac__OnPlayerConnect
#if	defined	new_ac__OnPlayerConnect
	forward new_ac__OnPlayerConnect(playerid);
#endif