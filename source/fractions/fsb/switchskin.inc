CMD:switchskin(playerid, params[]){
    if(!IsAFSB(playerid)) return YouCannotUseThisFunc(playerid);
    extract params -> new skin_id; else return SCM(playerid, blue, "[Подсказка]: {FFFFFF}Используйте /switchskin [ID скина (1 - 300)]");
    if(skin_id < 1 || skin_id > 299) return SCM(playerid, red, "Используйте число от 0 до 299.");
    cmd::me(playerid, "переоделся");
    SCM(playerid, blue, "Вы переоделись. Не забудьте потом переодется обратно в форму.");
    PlayerInfo[playerid][pFSkin] = skin_id;
    SaveAccounts(playerid);
    return SetPlayerSkin(playerid, skin_id);
}