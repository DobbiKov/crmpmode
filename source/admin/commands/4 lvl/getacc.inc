CMD:getacc(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 4) return ShowCommandNotFound(playerid);

    extract params -> new string: to_player[24]; else return SCM(playerid, blue, "[���������] {ffffff}�������: /getacc [���/ID ������]");

    if(IsNumeric(to_player))
    {
        new to_playerid = strval(to_player);
        if(!PlayerInfo[to_playerid][pLogin] || !IsPlayerConnected(to_playerid)) return PlayerOffLine(playerid);
        format(to_player, sizeof(to_player), "%s", PlayerInfo[to_playerid][pName]);
    }

    if(!CheckFD(playerid) && CheckNickFD(to_player))
        return SCM(playerid, red, !"�� �� ������ ���������� ������ ����� ��������!");

    new query[144];
    format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pName` = '%s'", to_player);
    mysql_tquery(connects, query, "Off_GetAcc", "ds", playerid, to_player);
    return 1;
}

publics Off_GetAcc(playerid, to_player[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(!rows)
        return SCM(playerid, red, !"������ ������ ���!");
    
    new acc_id = cache_get_field_content_int(0, "pID");
    new _admin = cache_get_field_content_int(0, "bAdmin");

    if(_admin > PlayerInfo[playerid][bAdmin])
        return SCM(playerid, red, !"�� �� ������ ���������� ������ ����� ��������!");

    new query[144];
    format(query, sizeof(query), "SELECT * FROM `ownable_cars` WHERE `owner_id` = '%d'", acc_id);
    mysql_tquery(connects, query, "Off_GetAccCars", "dsd", playerid, to_player, acc_id);
    return 1;
}

publics Off_GetAccCars(playerid, to_player[], acc_id)
{
    new rows, fields;
    cache_get_data(rows, fields);
    new string[2056];
    if(!rows)
        format(string, sizeof(string), "��� ����");

    for(new i = 0; i < rows; i++)
    {
        static id, model_id, number[32], _cost_car;

        id = cache_get_field_content_int(i, "id");
        model_id = cache_get_field_content_int(i, "model_id");
        _cost_car = cache_get_field_content_int(i, "cost_car");
        cache_get_field_content(i, "number", number, connects, 64);

        if(!strcmp(number, "None", false)) number = "��� �������";
        new temp_string[144] = "";
        format(temp_string, sizeof(temp_string), "{ffffff}�%d. %s (%d) [ %s ] %d ���.\n", id, GetCarName(model_id), model_id, number, _cost_car);
        strcat(string, temp_string);
    }

    new query[144];
    format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `pID` = '%d'", acc_id);
    return mysql_tquery(connects, query, "Off_GetAccWithCars", "dss", playerid, to_player, string);
}

publics Off_GetAccWithCars(playerid, to_player[], cars_string[])
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(!rows)
        return SCM(playerid, red, !"������ ������ ���!");
            
    new string[4056] = "";

    static acc_id, reg_date[30], reg_ip[16], last_date[30], last_ip[16], warns, lvl, exp, cash, bcash, job, member, mute, jail, kpz, rank, houseid, bizid, podid, kvartid;

    acc_id = cache_get_field_content_int(0, "pID");
    warns = cache_get_field_content_int(0, "pWarn");
    lvl = cache_get_field_content_int(0, "pLVL");
    exp = cache_get_field_content_int(0, "pExp");
    cash = cache_get_field_content_int(0, "pCash");
    bcash = cache_get_field_content_int(0, "pBCash");
    job = cache_get_field_content_int(0, "pJob");
    member = cache_get_field_content_int(0, "pMember");
    mute = cache_get_field_content_int(0, "pMute");
    jail = cache_get_field_content_int(0, "pJail");
    kpz = cache_get_field_content_int(0, "pKPZ");
    rank = cache_get_field_content_int(0, "pRang");

    if(jail < 1) jail = 0;
    if(kpz < 1) kpz = 0;
    if(mute < 1) mute = 0;
    
    houseid = cache_get_field_content_int(0, "pHomeID");
    bizid = cache_get_field_content_int(0, "pBizID");
    podid = cache_get_field_content_int(0, "pPodID");
    kvartid = cache_get_field_content_int(0, "pKvartID");

    cache_get_field_content(0, "pDateReg", reg_date, connects, 64);
    cache_get_field_content(0, "pRegIP", reg_ip, connects, 144);
    cache_get_field_content(0, "pLastIP", last_ip, connects, 144);
    cache_get_field_content(0, "pLastConnect", last_date, connects, 64);

    format(string, sizeof(string), "\
    {ffffff}����� ��������:\t{"cblue"}%d\n\
    {ffffff}���.����:\t\t{"cblue"}%s\n\
    {ffffff}���.IP:\t\t\t{"cblue"}%s\n\
    {ffffff}��������� ����:\t{"cblue"}%s\n\
    {ffffff}��������� IP:\t\t{"cblue"}%s\n\
    {ffffff}��������������:\t{"cblue"}%d\n\
    {ffffff}�������:\t\t{"cblue"}%d(%d/%d)\n\
    {ffffff}��������:\t\t{"cblue"}%d\n\
    {ffffff}����:\t\t\t{"cblue"}%d\n\
    {ffffff}�����������:\t\t{"cblue"}%s(���� %d)\n\
    {ffffff}����� ����:\t\t{"cblue"}%02d:%02d:%02d\n\
    {ffffff}����� ���:\t\t{"cblue"}%02d:%02d:%02d\n\
    {ffffff}����� ���������:\t{"cblue"}%02d:%02d:%02d\n\n\
    {ffffff}���:\t\t\t{"cblue"}%d\n\
    {ffffff}�������:\t\t{"cblue"}%d\n\
    {ffffff}�������:\t\t{"cblue"}%d\n\
    {ffffff}��������:\t\t{"cblue"}%d\n\
    {ffffff}����������:\n\n\
    ",
    acc_id,
    reg_date,
    reg_ip,
    last_date,
    last_ip,
    warns,
    lvl,exp,lvl*4,
    cash,
    bcash,
    (job >= 1) ? (jobs_name[job]) : (GetMember[member]), rank,
    floatround(mute / 3600, floatround_floor), floatround(mute / 60) % 60, mute % 60,
    floatround(kpz / 3600, floatround_floor), floatround(kpz / 60) % 60, (kpz % 60),
    floatround(jail / 3600, floatround_floor), floatround(jail / 60) % 60, (jail % 60),
    houseid, bizid, podid, kvartid
    );
    strcat(string, cars_string);

    new title_string[64];
    format(title_string, sizeof(title_string), "{"cgrey"}%s", to_player);
    return ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, title_string, string, !"�������", !"");
}