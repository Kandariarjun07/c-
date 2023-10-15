#include <iostream>
using namespace std;
class Bank
{
    string user;
    string accno;
    float balance;
    static int count;

public:
    Bank(string n, string an, float b)
    {
        count++;
        user = n;
        accno = an;
        balance = b;
    }
    void desposit(float amt)
    {
        balance += amt;
        cout << "Deposited Successfully !!" << endl;
    }
    void withdraw(float amt)
    {
        if (amt > balance)
        {
            cout << "Balance low" << endl;
        }
        else
        {
            balance -= amt;
            cout << "Withdrawn Successfully !!" << endl;
        }
    }
    static int getCount()
    {
        return count;
    }
};
int Bank::count = 0;
int main()
{
    Bank user[2] = {{"Arjun", "123344242131", 0},
                    {"Luffy", "342421231321", 0}};

    while (1)
    {
        int i = 0;
        cout << "Press 1 for user1 and 2 for user 2 :";
        cin >> i;
        if (i != 1 && i != 2)
        {
            cout << "Invalid option!!";
            break;
        }
        char a;
        cout << "press w/W to withdraw and d/D to Deposit else to quit: ";
        cin >> a;
        int amt = 0;
        if (tolower(a) == 'w')
        {
            cout << "enter amnt to withdraw :";
            cin >> amt;
            user[--i].withdraw(amt);
        }
        else if (tolower(a) == 'd')
        {
            cout << "enter amnt to desposit :";
            cin >> amt;
            user[--i].desposit(amt);
        }
        else
            break;
    }

    cout << "Thanks for using XYZ Bank\nAccounts created are : " << Bank::getCount();
    return 0;
}