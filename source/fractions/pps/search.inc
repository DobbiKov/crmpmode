CMD:search(playerid, params[])
{
    if(!IsAPolice(playerid)) return YouCannotUseThisFunc(playerid);

    extract params -> new to_player; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /search [ID ������]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] != true) return PlayerOffLine(playerid);
    if(to_player == playerid) return SCM(playerid, red, "�� ������� ���� ID.");

    new fmt_dialog[1024], string[144];
    format(string, sizeof(string), "�������(-�) %s", PlayerName(to_player));
    cmd::me(playerid, string);

    format
    (
        string, sizeof(string), 
        "\
        {"cblue"}%s[%d]\n\n\
        {FFFFFF}���������: {"cblue"}%d ��.\n\
        {FFFFFF}������: {"cblue"}%d ��.\n\
        {FFFFFF}�������: {"cblue"}%d ��.\n\n\
        ",
        PlayerInfo[to_player][pName],
        to_player,
        PlayerInfo[to_player][pDrugs],
        PlayerInfo[to_player][pMetall],
        PlayerInfo[to_player][pPatr]
    );
    strcat(fmt_dialog, string);

	new weapons[13][2];
	for(new i = 0; i != 12; i ++)
	{
		GetPlayerWeaponData(to_player, i, weapons[i][0], weapons[i][1]);
		if(weapons[i][0] != 0)
		{
			format(string, 70, "\n������:\t\t%s (%d)\n�������:\t\t%d", gun_name[ weapons[i][0] ],weapons[i][0],weapons[i][1]);
			strcat(fmt_dialog, string);
		}
	}
    return SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{"cblue"}����� ������", fmt_dialog, "�������", "");
}