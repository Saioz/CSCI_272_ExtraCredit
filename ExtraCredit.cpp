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
    if(isValid) {
        if (openParan == '(' && closeParan == ')' && separator == '-' &&
    areaCodeString.length() == 3 && 
    firstPartString.length()==3 && 
    secondPartString.length()==4)
    {
            return isValid;
    }
       
    }
      
    }
    return isValid;
    
    
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