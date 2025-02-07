#include <iostream>
#include <ctime>

using namespace std;




enum options {Stone = 1, Paper = 2, Scissor = 3};

enum Results {ComputerWin = 1, PlayerWin = 2, draw = 3};

struct player
{
    options Choice;
    short Wins;
    short Draw;
};

int RandomNumbers(int from, int to)
{
    return (rand() % (to - from + 1) + from);
} 

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

string Lines(short NumberOfLines)
{
    string lines;
    int i; 

    for (i = 0; i < NumberOfLines; i++)
    {
        lines += "-";
    }

    return (lines);
}

short HowManyRounds()
{
    short rounds;
    cout << "How many rounds You Want to play (1 To 10)?\n";
    cin >> rounds;

    return (rounds);
}

options PlayerChoice()
{
    short choice;
    cout << "Your choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
    cin >> choice;

    return ((options)choice);
}

options ComputerChoice()
{
    short choice = RandomNumbers(1, 3);

    return ((options)choice);
}

string PrintChoice(options choice)
{
    switch (choice)
    {
        case (options::Stone):
            return ("Stone");
            break;
        case (options::Paper):
            return ("Paper");
            break;
        case (options::Scissor):
            return ("Scissor");
            break; 
    }
}

Results RoundWinner(player &player1, player &Computer)
{
    Results R;
    if (player1.Choice == Computer.Choice)
    {
        player1.Draw += 1;
        Computer.Draw += 1;
        R = Results::draw;
    }
    else if (player1.Choice == options::Paper)
    {
        if (Computer.Choice == options::Stone)
        {
            player1.Wins += 1;
            R = Results::PlayerWin;
        }
        else
        {
            Computer.Wins += 1;
            R = Results::ComputerWin;
        }
        

    }
    else if (player1.Choice == options::Stone)
    {
        if (Computer.Choice == options::Scissor)
        {
            player1.Wins += 1;
            R = Results::PlayerWin;
        }
        else
        {
            Computer.Wins += 1;
            R = Results::ComputerWin;
        }
    }
    else
    {
        if (Computer.Choice == options::Paper)
        {
            player1.Wins += 1;
            R = Results::PlayerWin;
        }
        else
        {
            Computer.Wins += 1;
            R = Results::ComputerWin;
        }
    }

    return (R);

}

string PrintWinner(Results R)
{
    switch (R)
    {
        case (Results::PlayerWin):
            system("Color 2F");
            return ("[Player1 Win]");
            break;

        case (Results::ComputerWin):
            system("Color 4F");
            return ("[Computer Win\a]");

        case (Results::draw):
            system("Color 1F");
            return ("[No winner (Draw)]");
    }
}

void round(short NumberOFround, player &player1, player &computer)
{
    cout <<"round[" << NumberOFround << "] begins:\n\n\n";

    player1.Choice =  PlayerChoice();
    computer.Choice = ComputerChoice();

    cout << Tabs (5) << Lines(20) << "Round[" << NumberOFround << "]" << Lines(20) << endl;

    cout << Tabs(6) << "Player1 choice: " << PrintChoice(player1.Choice) << endl;
    cout << Tabs(6) << "Computer choice: " << PrintChoice(computer.Choice) << endl;
    cout << Tabs(6) << "Round winner: " << PrintWinner(RoundWinner(player1, computer)) << endl;

    cout << Tabs(5) << Lines(48)<< "\n\n\n";

}


void GameOver()
{
    cout << "\n\n\n";
    cout << Tabs(5) << Lines(50) << endl;
    cout << Tabs(7) << "+++ G a m e   O v e r +++" << endl;
    cout << Tabs(5) << Lines(50) ;
}


string FinalWinner(short PLayerWins, short ComputerWins)
{
    if (PLayerWins == ComputerWins)
        return ("Draw, No winner");
    else if (PLayerWins > ComputerWin)
        return ("Player1 Wins");
    else
        return ("Computer Wins");
}

void GameResults(short rounds, player player1, player computer)
{
    cout << "\n\n";
    cout << Tabs(5) << Lines(20) << "[ Game Results ]"<< Lines(20) << endl;
    cout << "\n\n";
    cout << Tabs(6) << "Game Rounds         : " << rounds << endl;
    cout << Tabs(6) << "Player1 Won Times   : " << player1.Wins << endl;
    cout << Tabs(6) << "Computer Won Times  : " << computer.Wins << endl;
    cout << Tabs(6) << "Draw Times          : " << player1.Draw << endl;
    cout << Tabs(6) << "Final Winner        : " << FinalWinner(player1.Wins, computer.Wins) << endl;
    cout << "\n\n";
    cout << Tabs(5) << Lines(60) << "\n\n\n";


}

void ResetGame()
{
    system("Color 0F");
}

void StartGame()
{

    short rounds = HowManyRounds();
    player player1;
    player computer;
    short i;

    player1.Wins = 0;
    player1.Draw = 0;
    computer.Wins = 0;
    computer.Draw = 0;

    
    for (i = 0; i < rounds; i++)
    {
        round(i+1, player1, computer);
    }

    GameOver();
    GameResults(rounds, player1, computer);

}


int main()
{
    srand((unsigned)time(NULL));
    char StartAgain;
    do 
    {
        ResetGame();
        StartGame();
        ResetGame();
        cout << "\nDo you want tp play Again? Y/N : ";
        cin >> StartAgain;
        cout << "\n\n";

    }while (StartAgain != 'N' && StartAgain != 'n');
    
}
