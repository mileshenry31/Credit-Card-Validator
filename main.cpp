/*
TODO:
    1. Drop first number of entered credit card number and save it as a check digit to use in TODO 4
    2. Find all individual numbers that are 2 digits, split those digits, add them together, and put it back in the same spot the two digit number was
    3. Add all of the resulting digits together
    4. For it to be true once you add up all the digits (s) (10 - (s % 10)) mod 10 should equal check digit
*/
#include <iostream>
#include <array>

// Just take away error and make u_long a thing
typedef unsigned long u_long;
bool luhns(std::string ccNum);
int main() {
    luhns("01839187319137");
    return 0;
}

bool luhns(std::string ccNum) {
    int checkDigit = ccNum.back() - '0';
    // create array the size of the string aka same number of "digits"
    int ccArr[ccNum.length()];
    // get length of array
    int len = sizeof(ccArr) / sizeof(ccArr[0]);
    //char multipliedArr[len];
    // iterate through the string and put each char in the array. has to be u_long or throws an error
    for (u_long i = 0; i < ccNum.length(); i++) {
        ccArr[i] = ccNum[i];
        ccArr[i] = ccArr[i];
    }
    // go from right to left of array
    for (int i = len - 1; i >= 0; i -= 2) {
        ccArr[i] = ccArr[i] * 2;
        //std::cout << ccArr[i] << "\n";
    }
    
    return true;
}