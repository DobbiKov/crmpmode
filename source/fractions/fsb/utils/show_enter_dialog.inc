stock ShowEnterDialog(playerid)
{
    ShowPlayerDialog
    (
        playerid, 
        D_FSB_ENTER_DIALOG, 
        DIALOG_STYLE_LIST, 
        !"{"cblue"}����� �", 
        !"{"cblue"}1. {ffffff}����\n\
        {"cblue"}2. {ffffff}�����\n\
        {"cblue"}3. {ffffff}�����", 
        !"�������", 
        !"�������"
    );
    return 1;
}