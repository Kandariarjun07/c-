#include <iostream>

using namespace std;

class Student
{
    string name;

public:
    Student(string Name = "")
    {
        name = Name;
    }
    void display()
    {
        cout << name << endl;
    }
    friend Student operator+(Student &, Student &);
};
Student operator+(Student &m1, Student &m2)
{
    Student ans;
    ans.name = m1.name + m2.name;
    return ans;
}
int main()
{
    Student m1("Arjun");
    Student m2("kandari");
    // Student m3 = m1 + m2;
    // m3.display();
    string a = "Arjun";
    string b = "Kandari";
    cout << a + b;
}
