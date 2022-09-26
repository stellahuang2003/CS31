//
//  main.cpp
//  Project 6
//
//  Created by Stella Huang on 3/1/22.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int * pArray = new int[n];     // Line 1: define a dynamic array pArray of size n
    for( int i = 0; i < n; i++ )
    {
       if (i % 2 == 0)                 // is the counter i even?
       {
          pArray[i] = i;               // Line 2: set pArray's even elements to the value i
       }
       else
       {
          pArray[i] = n;               // Line 3: set pArray's odd elements to the value n
       }
    }
    for( int i = 0; i < n; i++ ) {
        cout << pArray[i] << endl;
    }
    delete [] pArray;                    // Line 4: delete the dynamic array pArray
}
