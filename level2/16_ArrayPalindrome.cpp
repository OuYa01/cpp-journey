#include <iostream>

using namespace std;

void FillArray(int arr[100], int arrLength)
{
    int i;

    i = 0;
    do
    {
        cout << "Arr[" << i+1 << "] : ";
        cin >> arr[i];
        i++;

    } while(i!=arrLength);
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
    cout << endl;
}

bool IsPalindromeArray(int arr[100], int arrLenght) 
{
    if (arrLenght % 2 == 0)
    {
        int i = 0;
        int j = arrLenght - 1;

        while (i < j)
        {
            if (arr[i] != arr[j])
                return (false);
            i++;
            j--;
        }
        return (true);
    }

    return (false);
}

int main(void)
{
    int arr[100], arrLenght = 7;

    FillArray(arr, arrLenght);
    PrintArray(arr, arrLenght);

    if (IsPalindromeArray(arr, arrLenght))
        cout << "Is Palindrome Array\n";
    else
        cout << "Not a Palindrome Array\n";
}