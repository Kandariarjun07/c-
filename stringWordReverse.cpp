#include <iostream>
#include <vector>
using namespace std;

void reverse(string &str, int s, int e)
{
    while (s < e)
    {
        swap(str[s++], str[e--]);
    }
}

int main()
{
    string s;
    getline(cin, s);
    int len = s.length();
    int i = 0, j = 0;

    while (j < len)
    {
        if (s[j] == ' ' || j == len - 1)
        {
            int e = (j == len - 1) ? j : j - 1;
            reverse(s, i, e);
            i = j + 1;
        }
        j++;
    }

    cout << s;

    return 0;
}
