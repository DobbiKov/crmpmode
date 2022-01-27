const MAX_OWNABLE_CARS = MAX_VEHICLES;

enum E_OWNABLE_CAR
{
    oc_id,
	oc_owner_id,
	oc_number[32],
	oc_modelid,
	oc_color_1,
	oc_color_2,
	bool: oc_lock_status,
	Float: oc_mileage,
	Float: oc_fuel,
	Float: oc_health,
	tun_weels,
	tun_nitro,
	cost_car
};

new ownable_car[MAX_OWNABLE_CARS][E_OWNABLE_CAR];
new ownable_car_id[MAX_OWNABLE_CARS] = {-1, ...};
new Text3D: ownable_car_label[MAX_OWNABLE_CARS] = {Text3D: -1, ...};
new player_ownable_car[MAX_PLAYERS] = {-1, ...};