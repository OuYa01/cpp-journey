#include "matrix.h"


bool IsIdentityMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    if (Rows != Cols)
    {
        return false;
    }

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
	{
            if (i == j && Matrix1[i][j] != 1)
                return false;
            
            else if (i != j && Matrix1[i][j] != 0) 
                return false;
            
        }
    }
    return true;
}

