ALTX:godmode("/gm");
CMD:godmode(playerid, params[])
{
    if(!GetPVarInt(playerid, "gm"))          
    {                                            
        SetPlayerHealth(playerid, Float:0x7F800000 );   
        SCM(playerid, white, "Вы включили GodMode, для того что бы выключить его, введите: /gm");
        SetPVarInt(playerid, "gm", 1);         
    }
    else 
    {                                           
        SetPlayerHealth(playerid, 100);
        SCM(playerid, white, "Вы выключили GodMode, для того что бы включить его, введите: /gm");
        SetPVarInt(playerid, "gm", 0);          
    }
} 