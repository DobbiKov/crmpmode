CMD:flip(playerid,params[])
{
	if(PlayerInfo[playerid][bAdmin] < 4 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);
	if(!TotalAdminVehicles) return 1;
	new vehh = -1;
	if(!strlen(params)){
		if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid,  red, "�� �� � ����������.");
		vehh = GetPlayerVehicleID(playerid);
	}
	else{
		extract params -> new id; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /flip [ID ����������]");
		if(!IsValidVehicle(id))
			return SCM(playerid, red, "���������� ��� ����� ID ���!");
		vehh = id;
	}

    new Float:x, Float:y, Float:z;
    new Float:angle;
    
    // �������� ������� � ���� ��������
    GetVehiclePos(vehh, x, y, z);
    GetVehicleZAngle(vehh, angle);
    
    // ������������� ������� � ���� ��������
    SetVehiclePos(vehh, x, y, z + 1.5);
    SetVehicleZAngle(vehh, angle);


	stringer[0] = EOS;
	format(stringer, 128, "[A] %s ���������� ���������� [model: %d] [vehicleid: %d]", PlayerInfo[playerid][pName],GetVehicleModel(vehh),vehh);
	SCMA(grey, stringer);

	return 1;
}