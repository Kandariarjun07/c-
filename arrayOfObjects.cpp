#include <iostream>
using namespace std;
class Student
{
    string name;
    int rn;

public:
    void setData(string n, int r)
    {
        name = n;
        rn = r;
    }
    void display()
    {
        cout << "Name is " << name << " and Roll No is " << rn << endl;
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
        int rollno;
        cout << "Enter name of Student " << i + 1 << " : ";
        cin >> name;
        cout << "Enter roll no of Student " << i + 1 << " : ";
        cin >> rollno;
        s[i].setData(name, rollno);
    }
    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }
    return 0;
}