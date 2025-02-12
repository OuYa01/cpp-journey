#include "matrix.h"

bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], int size)
{
	int i,j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
