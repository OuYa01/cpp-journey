#include "str.h"


std::string raplaceAllPunctuationInStringV1(std::string str)
{
    int pos;

    for(pos = 0; pos < str.length(); pos++)
    {
        if (str[pos] == ',' ||
            str[pos] == ';' ||
            str[pos] == '?' ||
            str[pos] == '.' ||
            str[pos] == '!' ||
            str[pos] == '"' ||
            str[pos] == '(' ||
            str[pos] == ')' ||
            str[pos] == '[' ||
            str[pos] == ']' ||
            str[pos] == '{' ||
            str[pos] == '}' ||
            str[pos] == '-' ||
            str[pos] == '_'   ) {

                str.erase(pos, 1);
                pos--;
            }
    }

    return (str);
}

std::string raplaceAllPunctuationInStringV2(std::string str)
{
    int pos;

    for(pos = 0; pos < str.length(); pos++)
    {
        if (ispunct(str[pos])) {

                str.erase(pos, 1);
                pos--;
            }
    }

    return (str);
}


int main(void)
{
    cout << raplaceAllPunctuationInStringV2("hey, guys; hru[]{} hhh \" yes?! .. fff ;");
}