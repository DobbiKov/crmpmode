CMD:r(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] < 1 && PlayerInfo[playerid][pJob] == Job_None) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, red, "� ������ ������ � ��� ���������� ����!");

    extract params -> new string: text[144]; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /r [�����]");

	if(CheckAdvertOtherSource(text))
	{
		SendAdminAntiAdvert(playerid, text);
		return 0;
	}

    new string[144];
    format(string, sizeof(string), "[R] %s %s[%d]: %s", (PlayerInfo[playerid][pMember] > 0) ? (PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ]) : (jobs_name[ PlayerInfo[playerid][pJob] ]), PlayerInfo[playerid][pName], playerid, text);
    if(PlayerInfo[playerid][pMember] > 0) 
        SCMR(PlayerInfo[playerid][pMember], green, string);
    else if(PlayerInfo[playerid][pJob] > 0) 
        SCMR(PlayerInfo[playerid][pJob], green, string);

    format(string, sizeof(string), "������� � �����: \"%s\"", text);
    cmd::me(playerid, string);
    return 1;
}

CMD:rb(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] < 1 && PlayerInfo[playerid][pJob] == Job_None) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, red, "� ������ ������ � ��� ���������� ����!");

    extract params -> new string: text[144]; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /rb [�����]");

	if(CheckAdvertOtherSource(text))
	{
		SendAdminAntiAdvert(playerid, text);
		return 0;
	}

    new string[144];
    format(string, sizeof(string), "(( OOC: [R] %s %s[%d]: %s ))", (PlayerInfo[playerid][pMember] > 0) ? (PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ]) : (jobs_name[ PlayerInfo[playerid][pJob] ]), PlayerInfo[playerid][pName], playerid, text);

    if(PlayerInfo[playerid][pMember] > 0) 
        SCMR(PlayerInfo[playerid][pMember], green, string);
    else if(PlayerInfo[playerid][pJob] > 0) 
        SCMR(PlayerInfo[playerid][pJob], green, string);
    
    return 1;
}

CMD:rfsb(playerid, params[])
{
    if(!IsAFSB(playerid)) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][pMember] == TEAM_FSB) return SCM(playerid, red, "�� �� ���������� �� � ���� �� �����������, ����������� ������� ���: /r");
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, red, "� ������ ������ � ��� ���������� ����!");

    extract params -> new string: text[144]; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /rfsb [�����]");

	if(CheckAdvertOtherSource(text))
	{
		SendAdminAntiAdvert(playerid, text);
		return 0;
	}

    new string[144];
    format(string, sizeof(string), "[R] �����. ��������� %s[%d]: %s", PlayerInfo[playerid][pName], playerid, text);
    SCMR(TEAM_FSB, green, string);

    format(string, sizeof(string), "������� � �����: \"%s\"", text);
    cmd::me(playerid, string);
    return 1;
}

CMD:rbfsb(playerid, params[])
{
    if(!IsAFSB(playerid)) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][pMember] == TEAM_FSB) return SCM(playerid, red, "�� �� ���������� �� � ���� �� �����������, ����������� ������� ���: /rb");
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, red, "� ������ ������ � ��� ���������� ����!");

    extract params -> new string: text[144]; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /rbfsb [�����]");

	if(CheckAdvertOtherSource(text))
	{
		SendAdminAntiAdvert(playerid, text);
		return 0;
	}

    new string[144];
    format(string, sizeof(string), "(( OOC: [R] �����. ��������� %s[%d]: %s ))", PlayerInfo[playerid][pName], playerid, text);

    SCMR(TEAM_FSB, green, string);
    
    return 1;
}

CMD:d(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] < 1 || PlayerInfo[playerid][pRang] < 2) return YouCannotUseThisFunc(playerid);
    if(IsAOpg(playerid)) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, red, "� ������ ������ � ��� ���������� ����!");

    extract params -> new string: text[144]; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /d [�����]");

	if(CheckAdvertOtherSource(text))
	{
		SendAdminAntiAdvert(playerid, text);
		return 0;
	}

    new string[144];
    format(string, sizeof(string), "[D] %s %s[%d]: %s", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerInfo[playerid][pName], playerid, text);
    SCMD(0xFF7979AA, string);

    format(string, sizeof(string), "������� � �����: \"%s\"", text);
    cmd::me(playerid, string);
    return 1;
}

CMD:db(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] < 1 || PlayerInfo[playerid][pRang] < 2) return YouCannotUseThisFunc(playerid);
    if(IsAOpg(playerid)) return YouCannotUseThisFunc(playerid);
    if(PlayerInfo[playerid][pMute] > 0) return SCM(playerid, red, "� ������ ������ � ��� ���������� ����!");

    extract params -> new string: text[144]; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /db [�����]");

	if(CheckAdvertOtherSource(text))
	{
		SendAdminAntiAdvert(playerid, text);
		return 0;
	}

    new string[144];
    format(string, sizeof(string), "(( OOC: [D] %s %s[%d]: %s ))", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerInfo[playerid][pName], playerid, text);
    SCMD(0xFF7979AA, string);
    return 1;
}

stock SCMR(fraction, color, text[])
{
    foreach(new i : Player)
    {
        new string[144];
        // format(string, sizeof(string), "DEBUG: id: %d member: %d fraction %d", i, PlayerInfo[i][pMember], fraction);
        // print(string);

        if(PlayerInfo[i][pMember] > 0) 
        {
            // format(string, sizeof(string), "DEBUG: id: %d member: > 0", i);
            // print(string); 

            if(PlayerInfo[i][pMember] == fraction && fraction != TEAM_FSB)
            {
                SCM(i, color, text);
            }
        }
        else if(PlayerInfo[i][pJob] > 0)
        {
            if(PlayerInfo[i][pJob] == fraction)
            {
                SCM(i, color, text);
            } 
        }
        if(IsAFSB(i) && fraction == TEAM_FSB)
        {
            // format(string, sizeof(string), "DEBUG: id: %d FSB R", i);
            // print(string); 
            SCM(i, color, text);
        }
        else if(IsAFSB(i) || PlayerInfo[i][bAdmin] >= 2)
        {
            if(PlayerInfo[i][pTipster] == -1)
            {
                // format(string, sizeof(string), "DEBUG: id: %d tipster -1", i);
                // print(string); 


                // new string[256];
                format(string, sizeof(string), "[%s]: %s", GetMember[fraction], text);
                return SCM(i, color, string);
            }
            
            if(PlayerInfo[i][pJobTipster] == fraction)  
            {


                // new string[256];
                format(string, sizeof(string), "[%s]: %s", jobs_name[fraction], text);
                SCM(i, color, string);
            }

            if(PlayerInfo[i][pTipster] == fraction)
            {
                // format(string, sizeof(string), "DEBUG: id: %d tipster %d, frac %d", i, PlayerInfo[i][pTipster], fraction);
                // print(string);


                // new string[256];
                format(string, sizeof(string), "[%s]: %s", GetMember[fraction], text);
                SCM(i, color, string);
            } 
        }

        
    }
    return 1;
}

stock SCMD(color, text[])
{
    foreach(new i : Player)
    {
        if(PlayerInfo[i][pMember] > 0 && !IsAOpg(i)) 
        {
            SCM(i, color, text);
        }
    }
    return 1;
}