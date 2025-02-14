#include "matrix.h"

bool IsScalarMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int FirstDiagElemement = Matrix1[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j)
            {
                if (Matrix1[i][j] != FirstDiagElemement)
                {
                    return false;
                }
            }
            else if (i != j)
            {
                if (Matrix1[i][j] != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
