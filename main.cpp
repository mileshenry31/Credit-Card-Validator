/*
TODO:
    1. Find all individual numbers that are 2 digits, split those digits, add them together, and put it back in the same spot the two digit number was
    2. Add all of the resulting digits together
    3. For it to be true once you add up all the digits (s) (10 - (s % 10)) mod 10 should equal check digit
*/
#include <iostream>
#include <array>
#include <string>

// Just take away error and make u_long a thing
typedef unsigned long u_long;
bool luhns(std::string ccNum);
int main() {
    luhns("123456");
    return 0;
}

bool luhns(std::string ccNum) {
    // create array the size of the string aka same number of "digits"
    int ccArr[ccNum.length() - 1];
    // get length of array
    int len = sizeof(ccArr) / sizeof(ccArr[0]);
    int checkDigit = ccNum.back() - '0';
    //char multipliedArr[len];
    // iterate through the string and put each char in the array. has to be u_long or throws an error
    for (u_long i = 0; i < ccNum.length(); i++) {
       if (i == len) {
            continue;
        }
        ccArr[i] = ccNum[i];
        ccArr[i] = ccArr[i];
        ccArr[i] = ccArr[i] - '0';
        //std::cout << ccArr[i] << '\n';

    }
    // go from right to left of array
    for (int i = len - 1; i >= 0; i -= 2) {
        /*if (i == len - 1) {
            continue;
        }*/
        ccArr[i] = ccArr[i] * 2;
        //std::cout << ccArr[i] << "\n";
    }
    // goes through each number and splits the double digit ones in half and then adds those two numbers together
    for (int i = 0; i < len; i++) {
        std::string temp;
        int first;
        int second;
        if (ccArr[i] >= 10) {
            int added;
            temp = std::to_string(ccArr[i]);
            first = temp[0] - '0';
            second = temp[1] - '0';
            added = first + second;
            ccArr[i] = added;
        }
    }
    return true;
}