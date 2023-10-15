#include <iostream>
using namespace std;
class Tax
{
    string name;
    string PAN;
    float income;
    float tax;

public:
    void inputInfo(string n, string p, float ic)
    {
        PAN = p;
        name = n;
        income = ic;
    }
    void taxCal()
    {
        if (income <= 250000)
        {
            tax = 0;
        }
        else if (income <= 300000)
        {
            tax = income * 0.1;
        }
        else if (income <= 400000)
        {
            tax = (income * 0.2) + 5000;
        }
        else
        {
            tax = (income * 0.3) + 25000;
        }
    }
    void displayInfo()
    {
        cout << "Name : " << name << endl;
        cout << "PAN : " << PAN << endl;
        cout << "Income : " << income << endl;
        cout << "Tax to pay : " << tax << endl;
    }
};
int main()
{
    Tax user1;
    user1.inputInfo("Arjun", "1234Abcd", 9100006700);
    user1.taxCal();
    user1.displayInfo();
    Tax user2;
    user2.inputInfo("Hemu", "dasj6dasd6a", 3676786210);
    user2.taxCal();
    user2.displayInfo();
    return 0;
}