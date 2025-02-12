#include "matrix.h"




void PrintEachColSumInMatrix(int M[3][3], int size)
{
	int i, j;
	int sum;
	
	cout << "\nthe following are the sum of each col in the matrix:\n";
	for (j = 0; j < size; j++)
	{
		sum = 0;

		for (i = 0; i < size; i++)
		{
			sum += M[i][j];
		}
		cout << "Col " << j+1 << "sum = " << sum << endl;
	}
}
