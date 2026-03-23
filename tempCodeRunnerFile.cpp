#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

bool isValidPhoneNumber(const string& input) {
    istringstream iss(input);
    
    char openParan, closeParan, separator;
    string areaCode, firstPart, secondPart;
    
    if (iss >> openParan >> areaCode >> closeParan >> firstPart >> separator >> secondPart) {
        // Check format characters
        if (openParan != '(' || closeParan != ')' || separator != '-') {
            return false;
        }
        
        // Check lengths
        if (areaCode.length() != 3 || firstPart.length() != 3 || secondPart.length() != 4) {
            return false;
        }
        
        // Check that all characters are digits
        for (char c : areaCode) {
            if (!isdigit(c)) return false;
        }
        for (char c : firstPart) {
            if (!isdigit(c)) return false;
        }
        for (char c : secondPart) {
            if (!isdigit(c)) return false;
        }
        
        return true;
    }
    return false;
}

int main() {
    string input;
    cout << "Enter a U.S phone number (xxx) xxx-xxxx: ";
    getline(cin, input);
    
    if (isValidPhoneNumber(input)) {
        cout << "Valid." << endl;
    }
    else {
        cout << "Invalid." << endl;
    }
    return 0;
}