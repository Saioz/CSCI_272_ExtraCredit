#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

bool isValidPhoneNumber(const string& input) {
istringstream iss(input);

char openParan, closeParan, separator;

string areaCode, firstPart, secondPart;

bool isValid{};


if (iss >> openParan >> areaCode >> closeParan >> firstPart >> separator >> secondPart) {

    //tostring from int to string
    isValid = true;
    
    for (int i = 0; i < areaCode.length(); i++) {
            if (!isdigit(areaCode[i])) {
                isValid = false;
                break;
            }
        }
    for (int i = 0; i < firstPart.length(); i++) {
            if (!isdigit(firstPart[i])) {
                isValid = false;
                break;
            }
        }
    for (int i = 0; i < secondPart.length(); i++) {
            if (!isdigit(secondPart[i])) {
                isValid = false;
                break;
            }
        }
    //checks to_string, makes sure they are all integers / digits from 0-9
    
    if(isValid) {
        if (openParan == '(' &&
    areaCode.length() == 3 && 
    closeParan == ')' && 
    firstPart.length()== 3 && 
    separator == '-' &&
    secondPart.length()== 4) {
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