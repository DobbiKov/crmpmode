new WebSites[][] = 
{
    ".ws", ".tk", ".com", "www.", ".org", ".net", ".cc", ".??", ".by", ".biz", ".su", ".info",
    ". ws", ". tk", ". com", "www .", ". org", ". net", ". cc", ". ??", ". by", ". biz", ". su", ". info"
};
stock CheckString(string[])
{
	for(new i = 0; i < sizeof(WebSites); i++)
	{
		if(strfind(string,WebSites[i],true) != -1) return true;
	}
	return false;
}
new delimiters[]={'.', ' ', ',', '*', '/', ';', '\\', '|'};
stock IsIP(const str[])
{
	for(new cIP[4]; cIP[0] != strlen(str)+1; cIP[0]++)
	{
		switch(str[cIP[0]])
		{
		case '.', ' ', ':', ',', '*', '/', ';', '\\', '|' : continue;
		case '0' .. '9': cIP[1]++;
		}
		if(cIP[1] ==1){ cIP[2] = cIP[0];}
		if(cIP[1] >= 8)
		{
			new strx[16];
			new l[4][4];
			cIP[3] = cIP[0]+8;
			strmid(strx,str,cIP[2],cIP[3],16);
			for(new i = strlen(strx); i > 8; i--)
			{
				switch(strx[i])
				{
				case '0' .. '9','.', ' ', ':', ',', '*', '/', ';', '\\', '|': continue;
				default: strx[i] =0;
				}
			}
			for(new i = 0 ; i < sizeof(delimiters); i++)
			{
				split(strx,l,delimiters[i]);
				if(strlen(l[0]) == 1 ||strlen(l[1]) == 1 ||strlen(l[2]) == 1 ||strlen(l[3]) == 1) continue;
				if(strlen(l[0]) >3 ||strlen(l[1]) >3 ||strlen(l[2]) >3) continue;
				else return true;
			}
		}
	}
	return false;
}
stock CheckAdvertOtherSource(text[])
{
    return CheckString(text) || IsIP(text);
}
stock SendAdminAntiAdvert(playerid, text[])
{
    new string[144];
    format(string, sizeof(string), "[{"cred"}Anti-AD{"cgrey"}] %s[%d] возможно реклама: %s", PlayerInfo[playerid][pName], playerid, text);
    return SCMA(grey, string);
}