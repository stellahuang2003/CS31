//
//  main.cpp
//  cellplan
//
//  Created by Stella Huang on 1/16/22.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout.setf(  ios::fixed  );
    cout.setf(  ios::showpoint  );
    cout.precision( 2 ); // sets doubles to have two decimal places
    
    string response;
    string cellPlan;
    int lines = -1;
    int numGigabytes = -1;
    double cost = 0;
    bool planValid = true;
    bool autopayValid = true;
    bool billingValid = true;
    bool linesValid = true;
    bool gigabytesValid = true;
    
    // takes in cell plan input
    cout << "What type of cell plan do you have? ";
    getline( cin , response );
    if ( response == "Unlimited Elite" ) { // if-else statement checks to see if input matches with one of the four available options
        cellPlan = response;
        cost += 85;
    }
    else if ( response == "Unlimited Extra" ) {
        cellPlan = response;
        cost += 75;
    }
    else if ( response == "Unlimited Starter" ) {
        cellPlan = response;
        cost += 65;
    }
    else if ( response == "Prepaid" ) {
        cellPlan = response;
        cost += 50;
    }
    else {
        planValid = false; // if input doesn't match with one of the four options above, then the plan is not valid
    }
    
    // takes in autopay input
    cout << "Are you on autopay? ";
    getline( cin , response );
    if ( response == "Yes" ) {
        cost -= 2;
    }
    else if ( response != "No" ) {
        autopayValid = false; // if the  input isn't "Yes" or "No", then the autopay is not valid
    }
    
    // takes in billing input
    cout << "Are you on paperless billing? ";
    getline( cin , response );
    if ( response == "Yes" ) {
        cost -= 3;
    }
    else if ( response != "No" ) {
        billingValid = false; // if the input isn't "Yes" or "No", then the billing is not valid
    }
    
    // takes in lines input
    cout << "How many lines will be on your plan? ";
    cin >> lines;
    cin.ignore( 10000, '\n' );
    if ( lines != 1 && lines != 2 && lines != 3 ) {
        linesValid = false; // if the input isn't 1, 2, or 3, then the lines are not valid
    }
    else if ( lines == 2 || lines == 3 ) {
        cost = cost * lines - lines * 10 ;
    }
     
    // takes in gigabytes input
    cout << "How many gigabytes did you consume this month? ";
    cin >> numGigabytes;
    if ( numGigabytes >= 0 && numGigabytes <= 30 ) {
        if ( cellPlan == "Prepaid" ) {
            if ( numGigabytes > 4 ) {
                numGigabytes -= 4;
                cost += ( numGigabytes / 2 ) * 10;
            }
        }
    }
    else {
        gigabytesValid = false; // if the input isn't between 0 and 30, inclusive, then the gigabytes are not valid
    }
    
    // checks if there are any invalid input statements to print, and if not, then the cell plan amount is printed
    if ( planValid == false || autopayValid == false || billingValid == false || linesValid == false || gigabytesValid == false ) {
        if ( planValid == false ) {
            cout << "Your cell plan is not valid!\n";
        }
        else if ( autopayValid == false ) {
            cout << "Your autopay is not valid!\n";
        }
        else if ( billingValid == false ) {
            cout << "Your paperless billing is not valid!\n";
        }
        else if ( linesValid == false ) {
            cout << "Your lines are not valid!\n";
        }
        else if ( gigabytesValid == false ) {
            cout << "Your gigabytes are not valid!\n";
        }
    }
    else {
        cout << "Your " << cellPlan << " cell plan costs $" << cost << "." << endl;
    }
    return ( 0 );
}
