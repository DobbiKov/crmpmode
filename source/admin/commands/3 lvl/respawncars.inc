CMD:respawncars(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);
    extract params -> new radius; else return SCM(playerid, yellow, "[���������]: {FFFFFF}������� /respawncars [radius]");

	else if(!(radius >= -1 && radius <= 0x50)) return SCM(playerid, grey, "�������� �������� �������");
	if(radius == -1)
	{

	    for(new i = 1; i < MAX_VEHICLES; i++)
		{
		    if(!IsVehicleOccupied(i) && IsAbleToRespawnVehicle(i)) SetVehicleToRespawn(i);
		}
		new string[128];
		format(string, sizeof(string), "[A] %s[%d] ����������� ���� ��������� �� �������", PlayerInfo[playerid][pName], playerid);
		SCMA(grey, string);
	}
	else
	{
	    new Float:x, Float:y, Float:z;
	    for(new i = 1; i < MAX_VEHICLES; i++)
		{
		    GetPlayerPos(playerid, x, y, z);
		    if(IsVehicleInRangeOfPoint(i, radius, x, y, z))
			{
		 		if(!IsVehicleOccupied(i) && IsAbleToRespawnVehicle(i)) SetVehicleToRespawn(i);
			}
		}
		new string[128];
		format(string, sizeof(string), "[A] %s[%d] ����������� ���� ��������� � ������� %d �", PlayerInfo[playerid][pName], playerid, radius);
		SCMA(grey, string);
	}
	return 1;
}