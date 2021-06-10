CMD:myskill(playerid)
{
    SCM(playerid, white, !"Вы посмотрели свои навыки владения оружием.");
    new fmt_dialog[526];
    format
    (
        fmt_dialog, sizeof fmt_dialog,
        "{ffffff}SDPistol:\t%d / 100%%\n\
        Deagle:\t%d / 100%%\n\
        ShotGun:\t%d / 100%%\n\
        MP5:\t\t%d / 100%%\n\
        AK-47:\t\t%d / 100%%\n\
        M4A1:\t\t%d / 100%%",
        PlayerInfo[playerid][SKILL_SD_PISTOL],
        PlayerInfo[playerid][SKILL_DEAGLE],
        PlayerInfo[playerid][SKILL_SHOTGUN],
        PlayerInfo[playerid][SKILL_MP5],
        PlayerInfo[playerid][SKILL_AK_47],
        PlayerInfo[playerid][SKILL_M4]
    );
    ShowPlayerDialog
    (
        playerid, D_NULL, DIALOG_STYLE_MSGBOX,
        !"{"cblue"}Навыки владения оружием",
        fmt_dialog,
        !"Закрыть", !""
    );
    return 1;    
}