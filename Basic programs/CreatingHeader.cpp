#include <iostream>
#include "local.h"
using namespace std;
int main()
{
    int a, b;
    cout << "Enter two  numbers : ";
    cin >> a >> b;
    cout << "Addition is " << ns1::add(a, b) << endl;
    cout << "Subtraction is " << ns1::subtract(a, b) << endl;
    cout << "Multiplication is " << ns2::multiply(a, b) << endl;
    if (b)
        cout << "Division is " << ns2::divide(a, b) << endl;
    else
    {
        cout << "Zero cant divide a number!!";
    }
    return 0;
}