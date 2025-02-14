#include <iostream>
#include <limits>
#include <ctime>

using namespace std;




enum Gameoptions {Stone = 1, Paper = 2, Scissor = 3};

enum Results {PlayerWin = 1, ComputerWin = 2, draw = 3};


struct stRoundInfo
{
    short RoundNumber = 0;
    Gameoptions Player1Choice;
    Gameoptions ComputerChoice;
    Results Winner;
    string WinnerName = "";
};

struct stGameResults
{
    short GameRounds = 0;
    short player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    Results GameWinner;
    string WinnerName = "";
};


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
    system("cls"); // clear
    system("color 0F");
}

void setWinnerScreenColore(Results winner)
{
    switch (winner)
    {
        case Results::PlayerWin :
            system("color 2F"); //turn screen to Green
            break;
        case Results::ComputerWin :
            system("color 4F"); //turn screen to Red
            cout << "\a";
            break;
        default:
            system("color 6F"); //turn screen to Yellow
            break;
    }
}





short HowManyRounds()
{
    short rounds;

    cout << "How many rounds You Want to play (1 To 10)?\n";
    cin >> rounds;

    while ((rounds < 1 || rounds > 10) && cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "How many rounds You Want to play (1 To 10)?\n";
        cin >> rounds;
    }

    return (rounds);
}


Gameoptions ReadPlayerChoice()
{
    short choice;
    cout << "Your choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
    cin >> choice;
    while (choice < 1 || choice > 3)
    {
        cout << "Invalid Choice, Try Again";
        cout << "Your choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin >> choice;
    }
    
    return ((Gameoptions)choice);
}


Gameoptions GetComputerChoice()
{
    short choice = RandomNumbers(1, 3);

    return ((Gameoptions)choice);
}


Results WhoWinTheRound(stRoundInfo RoundInfo)
{
    Results result;
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
    {
        result = Results::draw;
    }
    else if (RoundInfo.Player1Choice == Gameoptions::Paper)
    {
        if (RoundInfo.ComputerChoice == Gameoptions::Stone)
        {
            result = Results::PlayerWin;
        }
        else
        {
            result = Results::ComputerWin;
        }
    }
    else if (RoundInfo.Player1Choice == Gameoptions::Stone)
    {
        if (RoundInfo.ComputerChoice == Gameoptions::Scissor)
        {
            result = Results::PlayerWin;
        }
        else
        {
            result = Results::ComputerWin;
        }
    }
    else
    {
        if (RoundInfo.ComputerChoice == Gameoptions::Paper)
        {
            result = Results::PlayerWin;
        }
        else
        {
            result = Results::ComputerWin;
        }
    }

    return (result);

}


string WinnerName(Results Winner)
{
    string arr[3] = {"Player1", "Computer", "No Winner (Draw)"};
    return (arr[Winner - 1]);
}

string PrintChoice(Gameoptions choice)
{
    string arr[3] = {"Stone", "Paper", "Scissor"};

    return (arr[choice - 1]);
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n______________Round[" << RoundInfo.RoundNumber << "]______________" << endl;

    cout << "Player1 choice: " << PrintChoice(RoundInfo.Player1Choice) << endl;
    cout << "Computer choice: " << PrintChoice(RoundInfo.ComputerChoice) << endl;
    cout << "Round winner: " << RoundInfo.WinnerName << endl;

    cout << "___________________________________\n" << endl;
    setWinnerScreenColore(RoundInfo.Winner);
}

Results WhoWonTheGame(short player1WinTimes, short ComputerWinTimes)
{
    if (ComputerWinTimes == player1WinTimes)
        return (Results::draw);
    else if (player1WinTimes > ComputerWinTimes)
        return (Results::PlayerWin);
    else
        return (Results::ComputerWin);

}

stGameResults FillResults(short Rounds, short player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults FinalResults;
    FinalResults.GameRounds = Rounds;
    FinalResults.player1WinTimes = player1WinTimes;
    FinalResults.ComputerWinTimes = ComputerWinTimes;
    FinalResults.DrawTimes = DrawTimes;
    FinalResults.GameWinner = WhoWonTheGame(player1WinTimes, ComputerWinTimes);
    FinalResults.WinnerName = WinnerName(FinalResults.GameWinner);

    return (FinalResults);
}



stGameResults PlayGame(short Rounds)
{
    stRoundInfo RoundInfo;
    short GameRound;
    short player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (GameRound = 1; GameRound <= Rounds; GameRound++)
    {
        cout <<"round[" << GameRound << "] begins:\n\n\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWinTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == Results::PlayerWin)
            player1WinTimes++;
        else if (RoundInfo.Winner == Results::ComputerWin)
            ComputerWinTimes++;
        else
            DrawTimes++;
        
        PrintRoundResults(RoundInfo);
    }

    return (FillResults(Rounds ,player1WinTimes, ComputerWinTimes, DrawTimes));

}


void GameOverScreen()
{
    cout << Tabs(2) << "__________________________________________________________\n\n";
    cout << Tabs(2) << "                +++ G a m e O v e r+++\n";
    cout << Tabs(2) <<"__________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
    cout << Tabs(2) << "_______________________________[Game Results]_______________________________\n\n";
    cout << Tabs(2) << "Game Rounds          : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player1 Won Times    : " << GameResults.player1WinTimes << endl;
    cout << Tabs(2) << "Computer Won Times   : " << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw Times           : " << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner         : " << GameResults.WinnerName << endl;
    cout << Tabs(2) << "_______________________________[Game Results]_______________________________\n\n";

    setWinnerScreenColore(GameResults.GameWinner);

}


void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(HowManyRounds());
        GameOverScreen();
        ShowFinalGameResults(GameResults);

        cout << endl << Tabs(3) << "Do you want to play Again? Y/N : ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
    
    system("color 0F");

}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}
