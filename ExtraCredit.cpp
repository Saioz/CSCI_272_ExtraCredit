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


if (iss >> openParan >> areaCode) {
        closeParan = areaCode.back();
        areaCode   = areaCode.substr(0, areaCode.length() - 1);
//can't direectly use closeParan since the string disregards this. 
//had to use string because unfortunately, int has issues with leading zeros. And to_string doesn't like that, so it just copies it over. 
        if (iss >> firstPart) {
            separator  = firstPart[firstPart.find('-')];
            secondPart = firstPart.substr(firstPart.find('-') + 1);
            firstPart  = firstPart.substr(0, firstPart.find('-'));
    //(xxx) xxx-xxxx the later xxx-xxxx becomes merged all into firstPart for some reason? 
    //This should fix it hopefully
 

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
   
    }

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


/*

initial testing with int : leading zeros are gone

Enter a U.S phone number xxx - xxx - xxxx: (999) 1-1
openParan: (
areaCode: 999
closeParan: )
firstPart: 1
separator: -
secondPart: 1
Valid.


my solution was to change it to string,


IT WORKS!!!!!



TEST CASES ---------

(023) 056-0890
(123) 456-7890
(123) 456-7890
(123) 056-0890
(123) 456-7890
(023) 456-7890
(123) 456-7890
(123) 456-7890
(023) 456-7890
(123) 456-7890


WORKS!!
*/