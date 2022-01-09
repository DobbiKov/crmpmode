new PlayerBlinded[MAX_PLAYERS];

CMD:box(playerid, params[])
{
    if(!IsAOpg(playerid) && !IsAPolice(playerid))
        return YouCannotUseThisFunc(playerid);
    
    if(!IsAFSB(playerid) && PlayerInfo[playerid][pRang] < 3)
        return YouCannotUseThisFunc(playerid);

    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /box [ID игрока]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) 
        return PlayerOffLine(playerid);
    if(!IsPlayerInRangeOfPlayer(playerid, to_player, 5.0))
        return SCM(playerid, red, !"Игрок далеко от вас!");
    if(playerid == to_player)
        return SCM(playerid, red, !"Вы не можете одеть мешок не себя!");
    if(PlayerBlinded[to_player] >= 1)
        return SCM(playerid, red, !"На игрока уже надет мешок!");
    if(GetPVarInt(to_player, "tied") != 1 && GetPVarInt(to_player, "cuffed") != 1)
        return SCM(playerid, red, !"Игрок не связан!");
    

  
    new string[128];
    format(string, sizeof(string), "Вы одели мешок на голову %s", PlayerName(to_player));
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s одел вам мешок на голову", PlayerName(playerid));
    SCM(to_player, blue, string);
    
    format(string, sizeof(string), "одевает мешок на голову %s", PlayerName(to_player));
    cmd::me(playerid, string);

    for(new i = 0; i <= 4; i++)
        TextDrawShowForPlayer(to_player, blindtd[i]);
    PlayerBlinded[to_player] = 1; 
    
    return 1;  
}

CMD:unbox(playerid, params[])
{
    if(!IsAOpg(playerid) && !IsAPolice(playerid))
        return YouCannotUseThisFunc(playerid);
    
    if(!IsAFSB(playerid) && PlayerInfo[playerid][pRang] < 3)
        return YouCannotUseThisFunc(playerid);

    extract params -> new to_player; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /unbox [ID игрока]");
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) 
        return PlayerOffLine(playerid);
    if(!IsPlayerInRangeOfPlayer(playerid, to_player, 5.0))
        return SCM(playerid, red, !"Игрок далеко от вас!");
    if(playerid == to_player)
        return SCM(playerid, red, !"Вы не можете снять мешок с себя!");
    if(PlayerBlinded[to_player] <= 0)
        return SCM(playerid, red, !"На игрока не надет мешок!");

  
    new string[128];
    format(string, sizeof(string), "Вы сняли мешок с головы %s", PlayerName(to_player));
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s снял мешок с вашей головы", PlayerName(playerid));
    SCM(to_player, blue, string);
    
    format(string, sizeof(string), "снимает мешок с головы %s", PlayerName(to_player));
    cmd::me(playerid, string);

    for(new i = 0; i <= 4; i++)
        TextDrawHideForPlayer(to_player, blindtd[i]);
    PlayerBlinded[to_player] = 0; 
              
    
    return 1;  
}

public OnPlayerSpawn(playerid)
{
    for(new i = 0; i <= 4; i++)
        TextDrawHideForPlayer(playerid, blindtd[i]);
    PlayerBlinded[playerid] = 0; 

    #if defined box__OnPlayerSpawn
        return box__OnPlayerSpawn(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else 
    #define _ALS_OnPlayerSpawn
#endif


#define OnPlayerSpawn box__OnPlayerSpawn
#if defined box__OnPlayerSpawn
    forward box__OnPlayerSpawn(playerid);
#endif