#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


/**
 * ReadPositiveNumber - reads a positive number from the user
 * @Message: the message to display to the user
 *
 * Return: the number entred by user.
 */
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}


/**
 * FillArrayWith1toN - fills an array with numbers from 1 to N
 * @arr: the array to be filled
 * @arrLength: the length of the array
 */
void FillArrayWith1toN(int* arr, int arrlength)
{
    int i;
    for (i = 0; i < arrlength; i++)
    {
        arr[i] = i + 1;
    }
}


/**
 * PrintArray - prints the elements of an array
 * @arr: the array to be printed
 * @arrLength: the length of the array
 *
 */
void PrintArray(int* arr, int arrlength)
{
    for (int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << "\t" ; 
    }
}

/**
 * RandomNumbers - generates a random number within a specified range
 * @from: the lower bound of the range
 * @to: the upper bound of the range
 *
 * Return: a random integer within the specified range.
 */
int RandomNumbers(int from, int to)
{
    return (rand() % (to - from + 1) + from);
}


/**
 * ShuffelArray - shuffles the elements of an array
 * @arr: the array to be shuffled
 * @arrLength: the length of the array
 *
 * This function shuffles the elements of the array by swapping elements at random positions.
 */
void ShuffelArray(int* arr, int arrlength)
{
    int i, temp;
    int j, k;
    for (i = 0; i < arrlength; i++)
    {
        j = RandomNumbers(0, arrlength - 1);
        k = RandomNumbers(0, arrlength - 1);
        temp = arr[j];
        arr[j] = arr[k];
        arr[k] = temp;
    }
}


/**
 * main - entry point of the program
 *
 * Return: 0 If success.
 */
int main(void)
{
    srand((unsigned)time(NULL));
    int arr[50];
    int size = ReadPositiveNumber("give size of array");
    FillArrayWith1toN(arr, size);
    cout << "\n Array elements before shuffel: \n";
    PrintArray(arr, size);

    ShuffelArray(arr, size);
    cout << "\n Array elements After shuffel: \n";
    PrintArray(arr, size);
}