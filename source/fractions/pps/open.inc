CMD:open(playerid)
{
    if(!IsAPolice(playerid)) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 8.0, 1900.59, 2157.94, 15.56)) return 1;

    switch(open_pps_status)
    {
        case false:
        {
            SCM(playerid, green, "�� ������� ��������");
            MoveObject(open_pps, 1900.59, 2157.94, 15.56, 0.2,  0.00, 0.00, 90.00);
            open_pps_status = true;
        }
        case true:
        {
            SCM(playerid, red, "�� ������� ��������");
            MoveObject(open_pps, 1900.59, 2157.94, 15.56, 0.2,  0.00, -90.00, 90.00);
            open_pps_status = false;          
        }
    }
    return 1;
}