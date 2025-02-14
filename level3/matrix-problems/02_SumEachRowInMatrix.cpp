#include "matrix.h"




void PrintEachRowSumInMatrix(int M[3][3], int size)
{
	int i, j;
	int sum;


	cout << "\nthe following are the sum of each Row in the matrix:\n";
	for (i = 0; i < size; i++)
	{
		sum = 0;

		for (j = 0; j < size; j++)
		{
			sum += M[i][j];
		}
		cout << "Row " << i+1 << "sum = " << sum << endl;
	}
}
