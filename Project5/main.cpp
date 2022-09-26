//
//  main.cpp
//  Project 5
//
//  Created by Stella Huang on 2/20/22.
//
#include "Gym.h"
#include "GymMember.h"
#include "Kind.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
    Gym gym( "BFit", "330 De Neve Drive", REGULAR);
    // checks if setFeatures properly sets bools and that the bool getters work properly
    gym.setFeatures(true, false, true, false );
    assert( gym.hasCardioFeatures() == true);
    assert( gym.hasWeightsFeatures() == false);
    assert( gym.hasPoolFeatures() == true);
    assert( gym.hasTrackFeatures() == false);
    
    GymMember stella( "Stella", "005707861", EXECUTIVE );
    // checks if constructor sets workout count to 0
    assert( stella.workoutsThisMonth() == 0 );
    // checks if newWorkout() increments workout count by 1
    stella.newWorkout();
    assert( stella.workoutsThisMonth() == 1 );
    
    // checks if canWorkoutHere function lets EXECUTIVE members into REGULAR GYM
    if (gym.canWorkoutHere( stella ))
       gym.checkin( stella, true, false, true, false );
    // checks if checkin increments workout count by 1
    assert( stella.workoutsThisMonth() == 2 );
    
    // checks if canWorkoutHere function is properly called in checkin and workout count is properly incremented
    gym.checkin( stella, false, false, false, false );
    assert( stella.workoutsThisMonth() == 3);
    
    // checks if start new month code works
    stella.startNewMonth();
    assert( stella.workoutsThisMonth() == 0);
    
    // checks if checkin function works when gym member's workout preferences aren't met by the gym and doesn't increment workout count
    gym.checkin( stella, true, true, true, true );
    assert( stella.workoutsThisMonth() == 0);
    
    Gym wooden( "Wooden", "BruinWalk", OTHER);
    // check if canWorkoutHere properly excludes EXECUTIVE from OTHER
    assert( wooden.canWorkoutHere( stella ) == false );
    // check if constructor sets hasCardio, hasWeights, hasPool, and hasTrack to false so that when a member wants them they can't check in
    assert( wooden.checkin( stella, true, true, true, true ) == false );
    stella.startNewMonth();
    // check if newWorkout properly increments workout count
    stella.newWorkout();
    assert( stella.workoutsThisMonth() == 1 );
    // checks if getKindAsString's switch-case code works properly
    assert( wooden.getKindAsString() == "OTHER" );
    assert( stella.getKindAsString() == "EXECUTIVE" );
    
    // checks if getters for GymMember work
    assert( stella.getKind() == EXECUTIVE );
    assert( stella.getName() == "Stella" );
    assert( stella.getKindAsString() == "EXECUTIVE" );
    assert( stella.getAccountNumber() == "005707861" );
    
    // checks if getters for Gym work
    assert( wooden.getKind() == OTHER );
    assert( gym.getKindAsString() == "REGULAR" );
    assert( gym.getName() == "BFit" );
    assert( gym.getLocation() == "330 De Neve Drive" );
    
    cerr << "All good!" << endl;
    return (0);
}
