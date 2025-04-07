enum{
    DEL_TYPE_NONE,
    DEL_TYPE_HOUSE,
    DEL_TYPE_BIZ,
    DEL_TYPE_KVART,
    DEL_TYPE_POD,
    DEL_TYPE_ATM,
    DEL_TYPE_TOILET,
    DEL_TYPE_RADAR
};

CMD:delete(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);

	extract params -> new string: type_str[24], obj_id; else return SCM(playerid, blue, "[Ïîäñêàçêà] {ffffff}Ââåäèòå: /delete [òèï] [ID]");
    
    new type = GetTypeIDOfDelete(type_str);
    if(type == DEL_TYPE_NONE)
        return SCM(playerid, red, !"Âû óêàçàëè íåâåðíûé òèï!");
    
    new temp_id = -1;
    switch(type)
    {
        case DEL_TYPE_HOUSE:
            foreach(new i:Allhouses) if(HouseInfo[i][hID] == obj_id) temp_id = i;
        case DEL_TYPE_BIZ:
            foreach(new i:Allbusiness) if(BusinessInfo[i][bID] == obj_id) temp_id = i;
        case DEL_TYPE_KVART:
            foreach(new i:Allkvart) if(KvartInfo[i][kvart_id] == obj_id) temp_id = i;
        case DEL_TYPE_POD:
            foreach(new i:Allpodezd) if(PodezdInfo[i][pod_id] == obj_id) temp_id = i;
        case DEL_TYPE_ATM:
            foreach(new i:AllATMs) if(AtmInfo[i][atmID] == obj_id) temp_id = i;
        case DEL_TYPE_TOILET:
            foreach(new i:AllToilets) if(ToiletInfo[i][tID] == obj_id) temp_id = i;
        case DEL_TYPE_RADAR:
            foreach(new i:AllRadars) if(RadarInfo[i][radar_id] == obj_id) temp_id = i;

        default: return SCM(playerid, red, !"Âû ââåëè íåâåðíûé ID");
    }
    if(temp_id == -1)
        return SCM(playerid, red, !"M-Îáúåêòà äàííîãî òèïà ñ òàêèì ID íåò!");

    new type_name[24];
    GetDelNameByTypeID(type, type_name);

    new string[256];
    format(string, sizeof(string), "{ffffff}Âû äåéñòâèòåëüíî æåëàåòå óäàëèòü m îáúåêò òèïà: {"cblue"}%s{ffffff} ïîä ID {"cblue"}%d{ffffff}?", type_name, obj_id);
    
    ShowPlayerDialog
    (
        playerid, 
        D_ASK_DEL_MOBJ, 
        DIALOG_STYLE_MSGBOX, 
        "{"cblue"}Óäàëåíèå m îáúåêòà", 
        string, 
        "Äà", 
        "Íåò"
    );

    SetPVarInt(playerid, "del_mobj_type", type);
    SetPVarInt(playerid, "del_mobj_id", obj_id);
    SetPVarInt(playerid, "del_mobj_temp_id", temp_id);

    return 1;
}

stock GetDelNameByTypeID(type, dest[])
{
    format(dest, 24, "%s", "îøèáêà");
    switch(type)
    {
        case DEL_TYPE_NONE: format(dest, 24, "%s", "îøèáêà");
        case DEL_TYPE_HOUSE: format(dest, 24, "%s", "äîì");
        case DEL_TYPE_BIZ: format(dest, 24, "%s", "áèçíåññ");
        case DEL_TYPE_KVART: format(dest, 24, "%s", "êâàðòèðà");
        case DEL_TYPE_POD: format(dest, 24, "%s", "ïîäúåçä");
        case DEL_TYPE_ATM: format(dest, 24, "%s", "áàíêîìàò");
        case DEL_TYPE_TOILET: format(dest, 24, "%s", "òóàëåò");
        case DEL_TYPE_RADAR: format(dest, 24, "%s", "ðàäàð");
    }
    return 1;
}

stock GetTypeIDOfDelete(input[])
{
    if(!strcmp(input, "house"))
    {
        return DEL_TYPE_HOUSE;
    }
    if(!strcmp(input, "biz"))
    {
        return DEL_TYPE_BIZ;
    }
    if(!strcmp(input, "kvart"))
    {
        return DEL_TYPE_KVART;
    }
    if(!strcmp(input, "podezd"))
    {
        return DEL_TYPE_POD;
    }
    if(!strcmp(input, "atm"))
    {
        return DEL_TYPE_ATM;
    }
    if(!strcmp(input, "toilet"))
    {
        return DEL_TYPE_TOILET;
    }
    if(!strcmp(input, "radar"))
    {
        return DEL_TYPE_RADAR;
    }
    return DEL_TYPE_NONE;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
        case D_ASK_DEL_MOBJ:
        {
            if(!response) return 1;
            new type = GetPVarInt(playerid, "del_mobj_type");
            new obj_id = GetPVarInt(playerid, "del_mobj_id");
            new idx = GetPVarInt(playerid, "del_mobj_temp_id");
            new mysql_table[24];
            new mysql_id_name[24];
            switch(type)
            {
                case DEL_TYPE_HOUSE:
                {
                    DestroyDynamicMapIcon(HouseInfo[idx][hIcon]);
                    DestroyDynamicPickup(HouseInfo[idx][hPickup]);
                    HouseInfo[idx][hExitX] = 0.0;
                    HouseInfo[idx][hExitY] = 0.0;
                    HouseInfo[idx][hExitZ] = 0.0;

                    HouseInfo[idx][car_pos_x] = 0.0;
                    HouseInfo[idx][car_pos_y] = 0.0;
                    HouseInfo[idx][car_pos_z] = 0.0;
                    HouseInfo[idx][car_pos_a] = 0.0;
                    HouseInfo[idx][hID] = -1;

                    format(mysql_table, sizeof(mysql_table), "%s", "houses");
                    format(mysql_id_name, sizeof(mysql_id_name), "%s", "hID");
                }
                case DEL_TYPE_BIZ:
                {
                    DestroyDynamicMapIcon(BusinessInfo[idx][bIcon]);
                    DestroyDynamicPickup(BusinessInfo[idx][bEnterPickup]);
                    DestroyDynamicPickup(BusinessInfo[idx][bExitPickup]);
                    Delete3DTextLabel(BusinessInfo[idx][bLabel]);

                    BusinessInfo[idx][bExitX] = 0.0;
                    BusinessInfo[idx][bExitY] = 0.0;
                    BusinessInfo[idx][bExitZ] = 0.0;
                    BusinessInfo[idx][bID] = -1;
                    format(mysql_table, sizeof(mysql_table), "%s", "bussines");
                    format(mysql_id_name, sizeof(mysql_id_name), "%s", "bID");
                }
                case DEL_TYPE_KVART:
                {
                    KvartInfo[idx][kvart_id] = -1;
                    KvartInfo[idx][kvart_type] = -1;
                    DestroyDynamicPickup(KvartInfo[idx][kvart_pick]);
                    format(mysql_table, sizeof(mysql_table), "%s", "kvart");
                    format(mysql_id_name, sizeof(mysql_id_name), "%s", "kvart_id");
                }
                case DEL_TYPE_POD:
                {
                    PodezdInfo[idx][pod_id] = -1;
                    PodezdInfo[idx][pod_x] = 0.0;
                    PodezdInfo[idx][pod_y] = 0.0;
                    PodezdInfo[idx][pod_z] = 0.0;
                    PodezdInfo[idx][a_car_pos_x] = 0.0;
                    PodezdInfo[idx][a_car_pos_y] = 0.0;
                    PodezdInfo[idx][a_car_pos_z] = 0.0;
                    PodezdInfo[idx][a_car_pos_a] = 0.0;
                    Delete3DTextLabel(PodezdInfo[idx][pod_text]);
                    DestroyDynamicMapIcon(PodezdInfo[idx][pod_icon]);
                    DestroyDynamicPickup(PodezdInfo[idx][pod_pickup]);
                    DestroyDynamicPickup(PodezdInfo[idx][pod_exit_pickup]);
                    DestroyDynamicPickup(PodezdInfo[idx][pod_menu_pickup]);

                    format(mysql_table, sizeof(mysql_table), "%s", "podezd");
                    format(mysql_id_name, sizeof(mysql_id_name), "%s", "pod_id");
                }
                case DEL_TYPE_ATM:
                {
                    AtmInfo[idx][atmID] = -1;
                    AtmInfo[idx][atmX] = 0.0;
                    AtmInfo[idx][atmY] = 0.0;
                    AtmInfo[idx][atmZ] = 0.0;
                    Delete3DTextLabel(AtmInfo[idx][atmLabel]);
                    format(mysql_table, sizeof(mysql_table), "%s", "atms");
                    format(mysql_id_name, sizeof(mysql_id_name), "%s", "atmID");
                }
                case DEL_TYPE_TOILET:
                {
                    ToiletInfo[idx][tID] = -1;
                    ToiletInfo[idx][tEnterX] = 0.0;
                    ToiletInfo[idx][tEnterY] = 0.0;
                    ToiletInfo[idx][tEnterZ] = 0.0;
                    Delete3DTextLabel(ToiletInfo[idx][tLabel]);
                    format(mysql_table, sizeof(mysql_table), "%s", "toilets");
                    format(mysql_id_name, sizeof(mysql_id_name), "%s", "tID");
                }
                case DEL_TYPE_RADAR:
                {
                    RadarInfo[idx][radar_id] = -1;
                    RadarInfo[idx][radar_x] = 0.0;
                    RadarInfo[idx][radar_y] = 0.0;
                    RadarInfo[idx][radar_z] = 0.0;
                    RadarInfo[idx][radar_a] = 0.0;

                    Delete3DTextLabel(RadarInfo[idx][radar_label]);
                    DestroyObject(RadarInfo[idx][radar_object]);
                    DestroyDynamicArea(RadarInfo[idx][radar_zone]);

                    format(mysql_table, sizeof(mysql_table), "%s", "radars");
                    format(mysql_id_name, sizeof(mysql_id_name), "%s", "radar_id");
                }
                default: return SCM(playerid, red, !"Íåèçâåñòíàÿ îøèáêà ñ óäàëåíèå m object'à.");
            }
            new query[128];
            format(query, sizeof(query), "DELETE FROM `%s` WHERE `%s` = '%d'", mysql_table, mysql_id_name, obj_id);
            mysql_tquery(connects, query);

            new type_name[24];
            GetDelNameByTypeID(type, type_name);

            new string[144];
            format(string, sizeof(string), "[A] Àäìèíèñòðàòîð %s[%d] óäàëèë m-îáúåêò [òèï: %s][id: %d]", PlayerInfo[playerid][pName], playerid, type_name, obj_id);
            SCMA(grey, string);
            return 1;
        }
	}
	#if	defined	del_mobj__OnDialogResponse
		return del_mobj__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse del_mobj__OnDialogResponse
#if	defined	del_mobj__OnDialogResponse
	forward del_mobj__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif
