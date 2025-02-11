#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int RandomNumber(int from, int to)
{
	return (rand() % (to - from + 1) + from);
}


void FillMatrixWithRandomNumbers(int M[3][3], short size)
{
	short i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			M[i][j] = RandomNumber(1, 100);
		}
	}
}


void PrintMatrice(int M[3][3], short size)
{
	short i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			cout << M[i][j] << "\t";
		}
		cout << endl;
	}
}

int main(void)
{
	srand((unsigned)time(NULL));
	int M[3][3];	

	FillMatrixWithRandomNumbers(M, 3);
	cout << "\nThe following is a 3x3 random matrix\n";
	PrintMatrice(M, 3);
}
