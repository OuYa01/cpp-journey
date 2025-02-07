#include <iostream>
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

// Utility functions
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

// Quiz flow
stQuestion GenerateQuestion(short total, short current, levels diff, operations op);
void ExecuteQuiz(stQuiz &quiz);
void ShowResults(stQuiz quiz);
string GetLevelName(levels level);
string GetOperationName(operations op);
void StartApplication();


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
    while (count < 1 || count > 20)
    {
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
 * GenerateQuestion - Generates a question based on the specified difficulty and operation type.
 * 
 * @total: The total number of questions in the quiz.
 * @current: The current question number being generated.
 * @diff: The difficulty level of the question.
 * @op: The operation type for the question.
 * 
 * Return: A stQuestion structure containing the generated question details.
 */
stQuestion GenerateQuestion(short total, short current, levels diff, operations op)
{
    stQuestion q;

    q.questionNumber = current;
    q.operationType = op;
    q.difficulty = diff;

    cout << "\nQuestion [" << current << "/" << total << "]\n";

    switch(diff)
    {
        case easy: CreateEasyQuestion(q); break;
        case medium: CreateMediumQuestion(q); break;
        case hard: CreateHardQuestion(q); break;
        default: CreateMixedQuestion(q); break;
    }

    return q;
}

/**
 * GetLevelName - Converts a difficulty level enum value to its corresponding string representation.
 * 
 * @lvl: The difficulty level.
 * 
 * Return: A string representing the difficulty level.
 */
string GetLevelName(levels lvl)
{
    string names[] = {"Easy", "Medium", "Hard", "Mix"};

    return names[lvl - 1];
}


/**
 * GetOperationName - Converts an operation type enum value to its corresponding string representation.
 * 
 * @op: The operation type.
 * 
 * Return: A string representing the operation type.
 */
string GetOperationName(operations op)
{
    string names[] = {"Addition", "Subtraction", "Multiplication", "Division", "Mix"};

    return names[op - 1];
}

/**
 * ShowResults - Displays the final results of the quiz to the user.
 * 
 * quiz: A stQuiz structure containing the quiz results to display.
 */
void ShowResults(stQuiz quiz)
{
    SetResultColor(quiz.passed);
    cout << CreateTabs(3) << "----------- Results -----------\n";
    cout << CreateTabs(3) << "Total Questions: " << quiz.totalQuestions << endl;
    cout << CreateTabs(3) << "Difficulty: " << GetLevelName(quiz.difficulty) << endl;
    cout << CreateTabs(3) << "Operation: " << GetOperationName(quiz.operationType) << endl;
    cout << CreateTabs(3) << "Correct: " << quiz.correctAnswers << endl;
    cout << CreateTabs(3) << "Wrong: " << quiz.wrongAnswers << endl;
    cout << CreateTabs(3) << "Result: " << (quiz.passed ? "Passed" : "Failed") << "\n\n";
}

/**
 * ExecuteQuiz - Runs the quiz by generating questions, collecting user answers, and tracking results.
 * 
 * @quiz: A reference to the stQuiz structure where quiz details and results are stored.
 */
void ExecuteQuiz(stQuiz &quiz) {
    quiz.difficulty = SelectDifficulty();
    quiz.operationType = SelectOperation();

    for (short i = 1; i <= quiz.totalQuestions; i++) {
        stQuestion q = GenerateQuestion(quiz.totalQuestions, i, quiz.difficulty, quiz.operationType);
        q.isCorrect ? quiz.correctAnswers++ : quiz.wrongAnswers++;
        SetResultColor(q.isCorrect);
    }
    quiz.passed = quiz.correctAnswers >= quiz.wrongAnswers;
}

/**
 * StartApplication - Manages the main application loop for the quiz.
 * 
 * - Clears the screen and initializes a new quiz session.
 * - Prompts the user for the number of questions and starts the quiz.
 * - Displays the results after the quiz is completed.
 * - Asks the user if they want to play again and repeats the process if they choose 'Y'.
 * - Exits the application if the user chooses 'N'.
 */
void StartApplication()
{
    char StartAgain;

    do {
        ClearScreen();
        stQuiz quiz;
        quiz.totalQuestions = GetQuestionCount();
        ExecuteQuiz(quiz);
        ShowResults(quiz);

        cout << "Play again? (Y/N): ";
        cin >> StartAgain;
    } while(StartAgain == 'Y' || StartAgain == 'y');
    ClearScreen();
}

/**
 * main - Entry point
 */
int main()
{
    srand((unsigned)(time(NULL)));
    StartApplication();

    return 0;
}