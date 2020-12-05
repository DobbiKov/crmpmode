#define MAX_BUSINESS 100

#define b_type_24_7     1
#define b_type_APTEKA   2
#define b_type_EAT      3
#define b_type_CASINO   4
#define b_type_REPAIR   5
#define b_type_FILL     6

new player_in_business[MAX_PLAYERS] = -1;

enum business_params_info
{
	bname[32],
	btype,
	b_rent_price,
	Float: exit_x,
	Float: exit_y,
	Float: exit_z,
	Float: exit_angle,
	Float: coord_menu_x,
	Float: coord_menu_y,
	Float: coord_menu_z,
	b_type_pred[32],
	icon,
    pickup,
    menu_pick,
}

new business_params[7][business_params_info] =
{
	{"INVALID BUSINESS ID!", 	0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, "INVALID BUSINESS ID", 0, 19132, 1},
	{"Магазин 24/7", 			1, 4000, 528.7020,1716.8123,2003.1100,175.9414, 538.3618,1727.5958,2003.1100, "24/7", 17, 19132, 2941},
	{"Аптека", 					2, 3000, -250.8096,1296.8456,1013.0979,176.2207,-250.7598,1300.6337,1013.0979, "Аптека", 22, 19132, 1239},
	{"Столовая", 				3, 2000, 377.0810,-192.9939,1000.6423,1.2533, 379.1561,-184.9244,1000.6350, "Столовая", 10, 19132, 1239},
	{"Казино", 					4, 6000, 1692.1874,2068.0063,-7.8350,267.6344,0.0, 0.0,0.0, "Казино", 25, 19132, 1239},
	{"СТО", 					5, 7000, 2516.1006,-2138.0664,1127.4161, 272.0187, 2516.1006,-2138.0664,1127.4161, "СТО", 27, 1073, 1},
	{"АЗС",		            	6, 9000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, "АЗС", 48, 1650, 1}
};

new Iterator: Allbusiness<MAX_BUSINESS>;
enum E_BIZ_INFO
{
    bID,
    bOwned,
    bOwner[MAX_PLAYER_NAME],
    bType,
    bPrice,
    bCash,
    bProfit,
    Float:bExitX,
    Float:bExitY,
    Float:bExitZ,
    Text3D: bLabel,
    bEnterPickup,
    bExitPickup,
    bMenuPick,
    bControl,
    bEnterPrice,
    bFillPrice,
    bRepairPrice,
    bDays,
}
new BusinessInfo[MAX_BUSINESS][E_BIZ_INFO];
new totalbusiness;