CMD:recipes(playerid){
    new str[1024] = "", string[144];
    format(string, sizeof(string), "{ffffff}Colt: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_9MM] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}�������� � ����������: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_USP] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}Desert Eagle: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_DEAGLE] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}TEK-9: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_TEK9] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}Micro-USI: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_USI] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}��-74�: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_MP5] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}Shot-Gun: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_SHOTGUN] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}Sawed-OFF: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_SAWED_OF] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}Fight Shot-Gun: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_FIGHT_SHOTGUN] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}������� �����������: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_AK47] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}M4: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_M4] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}Country Rifle: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_COUNTRY_RIFLE] == 1 ? "����" : "���");
    strcat(str, string);
    format(string, sizeof(string), "{ffffff}����������� ��������: {"cblue"}%s{ffffff}\n\n", PlayerInfo[playerid][R_SNIPER_RIFLE] == 1 ? "����" : "���");
    strcat(str, string);
    ShowPlayerDialog
    (
        playerid, D_NULL, DIALOG_STYLE_MSGBOX,
        !"{"cblue"}���� ������� �� ������",
        str, 
        !"�������", ""
    );
    return 1;
}