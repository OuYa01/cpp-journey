#include "matrix.h"


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
