CMD:take(playerid, params[])
{
    if(!IsAPolice(playerid) && PlayerInfo[playerid][bAdmin] < 2) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /take [ID ������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    //if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID.");

    SPD
    (
        playerid, D_TAKE, DIALOG_STYLE_LIST,
        !"{"cblue"}�������",
        !"{"cblue"}1. {FFFFFF}���������\n{"cblue"}2. {FFFFFF}������\n{"cblue"}3. {FFFFFF}�������\n{"cblue"}4. {FFFFFF}��� ������\n",
        !"������", "������"
    );
    return SetPVarInt(playerid, "take", to_player);
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_TAKE:
        {
            if(!response) DeletePVar(playerid, "take");
            else
            {
                new to_player = GetPVarInt(playerid, "take"), string[144];
                switch(listitem)
                {
                    case 0:
                    {
                        PlayerInfo[to_player][pDrugs] = 0;
                        format(string, sizeof(string), "�����(-�) ��������� � %s", PlayerName(to_player));
                        cmd::me(playerid, string);

                        format(string, sizeof(string), "�� ������ ��������� � %s", PlayerName(to_player));
                        SCM(playerid, blue, string);

                        format(string, sizeof(string), "%s %s ����� � ��� ���������", GetPlayerRank(playerid), PlayerName(playerid));
                        SCM(to_player, blue, string);
                    }
                    case 1:
                    {
                        PlayerInfo[to_player][pMetall] = 0;
                        format(string, sizeof(string), "�����(-�) ������ � %s", PlayerInfo[to_player][pName]);
                        cmd::me(playerid, string);

                        format(string, sizeof(string), "�� ������ ������ � %s", PlayerInfo[to_player][pName]);
                        SCM(playerid, blue, string);

                        format(string, sizeof(string), "%s %s ����� � ��� ������", GetPlayerRank(playerid), PlayerName(playerid));
                        SCM(to_player, blue, string);
                    }
                    case 2:
                    {
                        PlayerInfo[to_player][pPatr] = 0;
                        format(string, sizeof(string), "�����(-�) ������� � %s", PlayerName(to_player));
                        cmd::me(playerid, string);

                        format(string, sizeof(string), "�� ������ ������� � %s", PlayerName(to_player));
                        SCM(playerid, blue, string);

                        format(string, sizeof(string), "%s %s ����� � ��� �������", GetPlayerRank(playerid), PlayerName(playerid));
                        SCM(to_player, blue, string);
                    }
                    case 3:
                    {
                        ResetPlayerWeaponsAC(to_player);
                        format(string, sizeof(string), "�����(-�) ��� ������ � %s", PlayerName(to_player));
                        cmd::me(playerid, string);

                        format(string, sizeof(string), "�� ������ ��� ������ � %s", PlayerName(to_player));
                        SCM(playerid, blue, string);

                        format(string, sizeof(string), "%s %s ����� � ��� ��� ������", GetPlayerRank(playerid), PlayerInfo[playerid][pName]);
                        SCM(to_player, blue, string);
                    }
                }
                SaveAccounts(playerid);
                SaveAccounts(to_player);
                return DeletePVar(playerid, "take");
            }
        }
    }
	#if	defined	cmd_take__OnDialogResponse
		return cmd_take__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse cmd_take__OnDialogResponse
#if	defined	cmd_take__OnDialogResponse
	forward cmd_take__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif