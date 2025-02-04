#include <iostream>
using namespace std;

enum operationType {Add = '+', Mul = '*', Sub = '-', Div = '/'};

float ReadNumber(string msg)
{
    float a;

    cout << msg;
    cin >> a;
    
    return (a);
}

operationType ReadOperationType()
{
    char OT = '+';
    cout << "pls enter an operation (+, -, *, /): ";
    cin >> OT;

    return ((operationType)OT);
}

float calculate(float number1, float number2, operationType OT)
{
    switch (OT)
    {
        case (Add):
            return (number1 + number2);
        case (Mul):
            return (number1 * number2);
        case (Sub):
            return (number1 - number2);
        case (Div):
            return (number1 / number2);      
    }
}

int main(void)
{
    int a = ReadNumber("Entre number1 : ");
    int b = ReadNumber("Entre number2 : ");
    operationType OT = ReadOperationType();

    cout << a<< char(OT)<< b<< "="<< calculate(a, b, OT); 
}