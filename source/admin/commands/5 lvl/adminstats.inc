CMD:adminstats(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 5) return ShowCommandNotFound(playerid);

    extract params -> new string: to_player[24]; else return SCM(playerid, blue, "[���������] {ffffff}�������: /adminstats [��� ������]");

    if(IsNumeric(to_player))
    {
        new to_playerid = strval(to_player);
        if(!PlayerInfo[to_playerid][pLogin] || !IsPlayerConnected(to_playerid)) return PlayerOffLine(playerid);
        format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
    }

    new query[144];
    format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    mysql_tquery(connects, query, "Off_adminstats", "ds", playerid, to_player);
    return 1;
}

publics Off_adminstats(playerid, to_player[])
{
    new rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        new player_name[MAX_PLAYER_NAME];
        cache_get_field_content(0, "pName", player_name, connects, MAX_PLAYER_NAME);
        new awarns = cache_get_field_content_int(0, "pWarnA");
        new admin = cache_get_field_content_int(0, "bAdmin");
        new bjail = cache_get_field_content_int(0, "bJail");
        new bmute = cache_get_field_content_int(0, "bMute");
        new bban = cache_get_field_content_int(0, "bBan");
        new bwarn = cache_get_field_content_int(0, "bWarn");
        new boffjail = cache_get_field_content_int(0, "bOffJail");
        new boffmute = cache_get_field_content_int(0, "bOffMute");
        new boffban = cache_get_field_content_int(0, "bOffBan");
        new boffwarn = cache_get_field_content_int(0, "bOffWarn");
        new bunban = cache_get_field_content_int(0, "bUnBan");
        new bunwarn = cache_get_field_content_int(0, "bUnWarn");
        new bans = cache_get_field_content_int(0, "bAns");

        if(admin < 1) 
            return SCM(playerid, red, "����� �� �������� ���������������!");
        if(PlayerInfo[playerid][bAdmin] < admin) 
            return SCM(playerid, red, !"�� �� ������ ���������� ���������� ������� ��������������!");


        new string[1024] = "";
        format(string, sizeof(string), "\
        {"cblue"}%s(%d) {ffffff}%s\n\n\
        {"cblue"}���-�� ���������: \t\t\t\t\t{ffffff}%d/3\n\
        {"cblue"}���-�� ������� �� ������: \t\t\t\t{ffffff}%d\n\
        {"cblue"}���-�� ��������� ������� � ��������: \t\t{ffffff}%d\n\
        {"cblue"}���-�� ��������� ������� � �������� �������: \t{ffffff}%d\n\
        {"cblue"}���-�� �������� ���������� ����: \t\t\t{ffffff}%d\n\
        {"cblue"}���-�� �������� ���������� ���� �������: \t{ffffff}%d\n\
        {"cblue"}���-�� �������� ��������������: \t\t\t{ffffff}%d\n\
        {"cblue"}���-�� �������� �������������� �������: \t{ffffff}%d\n\
        {"cblue"}���-�� �������� ���������� ��������: \t\t{ffffff}%d\n\
        {"cblue"}���-�� �������� ���������� �������� �������: \t{ffffff}%d\n\
        {"cblue"}���-�� ������ ���������� ��������: \t\t\t{ffffff}%d\n\
        {"cblue"}���-�� ������ ��������������: \t\t\t{ffffff}%d\n\
        ", 
        GetRangAdmin[admin], admin,
        player_name,
        awarns,
        bans,
        bjail,
        boffjail,
        bmute,
        boffmute,
        bwarn,
        boffwarn,
        bban,
        boffban,
        bunban,
        bunwarn
        );

        ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, !"{"cblue"}���������� ��������������", string, "�������", "");
    }
    else
    {
        return SCM(playerid, red, "������ ������ ���!");
    }
    return 1;
}