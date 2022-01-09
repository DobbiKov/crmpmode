CMD:sfly(playerid)
{
    if(PlayerInfo[playerid][bAdmin] < 3) return ShowCommandNotFound(playerid);
    if(GetPVarInt(playerid, "is_player_sfly") == 1)
    {
        SCM(playerid, white, "Вы вышли из режима супер полёта!");
        DeletePVar(playerid, "is_player_sfly");
        StopFly(playerid);
    }
    else
    {
        SCM(playerid, white, "Вы вошли в режим супер полёта!");
        SetPVarInt(playerid, "is_player_sfly", 1);
        StartFly(playerid);
    }
    return 1;
}

public OnPlayerSpawn(playerid)
{
    if(GetPVarInt(playerid, "exit_fly_mode") == 1)
    {
        if(PlayerInfo[playerid][pMember] > 0) SetPlayerSkin(playerid, PlayerInfo[playerid][pFSkin]);
        else SetPlayerSkin(playerid, PlayerInfo[playerid][pChar]);
    }
    #if defined cmd_sfly__OnPlayerSpawn
        return cmd_sfly__OnPlayerSpawn(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn cmd_sfly__OnPlayerSpawn
#if defined cmd_sfly__OnPlayerSpawn
    forward cmd_sfly__OnPlayerSpawn(playerid);
#endif