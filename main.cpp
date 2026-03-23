#include <iostream>
#include <sstream>

using namespace std;

bool isValidPhoneNumber(const string& input) {
istringstream iss(input);

char openParan, closeParan, separator;

string areaCode, firstPart, secondPart;
    if (iss >> openParan >> areaCode >> closeParan >> firstPart >> separator >> secondPart) { 
        if (areaCode.length() == 3 && firstPart.length()==3 && secondPart.length()==4) {
            return true;
    }
    return false; 
}
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


