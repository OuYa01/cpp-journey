#include "matrix.h"




void PrintEachRowSumInMatrix(int M[3][3], int size)
{
	int i, j;
	int sum;

	for (j = 0; j < size; j++)
	{
		sum = 0;

		for (i = 0; i < size; i++)
		{
			sum += M[i][j];
		}
		cout << "Row " << j+1 << "sum = " << sum << endl;
	}
}
