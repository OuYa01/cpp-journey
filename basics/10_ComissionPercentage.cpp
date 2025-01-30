#include <iostream>
using namespace std;

int ReadTotalSales()
{
    int totalSales;
    cout << "What is your total sales: ";
    cin >> totalSales;

    return (totalSales);
}

float GetComissionPercentage(float totalSales)
{
    if (totalSales >= 1000000)
        return (0.01);
    else if (totalSales >= 500000)
        return (0.02);
    else if (totalSales >= 100000)
        return (0.03);
    else if (totalSales >= 50000)
        return (0.03);
    else
        return (0.00);
}

float CalculeTotalComission(float totalSales)
{
    return (GetComissionPercentage(totalSales) * totalSales);
}

int main(void)
{
    cout << "Total commission: "<< CalculeTotalComission(ReadTotalSales());
}