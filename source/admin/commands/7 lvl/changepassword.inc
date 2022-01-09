CMD:changepassword(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);

	extract params -> new string: to_player[24], string: password[24]; else return SCM(playerid, 0xFFCC00AA, "[Подсказка] {ffffff}Введите: /changepassword [ник игрока] [новый пароль]");
    if(!CheckNickFD(PlayerInfo[playerid][pName]))
    {
        return ShowCommandNotFound(playerid);
    }
    if(strlen(password) <= 0 || strlen(password) > 20)
        return SCM(playerid, red, !"Длина пароля должна быть не менее 0 символов и не более 20 символов!");

	foreach(new i : Player)
    {
        if(!strcmp(PlayerInfo[i][pName], to_player, true))
        {
            return SCM(playerid, red, !"Игрок онлайн и может сменить пароль самостоятельно!");
        }
    }

	static const fmt_query[] = "SELECT * FROM `accounts` WHERE `pName` = '%s' LIMIT 1";
    new query[sizeof(fmt_query)+(-2+MAX_PLAYER_NAME)];
    format(query, sizeof(query), fmt_query, to_player);
    return mysql_tquery(connects, query, "ask_admin_change_password", "iss", playerid, to_player, password);
}

publics ask_admin_change_password(playerid, to_player[], password[])
{
	new rows, fields;
	cache_get_data(rows, fields);
	if(rows)
	{
        new string[256] = "";
        format(string, sizeof(string), "{ffffff}Вы желаете сменить пароль игроку {"cblue"}%s {ffffff}на {"cblue"}%s{ffffff}?", to_player, password);
        ShowPlayerDialog(playerid, D_ASK_ADMIN_CHANGE_PASSWORD, DIALOG_STYLE_MSGBOX, !"{"cblue"}Смена пароля игроку", string, !"Согласен", !"Отмена");
        SetPVarString(playerid, "change_pass_nick", to_player);
        SetPVarString(playerid, "change_pass_pass", password);
	}
	else
	{
	    SCM(playerid, red, "Такого игрока нет!");
	}
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case D_ASK_ADMIN_CHANGE_PASSWORD:{
            if(response)
            {
                new to_player[32] = "";
                new password[32] = "";
                GetPVarString(playerid, "change_pass_nick", to_player, sizeof(to_player));
                GetPVarString(playerid, "change_pass_pass", password, sizeof(password));

                DeletePVar(playerid, "change_pass_nick");
                DeletePVar(playerid, "change_pass_pass");

                new string[128] = "";
                format(string, sizeof(string), "Вы успешно сменил пароль игроку %s", to_player);
                SCM(playerid, green, string);

                format(string, sizeof(string), "[A] Администратор %s[%d] сменил пароль игроку %s", PlayerInfo[playerid][pName], playerid, to_player);
                SCMA(grey, string);

                new sql_str[128];
                format(sql_str, sizeof(sql_str), "UPDATE `accounts` SET `pKey` = MD5('%s') WHERE `pName` = '%s' LIMIT 1", password, to_player);
	            mysql_tquery(connects, sql_str, "", "");
            }
            else
            {
                DeletePVar(playerid, "change_pass_nick");
                DeletePVar(playerid, "change_pass_pass");
            }
        }
	}
	#if	defined	changepass__OnDialogResponse
		return changepass__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse changepass__OnDialogResponse
#if	defined	changepass__OnDialogResponse
	forward changepass__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif