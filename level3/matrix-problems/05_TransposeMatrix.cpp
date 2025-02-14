#include "matrix.h"


void TransposeMatrix(int M[3][3], int TM[3][3], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			TM[i][j] = M[j][i];
		}
		cout << endl;
	}
}
