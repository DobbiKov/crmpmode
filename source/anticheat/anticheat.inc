new ac_names[13][30] = 
{
	".", 
	"������", 
	"�������", 
	"����������� �������", 
	"Speed Hack", 
	"�� �� ��������", 
	"�������� � ������", 
	"�������� ����", 
	"��������", 
	"�������� � ���������", 
	"AirBreak", 
	"BulletHitType",
	"���� ��������"
};

#define MAX_ANTICHEATS 6

#define SpeedHack_AC 0
#define TP_in_VEH_AC 1
#define	AirBreak_AC	 3
#define OnFootCrash_AC 4
#define BulletHitType_AC 5

new Iterator: AllAntiCheats<MAX_ANTICHEATS>;

enum E_AC_INFO
{
	acID,
	acName[32],
	acStatus,
}
new AntiCheatInfo[MAX_ANTICHEATS][E_AC_INFO];

stock ResultCheat(p, r)
{
	if(GetPVarInt(p, "Cheater") == 1) return 1;

	SetPVarInt(p, "Cheater", 1);
	SetTimerEx("AntiCheatMess", 30*1000, false, "d", p);
	SetPVarInt(p, "Cheaters", 1);

    new fmt_dialog[300], result[10], string[144];

    switch(r)
    {
        case 1: result = "#001"; // - ������
        case 2: result = "#002"; // - �������
        case 3: result = "#003"; // - ������������ �������
        case 4: result = "#004"; // - Speed Hack
		case 5: result = "#005"; // - �� �� ��������
		case 6: result = "#006"; // - goto
		case 7: result = "#007"; // - self kill
		case 8: result = "#008"; // - HP
		case 9: result = "#009"; // - TP IN VEH
		case 10: result = "#010"; // - AIRBREAK
		case 11: result = "#011"; // - ANTI ONFOOT CRASH
		case 12: result = "#012"; // - ANTI BULLET HIT TYPE
		case 13: result = "#013"; // - ANTI FLOOD CARS
    }

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
		"{FFFFFF}�����: {"cblue"}https://vk.com/unigvafre\n"\
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

		format(string, sizeof(string), "{"cgrey"}[{"cred"}����-���{"cgrey"}] <%s> ������������� %s(ID: %d) ��� ������ �� ���������� � ��������� [%s]", result, PlayerInfo[p][pName], p, ac_names[r]);
		SCMA(red, string);
	    NewKick(p);
	}
    return true;
}
stock ResultMessageCheat(p, r)
{
	if(GetPVarInt(p, "Cheater") == 1) return 1;
	
	SetPVarInt(p, "Cheater", 1);
	SetTimerEx("AntiCheatMess", 30*1000, false, "d", p);
	SetPVarInt(p, "Cheaters", 1);

    new result[10], string[144];

    switch(r)
    {
        case 1: result = "#001"; // - ������
        case 2: result = "#002"; // - �������
        case 3: result = "#003"; // - ������������ �������
        case 4: result = "#004"; // - Speed Hack
		case 5: result = "#005"; // - �� �� ��������
		case 6: result = "#006"; // - goto
		case 7: result = "#007"; // - self kill
		case 8: result = "#008"; // - HP
		case 9: result = "#009"; // - TP IN VEH
		case 10: result = "#010"; // - AIRBREAK
		case 11: result = "#011"; // - ANTI ONFOOT CRASH
		case 12: result = "#012"; // - ANTI BULLET HIT TYPE
		case 13: result = "#013"; // - ANTI FLOOD CARS
		// default:{
		// 	format(result, sizeof(result), "%d", r);

		// }
    }

	new Year, Month, Day;
	getdate(Year, Month, Day);

	new Hour, Minute;
	gettime(Hour, Minute);

	format(string, sizeof(string), "{"cgrey"}[{"cred"}����-���{"cgrey"}] <%s> ������������� %s(ID: %d) [%s]", result, PlayerInfo[p][pName], p, ac_names[r]);
	SCMA(red, string);

    return true;
}

publics AntiCheatMess(playerid)
{
	if(GetPVarInt(playerid, "Cheater") == 1) SetPVarInt(playerid, "Cheater", 0);
	return 1;
}

publics OnCheatDetected(playerid, ip_address[], type, code)
{
	new string[144];
	format(string, sizeof(string), "ac: type - %d | code - %d", type, code);
	return SCMTA(red, string);
	// return ResultMessageCheat(playerid, code);
}