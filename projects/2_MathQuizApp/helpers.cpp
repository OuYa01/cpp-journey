#include "Quiz.h"

/**
 * CreateTabs - Generates a string containing a specified number of tabs.
 * 
 * @count: The number of tab characters to generate.
 * 
 * Return: A string of tabs.
 */
string CreateTabs(short count)
{
    string tabs;

    for (short i = 0; i < count; i++) 
        tabs += "\t";

    return tabs;
}


/**
 * GenerateRandom - Generates a random integer within a specified range.
 * 
 * @min: The minimum value of the range.
 * @max: The maximum value of the range.
 * 
 * Return: A random integer between min and max.
 */
int GenerateRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}


/**
 * ClearScreen - Clears the console screen and resets the text color to default.
 */
void ClearScreen()
{
    system("cls");
    system("color 0F");
}

/**
 * SetResultColor - Changes the console screen color based on the correctness of the answer.
 * 
 * @isCorrect: A boolean flag indicating whether the answer is correct.
 * - If true, the screen turns green.
 * - If false, the screen turns red and a beep sound is played.
 */
void SetResultColor(bool isCorrect)
{
    isCorrect ? system("color 2F") : system("color 4F");
    if (!isCorrect) cout << "\a";
}