#include <iostream>
using namespace std;
class Student
{
    string name;
    int marks;

public:
    void setData(string n, int r)
    {
        name = n;
        marks = r;
    }
    void display()
    {
        cout << "Name : " << name << "  marks : " << marks << endl;
    }
    int getMarks()
    {
        return marks;
    }
};
int main()
{
    Student s[10];
    int n;
    cout << "enter limit : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int marks;
        cout << "Enter name of Student " << i + 1 << " : ";
        cin >> name;
        cout << "Enter marks of Student " << i + 1 << " : ";
        cin >> marks;
        s[i].setData(name, marks);
    }
    int Max = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i].getMarks() > s[Max].getMarks())
            Max = i;
    }
    s[Max].display();
    return 0;
}