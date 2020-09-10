CMD:setskill(playerid, params[]){
    if(PlayerInfo[playerid][bAdmin] < 5) return ShowCommandNotFound(playerid);
    extract params -> new to_player, gun, skill; else
    {
        SCM(playerid, blue, !"[Подсказка]: {FFFFFF}Используйте /setskill [ID игрока] [оружие(1-6)] [скилл(0-100)]");
        SCM(playerid, blue, !"[Оружие]: {FFFFFF}1 - SD Pistol | 2 - Desert Eagle | 3 - ShotGun | 4 - MP5 | 5 - AK47 | 6 - M4");
        return 1;
    }
    if(!IsPlayerConnected(to_player) || !PlayerInfo[to_player][pLogin]) return PlayerOffLine(playerid);
    if(skill > 100 || skill < 0)
        return SCM(playerid, red, "Параметр [скилл] должен быть не менее 0 и не более 100");

    switch(gun){
        case 1:{
            PlayerInfo[to_player][SKILL_SD_PISTOL] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] Администратор %s[%d] выдал игроку %s[%d] %d процентов навыков владения оружием SD Pistol.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "Администратор %s выдал вам %d процентов навыков владения оружием SD Pistol.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "Вы выдали игроку %s %d процентов навыков владения оружием SD Pistol", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        case 2:{
            PlayerInfo[to_player][SKILL_DEAGLE] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] Администратор %s[%d] выдал игроку %s[%d] %d процентов навыков владения оружием Desert Eagle.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "Администратор %s выдал вам %d процентов навыков владения оружием Desert Eagle.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "Вы выдали игроку %s %d процентов навыков владения оружием Desert Eagle", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        case 3:{
            PlayerInfo[to_player][SKILL_SHOTGUN] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] Администратор %s[%d] выдал игроку %s[%d] %d процентов навыков владения оружием ShotGun.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "Администратор %s выдал вам %d процентов навыков владения оружием ShotGun.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "Вы выдали игроку %s %d процентов навыков владения оружием ShotGun", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        case 4:{
            PlayerInfo[to_player][SKILL_MP5] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] Администратор %s[%d] выдал игроку %s[%d] %d процентов навыков владения оружием MP-5.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "Администратор %s выдал вам %d процентов навыков владения оружием MP-5.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "Вы выдали игроку %s %d процентов навыков владения оружием MP-5", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        case 5:{
            PlayerInfo[to_player][SKILL_AK_47] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] Администратор %s[%d] выдал игроку %s[%d] %d процентов навыков владения оружием AK-47.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "Администратор %s выдал вам %d процентов навыков владения оружием AK-47.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "Вы выдали игроку %s %d процентов навыков владения оружием AK-47", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        case 6:{
            PlayerInfo[to_player][SKILL_M4] = skill;
            SetPlayerSkills(playerid);
            SaveAccounts(playerid);
            new string[144];
            format(string, sizeof(string), "[A] Администратор %s[%d] выдал игроку %s[%d] %d процентов навыков владения оружием M4.", PlayerInfo[playerid][pName], playerid, PlayerInfo[to_player][pName], to_player, skill);
            SCMA(grey, string);

            format(string, sizeof(string), "Администратор %s выдал вам %d процентов навыков владения оружием M4.", PlayerInfo[playerid][pName], skill);
            SCM(to_player, white, string);

            format(string, sizeof(string), "Вы выдали игроку %s %d процентов навыков владения оружием M4", PlayerInfo[to_player][pName]);
            SCM(playerid, white, string);
        }
        default:{
            return SCM(playerid, red, "Параметр [оружие] должен быть не менее 1 и не более 6.");
        }
    }
    return 1;
}