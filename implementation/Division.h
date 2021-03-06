#ifndef DIVISION_H
#define DIVISION_H

#include <iostream>
#include <string>

#include "DragonForce.h"

using namespace std;

class Division
{
private:
    int    ruler;
    int    leaderId;
    string leaderName;
    int    status;
    string statusName;
    int    divNum;
    bool   hasPlayerRuler;
    int    numMembers;
    int    numCaptives;
    int    troopCount;
public:
    int  members[5];    //need solution to get/set
    int  captives[171]; //need solution to get/set
private:
    int  origin;
    int  goal;
    int  prev;
    int  next;
    int  xCoordinate;
    int  yCoordinate;

public:
    Division  (void);
    ~Division (void) {}

    Division(const Division& rhsDiv);
    Division& operator=(const Division& rhsDiv);

    friend ostream& operator<<(ostream& os, const Division& rhsDiv);

    bool addMember_init  (const int genIndex);
    void addCaptive_init (const int genIndex);
    void removeCaptive   (const int genIndex);

    bool isDivisionFull (void) {return numMembers == 5;}

    int    getRuler         (void) const {return ruler;}
    int    getLeaderId      (void) const {return leaderId;}
    string getLeaderName    (void) const {return leaderName;}
    int    getStatus        (void) const {return status;}
    string getStatusName    (void) const {return statusName;}
    int    getDivNum        (void) const {return divNum;}
    bool   hasPlayerMonarch (void) const {return hasPlayerRuler;}
    int    getNumMembers    (void) const {return numMembers;}
    int    getNumCaptives   (void) const {return numCaptives;}
    int    getTroopCount    (void) const {return troopCount;}
    int    getOrigin        (void) const {return origin;}
    int    getGoal          (void) const {return goal;}
    int    getPrev          (void) const {return prev;}
    int    getNext          (void) const {return next;}
    int    getXCoordinate   (void) const {return xCoordinate;}
    int    getYCoordinate   (void) const {return yCoordinate;}

    void setRuler       (const int i)  {ruler = i; return;}
    void setLeaderId    (const int i)  {leaderId = i; return;}
    void setLeaderName  (const int i);
    void setStatus      (const int i)  {status = i; return;}
    void setStatusName  (const int i);
    void setDivNum      (const int i)  {divNum = i; return;}
    void setHasPlayer   (const bool i) {hasPlayerRuler = i; return;}
    void setTroopCount  (const int i)  {troopCount = i; return;}
    void setOrigin      (const int i)  {origin = i; return;}
    void setGoal        (const int i)  {goal = i; return;}
    void setPrev        (const int i)  {prev = i; return;}
    void setNext        (const int i)  {next = i; return;}
    void setXCoordinate (const int i)  {xCoordinate = i; return;}
    void setYCoordinate (const int i)  {yCoordinate = i; return;}

    int  findRulerIndex (void);
    int  changeRuler    (const int rulerIndex);
    int  changeLeader   (const int leaderIndex);
    void changeStatus   (const int newStatus);
    void changeGoal     (const int newGoal);
    void setNewGoal     (const int newGoal);

    bool addMultiGenFromList (int* const genBuff, const int genCount);
    bool delMultiGenFromList (int* const genBuff, const int genCount);
    bool addMultiCapFromList (int* const capBuff, const int capCount);
    bool delMultiCapFromList (int* const capBuff, const int capCount);
    int  fromGenToCap        (int* const genBuff, const int genCount);
    bool fromCapToGen        (int* const capBuff, const int capCount);

    void removeMember_a      (const int genIndex);
    void addMember_a         (const int genIndex);
    void addCaptive_a        (const int genIndex);
    void moveCaptivesToHold  (void);
    void cleanCaptiveHolder  (void);
    void setDivisionEmpty    (void);
    void moveMembersToCastle (void);
    void setDivisionCoords   (const int locNum);
};

#endif
