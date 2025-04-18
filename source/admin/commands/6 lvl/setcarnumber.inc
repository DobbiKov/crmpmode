CMD:setcarnumber(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

    extract params -> new string: to_player[32], string: number[32]; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /setcarnumber [NickName ������] [�����]");
    if(strlen(number) < 0 || strlen(number) > 32) return SCM(playerid, red, "����� ������ �� ����� 0 � �� ����� 32.");
 
    if(IsNumeric(to_player))
    {
        new to_playerid = strval(to_player);
        if(!PlayerInfo[to_playerid][pLogin] || !IsPlayerConnected(to_playerid)) return PlayerOffLine(playerid);
        format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
    }

    foreach(new i : Player)
    {
        if(!strcmp(PlayerInfo[i][pName], to_player, false))
        {
            if(PlayerInfo[i][pCarID] == -1) return SCM(playerid, red, "� ������� ������ ��� ����������.");
            if(player_ownable_car[i] == -1) return SCM(playerid, red, "������ ���� ������� ������ �� �������.");

            ownable_car[player_ownable_car[i]][oc_number] = EOS;
            strcat(ownable_car[player_ownable_car[i]][oc_number], number);
            UpdateDynamic3DTextLabelText(ownable_car_label[player_ownable_car[i]], 0xFFFFFFFF, ownable_car[player_ownable_car[i]][oc_number]);

            new sql[144];
            format(sql, sizeof(sql), "UPDATE `ownable_cars` SET `number` = '%s' WHERE `id` = '%d'", number, ownable_car[player_ownable_car[i]][oc_id]);
            mysql_tquery(connects, sql, "", "");

            format(sql, sizeof(sql), "�� ������ ������ %s ������ �� ������ ���������: %s", to_player, number);
            SCM(playerid, white, sql);

            SaveOwnableCar(i);
            return 1;
        }
    }
    // new sql[144];
    // format(sql, sizeof(sql), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    // mysql_tquery(connects, sql, "CheckPlayerForSetCarNumber", "iss", playerid, to_player, number);
    return SCM(playerid, red, !"������ ������ ���!");
}

// publics CheckPlayerForSetCarNumber(playerid, to_player[], number[])
// {
//     static rows[2];
//     cache_get_data(rows[0], rows[1]);
//     if(rows[0])
//     {
//         static carid, owner_id;
//         carid = cache_get_field_content_int(0, "pCarID");
//         owner_id = cache_get_field_content_int(0, "pID");
//         if(carid == -1) return SCM(playerid, red, "� ������� ������ ��� ������� ����������.");

//         new sql[144];
//         format(sql, sizeof(sql), "UPDATE `ownable_cars` SET `number` = '%s' WHERE `owner_id` = '%d'", number, owner_id);
//         mysql_tquery(connects, sql, "", "");

//         format(sql, sizeof(sql), "�� ������ ������ %s ������ �� ������ ���������: %s", to_player, number);
//         SCM(playerid, white, sql);
//     }
//     else
//     {
//         return SCM(playerid, red, "������ ������ ���.");
//     }
//     return 1;
// }