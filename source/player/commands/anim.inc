enum E_ANIM_LIST_STRUCT
{
	AL_DESCRIPTION[32],
	AL_LIB[32],
	AL_NAME[32],
	Float: AL_DELTA,
	AL_LOOP,
	AL_LOCK_X,
	AL_LOCK_Y,
	AL_FREEZE,
	AL_TIME
};

new anim_list[74][E_ANIM_LIST_STRUCT] = 
{
	{"����� 1",                         "DANCING",			"DAN_Left_A",			4.0, true,  0, 0, 0, 0},
	{"����� 2",                         "DANCING",			"DAN_Left_A",			4.0, true,  0, 0, 0, 0},
	{"����� 3",                         "DANCING",			"DAN_Left_A",			4.0, true,  0, 0, 0, 0},
	{"����� 4", 						"DANCING",			"DAN_Left_A",			4.0, true,  0, 0, 0, 0},
	{"����� 5",							"DANCING",			"DAN_Left_A",			4.0, true,  0, 0, 0, 0},
	{"����� 6",							"DANCING",			"dnce_M_a",				4.0, true,  0, 0, 0, 0},
	{"������ �����",					"ON_LOOKERS",		"wave_loop",			4.0, true,  0, 0, 0, 0},
	{"���� �� �����",					"BEACH",			"bather",				4.0, true,  0, 0, 0, 0},
	{"������� �������",					"PED",				"WALK_DRUNK",			4.0, true,  1, 1, 1, 0},
	{"�����������",						"ped",				"Crouch_Roll_L",		4.0, true,  1, 1, 1, 1},
	{"�����������",						"ped",				"endchat_03",			4.0, true,  1, 1, 1, 0},
	{"������ ���",						"benchpress",		"gym_bp_celebrate",		4.0, true,  0, 1, 1, 0},
	{"��������",						"ped",				"cower", 				3.0, true,  0, 0, 0, 0},
	{"��������� �����",					"BOMBER",			"BOM_Plant",			4.0, false, 0, 0, 0, 0},                    
	{"������ �����",					"SHOP",				"ROB_Shifty",			4.0, false, 0, 0, 0, 0},                       
	{"�������� ���� ����� �����",		"SHOP",				"ROB_Loop_Threat",		4.0, true,  0, 0, 0, 0},          
	{"������� ���� ������",				"COP_AMBIENT",		"Coplook_loop",			4.0, true,  0, 1, 1, 0},                
	{"���� ���-�� �� ��...",			"FOOD",				"EAT_Vomit_P", 			3.0, false, 0, 0, 0, 0},               
	{"����������",						"FOOD",				"EAT_Burger", 			3.0, false, 0, 0, 0, 0},                         
	{"�������� ����-�� �� �������",		"SWEET",			"sweet_ass_slap",		4.0, false, 0, 0, 0, 0},        
	{"���������� ���������",			"DEALER",			"DEALER_DEAL",			4.0, false, 0, 0, 0, 0},               
	{"������ �������������",			"CRACK",			"crckdeth2",			4.0, true,  0, 0, 0, 0},               
	{"������� �������",					"SMOKING",			"M_smklean_loop",		4.0, true,  0, 0, 0, 0},                    
	{"������� �������",					"SMOKING",			"F_smklean_loop",		4.0, true,  0, 0, 0, 0},                    
	{"��������",						"BEACH",			"ParkSit_M_loop",		4.0, true,  0, 0, 0, 0},                           
	{"��������� ������������",			"PARK",				"Tai_Chi_Loop",			4.0, true,  0, 0, 0, 0},             
	{"������ �������",					"BAR",				"dnk_stndF_loop",		4.0, true,  0, 0, 0, 0},                     
	{"����������� �����",				"BLOWJOBZ",			"BJ_COUCH_LOOP_P",		4.0, true,  0, 0, 0, 0},                  
	{"���� �������",					"BSKTBALL",			"BBALL_def_loop",		4.0, true,  0, 0, 0, 0},                       
	{"Facepalm",						"MISC",				"plyr_shkhead",			4.0, false, 0, 0, 0, 0},                           
	{"������� ���������� �����",		"BSKTBALL",			"BBALL_idle",			4.0, true,  0, 0, 0, 0},           
	{"������� ����-��",					"CAMERA",			"camstnd_cmon",			4.0, true,  0, 0, 0, 0},                    
	{"���� �����!",						"PED",				"HANDSUP",				4.0, false, 1, 0, 1, 0},                        
	{"����� �� ����",					"CRACK",			"crckidle2",			4.0, true,  0, 0, 0, 0},                      
	{"����� �� �����",					"CRACK",			"crckidle4",			4.0, true,  0, 0, 0, 0},                     
	{"�������� �� ��������",			"DEALER",			"DEALER_IDLE",			4.0, true,  0, 0, 0, 0},               
	{"������������ �� ���",				"GANGS",			"leanIDLE",				4.0, true,  0, 0, 0, 0},                
	{"�������� �����",					"GANGS",			"shake_carSH",			4.0, false, 0, 0, 0, 0},                     
	{"��������",						"GANGS",			"smkcig_prtl",			4.0, false, 0, 0, 0, 0},                           
	{"����, ���������� �� ������",		"BEACH",			"ParkSit_W_loop",		4.0, true,  0, 0, 0, 0},         
	{"����� �� ����",					"INT_HOUSE",		"LOU_Loop",				4.0, true,  0, 0, 0, 0},                      
	{"������ �������� �� �����������",	"INT_OFFICE",		"OFF_Sit_Bored_Loop",	4.0, true,  0, 0, 0, 0},     
	{"������ �� ������",				"INT_OFFICE",		"OFF_Sit_Idle_Loop",	4.0, true,  0, 0, 0, 0},                   
	{"������ � ��������",				"INT_OFFICE",		"OFF_Sit_Type_Loop",	4.0, true,  0, 0, 0, 0},                  
	{"����� ���-�� � �����������",		"INT_SHOP",			"shop_shelf",			4.0, false, 0, 0, 0, 0},         
	{"�����, ������� ���� �� ����",		"JST_BUISNESS",		"girl_02",				4.0, true,  0, 0, 0, 0},        
	{"���������� �� ����-����",			"KISSING",			"GF_StreetArgue_02",	4.0, false, 0, 0, 0, 0},            
	{"������� 1",						"KISSING",			"Grlfrd_Kiss_01",		4.0, false, 0, 0, 0, 0},                          
	{"������� 2",						"KISSING",			"Grlfrd_Kiss_02",		4.0, false, 0, 0, 0, 0},                          
	{"������� 3",						"KISSING",			"Grlfrd_Kiss_03",		4.0, false, 0, 0, 0, 0},                          
	{"����������� ������ �� �����",		"LOWRIDER",			"RAP_B_Loop",			4.0, true,  0, 0, 0, 0},        
	{"������������ �������",			"MEDIC",			"CPR",					4.0, false, 0, 0, 0, 0},               
	{"�������� ��� ��������",			"MISC",				"bitchslap",			4.0, true,  0, 0, 0, 0},              
	{"������������ ����� ���-��",		"MISC",				"bng_wndw",				4.0, false, 0, 0, 0, 0},          
	{"�������� ���������",				"MISC",				"KAT_Throw_K",			4.0, false, 0, 0, 0, 0},                 
	{"����� �� ���� (2)",				"MISC",				"SEAT_LR",				4.0, true,  0, 0, 0, 0},                  
	{"����� �� ���� (3)",				"ped",				"SEAT_idle",			4.0, true,  0, 0, 0, 0},                  
	{"�������� ������",					"ON_LOOKERS",		"lkup_loop",			4.0, true,  0, 0, 0, 0},                    
	{"������� ����� ������",			"ON_LOOKERS",		"Pointup_loop",			4.0, true,  0, 0, 0, 0},               
	{"���� � ������",					"ON_LOOKERS",		"panic_loop",			4.0, true,  0, 0, 0, 0},                      
	{"��������� � ����-����",			"ON_LOOKERS",		"shout_02",				4.0, true,  0, 0, 0, 0},              
	{"������� ��-����������",			"PAULNMAC",			"Piss_loop",			4.0, true,  0, 0, 0, 0},              
	{"������������ ����",				"GHANDS",			"gsign1LH", 			3.0, true,  0, 0, 0, 0},                  
	{"���������� �� ���������",			"ped",				"IDLE_taxi", 			3.0, true,  0, 0, 0, 0},            
	{"���� �����",						"POLICE",			"Door_Kick",			4.0, false, 0, 0, 0, 0},                         
	{"��������� � �����",				"POLICE",			"CopTraf_Stop",			4.0, true,  0, 0, 0, 0},                  
	{"�������� ����",					"RIOT",				"RIOT_ANGRY_B",			4.0, true,  0, 0, 0, 0},                      
	{"��������������",					"RAPPING",			"RAP_C_Loop",			4.0, true,  0, 0, 0, 0},                     
	{"���� �� ����� (2)",				"SWAT",				"gnstwall_injurd",		4.0, true,  0, 0, 0, 0},                  
	{"������ ������������",				"SWEET",			"Sweet_injuredloop",	4.0, true,  0, 0, 0, 0},                
	{"����������� 1",					"RIOT",				"RIOT_ANGRY",			4.0, false, 0, 0, 0, 0},                      
	{"����������� 2",					"GHANDS",			"gsign2",				4.0, false, 0, 0, 0, 0},                      
	{"����������� 3",					"GHANDS",			"gsign5",				4.0, false, 0, 0, 0, 0},                      
	{"����������� 4",					"GHANDS",			"gsign4",				4.0, false, 0, 0, 0, 0}
};
//new anim_list_items[31 * (sizeof(anim_list)+1) + 1];

CMD:anim(playerid, params[])
{	
	if(IsPlayerInAnyVehicle(playerid))
		return SCM(playerid, 0xCECECEFF, "�������� ������ ������������ � ����������");

	if(!strlen(params))
	{
		new sttr[3000], string[128];
		for(new i = 0; i < sizeof(anim_list); i++)
		{
			format(string, sizeof(string), "{"cblue"}%d. {FFFFFF}%s\n", i+1, anim_list[i][AL_DESCRIPTION]);
			strcat(sttr, string);
		}

		ShowPlayerDialog
		(
			playerid, D_ANIM_LIST, DIALOG_STYLE_LIST, 
			"{"cblue"}��������",
			sttr, 
			"�������", "�������"
		);
	}
	else
	{
		extract params -> new count; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /anim [ID �������� �� ������]");
		new anim_count = count - 1;
		if(count > sizeof(anim_list)) return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /anim [ID �������� �� ������]");

		ApplyAnimation(playerid, anim_list[anim_count][AL_LIB], anim_list[anim_count][AL_NAME], anim_list[anim_count][AL_DELTA], anim_list[anim_count][AL_LOOP], anim_list[anim_count][AL_LOCK_X], anim_list[anim_count][AL_LOCK_Y], anim_list[anim_count][AL_FREEZE], anim_list[anim_count][AL_TIME]);
		SetPVarInt(playerid, "anim_status", 1);
		TextDrawShowForPlayer(playerid, anim_TD);
	}
	return 1;
}


public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
		case D_ANIM_LIST:
		{
			if(response)
			{
				ClearAnimations(playerid);
                ApplyAnimation(playerid, anim_list[listitem][AL_LIB], anim_list[listitem][AL_NAME], anim_list[listitem][AL_DELTA], anim_list[listitem][AL_LOOP], anim_list[listitem][AL_LOCK_X], anim_list[listitem][AL_LOCK_Y], anim_list[listitem][AL_FREEZE], anim_list[listitem][AL_TIME]);
				SetPVarInt(playerid, "anim_status", 1);
				TextDrawShowForPlayer(playerid, anim_TD);
			}
	
		}
    }
	#if	defined	anim__OnDialogResponse
		return anim__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnDialogResponse
	#undef	OnDialogResponse
#else
	#define	_ALS_OnDialogResponse
#endif

#define	OnDialogResponse anim__OnDialogResponse
#if	defined	anim__OnDialogResponse
	forward anim__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 16)
    {
		if(GetPVarInt(playerid, "anim_status") == 1)
		{
			TextDrawHideForPlayer(playerid, anim_TD);
			ClearAnimations(playerid);
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
			DeletePVar(playerid, "anim_status");
		}
    }

	#if	defined	anim__OnPlayerKeyStateChange
		return anim__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerKeyStateChange
	#undef	OnPlayerKeyStateChange
#else
	#define	_ALS_OnPlayerKeyStateChange
#endif

#define	OnPlayerKeyStateChange anim__OnPlayerKeyStateChange
#if	defined	anim__OnPlayerKeyStateChange
	forward anim__OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

stock PreloadAnimLib(playerid, animlib[])
{
   ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0);
   return 1;
}
stock PreloadAllAnimLibs (playerid)
{
	PreloadAnimLib(playerid,"AIRPORT");             
	PreloadAnimLib(playerid,"Attractors");          
	PreloadAnimLib(playerid,"BAR");         
	PreloadAnimLib(playerid,"BASEBALL");            
	PreloadAnimLib(playerid,"BD_FIRE");             
	PreloadAnimLib(playerid,"BEACH");               
	PreloadAnimLib(playerid,"benchpress");          
	PreloadAnimLib(playerid,"BF_injection");                
	PreloadAnimLib(playerid,"BIKED");               
	PreloadAnimLib(playerid,"BIKEH");                 
	PreloadAnimLib(playerid,"BIKELEAP");              
	PreloadAnimLib(playerid,"BIKES");                 
	PreloadAnimLib(playerid,"BIKEV");                 
	PreloadAnimLib(playerid,"BIKE_DBZ");              
	PreloadAnimLib(playerid,"BLOWJOBZ");              
	PreloadAnimLib(playerid,"BMX");           
	PreloadAnimLib(playerid,"BOMBER");                
	PreloadAnimLib(playerid,"BOX");           
	PreloadAnimLib(playerid,"BSKTBALL");              
	PreloadAnimLib(playerid,"BUDDY");                 
	PreloadAnimLib(playerid,"BUS");           
	PreloadAnimLib(playerid,"CAMERA");                
	PreloadAnimLib(playerid,"CAR");           
	PreloadAnimLib(playerid,"CARRY");                 
	PreloadAnimLib(playerid,"CAR_CHAT");              
	PreloadAnimLib(playerid,"CASINO");                
	PreloadAnimLib(playerid,"CHAINSAW");              
	PreloadAnimLib(playerid,"CHOPPA");                
	PreloadAnimLib(playerid,"CLOTHES");               
	PreloadAnimLib(playerid,"COACH");                 
	PreloadAnimLib(playerid,"COLT45");                
	PreloadAnimLib(playerid,"COP_AMBIENT");           
	PreloadAnimLib(playerid,"COP_DVBYZ");             
	PreloadAnimLib(playerid,"CRACK");                 
	PreloadAnimLib(playerid,"CRIB");                  
	PreloadAnimLib(playerid,"DAM_JUMP"); 

	PreloadAnimLib(playerid,"DANCING");  
	PreloadAnimLib(playerid,"SNM");  

	PreloadAnimLib(playerid,"DEALER");                
	PreloadAnimLib(playerid,"DILDO");                 
	PreloadAnimLib(playerid,"DODGE");                 
	PreloadAnimLib(playerid,"DOZER");                 
	PreloadAnimLib(playerid,"DRIVEBYS");              
	PreloadAnimLib(playerid,"FAT");           
	PreloadAnimLib(playerid,"FIGHT_B");               
	PreloadAnimLib(playerid,"FIGHT_C");               
	PreloadAnimLib(playerid,"FIGHT_D");               
	PreloadAnimLib(playerid,"FIGHT_E");               
	PreloadAnimLib(playerid,"FINALE");                
	PreloadAnimLib(playerid,"FINALE2");               
	PreloadAnimLib(playerid,"FLAME");                 
	PreloadAnimLib(playerid,"Flowers");               
	PreloadAnimLib(playerid,"FOOD");                  
	PreloadAnimLib(playerid,"Freeweights");           
	PreloadAnimLib(playerid,"GANGS");                 
	PreloadAnimLib(playerid,"GHANDS");                
	PreloadAnimLib(playerid,"GHETTO_DB");             
	PreloadAnimLib(playerid,"goggles");               
	PreloadAnimLib(playerid,"GRAFFITI");              
	PreloadAnimLib(playerid,"GRAVEYARD");             
	PreloadAnimLib(playerid,"GRENADE");               
	PreloadAnimLib(playerid,"GYMNASIUM");             
	PreloadAnimLib(playerid,"HAIRCUTS");              
	PreloadAnimLib(playerid,"HEIST9");                
	PreloadAnimLib(playerid,"INT_HOUSE");             
	PreloadAnimLib(playerid,"INT_OFFICE");            
	PreloadAnimLib(playerid,"INT_SHOP");              
	PreloadAnimLib(playerid,"JST_BUISNESS");                  
	PreloadAnimLib(playerid,"KART");                  
	PreloadAnimLib(playerid,"KISSING");               
	PreloadAnimLib(playerid,"KNIFE");                 
	PreloadAnimLib(playerid,"LAPDAN1");               
	PreloadAnimLib(playerid,"LAPDAN2");               
	PreloadAnimLib(playerid,"LAPDAN3");               
	PreloadAnimLib(playerid,"LOWRIDER");              
	PreloadAnimLib(playerid,"MD_CHASE");              
	PreloadAnimLib(playerid,"MD_END");                
	PreloadAnimLib(playerid,"MEDIC");                 
	PreloadAnimLib(playerid,"MISC");                  
	PreloadAnimLib(playerid,"MTB");           
	PreloadAnimLib(playerid,"MUSCULAR");              
	PreloadAnimLib(playerid,"NEVADA");                
	PreloadAnimLib(playerid,"ON_LOOKERS");            
	PreloadAnimLib(playerid,"OTB");           
	PreloadAnimLib(playerid,"PARACHUTE");             
	PreloadAnimLib(playerid,"PARK");                  
	PreloadAnimLib(playerid,"PAULNMAC");              
	PreloadAnimLib(playerid,"ped");           
	PreloadAnimLib(playerid,"PLAYER_DVBYS");                  
	PreloadAnimLib(playerid,"PLAYIDLES");             
	PreloadAnimLib(playerid,"POLICE");                
	PreloadAnimLib(playerid,"POOL");                  
	PreloadAnimLib(playerid,"POOR");                  
	PreloadAnimLib(playerid,"PYTHON");                
	PreloadAnimLib(playerid,"QUAD");                  
	PreloadAnimLib(playerid,"QUAD_DBZ");              
	PreloadAnimLib(playerid,"RAPPING");               
	PreloadAnimLib(playerid,"RIFLE");                 
	PreloadAnimLib(playerid,"RIOT");                  
	PreloadAnimLib(playerid,"ROB_BANK");              
	PreloadAnimLib(playerid,"ROCKET");                
	PreloadAnimLib(playerid,"RUSTLER");               
	PreloadAnimLib(playerid,"RYDER");                 
	PreloadAnimLib(playerid,"SCRATCHING");            
	PreloadAnimLib(playerid,"SHAMAL");                
	PreloadAnimLib(playerid,"SHOP");                  
	PreloadAnimLib(playerid,"SHOTGUN");               
	PreloadAnimLib(playerid,"SILENCED");              
	PreloadAnimLib(playerid,"SKATE");                 
	PreloadAnimLib(playerid,"SMOKING");               
	PreloadAnimLib(playerid,"SNIPER");                
	PreloadAnimLib(playerid,"SPRAYCAN");              
	PreloadAnimLib(playerid,"STRIP");                 
	PreloadAnimLib(playerid,"SUNBATHE");              
	PreloadAnimLib(playerid,"SWAT");                  
	PreloadAnimLib(playerid,"SWEET");                 
	PreloadAnimLib(playerid,"SWIM");                  
	PreloadAnimLib(playerid,"SWORD");                 
	PreloadAnimLib(playerid,"TANK");                  
	PreloadAnimLib(playerid,"TATTOOS");               
	PreloadAnimLib(playerid,"TEC");           
	PreloadAnimLib(playerid,"TRAIN");                 
	PreloadAnimLib(playerid,"TRUCK");                 
	PreloadAnimLib(playerid,"UZI");           
	PreloadAnimLib(playerid,"VAN");           
	PreloadAnimLib(playerid,"VENDING");               
	PreloadAnimLib(playerid,"VORTEX");                
	PreloadAnimLib(playerid,"WAYFARER");              
	PreloadAnimLib(playerid,"WEAPONS");               
	PreloadAnimLib(playerid,"WUZI");                  
	return 1;
}