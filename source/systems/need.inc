stock getNeeds(playerid, needType)
{
    switch(needType)
    {
        case need_drink: return PlayerInfo[playerid][pNeedDrink];
        case need_eat: return PlayerInfo[playerid][pNeedEat];
        case need_toilet: return PlayerInfo[playerid][pNeedToilet];
        case need_wash: return PlayerInfo[playerid][pNeedWash];
    }
    return -1;
}

stock setNeeds(playerid, needType, needValue)
{
    if(needValue < 0) needValue = 0;
    if(needValue > 100) needValue = 100;
    switch(needType)
    {
        case need_drink: PlayerInfo[playerid][pNeedDrink] = needValue;
        case need_eat: PlayerInfo[playerid][pNeedEat] = needValue;
        case need_toilet: PlayerInfo[playerid][pNeedToilet] = needValue;
        case need_wash: PlayerInfo[playerid][pNeedWash] = needValue;
    }
}

publics minuteupdate()
{
	new hours,minutes,seconds;
    gettime(hours, minutes, seconds);

    foreach(new i : Player)
    if(minutes == 5 || minutes == 15 || minutes == 30 || minutes == 45 || minutes == 55)
    {
        new Float:health;
        setNeeds(i, need_toilet, getNeeds(i, need_toilet) - 5);
        if(getNeeds(i, need_toilet) < 40) 
        {
            GetPlayerHealth(i, health);
            PlayerInfo[i][pHP] = health - 3;
            SetPlayerHealth(i, health - 3);
            SCM(i, need, "�� ������ � ������!");
        }

        setNeeds(i, need_eat, getNeeds(i, need_eat) - 4);
        if(getNeeds(i, need_eat) < 40) 
        {
            SCM(i, need, "�� �������������! �������� �������� ��� ������ ����� � 24/7. ������ ��������� ���������: /need");
            PlayerPlaySound(i, 40403, 0.0, 0.0, 0.0);
            GetPlayerHealth(i, health);
            PlayerInfo[i][pHP] = health - 3;
            SetPlayerHealth(i, health - 3);
        }
        setNeeds(i, need_drink, getNeeds(i, need_drink) - 3);
        if(getNeeds(i, need_drink) < 40)
        {
            GetPlayerHealth(i, health);
            PlayerInfo[i][pHP] = health - 3;
            SetPlayerHealth(i, health - 3);
            SCM(i, need, "�� ������ ����! �������� �������� ��� ������ ����� � 24/7. ������ ��������� ���������: /need");
        }

        setNeeds(i, need_wash, getNeeds(i, need_wash) - 3);
        if(getNeeds(i, need_wash) < 40)
        {
            cmd::do(i, "����� ������...");
            SCM(i, need, "�� ��������� ����� �������! �������� ���� ��� ��������� ���� � ����. ������ ��������� ���������: /need");
        }       
    }
    #if defined needs__minuteupdate
        return needs__minuteupdate();
    #else
        return 1;
    #endif
}
#if defined _ALS_minuteupdate
    #undef minuteupdate
#else
    #define _ALS_minuteupdate
#endif

#define minuteupdate needs__minuteupdate
#if defined needs__minuteupdate
    forward needs__minuteupdate();
#endif

CMD:need(playerid)
{
    new fmt_dialog[256];
    format(fmt_dialog, sizeof(fmt_dialog), "�������: \t%d%%\n�����: \t%d%%\n������: \t%d%%\n�������: \t%d%%", PlayerInfo[playerid][pNeedEat], PlayerInfo[playerid][pNeedDrink], PlayerInfo[playerid][pNeedToilet], PlayerInfo[playerid][pNeedWash]);
    SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}�����", fmt_dialog, "�������", "");
    return 1;
}