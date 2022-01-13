stock SAMP_AC_REAL_SPEED(playerid)
{
	new
	SAMP_AC_VEHICLE = GetPlayerVehicleID(playerid),
Float: SPEED_X,
Float: SPEED_Y,
Float: SPEED_Z;

	switch(SAMP_AC_VEHICLE)
	{
	case 0: GetPlayerVelocity(playerid, SPEED_X, SPEED_Y, SPEED_Z);
	default: GetVehicleVelocity(SAMP_AC_VEHICLE, SPEED_X, SPEED_Y, SPEED_Z);
	}
	return floatround(floatsqroot(floatpower(floatabs(SPEED_X), 2.0) + floatpower(floatabs(SPEED_Y), 2.0) + floatpower(floatabs(SPEED_Z), 2.0)) * 100.0);
}