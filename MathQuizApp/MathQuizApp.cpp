#include <iostream>
#include <ctime>

using namespace std;

enum levels {easy = 1, meduim = 2, hard = 3, mix = 4};

enum operations {Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5};

enum Results {Pass = 1, Fail = 2};


struct stQstInfo
{
    short numberOfQst;
    levels QstLvl;
	operations OpType;
    short operand1;
    short operand2;
    short UserAwnser;
    short CorrectAwnser;
    bool pass;
};

struct stQuizAppInfo
{
	short numberOfQsts = 0;
	levels QstLvl;
	operations OpType;
	short CorrectAwnsers = 0;
	short WrongAwnsers = 0;
	bool pass;
};

string Tabs(short NumberOfTabs);
int RandomNumbers(int from, int to);
void ResetScreen();
short NumberOfQuestions();
levels QuizLevel();
operations OperationType();
void PlayQuiz(stQuizAppInfo &QuizAppInfo);
short MadeQuestion(short operand1, short operand2, operations OpType);
bool ItsACorrectAwnser(short UserAwnser, short CorrectAwnser);
void EasyQuestion(stQstInfo &QstInfo);
void MeduimQuestion(stQstInfo &QstInfo);
void HardQuestion(stQstInfo &QstInfo);
void MixQuestion(stQstInfo &QstInfo);
short GetUserAwnser();
stQstInfo QuestionsGenerator(short NumberOfQst, levels QuestionsLevel, operations OpType);
void StartQuiz();
void printfFinalResults(stQuizAppInfo QuizzAppInfo);
string PrintQstlvl(levels Qstlvl);
string PrintOperationType(operations OpType);



string Tabs(short NumberOfTabs)
{
    string tabs;
    int i; 

    for (i = 0; i < NumberOfTabs; i++)
    {
        tabs += "\t";
    }

    return (tabs);
}

int RandomNumbers(int from, int to)
{
    return (rand() % (to - from + 1) + from);
} 

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

short NumberOfQuestions()
{
    short NumberOfqsts;
    cout << "How many questions you want to awnser (1 - 20)?\n";
    cin >> NumberOfqsts;

    while (NumberOfqsts < 1 || NumberOfqsts > 20)
    {
        cout << "Oops! You entered a number out of the range. Please try again.\n";
        cout << "How many questions you want to awnser (1 - 20)?\n";
        cin >> NumberOfqsts;
    }

    return (NumberOfqsts);
}

levels QuizLevel()
{
    short QstLvl;
    cout << "Enter questions level : [1] easy, [2] medium, [3] hard, [4] Mix? ";
    cin >> QstLvl;

    while (QstLvl < 1 || QstLvl > 4)
    {
        cout << "Oops! You entered a number out of the range. Please try again.\n";
        cout << "Enter questions level : [1] easy, [2] medium, [3] hard, [4] Mix? ";
        cin >> QstLvl;
    }
    return ((levels)QstLvl);
}

operations OperationType()
{
    short OpLvl;
    cout << "Enter operation type : [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? ";
    cin >> OpLvl;

    while (OpLvl < 1 || OpLvl > 4)
    {
        cout << "Oops! You entered a number out of the range. Please try again.\n";
        cout << "Enter operation type : [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? ";
        cin >> OpLvl;
    }

    return ((operations)OpLvl);
}


void PlayQuiz(stQuizAppInfo &QuizAppInfo)
{
    short NumberOfQst;
    stQstInfo QstInfo;
    QuizAppInfo.QstLvl = QuizLevel();
    QuizAppInfo.OpType = OperationType();
    for (NumberOfQst = 1; NumberOfQst <= QuizAppInfo.numberOfQsts; NumberOfQst++)
    {
        QstInfo = QuestionsGenerator(NumberOfQst, QuizAppInfo.QstLvl ,QuizAppInfo.OpType);
        if (QstInfo.pass == true)  QuizAppInfo.CorrectAwnsers += 1;
        else QuizAppInfo.WrongAwnsers += 1;

    }
    if (QuizAppInfo.CorrectAwnsers >= QuizAppInfo.WrongAwnsers)
        QuizAppInfo.pass = true;
    else
        QuizAppInfo.pass = false;
}


short MadeQuestion(short operand1, short operand2, operations OpType)
{
    int Awnser;
    switch (OpType)
    {
        case operations::Add :
            cout << operand1 << endl << operand2 << " +" << endl << "________" << endl;
            return (operand1 + operand2);
            break;
        case operations::Sub :
            cout << operand1 << endl << operand2 << " -" << endl << "________" << endl;
            return (operand1 - operand2);
            break;
        case operations::Mul :
            cout << operand1 << endl << operand2 << " x" << endl << "________" << endl;
            return (operand1 * operand2);
            break;
        case operations::Div :
            cout << operand1 << endl << operand2 << " /" << endl << "________" << endl;
            return (operand1 / operand2);
            break;
    }
}

bool ItsACorrectAwnser(short UserAwnser, short CorrectAwnser)
{
    if (UserAwnser == CorrectAwnser)
    {
        cout << "\nRight Awnser :)\n";
        return (true);
    }
    else
        cout << "\nWrong Awnser :(" << endl << "The Right Awnser is: " << CorrectAwnser << endl;
        return (false);
}

void EasyQuestion(stQstInfo &QstInfo)
{
    QstInfo.operand1 = RandomNumbers(1, 9);
    QstInfo.operand2 = RandomNumbers(1, 9);
    
    if (QstInfo.OpType != operations::Mix)
    {
        QstInfo.CorrectAwnser = MadeQuestion(QstInfo.operand1, QstInfo.operand2, QstInfo.OpType);
        QstInfo.UserAwnser = GetUserAwnser();
        QstInfo.pass = ItsACorrectAwnser(QstInfo.UserAwnser, QstInfo.CorrectAwnser);
    }
    // else
    // {

    // }
}

void MeduimQuestion(stQstInfo &QstInfo)
{
    
}

void HardQuestion(stQstInfo &QstInfo)
{
    
}

void MixQuestion(stQstInfo &QstInfo)
{
    
}

short GetUserAwnser()
{
    int Awnser;
    cin >> Awnser;

    return (Awnser);
}


stQstInfo QuestionsGenerator(short NumberOfQst , levels QuestionsLevel, operations OpType)
{
    stQstInfo QstInfo;
    QstInfo.numberOfQst = NumberOfQst;
    QstInfo.OpType = OpType;
    QstInfo.QstLvl = QuestionsLevel;

    cout << "Qst" << NumberOfQst << endl;
    switch (QuestionsLevel)
    {
        case levels::easy :
            EasyQuestion(QstInfo);
            break;
        case levels::meduim :
            MeduimQuestion(QstInfo);
            break;
        case levels::hard :
            HardQuestion(QstInfo);
            break;
        default:
            MixQuestion(QstInfo);
            break;
    }

    return QstInfo;
}

void StartQuiz()
{
    char StartAgain = 'Y';
    do
    {
        ResetScreen();
        stQuizAppInfo QuizAppInfo;
        QuizAppInfo.numberOfQsts = NumberOfQuestions();
        PlayQuiz(QuizAppInfo);
        printfFinalResults(QuizAppInfo);

        cout << "Do you want To play Again? (Y/N) ";
        cin >> StartAgain;

    } while (StartAgain != 'Y' || StartAgain != 'y');

}

void printfFinalResults(stQuizAppInfo QuizzAppInfo)
{
    cout << "\n\n"<< Tabs(3)<<"_________________________Final Results_________________________\n";
    if (QuizzAppInfo.pass == true)
        cout << Tabs(3) << "You Pass\n";
    else
        cout << Tabs(3) << "You didn't pass\n";
    cout << Tabs(3) <<"Number of Qsts is: " << QuizzAppInfo.numberOfQsts << endl;
    cout << Tabs(3) <<"Qst lvl is: " << PrintQstlvl(QuizzAppInfo.QstLvl) << endl;
    cout << Tabs(3) <<"operation type is: " << PrintOperationType(QuizzAppInfo.OpType) << endl;
    cout << Tabs(3) <<"Number of right awnsers: " << QuizzAppInfo.CorrectAwnsers << endl;
    cout << Tabs(3) <<"Number of wrong awnsers: " << QuizzAppInfo.WrongAwnsers << endl;
    cout << "\n\n";
}

string PrintQstlvl(levels Qstlvl)
{
    string arr[4] {"Easy", "medium", "Hard", "Mix"};

    return (arr[Qstlvl - 1]);
}

string PrintOperationType(operations OpType)
{
    string arr[4] {"Add", "Sub", "Mul", "Div"};

    return (arr[OpType - 1]);
}

int main(void)
{
    srand((unsigned)time(NULL));
    StartQuiz();
}