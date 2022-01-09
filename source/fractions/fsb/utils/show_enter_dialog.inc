stock ShowEnterDialog(playerid)
{
    ShowPlayerDialog
    (
        playerid, 
        D_FSB_ENTER_DIALOG, 
        DIALOG_STYLE_LIST, 
        !"{"cblue"}Войти в", 
        !"{"cblue"}1. {ffffff}Офис\n\
        {"cblue"}2. {ffffff}Гараж\n\
        {"cblue"}3. {ffffff}Крыша", 
        !"Выбрать", 
        !"Закрыть"
    );
    return 1;
}