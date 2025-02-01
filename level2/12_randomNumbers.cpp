#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * ReadNumber - this function just to read a number from user
 * 
 * Return : the number that get from user
 */
int ReadNumber()
{
    int number;

    cout << "Entre a number : ";
    cin >> number;

    return (number);
}

int RandomNumbers(int from, int to)
{
    return (rand() % (to - from + 1) + from);
}


int main(void)
{
    srand((unsigned)time(NULL));
    cout << RandomNumbers(70, 80);
}