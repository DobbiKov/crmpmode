#define AP_VOTE_ID 0

#include "../source/systems/apvotes/apvote.inc"
#include "../source/systems/apvotes/apvotevars.inc"
#include "../source/systems/apvotes/playervote.inc"

stock ShowAPVotePanel(playerid)
{
    if(GetPVarInt(playerid, "donate_access") == 1) return SCM(playerid, red, !"Диалога ID 127 не обнаружено!");

    new open_close[64] = "{"cgreen"}открыто";
    if(VoteInfo[AP_VOTE_ID][voteIsOpen] == 0)
        format(open_close, sizeof(open_close), "{"cred"}закрыто");
    new string[512];
    format(string, sizeof(string), "\
    {"cblue"}1. {ffffff}Название мероприятия ({"cblue"}%s{ffffff})\n\
    {"cblue"}2. {ffffff}Достуный игровой уровень ({"cblue"}%d{ffffff})\n\
    {"cblue"}3. {ffffff}Открыть/закрыть голосование (%s)\n\
    {"cblue"}4. {ffffff}Изменить координаты голосования\n\
    {"cblue"}5. {ffffff}Варианты ответов голосований\n\
    {"cblue"}6. {ffffff}Очистить голосования игроков (для создания нового)\n\
    {"cblue"}7. {ffffff}Посмотреть статистику голосов\n\
    ",
    VoteInfo[AP_VOTE_ID][voteName],
    VoteInfo[AP_VOTE_ID][voteLvlAccess],
    open_close
    );
    ShowPlayerDialog(playerid, D_APVOTES_SETTINGS, DIALOG_STYLE_LIST, !"{"cblue"}Настройки голосования", string, !"Далее", !"Назад");
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_APVOTES_SETTINGS:
        {
            if(!response) return ShowApanel(playerid);
            switch(listitem)
            {
                case 0: return ShowAPVoteChangeName(playerid);
                case 1: return ShowAPVoteChangeLevelAccess(playerid);
                case 2:{
                    VoteInfo[AP_VOTE_ID][voteIsOpen] = (VoteInfo[AP_VOTE_ID][voteIsOpen] == 0) ? 1 : 0;
                    SaveAPVotes(AP_VOTE_ID);
                    return ShowAPVotePanel(playerid);
                }
                case 3: return ShowAPVoteChangeCoords(playerid);
                case 4: return ShowAPVoteVars(playerid);
                case 5: return ShowAPVoteClearPlayerVotes(playerid);
                case 6: return ShowAPVotesStats(playerid);
            }
        }
        case D_APVOTES_CHANGE_COORDS:
        {
            if(!response) return ShowAPVotePanel(playerid);
            new Float:posX, Float:posY, Float:posZ;
            GetPlayerPos(playerid, posX, posY, posZ);

            VoteInfo[AP_VOTE_ID][vote_X] = posX;
            VoteInfo[AP_VOTE_ID][vote_Y] = posY;
            VoteInfo[AP_VOTE_ID][vote_Z] = posZ;

            SaveAPVotes(AP_VOTE_ID);
            SCM(playerid, blue, !"Вы успешно изменили координаты голосования!");
            return ShowAPVotePanel(playerid);
        }
        case D_APVOTES_CHANGE_NAME:
        {
            if(!response) return ShowAPVotePanel(playerid);
            
            format(VoteInfo[AP_VOTE_ID][voteName], 64, "%s", inputtext);

            SaveAPVotes(AP_VOTE_ID);
            SCM(playerid, blue, !"Вы успешно изменили название голосования!");
            return ShowAPVotePanel(playerid);
        }
        case D_APVOTES_CHANGE_LVL_ACCESS:
        {
            if(!response) return ShowAPVotePanel(playerid);
            
            VoteInfo[AP_VOTE_ID][voteLvlAccess] = listitem + 1;

            SaveAPVotes(AP_VOTE_ID);
            SCM(playerid, blue, !"Вы успешно изменили доступный уровень для голосования!");
            return ShowAPVotePanel(playerid);
        }
        case D_APVOTES_VARS:
        {
            if(!response) return ShowAPVotePanel(playerid);
            if(listitem == 0)
            {
                if(vote_totalvotevars[AP_VOTE_ID] >= 10)
                {
                    SCM(playerid, red, !"У вас уже имеется 10 вариантов ответов для голосвания!");
                    return ShowAPVoteVars(playerid);
                }
                return ShowAPVoteCreateVar(playerid);
            }
            return ShowAPVoteVarInfo(playerid, AP_VOTE_ID, dialog_listitem_values[playerid][listitem]);
        }
        case D_APVOTES_VAR_INFO:
        {
            if(!response) return ShowAPVoteVars(playerid);

            new vote_i = dialog_listitem_values[playerid][0];
            new var_id = dialog_listitem_values[playerid][1];

            switch(listitem)
            {
                case 0: return ShowAPVoteChangeVarName(playerid, vote_i, var_id);
                case 1: return ShowAPVoteDeleteVar(playerid, vote_i, var_id);
            }
        }
        case D_APVOTES_CHANGE_VAR_NAME:
        {
            new vote_i = dialog_listitem_values[playerid][0];
            new var_id = dialog_listitem_values[playerid][1];

            if(!response) return ShowAPVoteVarInfo(playerid, vote_i, var_id);

            if(!strlen(inputtext) || strlen(inputtext) > 32)
            {
                return ShowAPVoteChangeVarName(playerid, vote_i, var_id);
            }
            format(VoteVarInfo[vote_i][var_id][voteVarName], 32, "%s", inputtext);
            SaveAPVotes(vote_i);
            return ShowAPVoteVars(playerid);
        }
        case D_APVOTES_CREATE_VAR:
        {
            if(!response) return ShowAPVoteVars(playerid);

            if(!strlen(inputtext) || strlen(inputtext) > 32)
                return ShowAPVoteCreateVar(playerid);
            
            new query[144];
            format(query, sizeof(query), "INSERT INTO `apvotevars` (`vote_id`, `var_name`) VALUES ('%d', '%s')", VoteInfo[AP_VOTE_ID][voteID], inputtext);
            mysql_tquery(connects, query, "", "");

            format(query, sizeof(query), "SELECT * FROM `apvotevars` WHERE `vote_id` = '%d'", VoteInfo[AP_VOTE_ID][voteID]);
            mysql_tquery(connects, query, "LoadAPVoteVars", "i", AP_VOTE_ID);

            return ShowAPVotePanel(playerid);
        }
        case D_APVOTES_DELETE_VAR:
        {
            new vote_i = dialog_listitem_values[playerid][0];
            new var_id = dialog_listitem_values[playerid][1];

            if(!response) return ShowAPVoteVarInfo(playerid, vote_i, var_id);

            new query[144];
            format(query, sizeof(query), "DELETE FROM `apvotevars` WHERE `id` = '%d'", VoteVarInfo[vote_i][var_id][voteVarID]);
            mysql_query(connects, query);

            format(query, sizeof(query), "DELETE FROM `apvotes` WHERE `vote_var_id` = '%d'", VoteVarInfo[vote_i][var_id][voteVarID]);
            mysql_tquery(connects, query);

            ClearAPVoteVars(vote_i);

            format(query, sizeof(query), "SELECT * FROM `apvotevars` WHERE `vote_id` = '%d'", VoteInfo[vote_i][voteID]);
            mysql_tquery(connects, query, "LoadAPVoteVars", "i", vote_i);
            
            SCM(playerid, blue, !"Вы успешно удалили данный вариант ответа!");

            return ShowAPVotePanel(playerid);
        }
        case D_APVOTES_CLEAR_PLAYER_VOTES:
        {
            if(!response) return ShowAPVotePanel(playerid);

            new query[144];
            format(query, sizeof(query), "DELETE FROM `apvotes` WHERE `vote_id` = '%d'", VoteInfo[AP_VOTE_ID][voteID]);
            mysql_tquery(connects, query);

            new string[144];
            format(string, sizeof(string), "[A] %s[%d] очистил голосования всех игроков.", PlayerInfo[playerid][pName], playerid);
            return SCMA(grey, string);
        }
    }
	#if	defined	apvotes__OnDialogResponse
		return apvotes__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse apvotes__OnDialogResponse
#if	defined	apvotes__OnDialogResponse
	forward apvotes__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif



stock ShowAPVoteChangeCoords(playerid)
{
    ShowPlayerDialog
    (
        playerid, 
        D_APVOTES_CHANGE_COORDS, 
        DIALOG_STYLE_MSGBOX, 
        !"{"cblue"}Смена координат голосования", 
        !"{ffffff}Вы желаете изменить координаты голосвания, на те, в которых вы находитесь в данный момент?", 
        !"Да", 
        !"Нет"
    );
    return 1;
}
stock ShowAPVoteChangeLevelAccess(playerid)
{
    new string[2048];
    for(new i = 1; i <= 30; i++)
    {
        new temp_string[32];
        format(temp_string, sizeof(temp_string), "{"cblue"}%d. {ffffff}%d уровень\n", i, i);
        strcat(string, temp_string);
    }
    ShowPlayerDialog
    (
        playerid, 
        D_APVOTES_CHANGE_LVL_ACCESS, 
        DIALOG_STYLE_LIST, 
        !"{"cblue"}Смена доступного уровня для голосвания", 
        string, 
        !"Сменить", 
        !"Назад"
    );
    return 1;
}

stock ShowAPVoteChangeName(playerid)
{
    ShowPlayerDialog
    (
        playerid, 
        D_APVOTES_CHANGE_NAME, 
        DIALOG_STYLE_INPUT, 
        !"{"cblue"}Смена названия голосования", 
        !"{ffffff}Вы желаете изменить название голосвания?\nВ таком случае введите новое название в полне ниже:", 
        !"Сменить", 
        !"Назад"
    );
    return 1;
}

stock ShowAPVoteVars(playerid)
{
    new string[1024] = "{"cgreen"}Создать новый вариант\n";

    if(vote_totalvotevars[AP_VOTE_ID] >= 10)
        format(string, sizeof(string), "{"cred"}У вас уже имеется 10 вариантов\n");
    
    for(new i = 0; i < MAX_APVOTEVARS; i++)
    {
        if(VoteVarInfo[AP_VOTE_ID][i][voteVarID] < 1)
            continue;

        dialog_listitem_values[playerid][i+1] = i; 
        new temp_string[64];
        format(temp_string, sizeof(temp_string), "{ffffff}%s\n", VoteVarInfo[AP_VOTE_ID][i][voteVarName]);
        strcat(string, temp_string);
    }
    ShowPlayerDialog(playerid, D_APVOTES_VARS, DIALOG_STYLE_LIST, !"{"cblue"}Варианты ответов голосования", string, !"Изменить", !"Назад");
    return 1;
}

stock ShowAPVoteCreateVar(playerid)
{
    ShowPlayerDialog
    (
        playerid, 
        D_APVOTES_CREATE_VAR, 
        DIALOG_STYLE_INPUT, 
        !"{"cblue"}Создание нового варианта ответа голосования", 
        !"{ffffff}Введите новый вариант ответа:", 
        !"Создать", 
        !"Назад"
    );
    return 1;
}

stock ShowAPVoteDeleteVar(playerid, vote_i, var_id)
{
    new string[256];
    format(string, sizeof(string), "{ffffff}Вы уверенны, что хотите удалить вариант ответа {"cblue"}%s{ffffff}?", VoteVarInfo[vote_i][var_id][voteVarName])

    ShowPlayerDialog
    (
        playerid, 
        D_APVOTES_DELETE_VAR, 
        DIALOG_STYLE_MSGBOX, 
        !"{"cblue"}Удаление варианта ответа", 
        string, 
        !"Да", 
        !"Нет"
    );
    return 1;
}

stock ShowAPVoteChangeVarName(playerid, vote_i, var_id)
{
    new title_string[128];
    format(title_string, sizeof(title_string), "{"cblue"}%s", VoteVarInfo[vote_i][var_id][voteVarName])

    ShowPlayerDialog
    (
        playerid, 
        D_APVOTES_CHANGE_VAR_NAME, 
        DIALOG_STYLE_INPUT, 
        title_string, 
        !"{ffffff}Введите новое название вариант ответа:", 
        !"Изменить", 
        !"Назад"
    );
    return 1;
}

stock ShowAPVoteVarInfo(playerid, vote_i, var_id)
{
    new title_string[64];
    format(title_string, sizeof(title_string), "{"cblue"}%s", VoteVarInfo[vote_i][var_id][voteVarName]);

    dialog_listitem_values[playerid][0] = vote_i;
    dialog_listitem_values[playerid][1] = var_id;

    ShowPlayerDialog
    (
        playerid, 
        D_APVOTES_VAR_INFO, 
        DIALOG_STYLE_LIST, 
        title_string, 
        !"\
        {"cblue"}1. {ffffff}Изменить название\n\
        {"cblue"}2. {ffffff}Удалить вариант ответа\n\
        ", 
        !"Далее", 
        !"Назад"
    );
    return 1;
}

stock ShowAPVoteClearPlayerVotes(playerid)
{

    ShowPlayerDialog
    (
        playerid, 
        D_APVOTES_CLEAR_PLAYER_VOTES, 
        DIALOG_STYLE_MSGBOX, 
        !"{"cblue"}Очистка голосований", 
        !"{ffffff}Вы желаете очистить голосования для всех игроков?", 
        !"Да", 
        !"Нет"
    );
    return 1;
}

stock ShowAPVotesStats(playerid)
{
    new vote_stats[MAX_APVOTEVARS];
    for(new i = 0; i < MAX_APVOTEVARS; i++)
    {
        if(VoteVarInfo[AP_VOTE_ID][i][voteVarVoteID] != VoteInfo[AP_VOTE_ID][voteID])
            continue;

        vote_stats[i]++;
    }
    new query[128];
    format(query, sizeof(query), "SELECT * FROM `apvotes` WHERE `vote_id` = '%d'", VoteInfo[AP_VOTE_ID][voteID]);
    mysql_tquery(connects, query, "ShowAPVotesStatsMysql", "ii", playerid, AP_VOTE_ID);
    return 1;
}

publics ShowAPVotesStatsMysql(playerid, vote_i)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(!rows)
        return SCM(playerid, red, !"Еще никто не проголосовал!");
    
    new vote_stats[MAX_APVOTEVARS];
    new vote_var_id;
    for(new i = 0; i < rows; i++)
    {
        vote_var_id = cache_get_field_content_int(i, "vote_var_id");
        for(new j = 0; j < MAX_APVOTEVARS; j++)
        {
            if(VoteVarInfo[vote_i][j][voteVarID] == vote_var_id)
            {
                vote_stats[j]++;
            }
        }
    }
    

    new string[1024];
    for(new i = 0; i < MAX_APVOTEVARS; i++)
    {
        if(VoteVarInfo[vote_i][i][voteVarVoteID] != VoteInfo[vote_i][voteID])
            continue;

        new temp_string[128];
        format(temp_string, sizeof(temp_string), "{ffffff}%s\t({"cblue"}%d голосов{ffffff})\n", VoteVarInfo[vote_i][i][voteVarName], vote_stats[i]);
        strcat(string, temp_string);
    }

    ShowPlayerDialog
    (
        playerid, 
        D_NULL, 
        DIALOG_STYLE_MSGBOX, 
        !"{"cblue"}Статистика голосов", 
        string, 
        !"Закрыть", 
        !""
    );
    return 1;
}

