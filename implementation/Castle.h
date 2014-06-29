#ifndef CASTLE_H
#define CASTLE_H

#include <iostream>
#include <string>

#include "DragonForce.h"

using namespace std;

class Castle
{
private:
    int  castleNum;
    int  ruler;
    int  leader;
    int  numGenerals;
    int  numCaptives;
public:
    int  generals[10];  //find solution to set/get
    int  captives[171]; //find solution to set/get
private:
    int  xCoordinate;
    int  yCoordinate;
    bool hasPlayerRuler;
    int  level;
    int  troopCount;
    int  maxTroops;
    int  experience;
    int  expNext;
    string castleName;

public:
//constructors, destructors
    Castle  (void);
    ~Castle (void) {}

    Castle(const Castle& rhsCas);
    Castle& operator=(const Castle& rhsCas);

    friend ostream& operator<<(ostream& os, const Castle& rhsCas);

    int  addGeneral_init     (const int genIndex);
    int  addCaptive_init     (const int genIndex);
    void removeGeneral       (const int newCastle, const int genIndex);
    void setCastleEmpty      (void);
    void removeCaptive       (const int genIndex);
    int  changeLeader        (const int genIndex);
    int  adjustTroops        (const int newTroops);
    int  adjustLevel         (const int newLevel);
    int  changeRuler         (const int genIndex);
    int  findRulerIndex      (void);
    bool addMultiGenFromList (int* const genBuff, const int genCount);
    bool delMultiGenFromList (int* const genBuff, const int genCount);
    bool addMultiCapFromList (int* const capBuff, const int capCount);
    bool delMultiCapFromList (int* const capBuff, const int capCount);
    int  fromGenToCap        (int* const genBuff, const int genCount);
    bool fromCapToGen        (int* const capBuff, const int capCount);

    bool isCastleFull     (void) const {return numGenerals == 10;}
    bool isCastleEmpty    (void) const {return numGenerals == 0;}

    int    getCastleNum     (void) const {return castleNum;}
    int    getRuler         (void) const {return ruler;}
    int    getLeader        (void) const {return leader;}
    int    getNumGenerals   (void) const {return numGenerals;}
    int    getNumCaptives   (void) const {return numCaptives;}
    int    getXCoordinate   (void) const {return xCoordinate;}
    int    getYCoordinate   (void) const {return yCoordinate;}
    bool   hasPlayerMonarch (void) const {return hasPlayerRuler;}
    int    getLevel         (void) const {return level;}
    int    getTroopCount    (void) const {return troopCount;}
    int    getMaxTroops     (void) const {return maxTroops;}
    int    getExperience    (void) const {return experience;}
    int    getExpNext       (void) const {return expNext;}
    string getCastleName    (void) const {return castleName;}

    void setCastleNum   (const int i)      {castleNum = i; return;}
    void setRuler       (const int i)      {ruler = i; return;}
    void setLeader      (const int i)      {leader = i; return;}
    void setXCoordinate (const int i)      {xCoordinate = i; return;}
    void setYCoordinate (const int i)      {yCoordinate = i; return;}
    void setHasMonarch  (const bool i)     {hasPlayerRuler = i; return;}
    void setLevel       (const int i)      {level = i; return;}
    void setTroopCount  (const int i)      {troopCount = i; return;}
    void setMaxTroops   (const int i)      {maxTroops = i; return;}
    void setExperience  (const int i)      {experience = i; return;}
    void setExpNext     (const int i)      {expNext = i; return;}
    void setCastleName  (const char* name) {castleName = name; return;}

    void removeGeneral_a    (const int genIndex);
    void addGeneral_a       (const int genIndex);
    int  addCaptive_a       (const int genIndex);
    void moveCaptivesToHold (void);
    void cleanCaptiveHolder (void);
};

#endif
