#include <iostream>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int s = 0;
    int e = str.length() - 1;
    while (s < e)
    {
        swap(str[s++], str[e--]);
    }
    cout << str;
    return 0;
}