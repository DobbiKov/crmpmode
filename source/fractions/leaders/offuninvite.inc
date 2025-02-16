CMD:offuninvite(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] == TEAM_NONE || PlayerInfo[playerid][pRang] < 10) return YouCannotUseThisFunc(playerid);

    extract params -> new string: to_player[32], string: reason[128]; else return SCM(playerid, yellow, "[����������]: {FFFFFF}����������� /offuninvite [NickName ������] [�������]");
    if(!strcmp(to_player, PlayerInfo[playerid][pName], true)) return SCM(playerid, red, "�� �� ������ ������� ����!");
    foreach(new i : Player)
    {
        if(!strcmp(PlayerInfo[i][pName], to_player, true)) return SCM(playerid, red, "����� ������, �����������: /uninvite");
    }

    new string[128];
    format(string, sizeof(string), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    mysql_tquery(connects, string, "off_uninvite", "iss", playerid, to_player, reason);
    return 1;
}

publics off_uninvite(playerid, to_player[], reason[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
    {
        new acc_id, rang, member, string[256];
        acc_id = cache_get_field_content_int(0, "pID");
        member = cache_get_field_content_int(0, "pMember");
        rang = cache_get_field_content_int(0, "pRang");

        if(PlayerInfo[playerid][pMember] != member) return SCM(playerid, red, "����� �� ������� � ����� �����������!");
        if(rang >= PlayerInfo[playerid][pRang]) return SCM(playerid, red, "�� �� ������ ������� ������ ���� ��� �� �����!");

        format(string, sizeof(string), "�� ������� ������ %s �� �����������. �������: %s", to_player, reason);
        SCM(playerid, blue, string);

        OffUnInviteMyTK(acc_id, member, reason);

        format(string, sizeof(string), "UPDATE `accounts` SET `pMember` = '0' WHERE `pName` = '%s'", to_player);
        mysql_tquery(connects, string, "", "");

        format(string, sizeof(string), "UPDATE `accounts` SET `pRang` = '0' WHERE `pName` = '%s'", to_player);
        mysql_tquery(connects, string, "", "");

        format(string, sizeof(string), "UPDATE `accounts` SET `pWarnF` = '0' WHERE `pName` = '%s'", to_player);
        mysql_tquery(connects, string, "", "");
    
        format(string, sizeof(string), "UPDATE `accounts` SET `pFSkin` = '-1' WHERE `pName` = '%s'", to_player);
        mysql_tquery(connects, string, "", "");

        new data[144];
        format(data, sizeof(data), "%s %s ������ ��� �� ����������� %s offline. �������: %s", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerInfo[playerid][pName], GetMember[ PlayerInfo[playerid][pMember] ], reason);

        format(string, sizeof(string), "UPDATE `accounts` SET `pOffUninviteMess` = '%s' WHERE `pName` = '%s'", data, to_player);
        mysql_tquery(connects, string, "", "");

        format(data, sizeof(data), "[A] %s[%d] ������ %s ������� (%s). �������: %s",
            PlayerInfo[playerid][pName], playerid, to_player, GetMember[ PlayerInfo[playerid][pMember] ], reason
        );
        SCMA(grey, data);
    }
    else
    {
        SCM(playerid, red, "������ ������ ���.");
    }
    return 1;
}
