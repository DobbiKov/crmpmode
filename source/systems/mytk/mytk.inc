stock ShowMyTk(playerid, targetid)
{
    new string[256];
    format(string, sizeof(string), "\
    {ffffff}Имя: {"cblue"}%s\n\
    {ffffff}Организация: {"cblue"}%s\n\
    {ffffff}Звание/должность: {"cblue"}%s",
    PlayerInfo[targetid][pName],
    GetMember[PlayerInfo[targetid][pMember]],
    (PlayerInfo[targetid][pJob] >= 1) ? (jobs_name[PlayerInfo[targetid][pJob]]) : (PlayerRank[PlayerInfo[targetid][pMember]][PlayerInfo[targetid][pRang]]));
    SetPVarInt(playerid, "mytk_targetid", targetid);
    return ShowPlayerDialog(playerid, D_MYTK, DIALOG_STYLE_MSGBOX, !"{"cblue"}Трудовая книжка", string, !"История", !"Закрыть");
}

stock InviteMyTK(playerid)
{
    new query[256];
    format(query, sizeof(query), "INSERT INTO `org_history` (`date`, `account_id`, `org_id`, `action_type`, `data`) VALUES ('%d', '%d', '%d', '%d', ' ')", gettime(), PlayerInfo[playerid][pID], PlayerInfo[playerid][pMember], org_history_a_t_invite);
    return mysql_tquery(connects, query, "", "");
}

stock UnInviteMyTK(playerid, org_id, reason[])
{
    new query[256];
    format(query, sizeof(query), "INSERT INTO `org_history` (`date`, `account_id`, `org_id`, `action_type`, `data`) VALUES ('%d', '%d', '%d', '%d', '%s')", gettime(), PlayerInfo[playerid][pID], org_id, org_history_a_t_uninvite, reason);
    return mysql_tquery(connects, query, "", "");
}

stock OffUnInviteMyTK(acc_id, org_id, reason[])
{
    new query[256];
    format(query, sizeof(query), "INSERT INTO `org_history` (`date`, `account_id`, `org_id`, `action_type`, `data`) VALUES ('%d', '%d', '%d', '%d', '%s')", gettime(), acc_id, org_id, org_history_a_t_uninvite, reason);
    return mysql_tquery(connects, query, "", "");
}

stock RangUpMyTK(playerid)
{
    new rang_str[12];
    valstr(rang_str, PlayerInfo[playerid][pRang]);
    new query[256];
    format(query, sizeof(query), "INSERT INTO `org_history` (`date`, `account_id`, `org_id`, `action_type`, `data`) VALUES ('%d', '%d', '%d', '%d', '%s')", gettime(), PlayerInfo[playerid][pID], PlayerInfo[playerid][pMember], org_history_a_t_rang_up, rang_str);
    return mysql_tquery(connects, query, "", "");
}
stock RangDownMyTK(playerid)
{
    new rang_str[12];
    valstr(rang_str, PlayerInfo[playerid][pRang]);
    new query[256];
    format(query, sizeof(query), "INSERT INTO `org_history` (`date`, `account_id`, `org_id`, `action_type`, `data`) VALUES ('%d', '%d', '%d', '%d', '%s')", gettime(), PlayerInfo[playerid][pID], PlayerInfo[playerid][pMember], org_history_a_t_rang_down, rang_str);
    return mysql_tquery(connects, query, "", "");
}

stock MWarnMyTK(playerid, org_id, reason[])
{
    new query[256];
    format(query, sizeof(query), "INSERT INTO `org_history` (`date`, `account_id`, `org_id`, `action_type`, `data`) VALUES ('%d', '%d', '%d', '%d', '%s')", gettime(), PlayerInfo[playerid][pID], org_id, org_history_a_t_mwarn, reason);
    return mysql_tquery(connects, query, "", "");
}
stock OffMWarnMyTK(acc_id, org_id, reason[])
{
    new query[256];
    format(query, sizeof(query), "INSERT INTO `org_history` (`date`, `account_id`, `org_id`, `action_type`, `data`) VALUES ('%d', '%d', '%d', '%d', '%s')", gettime(), acc_id, org_id, org_history_a_t_mwarn, reason);
    return mysql_tquery(connects, query, "", "");
}
stock UnMWarnMyTK(playerid)
{
    new query[256];
    format(query, sizeof(query), "INSERT INTO `org_history` (`date`, `account_id`, `org_id`, `action_type`, `data`) VALUES ('%d', '%d', '%d', '%d', ' ')", gettime(), PlayerInfo[playerid][pID], PlayerInfo[playerid][pMember], org_history_a_t_unmwarn);
    return mysql_tquery(connects, query, "", "");
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
		case D_MYTK:
		{
		    if(!response)
            {
                return DeletePVar(playerid,"mytk_targetid");
            }
            new string[512];
            for(new i = 1; i < sizeof(GetMember); i++)
            {
                new temp_string[144];
                format(temp_string, sizeof(temp_string), "{"cblue"}%d. {ffffff}%s\n", i, GetMember[i]);
                strcat(string, temp_string);
            }
            ShowPlayerDialog(playerid, D_MYTK_HISTORY, DIALOG_STYLE_LIST, !"{"cblue"}Трудовая книжка", string, !"Далее", !"Назад");
		}
        case D_MYTK_HISTORY:
        {
            if(!response) return ShowMyTk(playerid, GetPVarInt(playerid, "mytk_targetid"));
            return OrgHistory(playerid, GetPVarInt(playerid, "mytk_targetid"), listitem + 1);
        }
        case D_MYTK_HISTORY_ORG:
        {
            new string[512];
            for(new i = 1; i < sizeof(GetMember); i++)
            {
                new temp_string[144];
                format(temp_string, sizeof(temp_string), "{"cblue"}%d. {ffffff}%s\n", i, GetMember[i]);
                strcat(string, temp_string);
            }
            ShowPlayerDialog(playerid, D_MYTK_HISTORY, DIALOG_STYLE_LIST, !"{"cblue"}Трудовая книжка", string, !"Далее", !"Назад");           
        }
    }
	#if	defined	mytk__OnDialogResponse
		return mytk__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse mytk__OnDialogResponse
#if	defined	mytk__OnDialogResponse
	forward mytk__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

stock OrgHistory(playerid, targetid, org_id)
{
    new query[256];
    format(query, sizeof(query), "SELECT * FROM `org_history` WHERE `account_id` = '%d' AND `org_id` = '%d' ORDER BY id DESC LIMIT 15", PlayerInfo[targetid][pID], org_id);
    return mysql_tquery(connects, query, "show_org_history", "iii", playerid, targetid, org_id); 
}

publics show_org_history(playerid, targetid, org_id)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
    {

        new string[2056];
        for(new i = 0; i < rows; i++)
        {
            new _date, _org_id, action_type, data[256];
            
            _date = cache_get_field_content_int(i, "date");
            _org_id = cache_get_field_content_int(i, "org_id");
            action_type = cache_get_field_content_int(i, "action_type");
            cache_get_field_content(i, "data", data, connects, 256);

            strcat(string, CompileMyTKString(_date, _org_id, action_type, data) );
        }
        new org_name[64];
        format(org_name, sizeof(org_name), "{"cblue"}%s", GetMember[org_id]);
        ShowPlayerDialog(playerid, D_MYTK_HISTORY_ORG, DIALOG_STYLE_MSGBOX, org_name, string, !"Назад", !"");
    }
    else
    {
        new string[512];
        for(new i = 1; i < sizeof(GetMember); i++)
        {
            new temp_string[144];
            format(temp_string, sizeof(temp_string), "{"cblue"}%d. {ffffff}%s\n", i, GetMember[i]);
            strcat(string, temp_string);
        }
        ShowPlayerDialog(playerid, D_MYTK_HISTORY, DIALOG_STYLE_LIST, !"{"cblue"}Трудовая книжка", string, !"Далее", !"Назад");
        return SCM(playerid, red, !"Информация отсутствует!");
    }
    return 1;
}

stock CompileMyTKString(_date, _org_id, action_type, data[])
{
    new string[256];
    switch(action_type)
    {
        case org_history_a_t_invite:
        {
            format(string, sizeof(string), "{ffffff}%s вступил в организацию %s\n", date("%dd.%mm.%yyyy, %hh:%ii:%ss",_date), GetMember[_org_id]);
        }
        case org_history_a_t_uninvite:
        {
            format(string, sizeof(string), "{ffffff}%s был уволен из организации %s. Причина: %s\n", date("%dd.%mm.%yyyy, %hh:%ii:%ss",_date), GetMember[_org_id], data);
        }
        case org_history_a_t_rang_up:
        {
            format(string, sizeof(string), "{ffffff}%s был повышен до должности %s(%d)\n", date("%dd.%mm.%yyyy, %hh:%ii:%ss",_date), PlayerRank[_org_id][strval(data)], strval(data));
        }
        case org_history_a_t_rang_down:
        {
            format(string, sizeof(string), "{ffffff}%s был понижен до должности %s(%d)\n", date("%dd.%mm.%yyyy, %hh:%ii:%ss",_date), PlayerRank[_org_id][strval(data)], strval(data));
        }
        case org_history_a_t_mwarn:
        {
            format(string, sizeof(string), "{ffffff}%s получил выговор. Причина: %s\n", date("%dd.%mm.%yyyy, %hh:%ii:%ss",_date), data);
        }
        case org_history_a_t_unmwarn:
        {
            format(string, sizeof(string), "{ffffff}%s снял выговор\n", date("%dd.%mm.%yyyy, %hh:%ii:%ss",_date));
        }
    }

    return string;
}