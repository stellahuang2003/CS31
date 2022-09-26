//
//  main.cpp
//  cdplayer
//
//  Created by Stella Huang on 1/28/22.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isValidCDPlayerString(string cdstring);
bool isOpen(string cdstring);
bool hasCD(string cdstring);
int totalTracksPlayed(string cdstring);
int currentTrack(string cdstring);

int main() {
    assert( isValidCDPlayerString("OICP123OC456") == false );
    assert( isValidCDPlayerString("OICP123SOCS") == false );
    assert( isValidCDPlayerString("OICP1234SOCP123") == false );
    assert( isValidCDPlayerString("OICP123ORICP456S") == false );
    assert( isValidCDPlayerString("OICP123ORICP123") == true );
    assert( isValidCDPlayerString("OICP123ORICS") == true );
    assert( isOpen( "OICP123ORIS" ) == true );
    assert( hasCD( "OICP123ORCS" ) == false );
    assert( totalTracksPlayed( "OC123P" ) == -1 );
    assert( currentTrack("OICP123ORI") == 1 );
    assert( currentTrack("OICP123O") == 4 );
    assert( currentTrack("OICP123456789") == 10 );
    assert( currentTrack("OIC") == 1 );
    assert( currentTrack("OICP") == 1 );
    assert( currentTrack("OIRC") == -1 );
    cerr << "All tests succeeded" << endl;
}

bool isValidCDPlayerString( string cdstring )
{
    bool isOpen = false; // by default the cd player is closed
    bool OisPlaying = false; // made to handle invalid cases like OICP123OC456 and OICP123ORIC123 (from Project 3 Discussion) where O inherently stops CD and tracks are only able to play if there is a P directly in front of them (ie. OICP123OC456 (invalid --> OICP123OCP456 (valid)), but O is not connected to P and S
    bool hasCD = false; // by default the cd player doesn't have a cd
    bool isPlaying = false; // by default the cd player isn't playing
    int currentTrack = 1;
    
    if (cdstring.length() == 0 || cdstring.at(0) != 'O') { // handles strings that are empty or don't start w/ 'O'
        return false;
    }
    
    for (size_t pos = 0; pos < cdstring.length(); pos++) { // goes through each character of string
        switch (cdstring.at(pos)) { // switch-case statement includes cases for all possible characters in a valid string
            case 'O':
                if (isOpen) {
                    // cerr << "false open"; // <-- cerr used to check what caused isValidCDPlayerString to return false
                    return false;
                }
                OisPlaying = false;
                isOpen = true;
                break;
            case 'C':
                if (!isOpen) {
                    // cerr << "false close";
                    return false;
                }
                isOpen = false;
                break;
            case 'I':
                if (isOpen && !hasCD) {
                    hasCD = true;
                    currentTrack = 1; // <-- currentTrack reset to 1 whenever new CD inserted
                } else {
                    // cerr << "false insert";
                    return false;
                }
                break;
            case 'R':
                if (isOpen && hasCD) {
                    hasCD = false;
                } else {
                    // cerr << "false remove";
                    return false;
                }
                break;
            case 'P':
                if (!isOpen && hasCD) {
                    OisPlaying = true;
                    isPlaying = true;
                } else {
                    // cerr << "false play";
                    return false;
                }
                break;
            case 'S':
                if (isPlaying) {
                    isPlaying = false;
                } else {
                    // cerr << "false stop";
                    return false;
                }
                break;
            case '1':
                if (OisPlaying && isPlaying && !isOpen && hasCD && currentTrack == 1) {
                    currentTrack++; // <-- makes sure that next track played is 2
                } else {
                    // cerr << "false 1";
                    return false;
                }
                break;
            case '2':
                if (OisPlaying && isPlaying && !isOpen && hasCD && currentTrack == 2) {
                    currentTrack++;
                } else {
                    // cerr << "false 2";
                    return false;
                }
                break;
            case '3':
                if (OisPlaying && isPlaying && !isOpen && hasCD && currentTrack == 3) {
                    currentTrack++;
                } else {
                    // cerr << "false 3";
                    return false;
                }
                break;
            case '4':
                if (OisPlaying && isPlaying && !isOpen && hasCD && currentTrack == 4) {
                    currentTrack++;
                } else {
                    // cerr << "false 4";
                    return false;
                }
                break;
            case '5':
                if (OisPlaying && isPlaying && !isOpen && hasCD && currentTrack == 5) {
                    currentTrack++;
                } else {
                    // cerr << "false 5";
                    return false;
                }
                break;
            case '6':
                if (OisPlaying && isPlaying && !isOpen && hasCD && currentTrack == 6) {
                    currentTrack++;
                } else {
                    // cerr << "false 6";
                    return false;
                }
                break;
            case '7':
                if (OisPlaying && isPlaying && !isOpen && hasCD && currentTrack == 7) {
                    currentTrack++;
                } else {
                    // cerr << "false 7";
                    return false;
                }
                break;
            case '8':
                if (OisPlaying && isPlaying && !isOpen && hasCD && currentTrack == 8) {
                    currentTrack++;
                } else {
                    // cerr << "false 8";
                    return false;
                }
                break;
            case '9':
                if (OisPlaying && isPlaying && !isOpen && hasCD && currentTrack == 9) {
                    currentTrack++;
                } else {
                    // cerr << "false 9";
                    return false;
                }
                break;
            default: // <-- handles cases where string's character doesn't match any of the valid options above
                // cerr << "false default";
                return false;
        }
    }
    
    return true; // <-- if string successfully makes it through the for-loop, then it is valid
}

bool hasCD( string cdstring )
{
    bool hasCD = false; // <-- by default false because cd player is empty
    if (!isValidCDPlayerString(cdstring)) {
        return hasCD;
    }
    for (int pos = 0; pos < cdstring.length(); pos++) {
        if (cdstring.at(pos) == 'I') {
            hasCD = true;
        } else if (cdstring.at(pos) == 'R') {
            hasCD = false;
        }
    }
    return hasCD;
}

bool isOpen( string cdstring )
{
    bool isOpen = false; // by default the cd player is closed
    if (!isValidCDPlayerString(cdstring)) {
        return isOpen;
    }
    for (size_t pos = 0; pos < cdstring.length(); pos++) {
        if (cdstring.at(pos) == 'O') {
            isOpen = true;
        } else if (cdstring.at(pos) == 'C') {
            isOpen = false;
        }
    }
    return isOpen;
}

int  totalTracksPlayed(  string cdstring )
{
    int total = 0; // by default 0 tracks played
    if (!isValidCDPlayerString(cdstring)) {
        return (-1);
    }
    for (size_t pos = 0; pos < cdstring.length(); pos++) {
        switch (cdstring.at(pos)) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                total++;
                break;
            default: // if char doesn't equal any of the numbers, then go on with for loop without updating total
                break;
        }
    }
    return total;
}

int  currentTrack( string cdstring )
{
   int currentTrack = 1;
    if (!isValidCDPlayerString(cdstring) || !hasCD(cdstring)) { // returns -1 when cdstring isn't valid or cd player is empty
        return (-1);
    }
    for (size_t pos = 0; pos < cdstring.length(); pos++) {
        switch (cdstring.at(pos)) {
            case 'I':
                currentTrack = 1; // current track reset to 1 if new cd is inserted or cd is reinserted
                break;
            case '1':
                currentTrack = 2;
                break;
            case '2':
                currentTrack = 3;
                break;
            case '3':
                currentTrack = 4;
                break;
            case '4':
                currentTrack = 5;
                break;
            case '5':
                currentTrack = 6;
                break;
            case '6':
                currentTrack = 7;
                break;
            case '7':
                currentTrack = 8;
                break;
            case '8':
                currentTrack = 9;
                break;
            case '9':
                currentTrack = 10;
                break;
            default:
                break;
        }
    }
    return currentTrack;
}
