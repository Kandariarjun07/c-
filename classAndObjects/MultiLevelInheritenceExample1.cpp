#include <iostream>
using namespace std;
class fruits
{
    int f;

public:
    fruits(int t)
    {
        f = t;
        cout << "Total fruits are : " << t << endl;
    }
};
class apple : public fruits
{
    int a;

public:
    apple(int m, int a) : fruits(m + a)
    {
        this->a = a;
        cout << "Total apple are : " << a << endl;
    }
};
class mango : public apple
{
    int m;

public:
    mango(int m, int a) : apple(m, a)
    {
        this->m = m;
        cout << "Total mangoes are : " << m << endl;
    }
};
int main()
{
    int m, a;
    cout << "Enter number of mangoes :";
    cin >> m;
    cout << "Enter number of apples :";
    cin >> a;
    mango m1(m, a);
    return 0;
}