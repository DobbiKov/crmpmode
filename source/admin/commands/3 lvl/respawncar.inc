CMD:rscar(playerid, params[])
	return cmd::respawncar(playerid, params);
CMD:respawncar(playerid, params[])
{
	if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);
    extract params -> new id; else return SCM(playerid, yellow, "[���������]: {FFFFFF}������� /respawncar [ID car]");

	if(!IsValidVehicle(id)) return SCM(playerid, red, "���������� ��� ���� ID ���.");

	SetVehicleToRespawn(id);

	new string[128];
	format(string, sizeof(string), "[A] %s[%d] ����������� ��������� ID: %d", PlayerInfo[playerid][pName], playerid, id);
	SCMA(grey, string);
	return 1;
}