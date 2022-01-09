// split(name, halfname, '_');  // Разделяем name(имя) до символа "_"

public OnPlayerCommandPerformed(playerid, cmdtext[], success)
{
	if(success != -1)
	{
		LogsSystem(playerid, cmdtext);
	}
    

    #if	defined	logsys__OnPlayerCommandPerforme
		return logsys__OnPlayerCommandPerforme(playerid, cmdtext, success);
	#else
		return 1;
	#endif
}
#if	defined	_ALS_OnPlayerCommandPerforme
	#undef	OnPlayerCommandPerforme
#else
	#define	_ALS_OnPlayerCommandPerforme
#endif

#define	OnPlayerCommandPerformed logsys__OnPlayerCommandPerforme
#if	defined	logsys__OnPlayerCommandPerforme
	forward logsys__OnPlayerCommandPerforme(playerid, cmdtext[], success);
#endif

stock LogsSystem(playerid, cmdtext[])
{
    new split_data[24][256];
    split(cmdtext, split_data, ' ');
    new command_name[128] = ""; 
    format(command_name, sizeof(command_name), "%s", split_data[0]);
    
    //remove /
    for(new i = 0; i < sizeof(command_name) - 1; i++)
    {
        command_name[i] = command_name[i + 1];
    }
    //
    // new File:f = fopen(command_name);
    // if (f == File:0)
    // {
    //     SCMA(red, "[A] Не удалось сохранить лог!");
    //     return printf("Не удалось открыть файл!");
    // }
    // new string[528];
    // format(string, sizeof(string), "%d | %d | %s", PlayerInfo[playerid][pID], gettime(), cmdtext); 
    // fwrite(f, string);
    // return fclose(f);
    mysql_format(logs_connects, stringer, sizeof(stringer), "INSERT INTO `commands_logs` (`account_id`, `date`, `cmd_text`, `cmd_name`) VALUES ('%d', '%d', '%s', '%s')", PlayerInfo[playerid][pID], gettime(), cmdtext, command_name);
	mysql_tquery(logs_connects, stringer);
}