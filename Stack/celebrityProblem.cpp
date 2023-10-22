#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> stack;
        for (int i = 0; i < n; i++)
        {
            stack.push(i);
        }
        // at the end of while loop, possible candidate of celebrity is left
        while (stack.size() > 1)
        {
            int first = stack.top();
            stack.pop();
            int second = stack.top();
            stack.pop();

            if (M[first][second])
            {
                stack.push(second);
            }
            else
            {
                stack.push(first);
            }
        }
        if (stack.empty())
            return 0;
        // Its not sure if it is celebrity or not

        int candidate = stack.top();
        // for being celebrity, Celebrity row shold be zero
        for (int i = 0; i < n; i++)
        {
            if (M[candidate][i] != 0)
                return -1;
        }
        // for being celebrity, celebrity colum should be all one except diagonal one
        for (int i = 0; i < n; i++)
        {
            if (i != candidate && M[i][candidate] != 1)
                return -1;
        }
        return candidate;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cout << "enter rows : ";
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        cout << "Enter elements : ";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
