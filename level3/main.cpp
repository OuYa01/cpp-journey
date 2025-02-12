#include "matrix.h"


int main(void)
{
	srand((unsigned)time(NULL));
	int M[3][3];
	FillMatrixWithRandomNumbers(M, 3);
	PrintMatrice(M, 3);
	PrintEachRowSumInMatrix(M, 3);
}
