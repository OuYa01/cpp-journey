#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void PrintFibonacciSequenceLoop(int length)
{
	int FebNumber = 0;
	int x = 0, y = 1;
	int i;

	cout << "\nFibonacci Series of " << length << " :" << endl;
	cout <<x << " " << y;
	
	i = 0;
	while (i < length-1)
	{
		FebNumber  = x + y;
		x = y;
		y = FebNumber;
		cout << " " << FebNumber;
		i++;
	}
	cout << endl;
}

void PrintFibonacciSequenceR(int length, int x = 0, int y = 1)
{
	int FebNumber;

	if (length <= -1)
	{
		cout << endl;
		return;
	}

	cout << x << " ";
	FebNumber = x + y;
	PrintFibonacciSequenceR(length - 1, y, FebNumber);
}


int main()
{
	PrintFibonacciSequenceLoop(10);	
	PrintFibonacciSequenceR(10);	
}