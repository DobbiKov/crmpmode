CMD:offmwarn(playerid, params[])
{
    if(PlayerInfo[playerid][pMember] == TEAM_NONE || PlayerInfo[playerid][pRang] < 10) return YouCannotUseThisFunc(playerid);

    extract params -> new string: to_player[32]; else return SCM(playerid, yellow, "[����������]: {FFFFFF}����������� /offmwarn [NickName ������]");
    foreach(new i : Player)
    {
        if(!strcmp(PlayerInfo[i][pName], to_player, true)) return SCM(playerid, red, "����� ������, �����������: /mwarn");
    }

    new string[128];
    format(string, sizeof(string), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    mysql_tquery(connects, string, "off_mwarn", "is", playerid, to_player);
    return 1;
}

publics off_mwarn(playerid, to_player[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
    {
        new rang, member, string[256], WarnF, acc_id;
        member = cache_get_field_content_int(0, "pMember");
        rang = cache_get_field_content_int(0, "pRang");
        WarnF = cache_get_field_content_int(0, "pWarnF");
        acc_id = cache_get_field_content_int(0, "pID");

        if(PlayerInfo[playerid][pMember] != member) return SCM(playerid, red, "����� �� ������� � ����� �����������!");
        if(rang >= PlayerInfo[playerid][pRang]) return SCM(playerid, red, "�� �� ������ ����� ������� ������ ���� ��� �� �����!");

        OffMWarnMyTK(acc_id, member, "������� �������");

        WarnF++;

        format(string, sizeof(string), "�� ������ ������� %s [%d|3].", to_player, WarnF);
        SCM(playerid, blue, string);

        if(WarnF >= 3)
        {
            format(string, sizeof(string), "UPDATE `accounts` SET `pMember` = '0' WHERE `pName` = '%s'", to_player);
            mysql_tquery(connects, string, "", "");

            format(string, sizeof(string), "UPDATE `accounts` SET `pRang` = '0' WHERE `pName` = '%s'", to_player);
            mysql_tquery(connects, string, "", "");

            format(string, sizeof(string), "UPDATE `accounts` SET `pWarnF` = '0' WHERE `pName` = '%s'", to_player);
            mysql_tquery(connects, string, "", "");
        
            format(string, sizeof(string), "UPDATE `accounts` SET `pFSkin` = '-1' WHERE `pName` = '%s'", to_player);
            mysql_tquery(connects, string, "", "");

            new data[144];
            format(data, sizeof(data), "%s %s ������ ��� �� ����������� %s offline. �������: 3 ��������", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerInfo[playerid][pName], GetMember[ PlayerInfo[playerid][pMember] ]);

            format(string, sizeof(string), "UPDATE `accounts` SET `pOffUninviteMess` = '%s' WHERE `pName` = '%s'", data, to_player);
            mysql_tquery(connects, string, "", "");

            format(string, sizeof(string), "����� %s ��� ������ �� �����������. �������: 3 ��������", to_player);
            SCM(playerid, blue, string);

            OffUnInviteMyTK(acc_id, member, "��������� ���������� ��-�� ���� ���������(�������)");
        }
        else
        {
            format(string, sizeof(string), "UPDATE `accounts` SET `pWarnF` = '%d' WHERE `pName` = '%s'", WarnF, to_player);
            mysql_tquery(connects, string, "", "");
        }
    }
    else
    {
        SCM(playerid, red, "������ ������ ���.");
    }
    return 1;
}