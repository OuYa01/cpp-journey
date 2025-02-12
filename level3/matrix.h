#ifndef MATRIX_H
#define MTARIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void PrintMatrice(int M[3][3], short size);
void FillMatrixWithRandomNumbers(int M[3][3], short size);
int RandomNumber(int from, int to);
void PrintEachRowSumInMatrix(int M[3][3], int size);

#endif
