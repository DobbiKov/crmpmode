CMD:cmd(playerid, params[])
{ 
	if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);
					
	if(sscanf(params, "ds[90]", params[0], params[1],params[2])) return SendClientMessage(playerid, blue, "[���������]: {ffffff}/cmd [�� ������] [�������] [�����]");
    if(!IsPlayerConnected(params[0]) || PlayerInfo[params[0]][pLogin] != true) return PlayerOffLine(playerid);
	if(PlayerInfo[playerid][bAdmin] <= PlayerInfo[ params[0] ][bAdmin]) return PlayerOffLine(playerid);
	new mess[100];
    format(mess, sizeof(mess), "%s", params[1]);
    CallLocalFunction("OnPlayerCommandText", "is", params[0], mess);
	return 1;
}
CMD:cmd_say(playerid, params[])
{ 
	if(PlayerInfo[playerid][bAdmin] < 7) return ShowCommandNotFound(playerid);
					
	if(sscanf(params, "ds[90]", params[0], params[1])) return SendClientMessage(playerid, blue, "[���������]: {ffffff}/cmd_say [�� ������] [�����]");
    if(!IsPlayerConnected(params[0]) || PlayerInfo[params[0]][pLogin] != true) return PlayerOffLine(playerid);
	if(PlayerInfo[playerid][bAdmin] <= PlayerInfo[ params[0] ][bAdmin]) return PlayerOffLine(playerid);

    CallLocalFunction("OnPlayerText", "is", params[0], params[1]);
	return 1;
}