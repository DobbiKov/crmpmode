CMD:readsms(playerid, params[]){
    if(!IsAFSB(playerid) && PlayerInfo[playerid][bAdmin] < 2) return YouCannotUseThisFunc(playerid);

    if(PlayerInfo[playerid][pReadsms] == 0)
    {
        cmd::me(playerid, "����� ������������ sms ���������");
        SCM(playerid, blue, "�� ������ ������������ SMS ���������. ���������� ���������: /readsms");
        PlayerInfo[playerid][pReadsms] = 1;
    }
    else
    {
        cmd::me(playerid, "��������� ������������ sms ���������");
        SCM(playerid, blue, "�� ���������� ������������ SMS ���������.");
        PlayerInfo[playerid][pReadsms] = 0;
    }
    
    return 1;
}