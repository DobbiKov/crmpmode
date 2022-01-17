CMD:activate(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);

	extract params -> new acc_id; else return SCM(playerid, blue, "[Подсказка] {ffffff}Введите: /activate [ID аккаунта]");

    new query[256];
    format(query, sizeof(query), "SELECT * FROM `deactivated_accs` WHERE `account_id` = '%d'", acc_id);
    mysql_tquery(connects, query, "activate_check_deactivates", "ii", playerid, acc_id);
    return 1;
}

publics activate_check_deactivates(playerid, acc_id)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(!rows)
        return SCM(playerid, red, !"Данный аккаунт не деактивирован!");
    
    new query[256];
    format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pID` = '%d'", acc_id);
    return mysql_tquery(connects, query, "activate_check_account", "ii", playerid, acc_id);  
}


publics activate_check_account(playerid, acc_id)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(!rows)
        return SCM(playerid, red, !"Данного аккаунта не существует!");
    new nickname[MAX_PLAYER_NAME];
    cache_get_field_content(0, "pName", nickname, connects, 144);

    new query[256];
    format(query, sizeof(query), "DELETE FROM `deactivated_accs` WHERE `account_id` = '%d'", acc_id);
    mysql_tquery(connects, query);

    new string[256];
    format(string, sizeof(string), "[A] %s %s[%d] активировал аккаунт игрока %s (№%d)", 
    GetRangAdmin[ PlayerInfo[playerid][bAdmin] ],
    PlayerInfo[playerid][pName],
    playerid,
    nickname,
    acc_id);
    return SCMA(red, string);
}


//
