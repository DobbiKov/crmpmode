CMD:deactivate(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);

	extract params -> new acc_id, string:_reason[256]; else return SCM(playerid, blue, "[���������] {ffffff}�������: /deactivate [ID ��������] [�������]");

    new query[256];
    format(query, sizeof(query), "SELECT * FROM `deactivated_accs` WHERE `account_id` = '%d'", acc_id);
    mysql_tquery(connects, query, "deactivate_check_deactivates", "iis", playerid, acc_id, _reason);
    return 1;
}

publics deactivate_check_deactivates(playerid, acc_id, _reason[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
        return SCM(playerid, red, !"������ ������� ��� �������������!");
    
    new query[256];
    format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pID` = '%d'", acc_id);
    return mysql_tquery(connects, query, "deactivate_check_account", "iis", playerid, acc_id, _reason);    
}

publics deactivate_check_account(playerid, acc_id, _reason[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(!rows)  
        return SCM(playerid, red, !"������ �������� �� ����������!");
    
    new adminlvl, nickname[MAX_PLAYER_NAME];
    adminlvl = cache_get_field_content_int(0, "bAdmin");
    cache_get_field_content(0, "pName", nickname, connects, 256);

    if(adminlvl >= PlayerInfo[playerid][bAdmin])
        return SCM(playerid, red, !"�� �� ������ �������������� ������ �������!");

    new string[512];
    format(string, sizeof(string), "INSERT INTO `deactivated_accs` (`account_id`, `date`, `reason`, `admin_id`) VALUES ('%d', '%d', '%s', '%d')", acc_id, gettime(), _reason, PlayerInfo[playerid][pID]);
    mysql_tquery(connects, string, "", ""); 

    format(string, sizeof(string), "[A] %s %s[%d] ������������� ������� ������ %s (�%d)", 
    GetRangAdmin[ PlayerInfo[playerid][bAdmin] ],
    PlayerInfo[playerid][pName],
    playerid,
    nickname,
    acc_id);
    return SCMA(red, string);
}

publics CheckDeactivates(playerid)
{
    new rows, fields;
    cache_get_data(rows, fields);  
    if(rows)
    {
        new _reason[144];
        cache_get_field_content(0, "reason", _reason, connects, 144);

        new string_title[64];
        format(string_title, sizeof(string_title), "{"cblue"}����������: ������ �%d", server_num);

        new string[1024];
        format(string, sizeof(string), 
            "{ffffff}��������! ��� ������� {"cblue"}%s {ffffff}��� {"cred"}������������� {ffffff}�� %s �������.\n\
            {ffffff}�������: %s", 
            PlayerInfo[playerid][pName], server_num,
            _reason);
        ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, string_title, string, !"������", !"����");
        return NewKick(playerid);
    }
    else
    {
        new querybans[256];
        format(querybans, sizeof(querybans), "SELECT * FROM `bans` WHERE `Nick` = '%s'", PlayerInfo[playerid][pName]);
        return mysql_function_query(connects, querybans, true, "CheckBan", "d", playerid);
    }
}