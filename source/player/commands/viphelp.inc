CMD:viphelp(playerid)
{
    new string[2048] = "";

    new temp_string[144] = "{"cred"}� ��� ��� VIP!\n\n";
    if(PlayerInfo[playerid][pVIP] <= 0)
        strcat(string, temp_string);

    format(temp_string, sizeof(temp_string), "{"cblue"}����������� VIP �������:\n\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- �������� ������� � ���� (/admins)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- �������� ������ (/makegun)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- ������� ������ (/sellgun)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- ������� ���������� (/selldrugs)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- ���������� �������� (/togphone)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- �������� 50.000 ���. ������ 10.000 (/pay)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- ����������� ������� ���� ���� (/clist)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- ��������� ������ �� ������ ���\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- ����������� ����������� ���������\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- ����� �������������� 3 ���, ������ 7 � ������ ���������(warn)\n");
    strcat(string, temp_string);
    format(temp_string, sizeof(temp_string), "{ffffff}- ����������� ����� ��� ���������� ������ ����\n");
    strcat(string, temp_string);
    return SPD(playerid, D_NULL, DIALOG_STYLE_MSGBOX, !"{"cblue"}����������� VIP �������", string, !"�������", !"");
}