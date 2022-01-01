CMD:asellhome(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);
    extract params -> new id, nullPlayer; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /asellhome [ID дома] [у игрока убирать (0 - нет, 1 - да)]");
    if(nullPlayer < 0 || nullPlayer > 1)
    {
        return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /asellhome [ID бизнесса] [у игрока убирать (0 - нет, 1 - да)]");
    }

    new h = -1;
    foreach(new i : Allhouses) 
    {
        if(HouseInfo[i][hID] == id && HouseInfo[i][hOwned] == 1)
        {
            h = i;
            break;
        }
    }
    if(h == -1)
    {
        return SCM(playerid, red, !"Дома под таким ID нет, либо им никто не владеет!");
    }
    SetPVarInt(playerid, "asellhome_house_id", h);
    SetPVarInt(playerid, "asellhome_nullplayer", nullPlayer);

    new string[256];
    format(string, sizeof(string), "{ffffff}Вы уверенны, что хотите продать дом под номером {"cblue"}%d {ffffff}игрока {"cblue"}%s{ffffff}?", HouseInfo[h][hID], HouseInfo[h][hOwner]);
    SPD
    (
        playerid,
        D_CMD_ASELLHOME,
        DIALOG_STYLE_MSGBOX,
        !"Продажа дома игрока",
        string,
        "Да", "Нет"
    );

    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_CMD_ASELLHOME:{
            if(!response)
            { 
                DeletePVar(playerid, "asellhome_house_id");
                DeletePVar(playerid, "asellhome_nullplayer");
                return 1;
            }
            else
            {
                new h = GetPVarInt(playerid, "asellhome_house_id");
                new nullPlayer = GetPVarInt(playerid, "asellhome_nullplayer");
                DeletePVar(playerid, "asellhome_house_id");
                DeletePVar(playerid, "asellhome_nullplayer");

                HouseInfo[h][hOwned] = 0;
                HouseInfo[h][hDays] = 3;
                HouseInfo[h][hOwner] = EOS;
                strcat(HouseInfo[h][hOwner], "None");
                BuyHouse(h);

                if(nullPlayer == 1)
                {
                    foreach(new i : Player)
                    {
                        if(PlayerInfo[i][pHomeID] == HouseInfo[h][hID])
                        {
                            new string[144];
                            format(string, sizeof(string), "{ffffff}Ваш дом был продан государству администратором %s.", PlayerInfo[playerid][pName]);
                            SCM(playerid, white, string);

                            PlayerInfo[i][pHomeID] = -1;
                            SaveAccounts(i);
                            DestroyOwnableCar(i);
                            return TotalFreeHouses++;
                        }
                    }

                    new sql[144];
                    format(sql, sizeof(sql), "SELECT * FROM `accounts` WHERE `pHomeID` = '%d'", HouseInfo[h][hID]);
                    return mysql_tquery(connects, sql, "SletHouseASellHouse", "ii", h, playerid);
                }
            }
        }
    }
	#if	defined	asellhome__OnDialogResponse
		return asellhome__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse asellhome__OnDialogResponse
#if	defined	asellhome__OnDialogResponse
	forward asellhome__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

publics SletHouseASellHouse(i, playerid)
{
    static rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        new player_id;
        player_id = cache_get_field_content_int(0, "pID");

        new houseoffmess[144];
        format(houseoffmess, sizeof(houseoffmess), "Ваш дом был продан государству администратором %s.", PlayerInfo[playerid][pName]);

        new sql[144];
        format(sql, sizeof(sql), "UPDATE `accounts` SET `pHomeID` = '-1', `pHouseOffMess` = '%s' WHERE `pID` = '%d'", houseoffmess, player_id);
        mysql_tquery(connects, sql, "", "");
    }
    else
    {
        printf("Залупа (дома)");
    }
    return 1;
}