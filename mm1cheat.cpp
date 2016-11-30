/*
mm1cheat - a cheating tool for Might and Magic book I.
author: OKA Motofumi (chikuzen.mo at gmail dot com)
License: WTFPLv2 (http://www.wtfpl.net/txt/copying/)
*/


#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <sys/types.h>
#include <sys/stat.h>


#if defined(_MSC_VER)
#pragma warning(disable:4996)
#endif


struct item {
    const char* name;
    uint8_t idx;
    uint8_t charges;
};

item items[256] = {
    { "NONE          ", 0x00,   0 },
    { "CLUB          ", 0x01,   0 },
    { "DAGGER        ", 0x02,   0 },
    { "HAND AXE      ", 0x03,   0 },
    { "SPEAR         ", 0x04,   0 },
    { "SHORT SWORD   ", 0x05,   0 },
    { "MACE          ", 0x06,   0 },
    { "FLAIL         ", 0x07,   0 },
    { "SCIMITAR      ", 0x08,   0 },
    { "BROAD SWORD   ", 0x09,   0 },
    { "BATTLE AXE    ", 0x0A,   0 },
    { "LONG SWORD    ", 0x0B,   0 },
    { "CLUB +1       ", 0x0C,   0 },
    { "CLUB +2       ", 0x0D,   0 },
    { "DAGGER +1     ", 0x0E,   0 },
    { "HAND AXE +1   ", 0x0F,   0 },

    { "SPEAR +1      ", 0x10,   0 },
    { "SHORT SWORD +1", 0x11,   0 },
    { "MACE +1       ", 0x12,   0 },
    { "FLAIL +1      ", 0x13,   0 },
    { "SCIMITAR +1   ", 0x14,   0 },
    { "BROAD SWORD +1", 0x15,   0 },
    { "BATTLE AXE +1 ", 0x16,   0 },
    { "LONG SWORD +1 ", 0x17,   0 },
    { "FLAMING CLUB  ", 0x18,  30 },
    { "CLUB OF NOISE ", 0x19,   0 },
    { "DAGGER +2     ", 0x1A,  25 },
    { "HAND AXE +2   ", 0x1B,   0 },
    { "SPEAR +2      ", 0x1C,   0 },
    { "SHORT SWORD +2", 0x1D,  15 },
    { "MACE +2       ", 0x1E,  10 },
    { "FLAIL +2      ", 0x1F,  15 },

    { "SCIMITAR +2   ", 0x20,   0 },
    { "BROAD SWORD +2", 0x21,   0 },
    { "BATTLE AXE +2 ", 0x22,  10 },
    { "LONG SWORD +2 ", 0x23,  10 },
    { "ROYAL DAGGER  ", 0x24,   0 },
    { "DAGGER OF MIND", 0x25,  20 },
    { "DIAMOND DAGGER", 0x26,   0 },
    { "ELECTRIC SPEAR", 0x27,  16 },
    { "HOLY MACE     ", 0x28,   5 },
    { "UN-HOLY MACE  ", 0x29,   5 },
    { "DARK FLAIL    ", 0x2A,  10 },
    { "FLAIL OF FEAR ", 0x2B,   8 },
    { "LUCKY SCIMITAR", 0x2C,   0 },
    { "MACE OF UNDEAD", 0x2D,   5 },
    { "COLD AXE      ", 0x2E,  10 },
    { "ELECTRIC SWORD", 0x2F,  10 },

    { "FLAMING SWORD ", 0x30,  10 },
    { "SWORD OF MIGHT", 0x31,  30 },
    { "SWORD OF SPEED", 0x32,  20 },
    { "SHARP SWORD   ", 0x33,   5 },
    { "ACCURATE SWORD", 0x34,  10 },
    { "SWORD OF MAGIC", 0x35,  15 },
    { "IMMORTAL SWORD", 0x36,  25 },
    { "AXE PROTECTOR ", 0x37,  15 },
    { "AXE DESTROYER ", 0x38,   6 },
    { "X!XX!X'S SWORD", 0x39,  10 },
    { "ADAMANTINE AXE", 0x3A,   5 },
    { "ULTIMATE SWORD", 0x3B,  20 },
    { "ELEMENT SWORD ", 0x3C,  10 },
    { "SLING         ", 0x3D,   0 },
    { "CROSSBOW      ", 0x3E,   0 },
    { "SHORT BOW     ", 0x3F,   0 },

    { "LONG BOW      ", 0x40,   0 },
    { "GREAT BOW     ", 0x41,   0 },
    { "SLING +1      ", 0x42,   0 },
    { "CROSSBOW +1   ", 0x43,   0 },
    { "SHORT BOW +1  ", 0x44,   0 },
    { "LONG BOW +1   ", 0x45,   0 },
    { "GREAT BOW +1  ", 0x46,   0 },
    { "MAGIC SLING   ", 0x47,  10 },
    { "CROSSBOW +2   ", 0x48,   0 },
    { "SHORT BOW +2  ", 0x49,   0 },
    { "LONG BOW +2   ", 0x4A,   0 },
    { "GREAT BOW +2  ", 0x4B,   0 },
    { "CROSSBOW LUCK ", 0x4C,  20 },
    { "CROSSBOW SPEED", 0x4D,  10 },
    { "LIGHTNING BOW ", 0x4E,  10 },
    { "FLAMING BOW   ", 0x4F,  10 },

    { "GIANT'S BOW   ", 0x50,   0 },
    { "THE MAGIC BOW ", 0x51,   5 },
    { "BOW OF POWER  ", 0x52,  15 },
    { "ROBBER'S X-BOW", 0x53,  10 },
    { "ARCHER'S BOW  ", 0x54,  10 },
    { "OBSIDIAN BOW  ", 0x55,   0 },
    { "STAFF         ", 0x56,   0 },
    { "GLAIVE        ", 0x57,   0 },
    { "BARDICHE      ", 0x58,   0 },
    { "HALBERD       ", 0x59,   0 },
    { "GREAT HAMMER  ", 0x5A,   0 },
    { "GREAT AXE     ", 0x5B,   0 },
    { "FLAMBERGE     ", 0x5C,   0 },
    { "STAFF +1      ", 0x5D,   0 },
    { "GLAIVE +1     ", 0x5E,   0 },
    { "BARDICHE +1   ", 0x5F,   0 },

    { "HALBERD +1    ", 0x60,   0 },
    { "GREAT HAMMER+1", 0x61,   0 },
    { "GREAT AXE +1  ", 0x62,   0 },
    { "FLAMBERGE +1  ", 0x63,   0 },
    { "STAFF +2      ", 0x64,  10 },
    { "GLAIVE +2     ", 0x65,   0 },
    { "BARDICHE +2   ", 0x66,   0 },
    { "HALBERD +2    ", 0x67,  20 },
    { "GREAT HAMMER+2", 0x68,  20 },
    { "GREAT AXE +2  ", 0x69,  10 },
    { "FLAMBERGE +2  ", 0x6A,  10 },
    { "STAFF OF LIGHT", 0x6B,  20 },
    { "COLD GLAIVE   ", 0x6C,  20 },
    { "CURING STAFF  ", 0x6D,  12 },
    { "MINOTAUR'S AXE", 0x6E,   0 },
    { "THUNDER HAMMER", 0x6F,  15 },

    { "GREAT AXE +3  ", 0x70,  10 },
    { "FLAMBERGE +3  ", 0x71,  10 },
    { "SORCERER STAFF", 0x72,  10 },
    { "STAFF OF MAGIC", 0x73,  10 },
    { "DEMON'S GLAIVE", 0x74,  40 },
    { "DEVIL'S GLAIVE", 0x75,  40 },
    { "THE FLAMBERGE ", 0x76,  10 },
    { "HOLY FLAMBERGE", 0x77,  15 },
    { "EVIL FLAMBERGE", 0x78,  15 },
    { "PADDED ARMOR  ", 0x79,   0 },
    { "LEATHER ARMOR ", 0x7A,   0 },
    { "SCALE ARMOR   ", 0x7B,   0 },
    { "RING MAIL     ", 0x7C,   0 },
    { "CHAIN MAIL    ", 0x7D,   0 },
    { "SPLINT MAIL   ", 0x7E,   0 },
    { "PLATE MAIL    ", 0x7F,   0 },

    { "PADDED +1     ", 0x80,   0 },
    { "LEATHER +1    ", 0x81,   0 },
    { "SCALE +1      ", 0x82,   0 },
    { "RING MAIL +1  ", 0x83,   0 },
    { "CHAIN MAIL +1 ", 0x84,   0 },
    { "SPLINT MAIL +1", 0x85,   0 },
    { "PLATE MAIL +1 ", 0x86,   0 },
    { "LEATHER +2    ", 0x87,   0 },
    { "SCALE +2      ", 0x88,   0 },
    { "RING MAIL +2  ", 0x89,   0 },
    { "CHAIN MAIL +2 ", 0x8A,   0 },
    { "SPLINT MAIL +2", 0x8B,   0 },
    { "PLATE MAIL +2 ", 0x8C,   0 },
    { "BRACERS AC 4  ", 0x8D,   0 },
    { "RING MAIL +3  ", 0x8E,   0 },
    { "CHAIN MAIL +3 ", 0x8F,   0 },

    { "SPLINT MAIL +3", 0x90,   0 },
    { "PLATE MAIL +3 ", 0x91,   0 },
    { "BRACERS AC 6  ", 0x92,  20 },
    { "CHAIN MAIL +3c", 0x93,   0 },
    { "BRACERS AC 8c ", 0x94,   0 },
    { "BLUE RING MAIL", 0x95,  30 },
    { "RED CHAIN MAIL", 0x96,  30 },
    { "X!XX!X'S PLATE", 0x97,  10 },
    { "HOLY PLATE    ", 0x98,  30 },
    { "UN-HOLY PLATE ", 0x99,  30 },
    { "ULTIMATE PLATE", 0x9A,  30 },
    { "BRACERS AC 8  ", 0x9B,  40 },
    { "SMALL SHIELD  ", 0x9C,   0 },
    { "LARGE SHIELD  ", 0x9D,   0 },
    { "SILVER SHIELD ", 0x9E,   0 },
    { "SMALL SHIELD+1", 0x9F,   0 },

    { "LARGE SHIELD+1", 0xA0,   0 },
    { "LARGESHIELD+1c", 0xA1,   0 },
    { "SMALL SHIELD+2", 0xA2,   0 },
    { "LARGE SHIELD+2", 0xA3,   0 },
    { "LARGESHIELD+2c", 0xA4,   0 },
    { "FIRE SHIELD   ", 0xA5,   0 },
    { "COLD SHIELD   ", 0xA6,   0 },
    { "ELEC SHIELD   ", 0xA7,   0 },
    { "ACID SHIELD   ", 0xA8,   0 },
    { "MAGIC SHIELD  ", 0xA9,  20 },
    { "DRAGON SHIELD ", 0xAA,  20 },
    { "ROPE & HOOKS  ", 0xAB,  30 },
    { "TORCH         ", 0xAC,   1 },
    { "LANTERN       ", 0xAD,  10 },
    { "10 FOOT POLE  ", 0xAE,   0 },
    { "GARLIC        ", 0xAF,   0 },

    { "WOLFSBANE     ", 0xB0,   0 },
    { "BELLADONNA    ", 0xB1,   0 },
    { "MAGIC HERBS   ", 0xB2,   3 },
    { "DRIED BEEF    ", 0xB3,   3 },
    { "ROBBER'S TOOLS", 0xB4,   0 },
    { "BAG OF SILVER ", 0xB5,   0 },
    { "AMBER GEM     ", 0xB6,   0 },
    { "SMELLING SALT ", 0xB7,   3 },
    { "BAG OF SAND   ", 0xB8,   5 },
    { "MIGHT POTION  ", 0xB9,   3 },
    { "SPEED POTION  ", 0xBA,   3 },
    { "SUNDIAL       ", 0xBB,  50 },
    { "CURING POTION ", 0xBC,   4 },
    { "MAGIC POTION  ", 0xBD,   2 },
    { "DEFENSE RING  ", 0xBE,  30 },
    { "BAG OF GARBAGE", 0xBF,   0 },

    { "SCROLL OF FIRE", 0xC0,   1 },
    { "FLYING CARPET ", 0xC1,  10 },
    { "JADE AMULET   ", 0xC2,   0 },
    { "ANTIDOTE BREW ", 0xC3,   2 },
    { "SKILL POTION  ", 0xC4,   5 },
    { "BOOTS OF SPEED", 0xC5,  10 },
    { "LUCKY CHARM   ", 0xC6,  20 },
    { "WAND OF FIRE  ", 0xC7,  10 },
    { "UNDEAD AMULET ", 0xC8,  20 },
    { "SILENT CHIME  ", 0xC9,  20 },
    { "BELT OF POWER ", 0xCA,   0 },
    { "MODEL BOAT    ", 0xCB,  15 },
    { "DEFENSE CLOAK ", 0xCC,   0 },
    { "KNOWLEDGE BOOK", 0xCD,   4 },
    { "RUBY IDOL     ", 0xCE,   0 },
    { "SORCERER ROBE ", 0xCF,  20 },

    { "POWER GAUNTLET", 0xD0,   0 },
    { "CLERIC'S BEADS", 0xD1,  50 },
    { "HORN OF DEATH ", 0xD2,  10 },
    { "POTION OF LIFE", 0xD3,   2 },
    { "SHINY PENDANT ", 0xD4,  10 },
    { "LIGHTNING WAND", 0xD5,  10 },
    { "PRECISION RING", 0xD6,   0 },
    { "RETURN SCROLL ", 0xD7,   1 },
    { "TELEPORT HELM ", 0xD8,  20 },
    { "YOUTH POTION  ", 0xD9,   2 },
    { "BELLS OF TIME ", 0xDA,  50 },
    { "MAGIC OIL     ", 0xDB,   1 },
    { "MAGIC VEST    ", 0xDC,  10 },
    { "DESTROYER WAND", 0xDD,  10 },
    { "ELEMENT SCARAB", 0xDE,  20 },
    { "SUN SCROLL    ", 0xDF,   1 },

    { "STAR RUBY     ", 0xE0,  30 },
    { "STAR SAPPHIRE ", 0xE1,  10 },
    { "WEALTH CHEST  ", 0xE2,   5 },
    { "GEM SACK      ", 0xE3,  10 },
    { "DIAMOND COLLAR", 0xE4,  10 },
    { "FIRE OPAL     ", 0xE5,  10 },
    { "UNOBTAINIUM   ", 0xE6,   0 },
    { "VELLUM SCROLL ", 0xE7,   0 },
    { "RUBY WHISTLE  ", 0xE8, 200 },
    { "KINGS PASS    ", 0xE9,   0 },
    { "MERCHANTS PASS", 0xEA,   0 },
    { "CRYSTAL KEY   ", 0xEB,  10 },
    { "CORAL KEY     ", 0xEC,  10 },
    { "BRONZE KEY    ", 0xED,  20 },
    { "SILVER KEY    ", 0xEE,  30 },
    { "GOLD KEY      ", 0xEF,  15 },

    { "DIAMOND KEY   ", 0xF0,  20 },
    { "CACTUS NECTAR ", 0xF1,  10 },
    { "MAP OF DESERT ", 0xF2,  20 },
    { "LASER BLASTER ", 0xF3,  10 },
    { "DRAGONS TOOTH ", 0xF4,  10 },
    { "WYVERN EYE    ", 0xF5,  20 },
    { "MEDUSA HEAD   ", 0xF6,   0 },
    { "RING OF OKRIM ", 0xF7,  20 },
    { "B QUEEN IDOL  ", 0xF8,   0 },
    { "W QUEEN IDOL  ", 0xF9,   0 },
    { "PIRATES MAP A ", 0xFA,   0 },
    { "PIRATES MAP B ", 0xFB,   0 },
    { "THUNDRANIUM   ", 0xFC, 250 },
    { "KEY CARD      ", 0xFD,   0 },
    { "EYE OF GOROS  ", 0xFE,  20 },
    { "(USELESS ITEM)", 0xFF,   0 },
};


enum gender : uint8_t {
    NO_GENDER, MALE, FEMALE,
};

enum alignment : uint8_t {
    NO_ALIGN, GOOD, NEUTRAL, EVIL,
};

enum race : uint8_t {
    NO_RACE, HUMAN, ELF, DWARF, GNOME, HALF_ORC,
};

enum chclass : uint8_t {
    NO_CLASS, KNIGHT, PALADIN, ARCHER, CLERIC, SORCERER, ROBBER,
};


#pragma pack(1)
class CharData {            // 127bytes per character
    char name[16];          // 最大15文字+NULL終端
    gender gender;
    alignment alignment[2];
    race race;
    chclass charClass;
    uint8_t intellect[2];   // 能力値と補正後(アイテム、泉等)
    uint8_t might[2];
    uint8_t personality[2];
    uint8_t endurance[2];
    uint8_t speed[2];
    uint8_t accuracy[2];
    uint8_t luck[2];
    uint8_t level[2];
    uint8_t age;
    uint8_t unknown0;
    uint32_t experience;
    uint16_t spellPoints[2];// 現在値, 最大値
    uint8_t spellLevel[2];  // 現在値
    uint16_t gems;
    uint16_t hitPoints[3];  // 現在値, 仮最大値(毒、一時的アイテム効果等), 最大値
    uint8_t gold[3];        // 所持金(24bit、最大値16,777,215)
    uint8_t acFromItems;    // アイテムによるAC補正値
    uint8_t armorClass;     // 現在のAC値
    uint8_t food;
    uint8_t unknown1;
    uint8_t equipped[6];    // 装備中アイテムのインデックスを保持
    uint8_t backpack[6];    // バックパックのアイテムのインデックスを保持
    uint8_t chargesEQ[6];   // 装備中アイテムの残チャージ
    uint8_t chargesBP[6];   // バックパックのアイテムの残チャージ
    uint8_t resMagic[2];    // 各種抵抗値(種族値+アイテム)とその補正値
    uint8_t resFire[2];
    uint8_t resCold[2];
    uint8_t resElec[2];
    uint8_t resAcid[2];
    uint8_t resFear[2];
    uint8_t resPoison[2];
    uint8_t resSleep[2];
    uint8_t unknown2[22];
    uint8_t id;             // 0x00~0x11
public:
    const char* getName() noexcept { return name; }
    void showCharacter() noexcept;
    void southCleric(int count) noexcept;
    void carryScrolls(int count) noexcept;
    void chapelOfDusk(int count) noexcept;
    void rejevenate(int val) noexcept;
    void fillBackPack() noexcept;
};


class SaveData {   // 127x18+18=2304bytes
    CharData data[18];
    uint8_t exists[18]; //キャラが存在する(有効データ)なら0x01
public:
    SaveData(std::string& path);
    void edit(int id, int opt) noexcept;
    void write(const char* path) noexcept;
};
#pragma pack()


void CharData::rejevenate(int val) noexcept
{
    if (age > val) {
        age = val;
    }
    fprintf(stderr, "%s rejevenated for %d years old.\n", name, val);
}


void CharData::fillBackPack() noexcept
{
    auto get_item = [](std::string name) {
        for (int i = 0; i < 0xFF; ++i) {
            if (name == items[i].name) {
                return &items[i];
            }
        }
        return &items[0xFF];
    };

    const item* bp[6] = {
        get_item("STAR SAPPHIRE "),
        get_item("DEFENSE CLOAK "),
        get_item("MAGIC VEST    "),
        nullptr,
    };

    switch (charClass) {
    case chclass::KNIGHT:
        bp[3] = get_item("ULTIMATE SWORD");
        bp[4] = get_item("MAGIC SHIELD  ");
        bp[5] = get_item("ULTIMATE PLATE");
        break;
    case chclass::PALADIN:
        bp[3] = get_item("ULTIMATE SWORD");
        bp[4] = get_item("MAGIC SHIELD  ");
        if (alignment[0] == alignment::GOOD) {
            bp[5] = get_item("HOLY PLATE    ");
        } else if (alignment[0] == alignment::EVIL) {
            bp[5] = get_item("UN-HOLY PLATE ");
        } else {
            bp[5] = get_item("X!XX!X'S PLATE");
        }
        break;
    case chclass::ARCHER:
        bp[3] = get_item("ARCHER'S BOW  ");
        bp[4] = get_item("THE FLAMBERGE ");
        bp[5] = get_item("ULTIMATE PLATE");
        break;
    case chclass::CLERIC:
        bp[3] = get_item("FLAIL OF FEAR ");
        bp[4] = get_item("MAGIC SHIELD  ");
        bp[5] = get_item("RED CHAIN MAIL");
        break;
    case chclass::SORCERER:
        bp[3] = get_item("DIAMOND DAGGER");
        bp[4] = get_item("TELEPORT HELM ");
        bp[5] = get_item("ULTIMATE PLATE");
        break;
    default: //ROBBER
        bp[3] = get_item("ULTIMATE SWORD");
        bp[4] = get_item("ROBBER'S X-BOW");
        bp[5] = get_item("BLUE RING MAIL");
    }

    for (int i = 0; i < 6; ++i) {
        backpack[i] = bp[i]->idx;
        chargesBP[i] = bp[i]->charges;
    }

    fprintf(stderr, "%s's backpack was filled.\n", name);
}


void CharData::carryScrolls(int count) noexcept
{
    int32_t exp = experience;
    int32_t gld = gold[0] | (gold[1] << 8) | (gold[2] << 16);
    int32_t g0 = gld;

    for (int i = 0; i < count; ++i) {
        if (exp < INT32_MAX - 3500) {
            exp += 3500;
        }
        if (gld < 0x00FFFFFF - 1500) {
            gld += 1500;
        }
    }
    fprintf(stderr, "%s got %dexp and %dgold.\n",
            name, exp - experience, gld - g0);

    experience = exp;
    uint8_t* g = reinterpret_cast<uint8_t*>(&gld);
    gold[0] = g[0];
    gold[1] = g[1];
    gold[2] = g[2];
}


void CharData::southCleric(int count) noexcept
{
    auto gain_attribute = [](uint8_t v, uint8_t* attr) {
        if (attr[0] < v) {
            attr[0] += 4;
            attr[1] += 4;
        }
    };

    for (int i = 0; i < count; ++i) {
        gain_attribute(26, intellect);
        gain_attribute(50, might);
        gain_attribute(30, personality);
        gain_attribute(26, endurance);
        gain_attribute(50, speed);
        gain_attribute(50, accuracy);
        gain_attribute(50, luck);
    }
    fprintf(stderr, "%s's statistics rose.\n", name);
}


void CharData::chapelOfDusk(int count) noexcept
{
    int32_t g = gems;
    for (int i = 0; i < count; ++i) {
        if (g >= UINT16_MAX - 200) {
            break;
        }
        g += 200;
    }
    fprintf(stderr, "%s got %d gems.\n", name, g - gems);
    gems = static_cast<uint16_t>(g);
}


void CharData::showCharacter() noexcept
{
    const char* gndr[] = {
        "no gender", "male", "female"
    };
    const char* align[] = {
        "no align", "good", "neutral", "evil"
    };
    const char* rc[] = {
        "no race", "human", "elf", "dwarf", "gnome", "half-orc"
    };
    const char* cls[] = {
        "no class", "knight", "paladin", "archer", "cleric", "sorcerer", "robber"
    };

    int32_t gld = gold[0] | (gold[1] << 8) | (gold[2] << 16);

    printf("name: %s\t", name);
    printf("id: %d\n", int(id));
    printf("gender: %s\t", gndr[gender]);
    printf("alignment: %s / %s\t", align[alignment[0]], align[alignment[1]]);
    printf("race: %s\t", rc[race]);
    printf("class: %s\n", cls[charClass]);
    printf("EXP: %d\t", int(experience));
    printf("GOLD: %d\t", gld);
    printf("GEMS: %d\n", int(gems));
    printf("INT: %d / %d\t", int(intellect[0]), int(intellect[1]));
    printf("MGT: %d / %d\t", int(might[0]), int(might[1]));
    printf("PER: %d / %d\n", int(personality[0]), int(personality[1]));
    printf("END: %d / %d\t", int(endurance[0]), int(endurance[1]));
    printf("SPD: %d / %d\t", int(speed[0]), int(speed[1]));
    printf("ACY: %d / %d\n", int(accuracy[0]), int(accuracy[1]));
    printf("LCK: %d / %d\n", int(luck[0]), int(luck[1]));
    printf("LVL: %d / %d\t", int(level[0]), int(level[1]));
    printf("HP: %d / %d / %d\t", int(hitPoints[0]), int(hitPoints[1]), int(hitPoints[2]));
    printf("SP: %d / %d\t", int(spellPoints[0]), int(spellPoints[1]));
    printf("SL: %d / %d\n", int(spellLevel[0]), int(spellLevel[1]));
    printf("AC: %d / %d\n", int(acFromItems), int(armorClass));
    printf("equipped:\n");
    printf("\t%s / %s / %s\n\t%s / %s / %s\n",
           items[equipped[0]].name, items[equipped[1]].name,
           items[equipped[2]].name, items[equipped[3]].name,
           items[equipped[4]].name, items[equipped[5]].name);
    printf("backpack:\n");
    printf("\t%s / %s / %s\n\t%s / %s / %s\n",
           items[backpack[0]].name, items[backpack[1]].name,
           items[backpack[2]].name, items[backpack[3]].name,
           items[backpack[4]].name, items[backpack[5]].name);
    printf("resists(magic/fire/cold/elec/acid/fear/poison/sleep):\n");
    printf("\t%d/\t%d/\t%d/\t%d/\t%d/\t%d/\t%d/\t%d\n",
           int(resMagic[1]), int(resFire[1]), int(resCold[1]), int(resElec[1]),
           int(resAcid[1]), int(resFear[1]), int(resPoison[1]), int(resSleep[1]));
    puts("");
    fflush(stdout);
}


SaveData::SaveData(std::string& path)
{
    if (path.rfind("ROSTER.DTA") == path.npos) {
        throw std::runtime_error("invalid filename.");
    }

    struct _stat st;
    if (_stat(path.c_str(), &st)) {
        throw std::runtime_error("the file does not exist.");
    }
    if (st.st_size != sizeof(SaveData)) {
        throw std::runtime_error("the file is not a M&M1's save data.");
    }

    FILE* fp = fopen(path.c_str(), "rb");
    if (!fp) {
        throw std::runtime_error("failed to open the file.");
    }
    fread(data, sizeof(SaveData), 1, fp);
    fclose(fp);
}


void SaveData::edit(int id, int opt) noexcept
{
    if (exists[id] != 1) {
        return;
    }

    if (opt == 0) {
        data[id].showCharacter();
        return;
    }

    if (opt & 0x01) {
        data[id].rejevenate(18);
    }

    if (opt & 0x02) {
        data[id].carryScrolls(1000);
        data[id].chapelOfDusk(10);
    }

    if (opt & 0x04) {
        data[id].southCleric(10);
    }

    if (opt & 0x08) {
        data[id].fillBackPack();
    }

    fflush(stderr);
}


void SaveData::write(const char* path) noexcept
{
    FILE* fp = fopen(path, "wb");
    fwrite(this, sizeof(SaveData), 1, fp);
    fclose(fp);
    fprintf(stderr, "new data was saved as '%s'\n", path);
}


int main(int argc, char** argv)
{
    try {
        if (argc != 3) {
            throw std::runtime_error("invalid arguments.");
        }

        auto path = std::string(argv[1]);
        int opt = atoi(argv[2]);
        if (opt > 15 || opt < 0) {
            opt = 0;
        }

        auto sd = SaveData(path);
        for (int id = 0; id < 18; ++id) {
            sd.edit(id, opt);
        }
        if (opt != 0) {
            sd.write((path + ".mod").c_str());
        }

    } catch (std::runtime_error& e) {
        fprintf(stderr, "%s\n", e.what());
        return -1;
    }

    return 0;
}
