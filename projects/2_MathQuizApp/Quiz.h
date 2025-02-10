#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <limits>
#include <ctime>

using namespace std;


/**
 * levels - Enum representing the difficulty levels of the quiz.
 * 
 * @easy: Basic level with simple arithmetic problems.
 * @medium: Intermediate level with moderately challenging problems.
 * @hard: Advanced level with complex arithmetic problems.
 * @mix: A combination of all difficulty levels.
 */
enum levels { easy = 1, medium = 2, hard = 3, mix = 4 };

/**
 * operations - Enum representing the types of arithmetic operations available in the quiz.
 * 
 * @Add: Addition operation.
 * @Sub: Subtraction operation.
 * @Mul: Multiplication operation.
 * @Div: Division operation.
 * @Mix: A combination of all operation types.
 */
enum operations { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };

/**
 * stQuestion - Structure containing all information about a single quiz question.
 * 
 * @questionNumber: The sequential number of the current question.
 * @difficulty: The difficulty level of the question.
 * @operationType: The arithmetic operation type for the question.
 * @operand1: The first operand in the arithmetic operation.
 * @operand2: The second operand in the arithmetic operation.
 * @userAnswer: Stores the user's input answer for the question.
 * @correctAnswer: Stores the correct answer to the question for comparison with user answer.
 * @isCorrect: A boolean flag indicating whether the user's answer is correct (true) or incorrect (false).
 */
struct stQuestion {
    short questionNumber;
    levels difficulty;
    operations operationType;
    short operand1;
    short operand2;
    short userAnswer;
    short correctAnswer;
    bool isCorrect;
};


/**
 * stQuiz - Structure containing all information about the quiz session.
 * 
 * @totalQuestions: The total number of questions in the quiz.
 * @difficulty: The selected difficulty level for the quiz.
 * @operationType: The selected arithmetic operation type for the quiz.
 * @correctAnswers: The count of questions answered correctly by the user.
 * @wrongAnswers: The count of questions answered incorrectly by the user.
 * @passed: A boolean flag indicating whether the user passed the quiz (true) or failed (false).
 */
struct stQuiz {
    short totalQuestions = 0;
    levels difficulty;
    operations operationType;
    short correctAnswers = 0;
    short wrongAnswers = 0;
    bool passed;
};


// Helpers functions
string CreateTabs(short count);
int GenerateRandom(int min, int max);
void ClearScreen();
void SetResultColor(bool isCorrect);

// Quiz configuration
short GetQuestionCount();
levels SelectDifficulty();
operations SelectOperation();

// Question logic
void CreateEasyQuestion(stQuestion &question);
void CreateMediumQuestion(stQuestion &question);
void CreateHardQuestion(stQuestion &question);
void CreateMixedQuestion(stQuestion &question);
short CalculateAnswer(short num1, short num2, operations op);
bool ValidateAnswer(short user, short correct);
short GetAnswerInput();

// Quiz
stQuestion GenerateQuestion(short total, short current, levels diff, operations op);
void ExecuteQuiz(stQuiz &quiz);
void ShowResults(stQuiz quiz);
string GetLevelName(levels level);
string GetOperationName(operations op);
void StartApplication();



#endif