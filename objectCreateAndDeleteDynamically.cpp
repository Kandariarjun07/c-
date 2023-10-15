#include <iostream>
using namespace std;
class student
{
    int rollno;
    string name;

public:
    student(int rn = 0, string n = "NILL")
    {
        rollno = rn;
        name = n;
    }
    void getInfo()
    {
        cout << rollno << "\t"
             << name << endl;
    }
};

int main()
{
    student *s1 = new student(18, "Arjun");
    student *s2 = new student(69, "wtf");
    s1->getInfo();
    s2->getInfo();
    delete s1;
    delete s2;
    return 0;
}
