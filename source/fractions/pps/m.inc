CMD:m(playerid, params[])
{
    if(!IsAPolice(playerid)) return YouCannotUseThisFunc(playerid);

    extract params -> new string: text[144]; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /m [�����]");
    if(!strlen(text)) return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /m [�����]");

    new string[144];
    format(string, sizeof(string), "[M] %s %s: %s", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerName(playerid), text);
    ProxDetector(50.0, playerid, string, yellow, yellow, yellow, yellow,yellow);
    return 1;
}