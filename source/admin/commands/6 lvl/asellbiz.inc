CMD:asellbiz(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);
    extract params -> new id, nullPlayer; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /asellbiz [ID бизнесса] [у игрока убирать (0 - нет, 1 - да)]");
    if(nullPlayer < 0 || nullPlayer > 1)
    {
        return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /asellbiz [ID бизнесса] [у игрока убирать (0 - нет, 1 - да)]");
    }
    foreach(new i : Allbusiness)
    {
        if(BusinessInfo[i][bOwned] == 1 && BusinessInfo[i][bID] == id)
        {
            SetPVarInt(playerid, "asellbiz_biz_id", i);
            SetPVarInt(playerid, "asellbiz_nullPlayer", nullPlayer);
            new string[256];
            format(string, sizeof(string), "{FFFFFF}Вы уверенны, что хотите продать бизнесс под номером {"cblue"}%d {FFFFFF}игрока {"cblue"}%s?", BusinessInfo[i][bID], BusinessInfo[i][bOwner]);
            SPD
            (
                playerid,
                D_CMD_ASELLBIZ,
                DIALOG_STYLE_MSGBOX,
                !"{FFFFFF}Продажа бизнесса",
                string,
                "Да", "Нет"
            );
            return 1;
        }
    }
    SCM(playerid, red, !"Бизнесса под таким ID нет, либо им никто не владеет!");
    return 1;
}

publics SletBizABiz(i, playerid)
{
    static rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        new player_id;
        player_id = cache_get_field_content_int(0, "pID");

        new bizoffmess[144];
        format(bizoffmess, sizeof(bizoffmess), "Ваш бизнесс был продан администратором %s.", PlayerInfo[playerid][pName]);

        new sql[1024];
        format(sql, sizeof(sql), "UPDATE `accounts` SET `pBizID` = '-1', `pBizOffMess` = '%s', WHERE `pID` = '%d'", bizoffmess, player_id);
    }
    else
    {
        printf("Залупа (дома)");
    }
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_CMD_ASELLBIZ:{
            if(!response)
            { 
                DeletePVar(playerid, "asellbiz_biz_id");
                DeletePVar(playerid, "asellbiz_nullPlayer");
                return 1;
            }
            else
            {
                new i = GetPVarInt(playerid, "asellbiz_biz_id");
                new nullPlayer = GetPVarInt(playerid, "asellbiz_nullPlayer");
                DeletePVar(playerid, "asellbiz_biz_id");
                DeletePVar(playerid, "asellbiz_nullPlayer");

                BusinessInfo[i][bOwned] = 0;
                BusinessInfo[i][bDays] = 3;
                BusinessInfo[i][bOwner] = EOS;
                format(BusinessInfo[i][bOwner], MAX_PLAYER_NAME, "None");
                UpdateBusiness(i);
                if(nullPlayer == 1)
                {
                    foreach(new j : Player)
                    {
                        if(PlayerInfo[j][pBizID] == BusinessInfo[i][bID])
                        {
                            new string[128];
                            format(string, sizeof(string), "Ваш бизнесс был продан государству администратором %s.", PlayerInfo[playerid][pName]);
                            SCM(j, green, string);

                            PlayerInfo[j][pBizID] = -1;

                            SaveAccounts(j);
                            return 1;
                        }
                    }

                    new sql[144];
                    format(sql, sizeof(sql), "SELECT * FROM `accounts` WHERE `pBizID` = '%d'", BusinessInfo[i][bID]);
                    return mysql_tquery(connects, sql, "SletBizABiz", "ii", i, playerid);
                }
            }
        }
    }
	#if	defined	asellbiz__OnDialogResponse
		return asellbiz__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse asellbiz__OnDialogResponse
#if	defined	asellbiz__OnDialogResponse
	forward asellbiz__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif