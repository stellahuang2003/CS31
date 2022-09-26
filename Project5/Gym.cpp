//
//  Gym.cpp
//  Project 5
//
//  Created by Stella Huang on 2/20/22.
//
#include "Gym.h"
#include "GymMember.h"
#include "Kind.h"
#include <iostream>
#include <string>
using namespace std;

Gym::Gym(string name, string location, Kind kind) {
    mName = name;
    mLocation = location;
    mKind = kind;
    hasCardio = false;
    hasWeights = false;
    hasPool = false;
    hasTrack = false;
}
void Gym::setFeatures(bool cardio, bool weights, bool pool, bool track) {
    hasCardio = cardio;
    hasWeights = weights;
    hasPool = pool;
    hasTrack = track;
}

bool Gym::canWorkoutHere(GymMember m) {
    Kind memberKind = m.getKind();
    if (memberKind == OTHER && mKind == OTHER) {
        return true;
    }
    if (memberKind == REGULAR && mKind == REGULAR) {
        return true;
    }
    if ((memberKind == PREMIER && mKind == REGULAR) ||
        (memberKind == PREMIER && mKind == PREMIER)) {
        return true;
    }
    if ((memberKind == EXECUTIVE && mKind == REGULAR) ||
        (memberKind == EXECUTIVE && mKind == PREMIER) ||
        (memberKind == EXECUTIVE && mKind == EXECUTIVE)) {
        return true;
    }
    return false;
}
bool Gym::checkin(GymMember & m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack) {
    if (Gym::canWorkoutHere(m) == false) {
        return false;
    }
    if (wantsCardio && !hasCardio) {
        return false;
    }
    if (wantsWeights && !hasWeights) {
        return false;
    }
    if (wantsPool && !hasPool) {
        return false;
    }
    if (wantsTrack && !hasTrack) {
        return false;
    }
    m.newWorkout();
    return true;
}

bool Gym::hasCardioFeatures() const {
    return (hasCardio);
}
bool Gym::hasWeightsFeatures() const {
    return (hasWeights);
}
bool Gym::hasPoolFeatures() const {
    return (hasPool);
}
bool Gym::hasTrackFeatures() const {
    return (hasTrack);
}

Kind Gym::getKind() const {
    return (mKind);
}
string Gym::getKindAsString() const {
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
string Gym::getLocation() const {
    return (mLocation);
}
string Gym::getName() const {
    return (mName);
}
