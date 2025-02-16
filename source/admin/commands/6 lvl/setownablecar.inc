CMD:setownablecar(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

    extract params -> new string: to_player[32], model_id, cost_oc_car; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /setownablecar [NickName ������] [������ ����] [��������� ����]");
    if(model_id < 400 || model_id > 611) return SCM(playerid, red, "������ ���� �� ����� 400 � �� ����� 611.");

    if(IsNumeric(to_player))
    {
        new to_playerid = strval(to_player);
        if(!PlayerInfo[to_playerid][pLogin] || !IsPlayerConnected(to_playerid)) return PlayerOffLine(playerid);
        format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
    }
    // foreach(new i : Player)
    // {
    //     if(!strcmp(PlayerInfo[i][pName], to_player, false))
    //     {
    //         if(PlayerInfo[i][pCarID] != -1) return SCM(playerid, red, "� ������� ������ ������� ����.");

    //         new query[120];
    //         format
    //         (
    //             query, sizeof query,
    //             "INSERT INTO `ownable_cars` (`owner_id`,`model_id`,`color`,`cost_car`) VALUES ('%d','%d','%d, %d', '%d')",
    //             PlayerInfo[playerid][pID],
    //             model_id,
    //             0,0,
    //             cost_oc_car
    //         );
    //         mysql_tquery(connects, query, "", "");
    //         PlayerInfo[i][pCarID] = model_id;
    //         SaveAccounts(playerid);

    //         format(query, sizeof(query), "�� ������ ������ %s ������ ��������� [������: %d] [���������: %d]", to_player, model_id, cost_oc_car);
    //         SCM(playerid, white, query);
    //         return 1;
    //     }
    // }
    new sql[144];
    format(sql, sizeof(sql), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    mysql_tquery(connects, sql, "CheckPlayerForSetOwnableCar", "isii", playerid, to_player, model_id, cost_oc_car);
    return 1;
}

publics CheckPlayerForSetOwnableCar(playerid, to_player[], model_id, cost_oc_car)
{
    static rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        static owner_id, adminlvl;
        owner_id = cache_get_field_content_int(0, "pID");
        adminlvl = cache_get_field_content_int(0, "bAdmin");

        if(PlayerInfo[playerid][bAdmin] < adminlvl)
            return SCM(playerid, red, !"�� �� ������ ������ ���� ������� ������!");
            
        new query[256];
        format
        (
            query, sizeof query,
            "SELECT * FROM `ownable_cars` WHERE `owner_id` = '%d' ORDER BY id DESC",
            owner_id
        );
        mysql_tquery(connects, query, "setowncar_check_own_cars", "dsdddd", playerid, to_player, model_id, cost_oc_car, owner_id, adminlvl);
    }
    else
    {
        return SCM(playerid, red, "������ ������ ���.");
    }
    return 1;
}

publics setowncar_check_own_cars(playerid, to_player[], model_id, cost_oc_car, owner_id, adminlvl)
{
    static rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        new _amount;
        for(new i = 0; i < rows[0]; i++)
        {
            _amount++;
        }
        if(_amount >= 2 && adminlvl < 7 && !CheckFD(playerid))
            return SCM(playerid, red, !"� ������ ��� ������� ��� ��� ����� ������������ �������.");
        if(_amount >= 3 && adminlvl < 8 && !CheckNickFD(to_player) && !CheckFD(playerid))
            return SCM(playerid, red, !"� ������ ��� ������� ��� ��� ����� ������������ �������.");
    }
    new query[120];
    format
    (
        query, sizeof query,
        "INSERT INTO `ownable_cars` (`owner_id`,`model_id`,`color`,`cost_car`) VALUES ('%d','%d','%d, %d', '%d')",
        owner_id,
        model_id,
        0,0,
        cost_oc_car
    );
    mysql_tquery(connects, query, "", "");

    format(query, sizeof(query), "UPDATE `accounts` SET `pCarID` = '%d' WHERE `pName` = '%s'", model_id, to_player);
    mysql_tquery(connects, query, "", "");

    format(query, sizeof(query), "�� ������ ������ %s ������ ��������� [������: %d] [���������: %d]", to_player, model_id, cost_oc_car);
    SCM(playerid, white, query);

    foreach(new i : Player)
    {
        if(!strcmp(PlayerInfo[i][pName], to_player))
        {
            if(PlayerInfo[i][pCarID] == -1)
            {   
                PlayerInfo[i][pCarID] = model_id;
                return 1;
            }
        }
    }

    return 1;
}