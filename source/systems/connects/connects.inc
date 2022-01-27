#define CONN_TYPE_CONNECT 1 
#define CONN_TYPE_DISCONNECT 2

public OnPlayerConnect(playerid)
{
	new hour, minute, second, year, month, day, _date[64];
	gettime(hour, minute, second);
	getdate(year, month, day);
	format(_date, sizeof(_date), "%0d.%02d.%d %d:%02d:%02d", day, month, year, hour, minute, second);

    new ip[20];
    GetPlayerIp(playerid, ip, sizeof(ip));

    new _nick[MAX_PLAYER_NAME];
    GetPlayerName(playerid, _nick, MAX_PLAYER_NAME);

    new query[256];
    format(
        query, 
        sizeof(query), 
        "INSERT INTO `connects` (`date`, `account_id`, `ip`, `nick`, `unixdate`, `type`) VALUES ('%s', '%d', '%s', '%s', '%d', '%d')",
        _date,
        -1,
        ip,
        _nick,
        gettime(),
        CONN_TYPE_CONNECT
    );
    mysql_tquery(connects, query);

	#if	defined	connects__OnPlayerConnect
		return connects__OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerConnect
	#undef	OnPlayerConnect
#else
	#define	_ALS_OnPlayerConnect
#endif

#define	OnPlayerConnect connects__OnPlayerConnect
#if	defined	connects__OnPlayerConnect
	forward connects__OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	new hour, minute, second, year, month, day, _date[64];
	gettime(hour, minute, second);
	getdate(year, month, day);
	format(_date, sizeof(_date), "%0d.%02d.%d %d:%02d:%02d", day, month, year, hour, minute, second);

    new ip[20];
    GetPlayerIp(playerid, ip, sizeof(ip));

    new acc_id = PlayerInfo[playerid][pID] < 1 ? -1 : PlayerInfo[playerid][pID];

    new query[256];
    format(
        query, 
        sizeof(query), 
        "INSERT INTO `connects` (`date`, `account_id`, `ip`, `nick`, `unixdate`, `type`) VALUES ('%s', '%d', '%s', '%s', '%d', '%d')",
        _date,
        acc_id,
        ip,
        PlayerInfo[playerid][pName],
        gettime(),
        CONN_TYPE_DISCONNECT
    );
    mysql_tquery(connects, query);

	#if defined connects_OnPlayerDisconnect
		return connects_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect connects_OnPlayerDisconnect
#if defined connects_OnPlayerDisconnect
	forward connects_OnPlayerDisconnect(playerid, reason);
#endif

publics ConnectsChangeAccountID(playerid)
{
    new rows, fields;
    cache_get_data(rows, fields);
    if(rows)
    {
        new _id = cache_get_field_content_int(0, "id");

        new query[144];
        format(query, sizeof(query), "UPDATE `connects` SET `account_id` = '%d' WHERE `id` = '%d'", PlayerInfo[playerid][pID], _id);
        return mysql_tquery(connects, query);
    }
    return 1;
}