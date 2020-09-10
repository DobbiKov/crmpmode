// - gun skills
#define Ammo_SDPISTOL          30 
#define Ammo_DEAGLE            24 
#define Ammo_SHOTGUN           15
#define Ammo_MP5               75 
#define Ammo_AK47              100 
#define Ammo_M4A1              89 

enum E_SKILL_SHOOTS_STRUCT{
    ESS_SD_PISTOL,
    ESS_DEAGLE,
    ESS_SHOTGUN,
    ESS_MP5,
    ESS_M4,
    ESS_AK47
}
new SkillShoots[MAX_PLAYERS][E_SKILL_SHOOTS_STRUCT];

new PlayerAmmo[MAX_PLAYERS];

public OnPlayerUpdate(playerid){
    new NewPlayerAmmo = GetPlayerAmmo(playerid);
    if(NewPlayerAmmo != PlayerAmmo[playerid]){
        OnPlayerAmmoChanged(playerid, NewPlayerAmmo, PlayerAmmo[playerid]);
        PlayerAmmo[playerid] = NewPlayerAmmo;
    }
    #if defined skills__OnPlayerUpdate
        return skills__OnPlayerUpdate(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate skills__OnPlayerUpdate
#if defined skills__OnPlayerUpdate
    forward skills__OnPlayerUpdate(playerid);
#endif

stock OnPlayerAmmoChanged(&playerid, newammo, oldammo){
    if(newammo < oldammo){
        switch(GetPlayerWeapon(playerid)){
            case 23: {
                SkillShoots[playerid][ESS_SD_PISTOL]++;
                if(SkillShoots[playerid][ESS_SD_PISTOL] >= Ammo_SDPISTOL){
                    PlayerInfo[playerid][SKILL_SD_PISTOL]++;
                    SkillShoots[playerid][ESS_SD_PISTOL] = 0;
                }
            }//ESS_SD_PISTOL
            case 24: {
                SkillShoots[playerid][ESS_DEAGLE]++;
                if(SkillShoots[playerid][ESS_DEAGLE] >= Ammo_DEAGLE){
                    PlayerInfo[playerid][SKILL_DEAGLE]++;
                    SkillShoots[playerid][ESS_DEAGLE] = 0;
                }
            }//ESS_DEAGLE
            case 25: {
                SkillShoots[playerid][ESS_SHOTGUN]++;
                if(SkillShoots[playerid][ESS_SHOTGUN] >= Ammo_SHOTGUN){
                    PlayerInfo[playerid][SKILL_SHOTGUN]++;
                    SkillShoots[playerid][ESS_SHOTGUN] = 0;
                }
            }//ESS_SHOTGUN
            case 29: {
                SkillShoots[playerid][ESS_MP5]++;
                if(SkillShoots[playerid][ESS_MP5] >= Ammo_MP5){
                    PlayerInfo[playerid][SKILL_MP5]++;
                    SkillShoots[playerid][ESS_MP5] = 0;
                }
            }//ESS_MP5
            case 30: {
                SkillShoots[playerid][ESS_AK47]++;
                if(SkillShoots[playerid][ESS_AK47] >= Ammo_AK47){
                    PlayerInfo[playerid][SKILL_AK_47]++;
                    SkillShoots[playerid][ESS_AK47] = 0;
                }
            }//ESS_AK47
            case 31: {
                SkillShoots[playerid][ESS_M4]++;
                if(SkillShoots[playerid][ESS_M4] >= Ammo_M4A1){
                    PlayerInfo[playerid][SKILL_M4]++;
                    SkillShoots[playerid][ESS_M4] = 0;
                }
            }//ESS_M4
        }
        SetPlayerSkills(playerid);
        SaveAccounts(playerid);
    }
}