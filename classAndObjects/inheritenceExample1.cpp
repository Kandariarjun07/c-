#include <iostream>
using namespace std;
class person
{
private:
    int id;
    string name;

public:
    void setValue(int i, string n)
    {
        id = i;
        name = n;
    }
    void getValue()
    {
        cout << "Name : " << name << endl
             << "ID : " << id << endl;
    }
};
class student : public person
{
private:
    string course;
    double fee;

public:
    void setV(int i, string n, string c, double f)
    {
        setValue(i, n);
        course = c;
        fee = f;
    }
    void display()
    {
        getValue();
        cout << "Course : " << course << endl
             << "Fees : " << fee << endl;
    }
};
int main()
{
    student s1;
    s1.setV(18, "Arjun Singh Kandari", "Btech CSE", 200000.0);
    s1.display();
    return 0;
}