#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

bool isValidPhoneNumber(const string& input) {
istringstream iss(input);

char openParan, closeParan, separator;

int areaCode, firstPart, secondPart;

bool isValid{};


if (iss >> openParan >> areaCode >> closeParan >> firstPart >> separator >> secondPart) {
    string areaCodeString = to_string(areaCode);
    string firstPartString = to_string(firstPart);
    string secondPartString = to_string(secondPart);
    //tostring from int to string
    isValid = true;
    
    for (int i = 0; i < areaCodeString.length(); i++) {
            if (!isdigit(areaCodeString[i])) {
                isValid = false;
                break;
            }
        }
    for (int i = 0; i < firstPartString.length(); i++) {
            if (!isdigit(firstPartString[i])) {
                isValid = false;
                break;
            }
        }
    for (int i = 0; i < secondPartString.length(); i++) {
            if (!isdigit(secondPartString[i])) {
                isValid = false;
                break;
            }
        }
    //checks to_string, makes sure they are all integers / digits from 0-9
    
    if(isValid) {
        if (openParan == '(' && closeParan == ')' && separator == '-' &&
    areaCodeString.length() == 3 && 
    firstPartString.length()==3 && 
    secondPartString.length()==4) {
            return isValid;
    }
    //should only be able to run if all the strings are completely valid, all integers no mixed inputs "00A" or "OO0" etc.
    
    }
    return false;
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