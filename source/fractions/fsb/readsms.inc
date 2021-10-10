CMD:readsms(playerid, params[]){
    if(!IsAFSB(playerid) && PlayerInfo[playerid][bAdmin] < 2) return YouCannotUseThisFunc(playerid);

    if(PlayerInfo[playerid][pReadsms] == 0)
    {
        cmd::me(playerid, "начал прослеживать sms сообщения");
        SCM(playerid, blue, "Вы начали прослеживать SMS сообщения. Прекратить прослушку: /readsms");
        PlayerInfo[playerid][pReadsms] = 1;
    }
    else
    {
        cmd::me(playerid, "прекратил прослеживать sms сообщения");
        SCM(playerid, blue, "Вы прекратили прослеживать SMS сообщения.");
        PlayerInfo[playerid][pReadsms] = 0;
    }
    
    return 1;
}