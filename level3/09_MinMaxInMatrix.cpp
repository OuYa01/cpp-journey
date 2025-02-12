#include "matrix.h"

int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int Max = Matrix1[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] > Max)
            {
                Max = Matrix1[i][j];
            }
        }
    }
    return Max;
}

int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int Min = Matrix1[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] < Min)
            {
                Min = Matrix1[i][j];
            }
        }
    }
    return Min;
}

