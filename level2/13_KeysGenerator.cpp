#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum enCharType {SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

int randomNumber(int from, int to)
{
    return (rand() % (to - from + 1) + from);
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case enCharType::SamallLetter:
        {
            return char(randomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(randomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(randomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(randomNumber(48, 57));
            break;
        }
    }
}


string GenerateWord(enCharType CharType, short Length)
{
    string Word;
    for (int i = 1; i <= Length; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}


string GenerateKey()
{
    string Key = "";
    Key = GenerateWord(enCharType::CapitalLetter,4) + "-";
    Key =Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key =Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key =Key + GenerateWord(enCharType::CapitalLetter, 4) ;
    return Key;
} 

void GenerateKeys(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "key[" << i+1 << "] : " << GenerateKey() << endl;
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    GenerateKeys(ReadPositiveNumber("give a postive number"));
}
