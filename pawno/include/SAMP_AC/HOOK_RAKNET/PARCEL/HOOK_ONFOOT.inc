IPacket:RAKNET_PLAYER_SYNC(playerid, BitStream:bs)
{
	new RAKNET_ONFOOT[RAKNET_ONFOOT_SYNC];
	new SAMP_AC_TICK = GetTickCount();
	new SAMP_AC_PING = GetPlayerPing(playerid);
	
	BS_ReadUint8(bs, 8);
	BS_ReadOnFootSync(bs, RAKNET_ONFOOT);


	SERVER_INFO[playerid][SAMP_POS_X] = RAKNET_ONFOOT[RAKNET_POS_X];
	SERVER_INFO[playerid][SAMP_POS_Y] = RAKNET_ONFOOT[RAKNET_POS_Y];
	SERVER_INFO[playerid][SAMP_POS_Z] = RAKNET_ONFOOT[RAKNET_POS_Z];
	
	SERVER_INFO[playerid][SAMP_SPEED_X] = RAKNET_ONFOOT[RAKNET_SPEED_X];
	SERVER_INFO[playerid][SAMP_SPEED_Y] = RAKNET_ONFOOT[RAKNET_SPEED_Y];
	SERVER_INFO[playerid][SAMP_SPEED_Z] = RAKNET_ONFOOT[RAKNET_SPEED_Z];
	
	#include                                                                        SAMP_AC/PROTECTION/NOP/POSITION
	
	#include																		SAMP_AC/PROTECTION/CHEAT/AIR_BREAK
	#include																		SAMP_AC/PROTECTION/CHEAT/TELEPORT_HACK
	#include																		SAMP_AC/PROTECTION/CHEAT/FlY_HACK
	#include																		SAMP_AC/PROTECTION/CHEAT/SLAP_SPEED
	#include																		SAMP_AC/PROTECTION/CHEAT/WEAPON_HACK
	
	
	SERVER_INFO[playerid][SAMP_FIX_Z] = RAKNET_ONFOOT[RAKNET_POS_Z];
	return 1;
}
