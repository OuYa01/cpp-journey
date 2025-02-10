#include "Quiz.h"

/**
 * GetAnswerInput - Prompts the user to input their answer to the current question.
 * 
 * Return: The user's answer.
 */
short GetAnswerInput()
{
    short answer;

    cin >> answer;
    return answer;
}

/**
 * CreateEasyQuestion - Generates an easy-level arithmetic question.
 * 
 * @q: A reference to the stQuestion structure where the question details will be stored.
 */
void CreateEasyQuestion(stQuestion &q)
{
    q.operand1 = GenerateRandom(1, 9);
    q.operand2 = GenerateRandom(1, 9);
    operations finalOp = q.operationType == Mix ? (operations)(GenerateRandom(1, 4)) : q.operationType;
    q.correctAnswer = CalculateAnswer(q.operand1, q.operand2, finalOp);
    q.userAnswer = GetAnswerInput();
    q.isCorrect = ValidateAnswer(q.userAnswer, q.correctAnswer);
}

/**
 * CreateMediumQuestion - Generates a medium-level arithmetic question.
 * 
 * @q: A reference to the stQuestion structure where the question details will be stored.
 */
void CreateMediumQuestion(stQuestion &q)
{
    q.operand1 = GenerateRandom(10, 99);
    q.operand2 = GenerateRandom(10, 99);
    operations finalOp = q.operationType == Mix ? (operations)(GenerateRandom(1, 4)) : q.operationType;
    q.correctAnswer = CalculateAnswer(q.operand1, q.operand2, finalOp);
    q.userAnswer = GetAnswerInput();
    q.isCorrect = ValidateAnswer(q.userAnswer, q.correctAnswer);
}

/**
 * CreateHardQuestion - Generates a hard-level arithmetic question.
 * 
 * @q: A reference to the stQuestion structure where the question details will be stored.
 */
void CreateHardQuestion(stQuestion &q)
{
    q.operand1 = GenerateRandom(100, 999);
    q.operand2 = GenerateRandom(100, 999);
    operations finalOp = q.operationType == Mix ? (operations)(GenerateRandom(1, 4)) : q.operationType;
    q.correctAnswer = CalculateAnswer(q.operand1, q.operand2, finalOp);
    q.userAnswer = GetAnswerInput();
    q.isCorrect = ValidateAnswer(q.userAnswer, q.correctAnswer);
}

/**
 * CreateMixedQuestion - Generates a question with a random difficulty level (easy, medium, or hard).
 * 
 * @q: A reference to the stQuestion structure where the question details will be stored.
 */
void CreateMixedQuestion(stQuestion &q)
{
    switch(GenerateRandom(1, 3))
    {
        case 1: CreateEasyQuestion(q); break;
        case 2: CreateMediumQuestion(q); break;
        case 3: CreateHardQuestion(q); break;
    }
}


/**
 * CalculateAnswer - Performs the arithmetic operation based on the provided operands and operation type.
 * 
 * @num1: The first operand in the arithmetic operation.
 * @num2: The second operand in the arithmetic operation.
 * @op: The operation type.
 * 
 * Return: The result of the arithmetic operation.
 */
short CalculateAnswer(short num1, short num2, operations op)
{
    switch(op) 
    {
        case Add:
            cout << num1 << "\n" << num2 << " +\n------\n";
            return (num1 + num2);
        case Sub:
            cout << num1 << "\n" << num2 << " -\n------\n";
            return (num1 - num2);
        case Mul:
            cout << num1 << "\n" << num2 << " x\n------\n";
            return (num1 * num2);
        case Div:
            cout << num1 << "\n" << num2 << " /\n------\n";
            return (num1 / num2);
        default: return (0);
    }
}

/**
 * ValidateAnswer - Compares the user answer with the correct answer.
 * 
 * @UserAwnser: The user input answer.
 * @correct: The correct answer to the question.
 * 
 * Return: the user's answer is correct (true) or incorrect (false).
 */
bool ValidateAnswer(short UserAwnser, short correct)
{
    if (UserAwnser == correct)
    {
        cout << "Correct Awnser (:!\n";
        return true;
    }
    cout << "Wrong Awnser ):!\nCorrect: " << correct << endl;

    return false;
}
