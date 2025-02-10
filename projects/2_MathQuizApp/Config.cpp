#include "Quiz.h"

/**
 * GetQuestionCount - Prompts the user to input the number of questions for the quiz.
 * 
 * Return: The number of questions entered by the user (between 1 and 20).
 */
short GetQuestionCount()
{
    short count;

    cout << "Number of questions (1-20): ";
    cin >> count;
    while ((count < 1 || count > 20) && cin.fail())
    {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid! Enter 1-20: ";
        cin >> count;
    }

    return count;
}



/**
 * SelectDifficulty - Prompts the user to select the difficulty level for the quiz.
 * 
 * Return: The selected difficulty level.
 */
levels SelectDifficulty()
{
    short choice;

    cout << "Difficulty [1]Easy [2]Medium [3]Hard [4]Mix: ";
    cin >> choice;
    while (choice < 1 || choice > 4)
    {
        cout << "Invalid! Enter 1-4: ";
        cin >> choice;
    }

    return (levels)(choice);
}


/**
 * SelectOperation - Prompts the user to select the arithmetic operation type for the quiz.
 * 
 * Return: The selected operation type.
 */
operations SelectOperation()
{
    short choice;

    cout << "Operation [1]+ [2]- [3]* [4]/ [5]Mix: ";
    cin >> choice;
    while (choice < 1 || choice > 5)
    {
        cout << "Invalid! Enter 1-5: ";
        cin >> choice;
    }

    return (operations)(choice);
}