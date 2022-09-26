//
//  GymMember.cpp
//  Kind
//
//  Created by Stella Huang on 2/19/22.
//
#include "GymMember.h"
#include "Kind.h"
#include <iostream>
#include <string>
using namespace std;

GymMember::GymMember(string name, string account, Kind kind) {
    mName = name;
    mAccountNumber = account;
    mKind = kind;
    mWorkoutCount = 0;
}

int GymMember::workoutsThisMonth() const {
    return(mWorkoutCount);
}
void GymMember::startNewMonth() {
    mWorkoutCount = 0;
}
void GymMember::newWorkout() {
    mWorkoutCount++;
}

Kind GymMember::getKind() const {
    return(mKind);
}
string GymMember::getKindAsString() const {
    switch(mKind) {
        case REGULAR:
            return ("REGULAR");
            break;
        case PREMIER:
            return ("PREMIER");
            break;
        case EXECUTIVE:
            return ("EXECUTIVE");
            break;
        default:
            return ("OTHER"); 
    }
}
string GymMember::getName() const {
    return(mName);
}
string GymMember::getAccountNumber() const {
    return(mAccountNumber);
}
