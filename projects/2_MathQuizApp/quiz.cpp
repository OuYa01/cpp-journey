#include "Quiz.h"


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
 * ExecuteQuiz - Runs the quiz by generating questions, collecting user answers, and tracking results.
 * 
 * @quiz: A reference to the stQuiz structure where quiz details and results are stored.
 */
void ExecuteQuiz(stQuiz &quiz) 
{
    quiz.difficulty = SelectDifficulty();
    quiz.operationType = SelectOperation();

    for (short i = 1; i <= quiz.totalQuestions; i++) 
    {
        stQuestion q = GenerateQuestion(quiz.totalQuestions, i, quiz.difficulty, quiz.operationType);
        q.isCorrect ? quiz.correctAnswers++ : quiz.wrongAnswers++;
        SetResultColor(q.isCorrect);
    }
    quiz.passed = quiz.correctAnswers >= quiz.wrongAnswers;
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


