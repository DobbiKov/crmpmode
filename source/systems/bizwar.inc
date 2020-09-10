enum E_CAPTURE_STRUCT
{
	bool: C_STATUS,
	C_BIZ_ID,
	C_ATTACK_TEAM,
	C_PROTECT_TEAM,
	C_ATTACKER_KILLS,
	C_PROTECTOR_KILLS,
	C_TIME,
	C_WAIT_TIME[8]
}

new g_capture[E_CAPTURE_STRUCT];
new CaptureZone;

public OnGameModeInit()
{
    CaptureZone = GangZoneCreate(1812.2565, 1277.7251, 1995.8712, 910.5800);
    g_capture[C_STATUS] = false;
	#if	defined	bizwar__OnGameModeInit
		return bizwar__OnGameModeInit();
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnGameModeInit
	#undef	OnGameModeInit
#else
	#define	_ALS_OnGameModeInit
#endif

#define	OnGameModeInit bizwar__OnGameModeInit
#if	defined	bizwar__OnGameModeInit
	forward bizwar__OnGameModeInit();
#endif

stock StartBizwar(playerid, opgId, bizOpgId, bizId){
    if(g_capture[C_STATUS]) return 0;
    foreach(new i : Player){
        if(PlayerInfo[i][pMember] == opgId || PlayerInfo[i][pMember] == bizOpgId){

		GangZoneShowForPlayer(i, CaptureZone, red);
		
		for(new j = 0; j < 4; j ++)
			TextDrawShowForPlayer(i, td_capture[j]);
        }
    }

    g_capture[C_STATUS] = true;
    g_capture[C_BIZ_ID] = bizId;
    g_capture[C_ATTACK_TEAM] = opgId;
    g_capture[C_PROTECT_TEAM] = bizOpgId;
    g_capture[C_ATTACKER_KILLS] = 0;
    g_capture[C_PROTECTOR_KILLS] = 0;
    g_capture[C_TIME] = 5*60;

    UpdateBizWarTextDraw();
    return 1; 
}

stock EndBizWar(){
    if(!g_capture[C_STATUS]) return 0;
    new bizId = g_capture[C_BIZ_ID], attackOpg = g_capture[C_ATTACK_TEAM], protectOpg = g_capture[C_PROTECT_TEAM], string[144];
    if(g_capture[C_ATTACKER_KILLS] > g_capture[C_PROTECTOR_KILLS]){
        new BizId;
        foreach(new i : Allbusines){
            if(BusinessInfo[i][bID] == bizId){
                BusinessInfo[i][bControl] = attackOpg;
                UpdateBusiness(i);
                BizId = i;
                break;
            }
        }

        format(string, sizeof(string), "[R] Вы одержали победу и теперь бизнесс %s [№%d] принадлежит вам.", business_params[ BusinessInfo[BizId][bType] ][bname], BusinessInfo[BizId][bID]);
        SCMR(attackOpg, green, string);

        format(string, sizeof(string), "[R] Вы проиграли. Бизнесс %s [№%d] более вам не принадлежит.", business_params[ BusinessInfo[BizId][bType] ][bname], BusinessInfo[BizId][bID]);
        SCMR(protectOpg, green, string);
    }
    else{
        new BizId;
        foreach(new i : Allbusines){
            if(BusinessInfo[i][bID] == bizId){
                BusinessInfo[i][bControl] = protectOpg;
                UpdateBusiness(i);
                BizId = i;
                break;
            }
        }

        format(string, sizeof(string), "[R] Вы проиграли, бизнесс %s [№%d] вам не пренадлежит.", business_params[ BusinessInfo[BizId][bType] ][bname], BusinessInfo[BizId][bID]);
        SCMR(attackOpg, green, string);

        format(string, sizeof(string), "[R] Вы выиграли. Бизнесс %s [№%d] остается под крышей вашей ОПГ.", business_params[ BusinessInfo[BizId][bType] ][bname], BusinessInfo[BizId][bID]);
        SCMR(protectOpg, green, string);       
    }

    g_capture[C_STATUS] = false;
    g_capture[C_BIZ_ID] = -1;
    g_capture[C_ATTACK_TEAM] = -1;
    g_capture[C_PROTECT_TEAM] = -1;
    g_capture[C_ATTACKER_KILLS] = 0;
    g_capture[C_PROTECTOR_KILLS] = 0;
    g_capture[C_TIME] = 0;
    g_capture[C_WAIT_TIME] = gettime() + 3600;
}

stock UpdateBizWarTextDraw(){
	new fmt_text[128];

	format(fmt_text, sizeof fmt_text, "%d", g_capture[C_ATTACKER_KILLS]);
	TextDrawSetString(td_capture[2], fmt_text);

	format(fmt_text, sizeof fmt_text, "%d", g_capture[C_PROTECTOR_KILLS]);
	TextDrawSetString(td_capture[3], fmt_text);
}

publics secondupdate()
{
    if(g_capture[C_STATUS]){
        g_capture[C_TIME]--;
        UpdateBizWarTextDraw();
    }
	#if	defined	bizwar__secondupdate
		return bizwar__secondupdate();
	#else
		return 1;
	#endif
}
#if	defined	_ALS_secondupdate
	#undef	secondupdate
#else
	#define	_ALS_secondupdate
#endif

#define	secondupdate bizwar__secondupdate
#if	defined	bizwar__secondupdate
	forward bizwar__secondupdate();
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case D_BIZ_WAR:{
            if(!response){
                SCM(playerid, red, !"Вы отказались от захвата бизнесса"); 
                DeletePVar(playerid, "bizwar_biz_id");
                return 1;
            }else{
                new bizId = GetPVarInt(playerid, "bizwar_biz_id");
                StartBizwar(playerid, PlayerInfo[playerid][pMember], BusinessInfo[bizId][bControl], BusinessInfo[bizId][bID]);
                DeletePVar(playerid, "bizwar_biz_id");

                new string[144];
                format(string, sizeof(string), "[R] Внимание! %s %s[%d] начал захват бизнесса %s. Место фойны обозначено на карте.", GetPlayerRank(playerid), PlayerInfo[playerid][pName], playerid, business_params[BusinessInfo[bizId][bType]][bname]);
                SCMR(PlayerInfo[playerid][pMember], green, string);

                format(string, sizeof(string), "[R] Внимание! Кто-то начал захват вашего бизнесса: %s. Место войны обозначено на карте.", business_params[BusinessInfo[bizId][bType]][bname]);
                SCMR(BusinessInfo[bizId][bControl], green, string);
            }
        }
    }
	#if	defined	bizwar__OnDialogResponse
		return bizwar__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse bizwar__OnDialogResponse
#if	defined	bizwar__OnDialogResponse
	forward bizwar__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif