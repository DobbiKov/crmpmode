public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER) 
    { 
        if((GetTickCount()-GetPVarInt(playerid, "cartime")) < 1000) 
        { 
            SetPVarInt(playerid, "carspam", GetPVarInt(playerid, "carspam")+1); 
            if(GetPVarInt(playerid, "carspam") >= 5) { 
                return ResultCheat(playerid, 12);
            } 
        } 
        SetPVarInt(playerid, "cartime", GetTickCount()); 
    } 
	#if defined flood_veh__OnPlayerStateChange
		return flood_veh__OnPlayerStateChange(playerid, newstate, oldstate);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerStateChange
	#undef OnPlayerStateChange
#else
	#define _ALS_OnPlayerStateChange
#endif

#define OnPlayerStateChange flood_veh__OnPlayerStateChange
#if defined flood_veh__OnPlayerStateChange
	forward flood_veh__OnPlayerStateChange(playerid, newstate, oldstate);
#endif