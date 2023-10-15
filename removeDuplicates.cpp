#include <iostream>
using namespace std;
int main()
{
    string s = "www.google.com";
    string temp = "";
    int i = 0;
    while (s[i])
    {
        temp.push_back(s[i]);
        int j = i + 1;
        while (s[j] == s[i])
            j++;
        i = j;
    }
    cout << temp;
    return 0;
}