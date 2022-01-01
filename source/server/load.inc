    enum MIcon
    {
        Float:mCoords[3],
        mVirtW, mInt, mIDIcon
    }
    new IconInfo[7][MIcon]= // Координаты, Вирт Мир, Интерьер, ID Иконки
    {
        {{2355.0168,-261.2938,2.7890}, 0, 0, 11}, //шахта
        {{2364.8711,2017.5398,15.9900}, 0, 0, 11}, // грузчики
        {{2813.1321,-1356.1815,4.0903}, 0, 0, 11}, // водолазы
        {{1809.6216,2253.1555,15.2729}, 0, 0, 11}, // уборщики улиц
        {{1912.2389,2227.6050,16.0831}, 0, 0, 36}, // autoschool
        {{1754.8612,2251.7861,15.8602}, 0, 0, 51}, // дальнобойщики
        {{2021.7657,1879.7209,15.6600}, 0, 0, 55} // автосалон
    };




//---------- [ LOAD ] ---------------



    //-------------------------------------------[ LOADPICKUPS LOAD_PICKUPS ]---------------------------------------
	MINER_PICK_ENTER = CreatePickup(19133, 23, 2366.5981, 2018.4624, 15.9900, 0); // enter in miner
	MINER_PICK_EXIT = CreatePickup(19133, 23, 2272.2991, 1655.2808, -39.9437, 0); // exit miner
	MAYOR_PICK_ENTER = CreatePickup(19133, 23, 1818.3209,2095.7932,16.1631, 0); // enter in miner
	MAYOR_PICK_EXIT = CreatePickup(19133, 23, 822.9056, 814.9786, -73.0132, 0); // exit miner
	DIVER_PICK_1 = CreatePickup(1279, 23, 2904.3411,-1365.9963,-19.7097, 0); //
	DIVER_PICK_2 = CreatePickup(1279, 23, 2905.0615,-1364.3999,-13.6273, 0); //
	AUTOSCHOOL_PICK_ENTER = CreatePickup(19133, 23, 1912.2389,2227.6050,16.0831, 0);
	AUTOSCHOOL_PICK_EXIT = CreatePickup(19133, 23, 141.1438,1365.9492,1002.9600, 0);
	PPS_PICK_ENTER = CreatePickup(19133, 23, 1919.2756,2183.4666,15.6982, 0);
	PPS_PICK_EXIT = CreatePickup(19133, 23, 2574.4910,-2416.1863,22.4148, -1);
	PPS_PICK_GUN_ENTER = CreatePickup(19133, 23, 2571.0950,-2421.4475,22.3623, -1);
	PPS_PICK_GUN_EXIT = CreatePickup(19133, 23, 2567.1414,-2419.4805,22.3545, -1);
	HOSPITAL_PICK_ENTER = CreatePickup(19133, 23, 1969.6117,1603.3933,16.4184, 0);
	HOSPITAL_PICK_EXIT = CreatePickup(19133, 23, -828.5120,1905.9200,702.0200, 0);
	TONNEL_PICK_ENTER = CreatePickup(19133, 23, 2494.8564,1869.4231,-7.5522, 0);
	TONNEL_PICK_EXIT = CreatePickup(19133, 23, 1539.1112,1762.3157,-7.5291, 0);
	VDV_SKLAD_PICK_ENTER = CreatePickup(19133, 23, 1355.8781,1734.7012,3.6245, 0);
	VDV_SKLAD_PICK_EXIT = CreatePickup(19133, 23, 1500.4392,1656.9667,-5.3244, 0);
	BANK_PICK_ENTER = CreatePickup(19133, 23, 1853.5145,2035.0291,16.9742, 0);
	BANK_PICK_EXIT = CreatePickup(19133, 23, 2056.9131,1905.3260,-77.2241, 0);

	KAZARMA_PICK_ENTER = CreatePickup(19133, 23, 1474.7345,1672.4983,15.3236, 0);
	KAZARMA_PICK_EXIT = CreatePickup(19133, 23, 1308.4167,1504.9818,1002.3200, 0);
	VOENKOM_PICK_ENTER = CreatePickup(19133, 23, 1919.4131,2304.0974,15.5697, 0);
	VOENKOM_PICK_EXIT = CreatePickup(19133, 23, 269.4301,1715.9561,602.9300, 0);

	SMI_PICK_ENTER = CreatePickup(19133, 23, 1795.3522,2037.9583,16.2072, 0);
	SMI_PICK_EXIT = CreatePickup(19133, 23, 1801.0632,2042.2676,-17.9900, 0);
	DPS_PICK_ENTER = CreatePickup(19133, 23, 2576.3184,-2416.0789,22.4951, 0);
	DPS_PICK_EXIT = CreatePickup(19133, 23, 2583.3887,-2426.7756,900.2700, 0);

	PRIBATH_PICK_ENTER = CreatePickup(19133, 23, 1869.6962,1474.0146,10.4394, 0);
	PRIBATH_PICK_EXIT = CreatePickup(19133, 23, 657.2775,2323.3455,1504.3500, 0);
	BATH_PICK_ENTER = CreatePickup(19133, 23, 661.6731,2326.3926,1504.3500, 0);
	BATH_PICK_EXIT = CreatePickup(19133, 23, 639.1815,2309.1450,1504.3500, 0);
	PAINT_PICK = CreatePickup(353, 23, 2234.5137,1376.8782,11.5700, 0);

	CreatePickup(1275, 23, 2283.6631, 1660.1389, -39.7354, 0); // устройство на шахте
	CreatePickup(1275, 23, 2355.0168, -261.2938, 2.7890, 0); // устройство на грузчиков
	CreatePickup(1275, 23, 2813.1321,-1356.1815,4.0903, 0); // устройство на водолазов
	CreatePickup(19134, 23, 817.4346,806.6161,-72.9914, 0); // устройство на на работы
	CreatePickup(19134, 23, 821.9419,804.5621,-72.9925, 0); // создание семьи
	CreatePickup(19134, 23, 2021.8312,1879.7206,15.6600, 0); // Автосалон
	CreatePickup(19134, 23, 131.3660,1368.7767,1002.9600, 0); // exam driving
	CreatePickup(1239, 23, 1754.8612,2251.7861,15.8602, 0); // аренда фур
	CreatePickup(1239, 23, 1809.6216,2253.1555,15.2729, 0);
	CreatePickup(1239, 23, 792.1604,797.8721,-68.2860, 0); //оружие администрации посёлка
	CreatePickup(19134, 23, 2567.2139,-2416.3386,22.3545, -1); // gun pps
	CreatePickup(19134, 23, 2400.3328,-1825.6747,32.5537, -1); // gun fsb
	CreatePickup(3052, 23, 1453.0112,1761.9174,-7.5053, -1); // yash patr vdv
	CreatePickup(3052, 23, 1494.8928,1660.9591,-5.3171, -1); // склад вдв
	CreatePickup(19134, 23, 2051.3542,1903.5139,-77.2241, -1); // Банк
	CreatePickup(19133, 23, 1945.6965, 2069.1343, 16.1989, -1); // Вход в магазин одежды
	CreatePickup(19133, 23, 576.9778, 2121.6274, 1551.4600, -1); // Выход из магазина одежды
	CreatePickup(2941, 23, 571.0848, 2121.6147, 1551.4600, -1); // Пикап покупки одежды 

	CreatePickup(19131, 23, 1490.5315,1668.2097,-5.3244, -1); // склад вдв
	CreatePickup(19131, 23, 661.4055,2323.3774,1504.3500, -1); // абонемент в баню
	CreatePickup(19134, 23, 2355.9548,2025.2953,15.9900, 0); // покупка металла
	CreatePickup(1277, 23, 2003.2611,1339.8290,26.1513, 0); // покупка рецептов
	CreatePickup(861, 23, 2927.5752,994.5273,3.8847, 0); // покупка наркотиков в порту
	CreatePickup(1247, 23, 1924.8105,-1907.2042,32.0061, 0); // снятие розыска на юж химе.

    printf("[UNIGVA]: Пикапы загружены!");
//---------------------------------------------------------------------------------------------------






    //----------------------------[ LOAD_3dLABEL 3dLABEL ]-----------------------------------------------------------------------
    Create3DTextLabel("Нажмите: {"cblue"}L.ALT", white, 2355.0168, -261.2938, 2.7890, 25.0, 0, 0);
    Create3DTextLabel("Нажмите: {"cblue"}L.ALT", white, 2283.6631,1660.1389,-39.7354, 25.0, 0, 0);
    Create3DTextLabel("Нажмите: {"cblue"}L.ALT", white, 2813.1321,-1356.1815,4.0903, 50.0, 0, 1);
    Create3DTextLabel("Нажмите: {"cblue"}L.ALT", white, 817.4346,806.6161,-72.9914, 50.0, 0, 0);
    Create3DTextLabel("Нажмите: {"cblue"}L.ALT", white, 131.3660,1368.7767,1002.9600, 50.0, 0, 0);
    Create3DTextLabel("Нажмите: {"cblue"}L.ALT", white, 2051.3542,1903.5139,-77.2241, 50.0, 0, 0);
    Create3DTextLabel("Нажмите: {"cblue"}L.ALT", white, 821.9419,804.5621,-72.9925, 10.0, 0, 0);


    Create3DTextLabel("Нажмите: {"cblue"}L.ALT {ffffff}что б войти", white, 1945.6965, 2069.1343, 16.1989, 10.0, 0, 0);
    Create3DTextLabel("Нажмите: {"cblue"}L.ALT {ffffff}что б выйти", white, 576.9778, 2121.6274, 1551.4600, 10.0, 0, 0);

    CreateDynamic3DTextLabel("Нажмите: {"cblue"}L.ALT {ffffff}что б справить нужду", 0xFFFFFFFF, toilet_params[0][menu_x], toilet_params[0][menu_y], toilet_params[0][menu_z], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 100.0);

	for(new i = 0; i < sizeof(DiceInfo); i++) CreateDynamic3DTextLabel("{ffffff}Используйте: {"cblue"}/dice", 0xFFFFFFFF, DiceInfo[i][diceX], DiceInfo[i][diceY], DiceInfo[i][diceZ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 100.0);

    Create3DTextLabel("Нажмите: {"cblue"}L.ALT", white, 1400.6801,1755.8474,4.1479, 50.0, 0, 0);
    Create3DTextLabel("Нажмите: {"cblue"}L.ALT", white, 1400.6577,1758.0184,-5.7436, 50.0, 0, 0);

    Create3DTextLabel("Нажмите: {"cblue"}L.ALT {ffffff}что б уничтожить мешок с контрабандой", white, 1967.2764, -1944.4343, 25.1482, 50.0, 0, 0); //уничтожение контрабанды

    Create3DTextLabel("{FFFFFF}Нажмите {"cblue"}'H' {FFFFFF}что б загрузить металл", white, 2371.0042,2006.6135,15.9900, 50.0, 0, 0);
    Create3DTextLabel("{FFFFFF}Нажмите {"cblue"}'H' {FFFFFF}что б разгрузить металл", white, 1425.2693,1672.7239,15.4692, 50.0, 0, 0);

	Create3DTextLabel("{FFFFFF}Нажмите {"cblue"}'H' {FFFFFF}что б поставить номерной знак", white, 2428.5806,-1832.4991,19.0850, 10.0, 0, 0); //fsb numbers

	new string_ammo[144];
	format(string_ammo, sizeof(string_ammo), "{ffcc00}Склад\n\n{ffffff}Патроны: {ff9900}%d\n{ffffff}Металл: {ff9900}%d\n\n{ff4f00}Команды:\n{ffcc00}/getmet\n/putmet", REPOSITORY_ARMY_PATRON, REPOSITORY_ARMY_METALL);
	RepositoryArmyText = CreateDynamic3DTextLabel(string_ammo, 0xFFFFFFFF, 1494.8928,1660.9591,-5.3171, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 100.0);

	new opg_o_ammo[256];
	format(opg_o_ammo, sizeof(opg_o_ammo), "{ffcc00}Склад\n\n{FFFFFF}Патроны: {ff9900}%d\n{ffffff}Металл: {ff9900}%d\n{ffffff}Наркотики: {ff9900}%d\n{ffffff}Деньги: {ff9900}%d\n\n{ffffff}Статус: {ff9900}%s\n\n\n", OPG_O_PATRON, OPG_O_METALL, OPG_O_DRUGS, OPG_O_MONEY, OPG_O_STATUS == 0 ? "Закрыт" : "Открыт");
	SkladOPGOText = CreateDynamic3DTextLabel(opg_o_ammo, 0xFFFFFFFF, 2610.9668,1767.7485,10.2175, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 100.0);

	new opg_s_ammo[256];
	format(opg_s_ammo, sizeof(opg_s_ammo), "{ffcc00}Склад\n\n{FFFFFF}Патроны: {ff9900}%d\n{ffffff}Металл: {ff9900}%d\n{ffffff}Наркотики: {ff9900}%d\n{ffffff}Деньги: {ff9900}%d\n\n{ffffff}Статус: {ff9900}%s\n\n\n", OPG_S_PATRON, OPG_S_METALL, OPG_S_DRUGS, OPG_O_MONEY, OPG_S_STATUS == 0 ? "Закрыт" : "Открыт");
	SkladOPGSText = CreateDynamic3DTextLabel(opg_s_ammo, 0xFFFFFFFF, 1705.9067,1337.9858,26.0344, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 100.0);

	new port_narko[256];
	format(port_narko, sizeof(port_narko), "{"cblue"}Наркотики\n\n{FFFFFF}Количество: %d\n{"cblue"}Стоимость:\n1 {FFFFFF}гр. - {"cblue"}500 {FFFFFF}рублей\n\n\n\n\n\n{"cblue"}___", ALL_NARKO);
	PortNarkoText = CreateDynamic3DTextLabel(port_narko, 0xFFFFFFFF, 2927.5752,994.5273,3.8847, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 100.0);


    printf("[UNIGVA]: 3Д тексты загружены!");
//---------------------------------------------------------------------------------------------------------------------------------------

    //---------------------------[ LOAD_OBJECTS шлагбаумы и ворота ]--------------------------------------------------------------------------
	post_dps_1 = CreateObject(968, 2747.48, -1382.81, 23.44, 0.00, 0.00, 0.00);//1
	post_dps_2 = CreateObject(968, 2746.83, -1382.82, 23.37, 0.00, 0.00, 0.00);//2

	dps_door = CreateObject(19303, 2583.39, -2417.25, 900.48, 0.00, 0.00, 180.00); // closed

	post_batyrevo_arzamas_1 = CreateObject(968, 1553.36, 2967.01, 11.69,   0.00, -90.00, 90.00);//1
	post_batyrevo_arzamas_2 = CreateObject(968, 1524.45, 2952.78, 11.69,   0.00, 90.00, 90.00);//2

	open_pps = CreateObject(968, 1900.59, 2157.94, 15.56,   0.00, -90.00, 90.00);

	open_vdv = CreateObject(988, 1892.15, 1722.07, 15.65,   0.00, 0.00, 90.00);

	shlak_truck = CreateObject(968, 1774.48, 2243.77, 15.60,   0.00, -90.00, 0.00);// закрытый шлагбаум

	shlak_vdv = CreateObject(968, 1653.39, 1686.51, 15.03, 0.00, -90.00, 90.00);//закрытый

	OpgDoors[OPG_S_DOOR] = CreateObject(1569, 1706.93, 1330.34, 12.76,   0.00, 0.00, 0.00);
	OpgDoors[OPG_O_DOOR] = CreateObject(1569, 2601.98, 1769.14, 2.51,   0.00, 0.00, 0.00); 

	OpgDoorsStatus[OPG_S_DOOR] = false;
	OpgDoorsStatus[OPG_O_DOOR] = false;

	fsb_vorota_1 = CreateObject(2957, 2395.02, -1792.44, 22.44,   0.00, 0.00, 0.00);
	fsb_vorota_2 = CreateObject(2957, 2445.66, -1795.02, 22.42,   0.00, 0.00, 90.00);
	fsb_door = CreateObject(1569, 2413.96, -1841.27, 21.79,   0.00, 0.00, 180.00);
	fsb_lift = CreateObject(1938, 2395.89, -1830.22, 23.06,   0.00, 0.00, 180.00); 


 	Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, 1000, -1);
 	printf("[UNIGVA]: Объекты загружены!");
 	
//--------------------------------------------------------------------------------------------------------------------------------------------



    //------------------------------[ LOAD_CARS LOADCARS ]--------------------------------------------------------
	new last_veh_id;
	job_car[BUS_CAR][0] = AddStaticVehicleEx(418,1754.0328,2477.4124,15.5396,114.7283,6,0,3600);
	AddStaticVehicleEx(418,1756.2593,2473.9465,15.5505,112.0174,6,0,3600);
	AddStaticVehicleEx(418,1761.8575,2465.4248,15.5543,110.3421,6,0,3600);
	AddStaticVehicleEx(418,1764.1523,2462.2390,15.5503,112.5190,6,0,3600);
	AddStaticVehicleEx(418,1766.3168,2459.0769,15.5486,112.2301,6,0,3600);
	AddStaticVehicleEx(418,1753.8151,2451.5786,15.5422,285.9609,6,0,3600);
	AddStaticVehicleEx(418,1751.6603,2454.8066,15.5502,288.1867,6,0,3600);
	AddStaticVehicleEx(418,1749.4467,2458.2263,15.5472,286.2426,6,0,3600);
	AddStaticVehicleEx(418,1747.0665,2461.4680,15.5481,287.1357,6,0,3600);
	AddStaticVehicleEx(418,1744.9137,2464.7236,15.5346,286.3633,6,0,3600);
	AddStaticVehicleEx(418,1742.4185,2468.0000,15.5460,285.5315,6,0,3600);
	job_car[BUS_CAR][1] = AddStaticVehicleEx(418,1739.9972,2471.1372,15.5478,284.0771,6,0,3600);

	job_car[MECHANIC_CAR][0] = AddStaticVehicleEx(525,2013.0392,1947.2505,15.4842,89.8683,6,0,3600); // mechanick car 1
	AddStaticVehicleEx(525,2012.9918,1940.7789,15.4902,88.5670,6,0,3600); // mechanick car 2
	AddStaticVehicleEx(525,2013.0846,1934.5726,15.4711,90.4882,6,0,3600); // mechanick car 3
	AddStaticVehicleEx(525,2012.8430,1927.9990,15.4737,89.8372,6,0,3600); // mechanick car 4
	job_car[MECHANIC_CAR][1] = AddStaticVehicleEx(525,2013.0894,1921.7423,15.4648,91.0125,6,0,3600); // mechanick car 5

	job_car[CATEG_A_CAR][0] = AddStaticVehicleEx(461, 1939.1744,2246.4094,15.3708,89.9513,3,3,3600);
	job_car[CATEG_A_CAR][1] = AddStaticVehicleEx(461, 1939.1692,2247.3604,15.3692,88.4778,3,3,3600);
	job_car[CATEG_B_CAR][0] = AddStaticVehicleEx(516, 1933.5253,2225.2029,15.7316,1.7649,3,0,3600);
	AddStaticVehicleEx(516, 1928.8000,2225.1650,15.7315,0.6086,3,0,3600);
	job_car[CATEG_B_CAR][1] = AddStaticVehicleEx(516, 1924.2289,2228.1021,15.7298,0.5742,3,0,3600);
	job_car[CATEG_C_CAR][0] = AddStaticVehicleEx(515, 1934.4994,2250.3352,16.3538,89.8652,3,3,3600);
	job_car[CATEG_C_CAR][1] = AddStaticVehicleEx(515, 1922.8806,2250.6436,16.3560,92.9310,3,3,3600);
	job_car[CATEG_D_CAR][0] = AddStaticVehicleEx(483, 1909.6436,2235.8845,15.9755,359.6084,3,3,3600);

	job_car[TAXI_CAR][0] = AddStaticVehicleEx(420,1871.4742,2238.5056,14.7061,359.7479,6,0,3600); // taxi car
	AddStaticVehicleEx(420,1865.3035,2238.0952,14.7038,0.9006,6,0,3600); // taxi car
	AddStaticVehicleEx(420,1859.3088,2237.9907,14.7082,359.4437,6,0,3600); // taxi car
	AddStaticVehicleEx(420,1853.3943,2238.2090,14.6631,357.3396,6,0,3600); // taxi car
	AddStaticVehicleEx(420,1873.7040,2272.0144,14.7081,178.6922,6,0,3600); // taxi car
	AddStaticVehicleEx(420,1870.3976,2275.2395,14.6976,179.1754,6,0,3600); // taxi car
	AddStaticVehicleEx(420,1866.2493,2275.5327,14.7042,174.6609,6,0,3600); // taxi car
	AddStaticVehicleEx(420,1862.0675,2275.5830,14.7164,179.7810,6,0,3600); // taxi car
	AddStaticVehicleEx(420,1863.2827,2255.6001,14.7039,241.8215,6,0,3600); // taxi car
	AddStaticVehicleEx(420,1863.5007,2262.1809,14.7104,240.5229,6,0,3600); // taxi car
	AddStaticVehicleEx(420,1863.6484,2258.6072,14.7084,243.9576,6,0,3600); // taxi car
	job_car[TAXI_CAR][1] = AddStaticVehicleEx(420,1863.7432,2265.4177,14.7138,238.5924,6,0,3600); // taxi car

    job_car[TEAM_PPS_CAR][0] = AddStaticVehicleEx(551,1952.9442,2171.6172,15.1306,91.9258,1,0,3600); // маишны полиции
	AddStaticVehicleEx(433,1932.9521,2169.8369,15.8399,270.2130,1,1,3600); // pps car
	AddStaticVehicleEx(433,1933.3911,2173.9595,15.7278,270.0634,1,1,3600); // pps car
	AddStaticVehicleEx(599,1947.1536,2167.8467,15.7797,90.9871,1,0,3600); // маишны полиции
	AddStaticVehicleEx(599,1947.1667,2164.0469,15.7801,92.1783,1,0,3600); // маишны полиции
	AddStaticVehicleEx(599,1947.1293,2160.4180,15.7813,90.8842,1,0,3600); // маишны полиции
	AddStaticVehicleEx(599,1947.3905,2156.9316,15.7802,90.7479,1,0,3600); // маишны полиции
	AddStaticVehicleEx(597,1936.4648,2156.9417,15.6122,91.0653,1,0,3600); // маишны полиции
	AddStaticVehicleEx(597,1931.5676,2156.9917,15.6009,89.7723,1,0,3600); // маишны полиции
	AddStaticVehicleEx(596,1926.5808,2156.9214,15.6108,89.9002,1,0,3600); // маишны полиции
	AddStaticVehicleEx(596,1921.2052,2156.9629,15.6149,90.2065,1,0,3600); // маишны полиции
	job_car[TEAM_PPS_CAR][1] = AddStaticVehicleEx(497,1954.1093,2160.8110,18.7617,90.0771,79,1,3600); // маишны полиции

	job_car[TEAM_HEAL_CAR][0] = AddStaticVehicleEx(551,1928.5714,1633.2848,15.1947,268.8003,1,0,3600); // болькар
	AddStaticVehicleEx(416,1928.1519,1618.5281,15.6105,0.3075,1,3,3600); // болькар
	AddStaticVehicleEx(416,1935.9171,1618.6458,15.6104,0.4965,1,3,3600); // болькар
	AddStaticVehicleEx(416,1942.7842,1618.5276,15.6110,0.5638,1,3,3600); // болькар
	job_car[TEAM_HEAL_CAR][1] = AddStaticVehicleEx(416,1949.5714,1618.3945,15.6106,1.3257,1,3,3600); // болькар

	job_car[TEAM_VDV_CAR][0] = AddStaticVehicleEx(437,1474.7107,1706.1307,15.7036,180.6131,16,16,3600); // автобус
	AddStaticVehicleEx(470,1423.2996,1708.4568,15.0224,180.6400,16,0,3600); // машина армии
	AddStaticVehicleEx(470,1429.5646,1708.8839,15.0212,183.1198,16,0,3600); // машина армии
	AddStaticVehicleEx(470,1436.2717,1709.2045,15.0212,183.4387,16,0,3600); // машина армии
	AddStaticVehicleEx(425,1403.2074,1637.0330,15.6961,355.6632,44,44,3600);
	AddStaticVehicleEx(425,1419.9327,1637.4308,15.6543,0.0507,44,44,3600);
	AddStaticVehicleEx(487,1437.9580,1637.2216,15.7092,4.0170,44,44,3600);
	AddStaticVehicleEx(487,1459.5155,1636.8601,15.7002,359.9991,44,44,3600);
	AddStaticVehicleEx(548,1478.4753,1636.2848,16.0588,0.0124,44,44,3600);
	AddStaticVehicleEx(548,1500.1798,1634.2589,16.0806,359.9662,44,44,3600);
	AddStaticVehicleEx(548,1523.2466,1633.7017,16.0826,0.0001,44,44,3600);
	AddStaticVehicleEx(548,1543.4731,1633.6104,16.0835,0.0395,44,44,3600);
	job_car[TEAM_VDV_HYDRA_CAR][0] = AddStaticVehicleEx(520,1952.9166,1541.3224,15.8126,90.5429,0,0, 3600); // hydra1
	job_car[TEAM_VDV_HYDRA_CAR][1] = AddStaticVehicleEx(520,1953.0867,1560.2249,15.8126,90.2583,0,0, 3600); // hydra2
	job_car[TEAM_VDV_CAR][1] =  AddStaticVehicleEx(470,1443.0614,1709.7073,15.0208,181.6893,16,0,3600); // машина армии

	job_car[TEAM_VDV_BTR_CAR][0] = AddStaticVehicleEx(601,1552.3802,1816.2875,14.9289,179.0188,16,16,3600); // бтр армии
	job_car[TEAM_VDV_BTR_CAR][1] = AddStaticVehicleEx(601,1546.6411,1816.2793,14.9299,180.3373,16,16,3600); // бтр армии


	job_car[TEAM_VDV_TANK_CAR][0] = AddStaticVehicleEx(432,1564.4659,1815.9969,15.4698,178.7035,16,16,3600); // танк армии
	job_car[TEAM_VDV_TANK_CAR][1] = AddStaticVehicleEx(432,1558.4132,1816.0608,15.4693,180.5871,16,16,3600); // танк армии

	job_car[TEAM_VDV_METALL_CAR][0] = 	AddStaticVehicleEx(578,1450.2106,1708.4806,15.4971,179.5312,16,16,3600); // металл армии
	AddStaticVehicleEx(578,1456.6053,1708.7610,15.4974,179.7553,16,16,3600); // металл армии
	AddStaticVehicleEx(578,1463.4430,1709.1674,15.4944,180.5852,16,16,3600); // металл армии
	job_car[TEAM_VDV_METALL_CAR][1] = AddStaticVehicleEx(578,1470.6415,1709.4380,15.5109,185.4001,16,16,3600); // металл армии

	job_car[TEAM_ADM_CAR][0] = AddStaticVehicleEx(426,1797.7288,2095.3735,15.9533,359.7466,1,1,3600); // ?????? ??
	AddStaticVehicleEx(551,1796.8479,2083.7485,15.2839,0.6409,1,1,3600); // ?????? ??
	AddStaticVehicleEx(551,1793.2229,2083.7983,15.2705,4.0739,1,1,3600); // ?????? ??
	AddStaticVehicleEx(551,1789.4148,2083.5420,15.2799,2.5445,1,1,3600); // ?????? ??
	job_car[TEAM_ADM_CAR][1] = AddStaticVehicleEx(551,1785.6165,2083.4573,15.2804,1.4502,1,1,3600); // ?????? ??

	SetVehicleHealth(job_car[TEAM_VDV_BTR_CAR][0], 1000000.0);
	SetVehicleHealth(job_car[TEAM_VDV_BTR_CAR][1], 1000000.0);
	SetVehicleHealth(job_car[TEAM_VDV_TANK_CAR][0], 1000000.0);
	SetVehicleHealth(job_car[TEAM_VDV_TANK_CAR][1], 1000000.0);

	job_car[TEAM_SMI_CAR][0] = 	AddStaticVehicleEx(582,1812.6904,2027.2992,15.6623,0.0892,1,7,3600); // ?????? ???
	AddStaticVehicleEx(582,1809.2700,2027.3883,15.6670,0.4690,1,7,3600); // ?????? ???
	job_car[TEAM_SMI_CAR][1] = AddStaticVehicleEx(582,1816.2390,2027.4240,15.6585,0.8832,1,7,3600); // ?????? ???

	job_car[TEAM_OREX_CAR][0] = AddStaticVehicleEx(421,2601.4233,1787.7559,2.4037,179.2988,0,0,3600); // Машины ОПГ О
	AddStaticVehicleEx(421,2604.6013,1787.7268,2.4070,182.7370,0,0,3600); // Машины ОПГ О
	AddStaticVehicleEx(421,2607.9216,1787.9923,2.4058,182.1655,0,0,3600); // Машины ОПГ О
	job_car[TEAM_OREX_FURGON_CAR][0] = AddStaticVehicleEx(482,2612.1052,1788.4001,2.3059,180.4688,0,0,3600); // Машины ОПГ О
	job_car[TEAM_OREX_FURGON_CAR][1] = AddStaticVehicleEx(482,2615.9863,1788.4403,2.3027,181.9853,0,0,3600); // Машины ОПГ О
	AddStaticVehicleEx(492,2617.6099,1767.9648,2.5536,1.0648,0,0,3600); // Машины ОПГ О
	AddStaticVehicleEx(492,2621.1025,1767.9376,2.5579,1.7950,0,0,3600); // Машины ОПГ О
	AddStaticVehicleEx(492,2624.9009,1767.9921,2.5590,2.0868,0,0,3600); // Машины ОПГ О
	AddStaticVehicleEx(475,2628.7573,1767.6250,2.4840,1.8866,0,0,3600); // Машины ОПГ О
	AddStaticVehicleEx(475,2632.4224,1767.8621,2.4837,1.5591,0,0,3600); // Машины ОПГ О
	job_car[TEAM_OREX_CAR][1] = AddStaticVehicleEx(475,2636.1665,1768.0181,2.4845,0.0854,0,0,3600); // Машины ОПГ О



	job_car[TEAM_SUN_CAR][0] = AddStaticVehicleEx(492,1697.3405,1317.1392,12.8825,308.6804,0,0,3600); // машина ОПГ-С
	AddStaticVehicleEx(492,1696.9441,1312.8358,12.8794,308.7019,0,1,3600); // машина ОПГ-С
	AddStaticVehicleEx(492,1704.2841,1313.4196,12.8787,1.2265,0,0,3600); // машина ОПГ-С
	AddStaticVehicleEx(475,1726.1501,1312.8503,12.8004,2.5939,0,0,3600); // машина ОПГ-С
	AddStaticVehicleEx(475,1731.0651,1313.4154,12.8036,1.0278,0,0,3600); // машина ОПГ-С
	AddStaticVehicleEx(475,1735.9634,1313.1888,12.8051,0.0083,0,1,3600); // машина ОПГ-С
	job_car[TEAM_SUN_FURGON_CAR][0] = AddStaticVehicleEx(482,1735.0342,1335.4175,12.6242,181.2941,0,1,3600); // машина ОПГ-С
	job_car[TEAM_SUN_FURGON_CAR][1] = AddStaticVehicleEx(482,1731.1531,1335.3409,12.6072,181.9114,0,0,3600); // машина ОПГ-С
	AddStaticVehicleEx(421,1726.1130,1335.4225,12.7299,185.1191,0,0,3600); // машина ОПГ-С
	AddStaticVehicleEx(421,1721.1545,1334.8625,12.7327,181.6565,0,0,3600); // машина ОПГ-С
	job_car[TEAM_SUN_CAR][1] = AddStaticVehicleEx(421,1716.7197,1334.6970,12.7316,180.0148,0,0,3600); // машина ОПГ-С

	job_car[TEAM_FSB_CAR][0] = AddStaticVehicleEx(601,2425.5081,-1796.7102,18.6892,180.6524,16,16,3600); // машина fsb
	
	job_car[TEAM_FSB_FURGON_CAR][0] = AddStaticVehicleEx(459,2416.5432,-1795.7845,18.8367,177.5269,0,0,3600);//vito
	AddStaticVehicleEx(459,2412.1343,-1795.8007,18.8423,178.7196,0,0,3600);//vito
	AddStaticVehicleEx(459,2407.8337,-1795.8203,18.8394,179.2205,0,0,3600);//vito
	job_car[TEAM_FSB_FURGON_CAR][1] = AddStaticVehicleEx(459,2403.8130,-1795.7736,18.8422,178.7282,0,0,3600);//vito 

	AddStaticVehicleEx(490,2399.4114,-1796.5762,19.0360,178.9212,0,0,3600);//suburban
	AddStaticVehicleEx(490,2399.5334,-1809.4105,19.0376,358.9885,0,0,3600);//suburban
	AddStaticVehicleEx(490,2403.7070,-1809.4764,19.0380,359.9570,0,0,3600);//suburban
	AddStaticVehicleEx(490,2407.8933,-1809.5325,19.0367,359.1015,0,0,3600);//suburban

	AddStaticVehicleEx(558, 2412.1982,-1810.0485,18.6512,358.2335,0,0,3600);//audi1
	AddStaticVehicleEx(558, 2416.4451,-1810.1492,18.6550,359.1962,0,0,3600);//audi1
	AddStaticVehicleEx(558, 2420.7737,-1810.0956,18.6615,358.2147,0,0,3600);//audi1
	AddStaticVehicleEx(558, 2424.8616,-1810.0613,18.6510,359.3500,0,0,3600);//audi1

	AddStaticVehicleEx(516, 2425.0764,-1816.5448,18.8286,179.0849,0,0,3600);//vaz 21099
	AddStaticVehicleEx(516, 2420.7285,-1816.4054,18.8307,179.0035,0,0,3600);//vaz 21099
	AddStaticVehicleEx(516, 2416.4958,-1816.2133,18.8339,179.3606,0,0,3600);//vaz 21099
	AddStaticVehicleEx(516, 2412.3525,-1816.1954,18.8123,179.0901,0,0,3600);//vaz 21099

	AddStaticVehicleEx(579, 2407.8250,-1816.1100,19.2039,178.0999,0,0,3600);//gelik
	AddStaticVehicleEx(579, 2403.6257,-1816.1276,19.2118,181.2769,0,0,3600);//gelik
	AddStaticVehicleEx(579, 2399.6091,-1816.1813,19.2055,179.7655,0,0,3600);//gelik
	job_car[TEAM_FSB_CAR][1] = AddStaticVehicleEx(601,2420.7625,-1796.6593,18.6905,179.8344,16,16,3600); // машина fsb

	SetVehicleHealth(job_car[TEAM_FSB_CAR][0], 1000000.0);
	SetVehicleHealth(job_car[TEAM_FSB_CAR][1], 1000000.0);

	job_car[VELO][0] = AddStaticVehicleEx(509,1818.2428,2513.2729,15.3373,83.9994,0,0,300); // велосипед
	AddStaticVehicleEx(509,1818.2673,2515.2239,15.2991,78.9251,0,0,300); // велосипед
	AddStaticVehicleEx(509,1815.4952,2518.1267,15.3371,81.1773,0,0,300); // велосипед
	AddStaticVehicleEx(509,1815.7534,2520.0635,15.3375,79.5587,0,0,300); // велосипед
	AddStaticVehicleEx(509,1812.1753,2523.0869,15.3368,80.3483,0,0,300); // велосипед
	AddStaticVehicleEx(509,1812.4631,2524.8750,15.3368,85.0137,0,0,300); // велосипед
	AddStaticVehicleEx(509,1808.8082,2528.0085,15.3367,87.7388,0,0,300); // велосипед
	last_veh_id = job_car[VELO][1] = AddStaticVehicleEx(509,1809.0144,2529.6121,15.3207,82.7718,0,0,300); // велосипед

	for( new i = 0; i < last_veh_id; i++)
	{
	    vehicle[i][veh_fuel] = 80.0;
	    vehicle[i][veh_limit] = 0.0;
	}
	printf("[UNIGVA]: Всего автомобилей загружено: %d", last_veh_id);
//-------------------------------------------------------------------------------------------------------------------------------

    //-------------------------[ MAP ICON ]-------------------------------------
    for(new i = 0; i < sizeof(IconInfo); i++) CreateDynamicMapIcon(IconInfo[i][mCoords][0],IconInfo[i][mCoords][1],IconInfo[i][mCoords][2], IconInfo[i][mIDIcon], -1,IconInfo[i][mVirtW],IconInfo[i][mInt], 0, 150.0);
    printf("[UNIGVA]: Иконки на радаре загружены!");    
//------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------[ LOAD TRAINS ]-----------------------------------------------------------
	new train_1 = AddStaticVehicle(538,2496.8569,-2021.4492,22.1124,180.5482,6,0);
//------------------------------------------------------------------------------------------------------------------------------



