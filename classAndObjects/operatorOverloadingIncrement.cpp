#include <iostream>

using namespace std;

class Student
{
    int val;
public:
    Student(int value = 0)
    {
        val = value;
    }
    void display()
    {
        cout << val << endl;
    }
    friend Student operator++(Student &);      // prefix
    friend Student operator++(Student &, int); // postfix
};
Student operator++(Student &m)
{
    Student ans;

    m.val = m.val + 1;
    ans.val = m.val;
    return ans;
}
Student operator++(Student &m, int)
{
    Student ans = m;
    m.val = m.val + 1;
    return ans;
}
int main()
{
    Student m1(5);
    m1.display();
    ++m1;
    m1.display();
    m1++;
    m1.display();
}
