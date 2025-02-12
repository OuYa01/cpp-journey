#include "matrix.h"


int main(void)
{
	srand((unsigned)time(NULL));
	int M[3][3];
	int TM[3][3];
	FillMatrixWithRandomNumbers(M, 3);
	PrintMatrice(M, 3);	
	PrintEachRowSumInMatrix(M, 3);
	PrintEachColSumInMatrix(M, 3);
	FillMatrixWithOrderdNumbers(M, 3);
	cout << endl;
	PrintMatrice(M, 3);
	cout << endl << "Transpose Matrice:" << endl;
	TransposeMatrix(M, TM, 3);
	PrintMatrice(TM, 3);

	cout << endl << ( AreTypicalMatrices(M, TM, 3) ? "Are Typical Matrices" : "Not Typical Matrices") << endl;
	int Matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	PrintMatrice(TM, 3);
	cout << endl;
	int Matrix2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	PrintMatrice(TM, 3);
	cout << endl;
	cout << endl << ( AreTypicalMatrices(Matrix1, Matrix2, 3) ? "Are Typical Matrices" : "Not Typical Matrices" ) << endl;

}
