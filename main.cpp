#include <iostream>
#include <array>
#include <string>

// Just take away error and make u_long a thing
typedef unsigned long u_long;
bool luhns(std::string ccNum);
int main() {
    // random comment
    std::string number;
    std::cout << "What is your credit card number? ";
    std::cin >> number;
    luhns(number);
    return 0;
}

bool luhns(std::string ccNum) {
    // create array the size of the string aka same number of "digits"
    int ccArr[ccNum.length() - 1];
    // get length of array
    int len = sizeof(ccArr) / sizeof(ccArr[0]);
    int checkDigit = ccNum.back() - '0';
    int finally = 0;
    // iterate through the string and put each char in the array. has to be u_long or throws an error
    for (u_long i = 0; i < ccNum.length(); i++) {
        if (ccNum[i] < 48 || ccNum[i] > 57) {
            std::cout << "Please enter only numbers.\n";
            return false;
        }
        if (i == len) {
            continue;
        }
        ccArr[i] = ccNum[i];
        ccArr[i] = ccArr[i];
        ccArr[i] = ccArr[i] - '0';

    }
    // go from right to left of array
    for (int i = len - 1; i >= 0; i -= 2) {
        ccArr[i] = ccArr[i] * 2;
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
    for (int i : ccArr) {
        finally += i;
    }
    if ((10 - (finally % 10)) % 10 == checkDigit) {
        std::cout << "Valid" << "\n";
    } else {
        std::cout << "Not valid." << "\n";
    }
    return true;
}
