publics Restart(playerid)
{
	new string[128];
	format(string, sizeof(string), "��������! ����� %d ������ ���������� ������������ �������!", restart_time);
	SCMTA(red, string);
	restart_time--;
	if(restart_time == 0)
	{
		KillTimer(_restart_timer);
	    SCMTA(red, "��������! ���������� ������������ �������!");
		SetTimer("Restart_", 5000, false);
	}
	return 1;
}
publics Restart_()
{
	foreach(new i: Player)
	{
	    if(PlayerInfo[i][pLogin] != false)
			SaveAccounts(i);
	}
	// kick_all_players();
	KillTimer(_restart_timer);
	SendRconCommand("gmx");
	return GameModeExit();
}
stock Restart_Server(playerid)
{
	if(GetPVarInt(playerid, "restart") == 1)
	{
		return SetTimer("Restart_", 5000, false);
	}

	SCMTA(red, "��������! ����� 5 ����� ���������� ������������ �������!");

	_restart_timer = SetTimer("Restart", 60000, true);

	SetPVarInt(playerid, "restart", 1);

	return 1;
}

publics minuteupdate()
{
    new hour, minute, second;
    gettime(hour, minute, second);

	if(hour == 4 && minute == 0)
	{
	    SCMTA(red, "��������! ����� 5 ����� ��������� ����������� ������������ �������!");
	}
	if(hour == 4 && minute == 1)
	{
	    SCMTA(red, "��������! ����� 4 ������ ��������� ����������� ������������ �������!");
	}
	if(hour == 4 && minute == 2)
	{
	    SCMTA(red, "��������! ����� 3 ������ ��������� ����������� ������������ �������!");
	}
	if(hour == 4 && minute == 3)
	{
	    SCMTA(red, "��������! ����� 2 ������ ��������� ����������� ������������ �������!");
	}
	if(hour == 4 && minute == 4)
	{
	    SCMTA(red, "��������! ����� 1 ������ ��������� ����������� ������������ �������!");
	}
	if(hour == 4 && minute == 5)
	{
	    SCMTA(red, "��������! ���������� ����������� ������������ �������!");
	    foreach(new i : Player)
	    {
			if(PlayerInfo[i][pLogin] != false)
	        	SaveAccounts(i);
	    }
		GameTextForAll("~r~SERVER IS RESTARTING", 9000, 5);
		kick_all_players();
	    SetTimer("TehRestart", 5000, false);
	}
    #if defined gmx__minuteupdate
        return gmx__minuteupdate();
    #else
        return 1;
    #endif
}
#if defined _ALS_minuteupdate
    #undef minuteupdate
#else
    #define _ALS_minuteupdate
#endif

#define minuteupdate gmx__minuteupdate
#if defined gmx__minuteupdate
    forward gmx__minuteupdate();
#endif

publics TehRestart()
{
    GameModeExit();
}

CMD:restart(playerid)
{
	if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);
	return Restart_Server(playerid);
}