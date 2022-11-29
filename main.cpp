#include <iostream>

// Just take away error and make u_long a thing
typedef unsigned long u_long;
bool luhns(std::string ccNum);
int main() {
    luhns("0298472");
    return 0;
}

bool luhns(std::string ccNum) {
    // create array the size of the string aka same number of "digits"
    int ccArr[ccNum.length()];
    // get length of array
    int len = sizeof(ccArr) / sizeof(ccArr[0]);
    //char multipliedArr[len];
    // iterate through the string and put each char in the array. has to be u_long or throws an error
    for (u_long i = 0; i < ccNum.length(); i++) {
        ccArr[i] = ccNum[i];
        ccArr[i] = ccArr[i] - '0';
    }
    // go from right to left of array
    for (int i = len - 1; i >= 0; i -= 2) {
        ccArr[i] = ccArr[i] * 2;
        //std::cout << ccArr[i] << "\n";
    }
    
    return true;
}