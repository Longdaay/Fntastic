#include <iostream>
#include <string>
#include <map>

void convertStrToBrackets(std::string& InputStr)
{
    std::map<char, int> ñharactersEncounteredList; // map  [character : first encountered index]

    for (unsigned int index = 0; index < InputStr.size(); index++) // check each characters
    {
        if (ñharactersEncounteredList.find(std::tolower(InputStr[index])) != ñharactersEncounteredList.end()) // if lowercase character is not found in map
        {
            InputStr[ñharactersEncounteredList.find(std::tolower(InputStr[index]))->second] = ')'; // replace the first repeated character in the string with ")"
            InputStr[index] = ')';
        }
        else
        {
            ñharactersEncounteredList[std::tolower(InputStr[index])] = index; // add character info to map and check next character
            InputStr[index] = '(';
        }
    }
}

int main() {
    std::string InputStr;

    //setlocale(0, ""); // for russian characters

    std::cout << "Enter the string: ";
    std::getline(std::cin, InputStr);

    convertStrToBrackets(InputStr);

    std::cout << "Perform string: " << InputStr;

    return 0;
}