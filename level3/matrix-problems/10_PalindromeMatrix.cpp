#include "matrix.h"



bool IsPalindromeArray(int A[], short size)
{
	short i = 0, j = size - 1;

	while (i < j)
	{
		if(A[i] != A[j])
			return (false);
		i++;
		j--;
	}
	return (true);
}

bool IsPalindromeMatrix(int M[3][3], short Rows, short Cols)
{
	short i;

	for (i = 0; i < Rows; i++)
	{
		if (!IsPalindromeArray(M[i], Cols))
			return (false);
	}
	return (true);
}
