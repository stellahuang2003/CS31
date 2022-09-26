//
//  GymMember.h
//  GymMember
//
//  Created by Stella Huang on 2/19/22.
//
#ifndef GYMMEMBER_H
#define GYMMEMBER_H
#include "Kind.h"
#include <iostream>
#include <string>

class GymMember {
private:
    std::string mName;
    std::string mAccountNumber;
    Kind mKind;
    int mWorkoutCount;
public:
    GymMember(std::string name, std::string account, Kind kind);
    
    int workoutsThisMonth() const;
    void startNewMonth();
    void newWorkout();
    
    Kind getKind() const;
    std::string getKindAsString() const;
    std::string getName() const;
    std::string getAccountNumber() const;
};
#endif 

