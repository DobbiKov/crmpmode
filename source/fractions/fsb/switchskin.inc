CMD:switchskin(playerid, params[]){
    if(!IsAFSB(playerid) || PlayerInfo[playerid][pRang] < 8) return YouCannotUseThisFunc(playerid);
    extract params -> new skin_id; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /switchskin [ID ����� (1 - 300)]");
    if(skin_id < 1 || skin_id > 299) return SCM(playerid, red, "����������� ����� �� 1 �� 299.");
    cmd::me(playerid, "����������");
    SCM(playerid, blue, "�� �����������. �� �������� ����� ���������� ������� � �����.");
    PlayerInfo[playerid][pFSkin] = skin_id;
    SaveAccounts(playerid);
    return SetPlayerSkin(playerid, skin_id);
}