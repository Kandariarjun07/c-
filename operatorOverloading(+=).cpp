#include <iostream>

using namespace std;

class Student
{
    int val;

public:
    Student(int v = 0)
    {
        val = v;
    }
    void display()
    {
        cout << val << endl;
    }
    friend void operator+=(Student &s, int value);
};
void operator+=(Student &s, int value)
{
    s.val += value;
}
int main()
{
    Student s1(5);
    s1.display();
    s1 += 6;
    s1.display();
}
