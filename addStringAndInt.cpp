#include <iostream>
#include <string>
using namespace std;
class Student
{
    string str;

public:
    Student(string str)
    {
        this->str = str;
    }
    void display()
    {
        cout << str;
    }
    friend string operator+(Student &, int num);
};
string operator+(Student &s, int num)
{
    return s.str + to_string(num);
}
int main()
{
    Student s("Arjun");
    cout << s + 123;
    return 0;
}
