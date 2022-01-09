stock IsAbleToRespawnVehicle(vehicleid)
{
    switch(GetVehicleModel(vehicleid))
    {
        case 435, 450, 584: return false;
    }
    return true;
}