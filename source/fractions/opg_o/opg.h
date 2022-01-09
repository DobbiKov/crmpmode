#define OPG_S_DOOR 0
#define OPG_O_DOOR 1
new OpgDoors[2];
new bool: OpgDoorsStatus[2];

enum
	E_CONTRABAND_ENUM
{
	Float: contraband_route_x,
	Float: contraband_route_y,
	Float: contraband_route_z
};

new
	Float: contraband_pos[][E_CONTRABAND_ENUM] =
	{
		{2024.6172,1690.1265,15.9300},
		{2004.3597,1348.2574,26.1533},
		{2277.0801,1391.9866,11.4501},
        {1745.4849,-2364.7610,8.2991},
        {2327.1643,445.8519,21.4450},
        {1519.2729,-893.6899,39.1834},
        {1943.2849,-1613.9069,14.9636},
        {2794.4978,-2571.6919,11.5845},
        {1974.9193,-2659.1907,9.4734},
        {162.7108,-2799.7930,6.5492},
        {1921.4929,847.5480,15.4993},
        {2299.5996,-190.9950,3.5000}
	};

new next_contraband_time = 0;

#define CONTRABANDA_VALUE 15
#define CONTRABANDA_PRICE 100
#define CONTRABANDA_GRAM_IN_BAG 500

new contraband_pos_id = -1;
new contraband_fraction = -1;
new contraband_timer = -1;
new contraband_pickup = -1;
new contraband_bags = CONTRABANDA_VALUE;




// new string[128];
// format(string, sizeof(string), "UPDATE `other` SET `next_contraband_time` = '%d' LIMIT 1", next_contraband_time);
// mysql_tquery(connects, string, "", "");