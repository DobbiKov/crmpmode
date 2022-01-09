stock owner_of_vehicle_by_id(vehicleid)
{
    foreach(new i: Player)
    {
        if(player_ownable_car[i] == vehicleid)
        {
            return i;
        }
    }
    return -1;
}