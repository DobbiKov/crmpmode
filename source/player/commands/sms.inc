CMD:sms(playerid, params[])
{
    if(GetPVarInt(playerid, "tied") == 1 || GetPVarInt(playerid, "cuffed") == 1)
        return SCM(playerid, red, !"� ������ ������ �� �������!");
    extract params -> new number, string: text[128]; else return SCM(playerid, blue, "[���������]: {FFFFFF}����������� /sms [����� ��������] [�����]");
    if(PlayerInfo[playerid][pPhone] < 1 || PlayerInfo[playerid][pPhoneNumber] < 1) return SCM(playerid, red, "� ��� ��� ��������.");
    if(PlayerInfo[playerid][pPhoneNumber] < 1) return SCM(playerid, red, "� ��� ��� ��������, ��� ���-�����.");
    if(PlayerInfo[playerid][pPhoneCash] < 5) return SCM(playerid, red, "�� ������� �������� ������������ �������.");
    if(PlayerInfo[playerid][pPhoneStatus] == 1) return SCM(playerid, red, "��� ������� ��������.");
    if(number == PlayerInfo[playerid][pPhoneNumber]) return SCM(playerid, red, "�� ����� ���� ����� ��������.");

	if(CheckAdvertOtherSource(text))
	{
		SendAdminAntiAdvert(playerid, text);
		return 0;
	}

    foreach(new i : Player)
    {
        if(IsPlayerConnected(i) && PlayerInfo[i][pLogin] != false)
        {
            if(number == PlayerInfo[i][pPhoneNumber] && PlayerInfo[i][pPhone] >= 1 && PlayerInfo[i][pPhoneNumber] > 0)
            {
                PlayerInfo[playerid][pPhoneCash] -= 5;
                
                new string[144];
                format(string, sizeof(string), "SMS: %s | �����������: %s[�. %d]", text, PlayerInfo[playerid][pName], PlayerInfo[playerid][pPhoneNumber]);
                SCM(i, yellow, string);

                format(string, sizeof(string), "SMS: %s | ����������: %s[�. %d]", text, PlayerInfo[i][pName], PlayerInfo[i][pPhoneNumber]);
                SCM(playerid, yellow, string);

                format(string, sizeof(string), "[SMS]: %s | �� %s[%d] ��� %s[%d]", text, PlayerInfo[playerid][pName], playerid, PlayerInfo[i][pName], i);
                foreach(new j : Player)
                {
                    if(PlayerInfo[j][pReadsms] == 1)
                    {
                        SCM(j, green, string);
                    }
                }
                return 1;
            }
        }
    }
    return SCM(playerid, red, "������� ��� ���� ��������.");
}