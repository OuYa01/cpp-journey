#include "matrix.h"


void FillMatrixWithOrderdNumbers(int M[3][3], int size)
{
	int i, j;
	short count = 1;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			M[i][j] = count++;
		}
	}
}
