enum gps_struct { //��������� �������� 
    gps_name[128],
    Float: gps_x,
    Float: gps_y,
    Float: gps_z
}
new gps_publicplaces[7][gps_struct] = { //��������� ������� �������, �������, ��� � ��� �������������� enum'�
    {"������������� �������", 1826.0516,2095.8135,15.8505},    // �����
    {"���������", 1902.7854,2227.7236,15.7135},    // ���������
    {"���������", 1894.5282,2298.3740,15.8627},    // ���������
    {"���������", 2010.9583,1894.1467,15.6600},    // ���������
    {"�/� ������ �. �����", 2522.8638,-2129.4233,21.9700},    // �/� ������ �. �����
    {"����", 1849.6559,2045.5410,15.8850},        // ����
    {"������� ������", 1945.0624,2065.6750,15.7053}        // ������� ������
};
new gps_jobs[4][gps_struct] = { //��������� ������� �������
    {"�������", 2353.1272,-263.8854,2.7890},    // �������
    {"�����", 2345.2053,2006.3165,15.9900},    // �����
    {"�������", 2817.3772,-1369.1652,2.9151},     // �������
    {"������� ����", 1826.7554,2250.5266,15.2729}
};
new gps_works[4][gps_struct] = { //��������� ������� �������
    {"�������� ��������", 1751.6907,2465.2742,15.4400},    
    {"�������", 1876.4078,2253.3743,15.2882},    
    {"�����������", 1975.9448,1931.4481,15.5100},     
    {"������������", 1754.9402,2255.4050,15.8620}
};
new gps_entertainment[2][gps_struct] = { //��������� ������� �������
    {"������", 2333.1096,1757.6904,1.0400},    // ������
    {"��������", 2219.9290,1367.8815,11.5600}
};
new gps_stateorganizations[5][gps_struct] = { //��������� ������� �������
    {"������������� ������", 1826.0516,2095.8135,15.8505},    // ������������� �������
    {"��������", 1978.3701,1602.6826,15.7700},    // ��������
    {"���", 1908.7045,2183.2463,15.7060},    // ���
    {"���", 1900.4652,1722.9036,15.9379},     // ���
    {"���", 1794.6233,2047.6736,15.8741}     // ���
}; 
new gps_gangs[2][gps_struct] = { //��������� ������� �������
    {"��� ����������", 2620.9275,1787.5305,2.5600},    // ����
    {"��� �����������", 1714.9672,1337.8615,12.88001}     // �����
};



CMD:gps(playerid) { //�������, � ���� ����� ���: /gps
    if(GetPVarInt(playerid, "loader_job") == 1 || GetPVarInt(playerid, "diver_job") == 1 || GetPVarInt(playerid, "miner_job") == 1) return SCM(playerid, red, !"�� �� ������ ������������ ���������, ���� ��������� �� �����������.");
    ShowGpsDialog(playerid);
    return 1;
}
stock ShowGpsDialog(playerid) {
    ShowPlayerDialog(playerid, D_GPS, DIALOG_STYLE_LIST, "{"cblue"}���������", "\
    {"cblue"}1. {FFFFFF}������������ �����\n\
    {"cblue"}2. {FFFFFF}����������\n\
    {"cblue"}3. {FFFFFF}������\n\
    {"cblue"}4. {FFFFFF}�����������\n\
    {"cblue"}5. {FFFFFF}�����������\n\
    {"cblue"}6. {FFFFFF}����������� �����������\n\
    {"cblue"}7. {FFFFFF}�������", "�����", "������"); // �������, ������� ������� ������ ������. 
    //1-�� ��������(playerid) - id ������, �������� ����� ������� ������
    //2-�� (D_GPS) - ������������� �������, id ����� ������
    //3-�� (DIALOG_STYLE_LIST) - ��� �������
    //4-�� - ��������� �������
    //5-�� - ���������� �������
    //6-�� - ������ ������
    //7-�� - ������ ������
}
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) //�������, ������� ���������� �������������, ����� ������� ����������� ������
{
    switch(dialogid)//���������� �������, ����� ������ ���� ������������ if'�
    {
        case D_GPS_PUBLICPLACES: { //�� ��������������
            if (!response) ShowGpsDialog(playerid); //���� ����� ����� ������ ������ if(!response) - �� ������� ������ ������
            else { //���� ������, �� ������ �����
                SetGpsCheckpoint(playerid, gps_publicplaces[listitem][gps_x], gps_publicplaces[listitem][gps_y], gps_publicplaces[listitem][gps_z]);
            }
        }
        case D_GPS_JOBS: {
            if (!response) ShowGpsDialog(playerid);
            else {
                SetGpsCheckpoint(playerid, gps_jobs[listitem][gps_x], gps_jobs[listitem][gps_y], gps_jobs[listitem][gps_z]);
            }
        }
        case D_GPS_WORKS: {
            if (!response) ShowGpsDialog(playerid);
            else {
                SetGpsCheckpoint(playerid, gps_works[listitem][gps_x], gps_works[listitem][gps_y], gps_works[listitem][gps_z]);
            }
        }
        case D_GPS_ENTERTAINMENTS: {
            if (!response) ShowGpsDialog(playerid);
            else {
                SetGpsCheckpoint(playerid, gps_entertainment[listitem][gps_x], gps_entertainment[listitem][gps_y], gps_entertainment[listitem][gps_z]);
            }
        }
        case D_GPS_STATEORGANIZATIONS: {
            if (!response) ShowGpsDialog(playerid);
            else {
                SetGpsCheckpoint(playerid, gps_stateorganizations[listitem][gps_x], gps_stateorganizations[listitem][gps_y], gps_stateorganizations[listitem][gps_z]);
            }
        }
        case D_GPS_GANGS: {
            if (!response) ShowGpsDialog(playerid);
            else {
                SetGpsCheckpoint(playerid, gps_gangs[listitem][gps_x], gps_gangs[listitem][gps_y], gps_gangs[listitem][gps_z]);
            }
        }
        case D_GPS_BUSINESS: {
            if (!response) ShowGpsDialog(playerid);
            else {
                SetGpsCheckpoint(playerid, BusinessInfo[listitem + 1][bExitX], BusinessInfo[listitem + 1][bExitY], BusinessInfo[listitem + 1][bExitZ]);
            }
        }
        case D_GPS: {
            if (response) { // ���� ����� ������ ������
                switch(listitem) {//����������, �� ����� ������ ����� �����
                    case 0: {
                        new str[1024] = ""; //��������� ����������
                        new string[128]; //��������� ����������
                        for (new i = 0; i < 7; i++) { //����������, �� ����������� �������
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, gps_publicplaces[i][gps_name]); //������������� �������� ���������� string
                            strcat(str, string); //������ � ����� c����� ���������� str ������ ���������� string
                        }
                        ShowPlayerDialog(playerid, D_GPS_PUBLICPLACES, DIALOG_STYLE_LIST, "{"cblue"}���������", str, "�����", "�����");
                    }
                    case 1: {
                        new str[1024] = "";
                        new string[128];
                        for (new i = 0; i < 4; i++) {
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, gps_jobs[i][gps_name]);
                            strcat(str, string);
                        }
                        ShowPlayerDialog(playerid, D_GPS_JOBS, DIALOG_STYLE_LIST, "{"cblue"}���������", str, "�����", "�����");
                    }
                    case 2: {
                        new str[1024] = "";
                        new string[128];
                        for (new i = 0; i < 4; i++) {
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, gps_works[i][gps_name]);
                            strcat(str, string);
                        }
                        ShowPlayerDialog(playerid, D_GPS_WORKS, DIALOG_STYLE_LIST, "{"cblue"}���������", str, "�����", "�����");
                    }
                    case 3: {
                        new str[1024] = "";
                        new string[128];
                        for (new i = 0; i < 2; i++) {
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, gps_entertainment[i][gps_name]);
                            strcat(str, string);
                        }
                        ShowPlayerDialog(playerid, D_GPS_ENTERTAINMENTS, DIALOG_STYLE_LIST, "{"cblue"}���������", str, "�����", "�����");
                    }
                    case 4: {
                        new str[1024] = "";
                        new string[128];
                        for (new i = 0; i < 5; i++) {
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, gps_stateorganizations[i][gps_name]);
                            strcat(str, string);
                        }
                        ShowPlayerDialog(playerid, D_GPS_STATEORGANIZATIONS, DIALOG_STYLE_LIST, "{"cblue"}���������", str, "�����", "�����");
                    }
                    case 5: {
                        new str[1024] = "";
                        new string[128];
                        for (new i = 0; i < 2; i++) {
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i + 1, gps_gangs[i][gps_name]);
                            strcat(str, string);
                        }
                        ShowPlayerDialog(playerid, D_GPS_GANGS, DIALOG_STYLE_LIST, "{"cblue"}���������", str, "�����", "�����");
                    }
                    case 6:{
                        new str[2048];
                        new string[128];
                        foreach(new i : Allbusiness)
                        {
                            format(string, sizeof(string), "{"cblue"}%d. {ffffff}%s\n", i, business_params[ BusinessInfo[i][bType] ][bname]);
                            strcat(str, string);
                        }
                        SPD(playerid, D_GPS_BUSINESS, DIALOG_STYLE_LIST, !"{"cblue"}���������", str, !"�����", !"�����");
                    }
                }
            }
        }
        case D_TP_GPS:
        {
            if(!response)
            {
                DeletePVar(playerid, "GPS_TP_X");
                DeletePVar(playerid, "GPS_TP_Y");
                DeletePVar(playerid, "GPS_TP_Z");
            }
            else
            {
                new Float:x, Float:y, Float:z;
                x = GetPVarFloat(playerid, "GPS_TP_X");
                y = GetPVarFloat(playerid, "GPS_TP_Y");
                z = GetPVarFloat(playerid, "GPS_TP_Z");

				if(IsPlayerInAnyVehicle(playerid))
				{
				    new vehid = GetPlayerVehicleID(playerid);
					new player_state = GetPlayerVehicleSeat(playerid);
				    SetVehiclePos(vehid, x, y, z);
				    PutPlayerInVehicle(playerid, vehid, player_state);
				}
				else
				{
				    SetPlayerPos(playerid, x, y, z);
				}

                DeletePVar(playerid, "GPS_TP_X");
                DeletePVar(playerid, "GPS_TP_Y");
                DeletePVar(playerid, "GPS_TP_Z");
            }
        }
    }
    #if    defined    gps__OnDialogResponse
        return gps__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
    #else
        return 1;
    #endif
}
#if    defined    _ALS_OnDialogResponse
    #undef    OnDialogResponse
#else
    #define    _ALS_OnDialogResponse
#endif

#define    OnDialogResponse gps__OnDialogResponse
#if    defined    gps__OnDialogResponse
    forward gps__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

stock SetGpsCheckpoint(playerid, Float:x, Float:y, Float:z)
{
    SetPlayerCheckpoint(playerid, x, y, z, 3.0);//������� ������� ������ ����� � ������������ ����� ������������� �������
    SCM(playerid, blue, "����� �������� ������� �������� � ��� �� ���������");
    pCheckpoint[playerid] = CP_GPS;

    if(PlayerInfo[playerid][bAdmin] >= 2)
    {
        SetPVarFloat(playerid, "GPS_TP_X", x);
        SetPVarFloat(playerid, "GPS_TP_Y", y);
        SetPVarFloat(playerid, "GPS_TP_Z", z);

        ShowPlayerDialog(playerid, D_TP_GPS, DIALOG_STYLE_MSGBOX, !"{"cblue"}��������", !"{ffffff}������� ����������������� �� ��������� �������?", !"��", !"���");
    }
}

public OnPlayerEnterCheckpoint(playerid) //������� ������� ������������� ����������, ����� ����� ���������� �� checkpoint
{
    switch(pCheckpoint[playerid])
    {
        case CP_GPS: 
        {
            DisablePlayerCheckpoint(playerid); //������� ��������
            SCM(playerid, blue, "�� ������� � ����� ����������"); //��������� � ���
        }
    }
    #if defined gps__OnPlayerEnterCheckpoint
        return gps__OnPlayerEnterCheckpoint(playerid);
    #else
        return 1;
    #endif
}
#if    defined    _ALS_OnPlayerEnterCheckpoint
    #undef    OnPlayerEnterCheckpoint
#else
    #define    _ALS_OnPlayerEnterCheckpoint
#endif

#define    OnPlayerEnterCheckpoint gps__OnPlayerEnterCheckpoint
#if    defined    gps__OnPlayerEnterCheckpoint
    forward gps__OnPlayerEnterCheckpoint(playerid);
#endif