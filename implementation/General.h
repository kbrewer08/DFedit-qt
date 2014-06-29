#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>
#include <string>

#include "DragonForce.h"

using namespace std;

class General
{
private:
      int    listIndex;
      int    isPlayerMonarch;
      string name;
      string owner;
      int    fieldStatus1;
      int    fieldStatus2;
      int    level;
      int    classType;
      int    fixedLocation; //  true/false  1/0
      int    location;
      int    troopIndex;
      string troopType;
      int    currentTroopCount;
      int    nAction;
      int    bAction;
      int    livesLeft;
      int    currentHP;
      int    maxHP;
      int    currentMP;
      int    maxMP;
      int    strength;
      int    defp;
      int    escapeChance;
      int    command;
      int    intelligence;
      int    loyalty;
      int    equippedItem;
      int    portrait;
      int    naisei;
      int    domesticsMedal; //status for if they were given a medal this week
      int    domesticsSF;    //status for searched or fortified this week
      int    newWins;
      int    newLosses;
      int    oldWins;
      int    oldLosses;
      ushort soldierCavalry;
      ushort mageSamurai;
      ushort archerMonk;
      ushort harpyBeast;
      ushort dragonZombie;
      int    currentExp;
      int    newMerits;
      int    oldMerits;
      int    hospital;
      int    btlAction;
      int    moral;
      int    warlike;
      int    nego;
      int    atkPlus;
      int    spellTier;
      int    defPlus;
      int    defSword;
      int    defIce;
      int    defFire;
      int    defLight;
      int    defDark;
public:
      ushort troopMedals[11]; //need to find get/set solution

public:
//Constructors, Destructors
    General  (void) {}
    General  (int i);
    ~General (void) {}
    
    General(const General& rhsGen);
    General& operator=(const General& rhsGen);

    int  editOneByteStat        (const int min, const int max, const int newStat, const int fileOffset, int* stat, uchar* statBuffer);
    int  editTwoByteStat        (const int min, const int max, const int newStat, const int fileOffset, int* stat, ushort* statBuffer);
    int  editMedals             (ushort newMedalCount, int troopTypeToChange, ushort* packedMedalToChange, int nibbleToChange, int highNibble, int lowNibble, int fileOffset);
    int  changeGenTroopType     (const ushort newGenTroopType);
    int  changeGenOwner         (const int newOwner);

    int  setSearchFortifyStatus (const bool setNaisei);
    void setStatus              (const int fs1, const int fs2);
    void setLocation            (const int locType, const int newLoc);
    void setOwner               (const int newOwner);
    void setTroopCount          (const int newTroopCount);
    int  changeLocation         (const int destLocType, const int destStatusType, const int newLoc);
    void hide                   (void);

    void setPlayer              (void) {isPlayerMonarch = 1; return;}

    int    getListIndex      (void) const {return listIndex;}
    bool   isPlayer          (void) const {return isPlayerMonarch;}
    string getName           (void) const {return name;}
    string getOwner          (void) const {return owner;}
    int    getFieldStatus1   (void) const {return fieldStatus1;}
    int    getFieldStatus2   (void) const {return fieldStatus2;}
    int    getLevel          (void) const {return level;}
    int    getClassType      (void) const {return classType;}
    int    getFixedLocation  (void) const {return fixedLocation;}
    int    getLocation       (void) const {return location;}
    int    getTroopIndex     (void) const {return troopIndex;}
    string getTroopType      (void) const {return troopType;}
    int    getCurrTroopCount (void) const {return currentTroopCount;}
    int    getNAction        (void) const {return nAction;}
    int    getBAction        (void) const {return bAction;}
    int    getLivesLeft      (void) const {return livesLeft;}
    int    getCurrentHP      (void) const {return currentHP;}
    int    getMaxHP          (void) const {return maxHP;}
    int    getCurrentMP      (void) const {return currentMP;}
    int    getMaxMP          (void) const {return maxMP;}
    int    getStrength       (void) const {return strength;}
    int    getDefp           (void) const {return defp;}
    int    getEscapeChance   (void) const {return escapeChance;}
    int    getCommand        (void) const {return command;}
    int    getIntelligence   (void) const {return intelligence;}
    int    getLoyalty        (void) const {return loyalty;}
    int    getEquippedItem   (void) const {return equippedItem;}
    int    getPortrait       (void) const {return portrait;}
    int    getNaisei         (void) const {return naisei;}
    int    getDomesticsMedal (void) const {return domesticsMedal;}
    int    getDomesticsSF    (void) const {return domesticsSF;}
    int    getNewWins        (void) const {return newWins;}
    int    getNewLosses      (void) const {return newLosses;}
    int    getOldWins        (void) const {return oldWins;}
    int    getOldLosses      (void) const {return oldLosses;}
    ushort getSoldierCavalry (void) const {return soldierCavalry;}
    ushort getMageSamurai    (void) const {return mageSamurai;}
    ushort getArcherMonk     (void) const {return archerMonk;}
    ushort getHarpyBeast     (void) const {return harpyBeast;}
    ushort getDragonZombie   (void) const {return dragonZombie;}
    int    getCurrentExp     (void) const {return currentExp;}
    int    getNewMerits      (void) const {return newMerits;}
    int    getOldMerits      (void) const {return oldMerits;}
    int    getHospital       (void) const {return hospital;}
    int    getBtlAction      (void) const {return btlAction;}
    int    getMoral          (void) const {return moral;}
    int    getWarlike        (void) const {return warlike;}
    int    getNego           (void) const {return nego;}
    int    getAtkPlus        (void) const {return atkPlus;}
    int    getSpellTier      (void) const {return spellTier;}
    int    getDefPlus        (void) const {return defPlus;}
    int    getDefSword       (void) const {return defSword;}
    int    getDefIce         (void) const {return defIce;}
    int    getDefFire        (void) const {return defFire;}
    int    getDefLight       (void) const {return defLight;}
    int    getDefDark        (void) const {return defDark;}
};

#endif
