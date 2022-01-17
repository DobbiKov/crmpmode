new bool:antibots = true;
new stock prohibited_weapons[10] = {40, 39, 38, 37, 36, 35, 18, 16, 44, 45};

enum PG_Enum
{
	//DoS
	PG_InterP[16],
	//Flood
	FLOOD_CMD,
	FLOOD_TXT,
	FLOOD_TICK,
	//AC
bool:PG_ObhodAvt,
bool:USE_CRASHER,
	Pizdorvanka,
	warning_kick,
	Kill_Time,
	pGuns[47],
	pGunEst,
	pCarAC,
	pCarEntTime,
	pCarSpeed,
Float:P_POS_X,
Float:P_POS_Y,
Float:P_POS_Z,
	P_SET_POS_TICK,
Float:P_SET_POS_X,
Float:P_SET_POS_Y,
Float:P_SET_POS_Z,
	pCarTolkKol,
	pCarTolkTick,
Float:pCarTolkKord[3],
	pCarTolkVeh

}
new PG_DATA[MAX_PLAYERS][PG_Enum];

//new bool:antibots = true;//BOTSGUARD: false - защита неактивна, true - активна.

new reasonSTR[150];

new stock Maximum_Passengers[27] =
{
	0x10331113, 0x11311131, 0x11331313, 0x80133301,
	0x1381F110, 0x10311103, 0x10001F10, 0x11113311,
	0x13113311, 0x31101100, 0x30001301, 0x11031311,
	0x11111331, 0x10013111, 0x01131100, 0x11111110,
	0x11100031, 0x11130221, 0x33113311, 0x11111101,
	0x33101133, 0x101001F0, 0x03133111, 0xFF11113F,
	0x13330111, 0xFF131111, 0x0000FF3F
};

//******************
stock IsOdinPatrGun(weaponid)
{
	if(weaponid > 0 && weaponid < 16) return 1;
	if(weaponid == 46) return 1;
	return 0;
}