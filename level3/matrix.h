#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void PrintMatrice(int M[3][3], short size);
void FillMatrixWithRandomNumbers(int M[3][3], short size);
int RandomNumber(int from, int to);
void PrintEachRowSumInMatrix(int M[3][3], int size);
void PrintEachColSumInMatrix(int M[3][3], int size);
void FillMatrixWithOrderdNumbers(int M[3][3], int size);
void TransposeMatrix(int M[3][3], int TM[3][3], int size);
bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], int size);
bool IsIdentityMatrix(int Matrix1[3][3], short Rows, short Cols);
bool IsScalarMatrix(int Matrix1[3][3], short Rows, short Cols);
int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols);
int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols);
bool IsPalindromeMatrix(int M[3][3], short Rows, short Cols);
bool IsPalindromeArray(int A[], short size);


#endif
