CMD:offawarn(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 6) return ShowCommandNotFound(playerid);

    extract params -> new string: to_player[32]; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /offawarn [NickName ������]");

    foreach(new i : Player)
    {
        if(!strcmp(PlayerInfo[i][pName], to_player, true))
        {
            SCM(playerid, white, "����� �� ������. �����������: /awarn");
            return 1;
        }
    }
    new query[144];
    format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    mysql_tquery(connects, query, "Off_AWarn", "ds", playerid, to_player);
    return 1;
}

publics Off_AWarn(playerid, to_player[])
{
    new rows[2];
    cache_get_data(rows[0], rows[1]);
    if(rows[0])
    {
        new awarns, admin;
        awarns = cache_get_field_content_int(0, "pWarnA");
        admin = cache_get_field_content_int(0, "bAdmin");

        if(admin < 1) return SCM(playerid, red, "����� �� �������� ���������������!");
        if(PlayerInfo[playerid][bAdmin] <= admin) 
            return SCM(playerid, red, !"�� �� ������ ������ ������� ������� ��������������!");

        awarns++;
        new string[144];
        format(string, sizeof(string), "[A] %s[%d] ����� �����. ������� %s � �������� [%d|3]", PlayerInfo[playerid][pName], playerid, to_player, awarns);
        SCMA(grey, string);


        if(awarns >= 3)
        {
            format(string, sizeof(string), "UPDATE `accounts` SET `pMember` = '0' WHERE `pName` = '%s'", to_player);
            mysql_tquery(connects, string, "", "");

            format(string, sizeof(string), "UPDATE `accounts` SET `pRang` = '0' WHERE `pName` = '%s'", to_player);
            mysql_tquery(connects, string, "", "");

            format(string, sizeof(string), "UPDATE `accounts` SET `pWarnF` = '0' WHERE `pName` = '%s'", to_player);
            mysql_tquery(connects, string, "", "");

            format(string, sizeof(string), "UPDATE `accounts` SET `pWarnA` = '0' WHERE `pName` = '%s'", to_player);
            mysql_tquery(connects, string, "", "");
        
            format(string, sizeof(string), "UPDATE `accounts` SET `pFSkin` = '-1' WHERE `pName` = '%s'", to_player);
            mysql_tquery(connects, string, "", "");

            format(string, sizeof(string), "UPDATE `accounts` SET `bAdmin` = '0' WHERE `pName` = '%s'", to_player);
            mysql_tquery(connects, string, "", "");

            new data[144];
            format(data, sizeof(data), "%s ���� ��� � ����� ��������������. �������: 3 ��������", PlayerInfo[playerid][pName]);

            format(string, sizeof(string), "UPDATE `accounts` SET `pOffUninviteMess` = '%s' WHERE `pName` = '%s'", data, to_player);
            mysql_tquery(connects, string, "", "");

            format(string, sizeof(string), "[A] %s ��� ���� � ����� ��������������. �������: 3 �����. ��������", to_player);
            SCMA(grey, string);
        }
        else
        {
            format(string, sizeof(string), "UPDATE `accounts` SET `pWarnA` = '%d' WHERE `pName` = '%s'", awarns, to_player);
            mysql_tquery(connects, string, "", "");
        }
    }
    else
    {
        return SCM(playerid, red, "������ ������ ���!");
    }
    return 1;
}