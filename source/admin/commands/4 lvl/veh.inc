CMD:veh(playerid,params[])
{
	if(PlayerInfo[playerid][bAdmin] < 4 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);
	if(sscanf(params,"ddd",params[0],params[1],params[2])) return SCM(playerid, white, "{"cblue"}� [���������]{"cwhite"}: ����������� /veh [carid] [����1] [����2]");
	if(params[0] < 400 || params[0] > 611) return SCM(playerid,  red, "����� ������ �� ����� ���� ������ 400 � ������ ��� 611!");
	if(params[1] < 0 || params[1] > 126) return SCM(playerid,  red, "����� ����� �� ����� ���� ������ 0 � ������ 126!");
	if(params[2] < 0 || params[2] > 126) return SCM(playerid,  red, "����� ����� �� ����� ���� ������ 0 � ������ 126!");
	if(TotalAdminVehicles > 50)
	{
	   SCM(playerid,  red, "����� �����-����� ��������");
	   return 1;
	}
	new Float:X,Float:Y,Float:Z;
	GetPlayerPos(playerid, X,Y,Z);
	new Float: face_angle;
	GetPlayerFacingAngle(playerid, face_angle);

	AVehicle[TotalAdminVehicles] = CreateVehicle(params[0], X+1,Y+1,Z, face_angle, params[1], params[2], -1);

	LinkVehicleToInterior(AVehicle[TotalAdminVehicles], GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(AVehicle[TotalAdminVehicles],GetPlayerVirtualWorld(playerid));
	vehicle[AVehicle[TotalAdminVehicles]][veh_fuel] = 80.0;
	vehicle[AVehicle[TotalAdminVehicles]][veh_limit] = 0.0;
    stringer[0] = EOS;
	format(stringer, 128, "[A] %s[%d] ������ ���������� [model: %d] [vehicleid: %d]", PlayerInfo[playerid][pName],playerid,params[0],AVehicle[TotalAdminVehicles]);
	SCMA(grey, stringer);
	TotalAdminVehicles ++;
	return 1;
}