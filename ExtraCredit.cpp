#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool isValidPhoneNumber(const string& input) {
istringstream iss(input);

char openParan, closeParan, separator;

int areaCode, firstPart, secondPart;

if (iss >> openParan >> areaCode >> closeParan >> firstPart >> separator >> secondPart) {

    string areaCodeString = to_string(areaCode);
    string firstPartString = to_string(firstPart);
    string secondPartString = to_string(secondPart);
    
    
    
    if (openParan == '(' && closeParan == ')' && separator == '-' &&
    areaCodeString.length() == 3 && 
    firstPartString.length()==3 && 
    secondPartString.length()==4 &&
    areaCode <=999 &&
    firstPart <= 999 &&
    secondPart <=9999)
    {
            return true;
    }
        return false;
    }
    return false;
}

int main() {
string input;

    cout << "Enter a U.S phone number xxx - xxx - xxxx: ";
    getline(cin, input);

    if (isValidPhoneNumber(input)) {
        cout << "Valid." << endl;
    }
    else {
        cout << "Invalid." << endl;

    }
        return 0;

}