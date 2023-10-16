#include <iostream>
#include <vector>
using namespace std;

void replacePalindromeWords(string &str, int s, int e)
{
    int i = s, j = e;
    while (s < e)
    {
        if (str[s++] != str[e--])
        {
            return;
        }
    }
    while (i <= j)
    {
        str[i++] = '*';
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
            replacePalindromeWords(s, i, e);
            i = j + 1;
        }
        j++;
    }

    cout << s;
}
