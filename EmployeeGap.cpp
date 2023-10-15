#include <iostream>
#include <cmath>
using namespace std;
class Employee
{
    string name;
    int age;
    string empcode;

public:
    Employee(string n, int a, string ec)
    {
        name = n;
        age = a;
        empcode = ec;
    }
    int operator-(Employee e)
    {
        return abs(age - e.age);
    }
};
int main()
{
    Employee e1("Arjun", 20, "E101"), e2("Hemu", 19, "E102");
    cout << "Age gap is " << e2 - e1;
    return 0;
}