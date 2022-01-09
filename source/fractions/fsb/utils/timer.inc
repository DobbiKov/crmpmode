publics MoveFSBLiftTo3flat()
{
    MoveObject(fsb_lift, 2395.89, -1830.22, 32.67, 2.00,  0.00, 0.00, 180.00);
    SetTimer("MoveFSBLiftTo1flatdown", (1000 * 5) + (1000 * 5), false);
}
publics MoveFSBLiftTo1flatdown()
{
    MoveObject(fsb_lift, 2395.89, -1830.22, 23.06, 2.00,  0.00, 0.00, 180.00);
    SetTimer("MoveFSBLiftToGarage", (1000 * 5) + (1000 * 5), false);
}
publics MoveFSBLiftToGarage()
{
    MoveObject(fsb_lift, 2395.8899, -1830.2700, 19.1800, 0.8, 0.00, 0.00, 180.00);
    SetTimer("MoveFSBLiftTo1flatup", (1000 * 5) + (1000 * 5), false);
}
publics MoveFSBLiftTo1flatup()
{
    MoveObject(fsb_lift, 2395.89, -1830.22, 23.06, 0.8,  0.0, 0.00, 180.00);
    SetTimer("MoveFSBLiftTo3flat", (1000 * 5) + (1000 * 5), false);
}