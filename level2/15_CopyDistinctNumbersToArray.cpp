#include <iostream>

using namespace std;

void FillArray(int arr[100], int &arrLength)
{
    arrLength = 12;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
    arr[10] = 2;
    arr[11] = 2;
}


/**
 * PrintArray - prints the elements of an array
 * @arr: the array to be printed
 * @arrLength: the length of the array
 *
 */
void PrintArray(int arr[100], int arrLenght)
{
    int i;

    for (i = 0; i < arrLenght; i++)
    {
        cout << arr[i] << "\t";
    }
}


/**
 * FindNumberPositionInArray - finds the position of a number in an array
 * @number: the number to search for
 * @arr: the array to search in
 * @arrLength: the length of the array
 *
 * Return: the index of the number if found, otherwise -1.
 */
short FindNumberPositionInArray(int number, int arr[100], int arrLenght)
{
    int i;
    for (i = 0; i < arrLenght; i++)
    {
        if (arr[i] == number)
            return (i);
    }
    return (-1);
}


/**
 * IsNumberInArray - checks if a number is in an array
 * @number: the number to check
 * @arr: the array to search in
 * @arrLength: the length of the array
 *
 * Return: true if the number is found, otherwise false.
 */
bool IsNumberInArray(int number, int arr[100], int arrLength)
{

    if (FindNumberPositionInArray(number, arr, arrLength) != -1)
        return (true);
    return (false);
}


/**
 * AddArrayElement - adds an element to the end of an array
 * @number: the number to add
 * @arr: the array to add the number to
 * @arrLength: reference to the length of the array
 */
void AddArrayElement(int number, int arr[100], int &arrLength)
{
    arr[arrLength] = number;
    arrLength++;
}


/**
 * CopyDistinctNumbersToArray - copies distinct numbers from one array to another
 * @arrSource: the source array
 * @arrDestination: the destination array
 * @sourceLength: the length of the source array
 * @DestinationLength: reference to the length of the destination array
 *
 * This function copies unique elements from the source array to the destination array.
 */
void CopyDistinctNumbersToArray(int arrSource[100], int arrDestinantion[100], int sourceLenght, int &DestinantionLenght)
{
    int i;
    AddArrayElement(arrSource[0], arrDestinantion, DestinantionLenght);
    for (i = 1; i < sourceLenght; i++)
    {
        if (!IsNumberInArray(arrSource[i], arrDestinantion, DestinantionLenght))
            AddArrayElement(arrSource[i], arrDestinantion, DestinantionLenght);
    }
}

/**
 * main - entry point of the program
 *
 * Return: 0 If success.
 */
int main(void)
{
    int arrSouce[100], sourceLength = 0, arrDestinantion[100], DestinantionLenght = 0;
    FillArray(arrSouce, sourceLength);

    cout << "Arr1: Elements :\n";
    PrintArray(arrSouce, sourceLength);

    CopyDistinctNumbersToArray(arrSouce, arrDestinantion, sourceLength, DestinantionLenght);

    cout << "\nArr2: Elements :\n";
    PrintArray(arrDestinantion, DestinantionLenght);

    return (0);
}