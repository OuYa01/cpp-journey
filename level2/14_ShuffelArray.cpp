#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

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

void FillArrayWith1toN(int* arr, int arrlength)
{
    int i;
    for (i = 0; i < arrlength; i++)
    {
        arr[i] = i + 1;
    }
}

void PrintArray(int* arr, int arrlength)
{
    for (int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << " " ; 
    }
}

int RandomNumbers(int from, int to)
{
    return (rand() % (to - from + 1) + from);
}

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