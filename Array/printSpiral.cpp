#include <iostream>
#define rows 3
#define cols 4
using namespace std;

int main()
{
    int arr[rows][cols] = {{1, 2, 3, 4},
                           {12, 13, 14, 5},
                           {11, 16, 15, 6}};

    int top = 0, down = rows - 1, left = 0, right = cols - 1;
    int d = 0;
    while (top <= down && right >= left)
    {
        if (d == 0)
        {
            for (int i = left; i <= right; i++)
            {
                cout << arr[top][i] << " ";
            }
            top++;
        }
        else if (d == 1)
        {
            for (int i = top; i <= down; i++)
            {
                cout << arr[i][right] << " ";
            }
            right--;
        }
        else if (d == 2)
        {
            for (int i = right; i >= left; i--)
            {
                cout << arr[down][i] << " ";
            }
            down--;
        }
        else
        {
            for (int i = down; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
        }
        d = (d + 1) % 4;
    }
    return 0;
}