CMD:arrest(playerid, params[])
{
    if(!IsAPolice(playerid)) return YouCannotUseThisFunc(playerid);
    if(!IsPlayerInRangeOfPoint(playerid, 5.0, 1939.8840,2161.2378,15.7034)) return SCM(playerid, red, "�� �� � ������!");

    extract params -> new to_player; else return SCM(playerid, yellow, "[���������]: {FFFFFF}����������� /arrest [ID ������]");

    if(!IsPlayerConnected(to_player) || PlayerInfo[to_player][pLogin] == false) return PlayerOffLine(playerid);
    if(PlayerInfo[to_player][pWANTED] < 1) return SCM(playerid, red, "����� �� � �������!");
    if(GetPVarInt(to_player, "cuffed") < 1) return SCM(playerid, red, "����� �� � ����������!");
    if(!IsPlayerInRangeOfPlayer(playerid, to_player, 5.0))
        return SCM(playerid, red, !"����� ������ �� ���!");



    PlayerInfo[to_player][pKPZ] = PlayerInfo[to_player][pWANTED]*600;
    PlayerInfo[to_player][pJP] = random(2);

    new string[144];
    format(string, sizeof(string), "�� �������� ����������� %s � ������ � �������� ������ � ������� %d ������.", PlayerName(to_player), PlayerInfo[to_player][pWANTED]*500);
    SCM(playerid, blue, string);

    format(string, sizeof(string), "%s %s ������� %s � ������. � ������� ������ � ������� %d ������.", PlayerRank[ PlayerInfo[playerid][pMember] ][ PlayerInfo[playerid][pRang] ], PlayerInfo[playerid][pName], PlayerInfo[to_player][pName], PlayerInfo[to_player][pWANTED]*500);
    SCMPolice(blue, string);

    format(string, sizeof(string), "%s ������� ��� � ������, ��� ��� �� ���� � �������. ���������� ����� �� ������ - /time", PlayerInfo[playerid][pName]);
    SCM(to_player, blue, string);

    GiveMoney(playerid, PlayerInfo[to_player][pWANTED]*500, "������� �����������");
    PlayerInfo[to_player][pWANTED] = 0;
    SetPlayerWantedLevel(to_player, 0);
    DeletePVar(to_player, "cuffed");
    SetPlayerSpecialAction(to_player, SPECIAL_ACTION_NONE); 

    ResetPlayerWeaponsAC(to_player);

    func_ungotome(playerid, to_player);

    SaveAccounts(playerid);
    SaveAccounts(to_player);
    PutPlayerInKPZ(to_player);
    return 1;
}