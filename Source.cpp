#include <iostream>
#include <string>
#include <map>

void convertStrToBrackets(std::string& InputStr)
{
    std::map<char, int> ñharactersEncounteredList;

    for (unsigned int index = 0; index < InputStr.size(); index++) // check each characters
    {
        char foundCharacter;

        //In principle, there is no need for the task to save the case of characters,
        //since they will lose their logical meaning after the conversion of the string.
        //Therefore, as an alternative solution, hard write characters with lower or upper case into the map at once

        if (ñharactersEncounteredList.find(std::tolower(InputStr[index])) != ñharactersEncounteredList.end()) // if lowercase character is not found in map
        {
            foundCharacter = std::tolower(InputStr[index]);
        }
        else if (ñharactersEncounteredList.find(std::toupper(InputStr[index])) != ñharactersEncounteredList.end()) // if uppercase character is not found in map
        {
            foundCharacter = std::toupper(InputStr[index]);
        }
        else
        {
            ñharactersEncounteredList[InputStr[index]] = index; // add character info to map and check next character
            InputStr[index] = '(';
            continue;
        }

        if (InputStr[ñharactersEncounteredList.find(foundCharacter)->second] != ')') // check first ecnountered character with ")"
        {
            InputStr[ñharactersEncounteredList.find(foundCharacter)->second] = ')'; // set ")" if not
        }
        InputStr[index] = ')';
    }
}

int main() {
    std::string InputStr;

    std::cout << "Enter the string: ";
    std::getline(std::cin, InputStr);

    convertStrToBrackets(InputStr);

    std::cout << "Perform string: " << InputStr;
}