stock CanPlayerGetAmountDrugs(playerid, amount)
{
    if(PlayerInfo[playerid][pVIP] > 0 && PlayerInfo[playerid][pDrugs] + amount > MAX_DRUGS_IN_INVENTORY_VIP)
        return false;
    if(PlayerInfo[playerid][pDrugs] + amount > MAX_DRUGS_IN_INVENTORY)
        return false;
    return true;
}