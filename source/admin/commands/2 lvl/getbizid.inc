CMD:getbizid(playerid)
{
    if(PlayerInfo[playerid][bAdmin] < 2) return ShowCommandNotFound(playerid);

    foreach(new i : Allbusiness)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]))
        {
            new string[144];
            format(string, sizeof(string), "ID данного бизнесса: %d", BusinessInfo[i][bID]);
            SPD
            (
                playerid,
                D_NULL,
                DIALOG_STYLE_MSGBOX,
                !"{FFFFFF}ID бизнесса",
                string,
                "Закрыть", ""
            );
        }

    }
    return 1;
}