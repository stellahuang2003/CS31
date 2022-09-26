//
//  main.cpp
//  array
//
//  Created by Stella Huang on 2/8/22.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int locateMinimum( const  string  array[ ],  int  n );
int countCommonElements( const string array1[ ], int  n1, const string array2[ ], int n2 );
int countVowels( const string array[ ], int n );
bool hasThreeOfX( const string array[ ], int n, string x );
string majorityElement( const string array[ ], int  n );
bool shiftRight( string array[ ], int n, int amount, string placeholder );
bool rotateLeft( string array[ ], int n, int amount );
int replaceAll( string array[ ], int n, char letterToReplace, char letterToFill );

int main(int argc, const char * argv[]) {
    string folks[8] = {  "samwell", "jon", "margaery", "daenerys",
        "tyrion", "sansa", "magdalena", "jon" };
    string data[5] = { "mama", "mama", "12", "sansa", "mama" };
    string a[7] = { "ee", "dd", "cc", "bb", "aa", "BB", "AA" };
    string b[7] = { "AA", "BB", "BB", "BB", "cc", "dd", "ee" };
    string c[6] = { "123", "456", "789", "gamma", "beta", "delta" };
    string hello[4] = { "aa", "bb", "bb", "cc" };
    string bye[4] = { "bb", "bb", "dd", "ee" };
    string same[4] = { "a", "a", "a", "a"};
    string nothing[3] = { " ", " ", "" };
    string r[1] = {"aa"};
    string foo[7] = {"foo", "foo", "foo", "bb", "aa", "BB", "AA"};
    //locateMinimum
    assert(locateMinimum (folks, 8) == 3 );
    assert(locateMinimum (same, 3) == 0 );
    //countCommonElements
    assert(countCommonElements(folks, 8, data, 5) == 1);
    assert(countCommonElements(folks, 9, data, -1) == -1);
    assert(countCommonElements(folks, 3, data, 3) == 0);
    assert(countCommonElements(a, 7, b, 7 ) == 7);
    assert(countCommonElements(hello, 4, bye, 4) == 4);
    // codeboard test but reversed
    assert(countCommonElements(b, 7, a, 7) == 7);
    //countVowels
    assert(countVowels(c, 3) == 0 );
    assert(countVowels(data, 5) == 8 );
    //hasThreeOfX
    assert(hasThreeOfX(c, 6, "X" ) == false );
    assert(hasThreeOfX( folks, 5, "jon") == false);
    assert(hasThreeOfX(foo, 2, "foo") == false);
    assert(hasThreeOfX(foo, 4, "foo") == true);
    //has more than three of x
    assert(hasThreeOfX(same, 4, "a") == false);
    //majorityElement
    assert(majorityElement(r, 1) == "aa");
    assert(majorityElement(same, 4) == "a");
    assert(majorityElement(folks, 8) == "");
    assert(majorityElement(data, 5) == "mama");
    //shiftRight
    assert(shiftRight(a, 5, 1, "foo" ) == true);
    assert(shiftRight(a, 5, 0, "foo" ) == false);
    assert(shiftRight(foo, 3, 2, "foo") == true);
    assert(shiftRight(data, 5, 2, "foo" ) == true);
    assert(shiftRight(data, 5, -10, "bar" ) == false);
    //rotateLeft
    assert(rotateLeft(r, 1, 5) == false);
    assert(rotateLeft(hello, 2, 3) == true);
    assert(rotateLeft(hello, 1, 3) == false);
    assert(rotateLeft(folks, 2, 12) == false);
    //replaceAll
    assert(replaceAll(folks, 8, 'A', 'Z') == 0);
    assert(replaceAll(folks, 8, 'a', 'Z') == 9);
    assert(replaceAll(nothing, 3, ' ', 'Z') == 2);
    
    cerr << "Functions worked!" << endl;
    return (0);
}

int locateMinimum( const  string  array[ ],  int  n ) {
    if (n <= 0) {
        return (-1);
    }
    int min = 0; // if array is one string long then 0 will be default smallest index
    for (int i = 0; i < n; i++) {
        if (array[i] < array[min]) {
            min = i;
        }
    }
    return min;
}

int countCommonElements( const string array1[ ], int  n1, const string array2[ ], int n2 ) {
    if (n1 <= 0 || n2 <= 0) {
        return (-1);
    }
    int common = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (array1[i] == array2[j]) {
                common++;
            }
        }
    }
    return common;
}

int countVowels( const string array[ ], int n ) {
    if (n <= 0) {
        return (-1);
    }
    string word;
    int numVowels = 0;
    for (int i = 0; i < n; i++) {
        word = array[i];
        for (size_t j = 0; j < word.length(); j++) {
            switch (word[j]) {
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                case 'y':
                case 'Y':
                    numVowels++;
                    break;
                default:
                    break;
            }
        }
    }
    return numVowels;
}

bool hasThreeOfX( const string array[ ], int n, string x ) {
    if (n <= 0) {
        return false;
    }
    int numX = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] == x) {
            numX++;
        }
    }
    return (numX == 3);
}

string majorityElement( const string array[ ], int  n ) {
    string majority = "";
    string word;
    int timesFound = 0;
    for (int i = 0; i < n; i++) {
        word = array[i];
        for (int j = 0; j < n; j++) {
            if (word == array[j]) {
                timesFound++;
            }
        }
        if (timesFound > (n / 2)) {
            majority = word;
        }
        timesFound = 0;
    }
    return majority;
}

bool shiftRight( string array[ ], int n, int amount, string placeholder ) {
    if (n <= 0 || amount <= 0) {
        return false;
    }
    // just to make sure we don't walk off the array if amount >= array length
    if (n <= amount) {
        for (int i = 0; i < n; i++) {
            array[i] = placeholder;
        }
        return true;
    }
    // for all remaining cases where the amount shifted isn't greater than or equal to the array length
    string lastValue;
    for (int i = 0; i < amount; i++) { // do this shifting 'amount' times
        lastValue = array[n - 1]; // so that when last value gets filled by the previous position's value its original value can still be used to fill the first index
        for (int j = n - 1; j >= 0; j--) { // descending for loop
            if (j == 0) { // make sure we don't go into negative indices (ie. array[0] = array[-1])
                array[j] = lastValue;
            } else {
                array[j] = array[j - 1];
            }
        }
    }
    for (int i = 0; i < amount; i++) { // fills array's first 'amount' indices with placeholder
        array[i] = placeholder;
    }
    
    return true;
}

bool rotateLeft( string array[ ], int n, int amount ) {
    if (n <= 0 || amount <= 0 || (amount % n) == 0) { // accounts for cases where array is rotated by multiples of its size
        return false;
    }
    string firstValue;
    for (int i = 0; i < amount; i++) { // same as shiftRight's first for loop, just left instead of right :)
        firstValue = array[0]; // so that the original value isn't lost and can be used to fill the last value
        for (int j = 0; j < n; j++) {
            if (j == (n - 1)) { // if the index is at the last value, make it the original first value; also ensures we don't walk off array
                array[j] = firstValue;
            } else {
                array[j] = array[j + 1];
            }
        }
    }
    return true;
}

int replaceAll( string array[ ], int n, char letterToReplace, char letterToFill ) {
    if (n <= 0) {
        return (-1);
    }
    string word;
    int count = 0;
    for (int i = 0; i < n; i++) {
        word = array[i];
        for (size_t j = 0; j < word.length(); j++) {
            if (word[j] == letterToReplace) {
                word[j] = letterToFill;
                count++;
            }
        }
        array[i] = word; //updates array with modified (or not modified) word
    }
    return count;
}
