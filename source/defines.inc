//************* | MYSQL | *************//
#if defined PRODUCTION
    // #define 	sqlhost     "localhost"
    // #define 	sqluser     "gs29164"
    // #define 	sqlpass     "pZP4vqGLIQ"
    // #define 	sqldb       "gs29164"

    // #define 	logssqlhost     "localhost"
    // #define 	logssqluser     "gs29164"
    // #define 	logssqlpass     "pZP4vqGLIQ"
    // #define 	logssqldb       "gs29164"
#endif

// #if defined DEBUG
    #define 	sqlhost     "localhost"
    #define 	sqluser     "root"
    #define 	sqlpass     "HelloDobbiKovKalKalych23122005SHUA--@$#"
    #define 	sqldb       "unigvacrmp"

    #define 	logssqlhost     "localhost"
    #define 	logssqluser     "root"
    #define 	logssqlpass     "TapolskyAnatoliyUnigvovich436!!"
    #define 	logssqldb       "unigvacrmp"
// #endif

// #define 	logssqlhost     "185.206.212.246"
// #define 	logssqluser     "unigva"
// #define 	logssqlpass     "TapolskyAnatoliyUnigvovich436!!"
// #define 	logssqldb       "unigvacrmplogs"

// //host
// #define 	sqlhost     "185.206.212.246"
// #define 	sqluser     "root"
// #define 	sqlpass     "HelloDobbiKovKalKalych23122005SHUA--@$#"
// #define 	sqldb       "unigva"

//*********** | ��������� | ***********//
#define 	gamemode    "UNIGVA - 0.8.0"
#define     hostname    "[ Unigva RolePlay | ��, �����-�� ���� ]"
#define     mapname     "Criminal Russia"
#define     site_url    "unigva-rp.ru"
#define     name_serv   "Unigva RolePlay"
#define     forum_url   "forum.unigva-rp.ru"

#define     server_num  "1"

//************* | ����� | *************//
#define     red        	0xFF0000AA
#define     lightred   	0xFF0033FF
#define     grey       	0xAFAFAFAA
#define     lightgrey  	0xD3D3D3FF
#define     orange     	0xFF9900AA
#define     lightorange 0xFFA161FF
#define     green       0x33AA33AA
#define     lightgreen  0x00FF00AA
#define     yellow      0xFFFF00AA
#define     lightyellow 0xFFFF47FF
#define     blue        0x0099FFAA
#define     lightblue   0x6475BFFF
#define     purple      0xDD90FFFF
#define     white       0xFFFFFFFF
#define     need        0x87bae7FF

#define     cred        #FF0000
#define     clred       #FF0033
#define     cgrey       #AFAFAF
#define     clgrey      #D3D3D3
#define     corange     #FF9900
#define     clorange    #FFA161
#define     cgreen      #33AA33
#define     clgreen     #00FF00
#define     cyellow     #FFFF00
#define     cblue       #0099FF
#define     clblue      #6475BF
#define     cwhite      #FFFFFF
#define     cerror      #AB1313
//************* | ������� | *************//
#define 	SCM 		SendClientMessage
#define 	SCMTA 		SendClientMessageToAll
#define     SPD         ShowPlayerDialog

#define     MAX_DRUGS_IN_INVENTORY 100
#define     MAX_DRUGS_IN_INVENTORY_VIP 200

#define 	IsValidEmail(%1) regex_match(%1, "|([a-z0-9_\\.\\-]{1,20})@([a-z0-9\\.\\-]{1,20})\\.([a-z]{2,4})|is")

#define     publics%0(%1)			    forward%0(%1); public%0(%1)
#define 	FreezePlayer(%0,%1)    	    TogglePlayerControllable(%0, false), SetTimerEx("PlayerToggle", %1, false, "d", %0)
#define 	UnFreezePlayer(%0)    	    TogglePlayerControllable(%0, true)
#define     ShowCommandNotFound(%0)     SCM(%0, white, !"{"cwhite"}������� �� �������. ����������� {"cblue"}/menu {"cwhite"}��� ������ ������.")
#define     YouCannotUseThisFunc(%0)    SCM(%0, red, !"�� �� ������ ������������ ������ �������.")
#define     PlayerOffLine(%0)           SCM(%0, red, !"����� �������.")
#define 	NewKick(%0) 			    SetTimerEx("DelayedKick", 1000, false, "d", (%0))
#define     GetPlayerRank(%0)           PlayerRank[PlayerInfo[%0][pMember]][PlayerInfo[%0][pRang]]

#define 	PRESSED(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
native 		IsValidVehicle(vehicleid);

#define player_in_business[%0] GetPlayerVirtualWorld(%0)
#define player_in_house[%0] GetPlayerVirtualWorld(%0)
#define player_in_kvart[%0] GetPlayerVirtualWorld(%0)

#if !defined SPECIAL_ACTION_PISSING
    const SPECIAL_ACTION_PISSING = 68;
#endif

new stock SuperNick_S[][MAX_PLAYER_NAME] = {"Robert_Chaze", "Lewis_Clifford", "Roman_Dobbikov"};

// native GameTextForAll(const string[],time,style);
// native GameTextForPlayer(playerid,const string[],time,style);
// native Menu:CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0);
// native AddMenuItem(Menu:menuid, column, const menutext[]);
// native SetMenuColumnHeader(Menu:menuid, column, const columnheader[]);
// native Text:TextDrawCreate(Float:x, Float:y, text[]);
// native TextDrawSetString(Text:text, string[]);
