ALTX:godmode("/gm");
CMD:godmode(playerid, params[])
{
    if(PlayerInfo[playerid][bAdmin] < 2 && PlayerInfo[playerid][bYoutube] == 0) return ShowCommandNotFound(playerid);

    if(!GetPVarInt(playerid, "gm"))          
    {                                            
        SetPlayerHealth(playerid, Float:0x7F800000 );   
        SCM(playerid, white, "�� �������� GodMode, ��� ���� ��� �� ��������� ���, �������: /gm");
        SetPVarInt(playerid, "gm", 1);         
    }
    else 
    {                                           
        SetPlayerHealth(playerid, 100);
        SCM(playerid, white, "�� ��������� GodMode, ��� ���� ��� �� �������� ���, �������: /gm");
        SetPVarInt(playerid, "gm", 0);          
    }
    return 1;
} 