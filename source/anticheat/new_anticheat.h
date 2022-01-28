/*
    Настройки, связанные с базой данных (MySQL)
*/
#define AC_TABLE_SETTINGS               "anticheat_settings" // Название таблицы в базе данных с настройками анти-чита
#define AC_TABLE_FIELD_CODE             "ac_code" // Название поля с кодом анти-чита в таблице
#define AC_TABLE_FIELD_TRIGGER          "ac_code_trigger_type" // Название поля со значением срабатывания кода анти-чита в таблице

/*
    Общие настройки, касающиеся анти-чита
*/
#define AC_MAX_CODES                    53 // Количество кодов анти-чита (на данный момент их 53)
#define AC_MAX_CODE_LENGTH              (3 + 1) // Максимальное количество символов в "коде" анти-чита (001/002/003, etc.)
#define AC_MAX_CODE_NAME_LENGTH         (33 + 1) // Максимальное количество символов в полном названии чита, за который отвечает какой-либо код

#define AC_MAX_TRIGGER_TYPES            3 // Количество типов срабатываний (наказаний) анти-чита. По мере добавления типов срабатываний (наказаний), увеличивайте данное значение.
#define AC_MAX_TRIGGER_TYPE_NAME_LENGTH (8 + 1) // Максимальное количество символов в названии типа срабатывания (наказания) анти-чита

#define AC_GLOBAL_TRIGGER_TYPE_PLAYER   0
#define AC_GLOBAL_TRIGGER_TYPE_IP       1

// Типы срабатываний объявлены макросами, чтобы было проще ориентироваться в OnCheatDetected.
#define AC_CODE_TRIGGER_TYPE_DISABLED   0 // AC_CODE_TRIGGER_TYPE_DISABLED - Тип наказания: Отключён
#define AC_CODE_TRIGGER_TYPE_WARNING    1 // AC_CODE_TRIGGER_TYPE_WARNING - Тип наказания: Warning
#define AC_CODE_TRIGGER_TYPE_KICK       2 // AC_CODE_TRIGGER_TYPE_KICK - Тип наказания: Kick

#define AC_TRIGGER_ANTIFLOOD_TIME       20 // Время для анти-флуда срабатываниями (в секундах)

/*
    Настройки визуальной части системы (диалогов)
*/
#define AC_MAX_CODES_ON_PAGE            15 // Максимальное количество элементов на странице настроек анти-чита
#define AC_DIALOG_NEXT_PAGE_TEXT        ">>> Следующая страница" // Текст кнопки, которая будет отображать следующую страницу списка
#define AC_DIALOG_PREVIOUS_PAGE_TEXT    "<<< Предыдущая страница" // Текст кнопки, которая будет отображать предыдущую страницу списка

// больница, платное лечение
// new	Cheat[2],
// 	Cheatp[MAX_PLAYERS][2],
// 	Text:CheatText[2][10];

new AC_CODE[AC_MAX_CODES][AC_MAX_CODE_LENGTH] =
{
    "000",
    "001",
    "002",
    "003",
    "004",
    "005",
    "006",
    "007",
    "008",
    "009",
    "010",
    "011",
    "012",
    "013",
    "014",
    "015",
    "016",
    "017",
    "018",
    "019",
    "020",
    "021",
    "022",
    "023",
    "024",
    "025",
    "026",
    "027",
    "028",
    "029",
    "030",
    "031",
    "032",
    "033",
    "034",
    "035",
    "036",
    "037",
    "038",
    "039",
    "040",
    "041",
    "042",
    "043",
    "044",
    "045",
    "046",
    "047",
    "048",
    "049",
    "050",
    "051",
    "052"
};

// Массив AC_CODE_NAME хранит в себе названия читов, которые соответствуют кодам анти-чита
new AC_CODE_NAME[AC_MAX_CODES][AC_MAX_CODE_NAME_LENGTH] =
{
    {"AirBreak (onfoot)"},
    {"AirBreak (in vehicle)"},
    {"Teleport (onfoot)"},
    {"Teleport (in vehicle)"},
    {"Teleport (into/between vehicles)"},
    {"Teleport (vehicle to player)"},
    {"Teleport (pickups)"},
    {"FlyHack (onfoot)"},
    {"FlyHack (in vehicle)"},
    {"SpeedHack (onfoot)"},
    {"SpeedHack (in vehicle)"},
    {"Health hack (in vehicle)"},
    {"Health hack (onfoot)"},
    {"Armour hack"},
    {"Money hack"},
    {"Weapon hack"},
    {"Ammo hack (add)"},
    {"Ammo hack (infinite)"},
    {"Special actions hack"},
    {"GodMode from bullets (onfoot)"},
    {"GodMode from bullets (in vehicle)"},
    {"Invisible hack"},
    {"Lagcomp-spoof"},
    {"Tuning hack"},
    {"Parkour mod"},
    {"Quick turn"},
    {"Rapid fire"},
    {"FakeSpawn"},
    {"FakeKill"},
    {"Pro Aim"},
    {"CJ run"},
    {"CarShot"},
    {"CarJack"},
    {"UnFreeze"},
    {"AFK Ghost"},
    {"Full Aiming"},
    {"Fake NPC"},
    {"Reconnect"},
    {"High ping"},
    {"Dialog hack"},
    {"Sandbox"},
    {"Invalid version"},
    {"Rcon hack"},
    {"Tuning crasher"},
    {"Invalid seat crasher"},
    {"Dialog crasher"},
    {"Attached object crasher"},
    {"Weapon Crasher"},
    {"Connects to one slot"},
    {"Flood callback functions"},
    {"Flood change seat"},
    {"DDos"},
    {"NOP's"}
};


// Массив AC_TRIGGER_TYPE_NAME хранит в себе названия типов срабатываний (наказаний) анти-чита.
new AC_TRIGGER_TYPE_NAME[AC_MAX_TRIGGER_TYPES][AC_MAX_TRIGGER_TYPE_NAME_LENGTH] =
{
    {"Отключён"},
    {"Warning"},
    {"Kick"}
};

// new fstr[1000];
new
    AC_CODE_TRIGGER_TYPE[AC_MAX_CODES], // Массив AC_CODE_TRIGGER_TYPE хранит в себе наказания каждого кода анти-чита, которые мы загрузим из базы данных.
    AC_CODE_TRIGGERED_COUNT[AC_MAX_CODES] = {0, ...}; // Массив, хранящий количество срабатываний того или иного кода анти-чита на протяжении текущей сессии

new
    pAntiCheatLastCodeTriggerTime[MAX_PLAYERS][AC_MAX_CODES], // Массив, хранящий последнее время срабатывания каждого кода анти-чита на игрока
    pAntiCheatSettingsPage[MAX_PLAYERS char], // Массив, хранящий номер страницы настроек, на которой сейчас находится игрок
    pAntiCheatSettingsMenuListData[MAX_PLAYERS][AC_MAX_CODES_ON_PAGE], // Массив, хранящий в себе идентификаторы (ID) отображённых анти-читов на текущей странице, при их настройке в диалоге
    pAntiCheatSettingsEditCodeId[MAX_PLAYERS]; // Массив, хранящий номер кода анти-чита, который редактируется игроком