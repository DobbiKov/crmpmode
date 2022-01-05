CMD:uncuff(playerid, params[])
{
    if(!IsAPolice(playerid) && PlayerInfo[playerid][pMember] != TEAM_ADM) return YouCannotUseThisFunc(playerid);
    
    extract params -> new to_player; else return SCM(playerid, yellow, "[Оповещение]: {FFFFFF}Используйте /uncuff [ID игрока]");
    
    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(!IsPlayerInRangeOfPoint(to_player, 5.0, x, y, z)) return SCM(playerid, red, "Человек далеко от вас!");
    if(to_player == playerid) return SCM(playerid, red, "Вы указали свой ID!");
    if(GetPVarInt(to_player, "cuffed") != 1) return SCM(playerid, red, "Человек не в наручниках!");

    SetPlayerSpecialAction(to_player, SPECIAL_ACTION_NONE);
    DeletePVar(to_player, "cuffed");

    new string[128];
    format(string, sizeof(string), "Вы сняли наручники с %s", PlayerName(to_player));
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s снял с вас наручники", PlayerName(playerid));
    SCM(to_player, blue, string);
    
    format(string, sizeof(string), "снимает наручники с %s", PlayerName(to_player));
    cmd::me(playerid, string);
    func_ungotome(playerid, to_player);
    return UnFreezePlayer(to_player);
}