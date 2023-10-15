#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int s, int e, int mid)
{
    vector<int> temp;
    int left_size = mid - s + 1;
    int right_size = e - mid;

    int idx1 = s, idx3 = mid + 1;

    while (idx1 <= mid && idx3 <= e)
    {
        if (arr[idx1] > arr[idx3])
        {
            temp.push_back(arr[idx3++]);
        }
        else
        {
            temp.push_back(arr[idx1++]);
        }
    }
    while (idx1 <= mid)
    {
        temp.push_back(arr[idx1++]);
    }
    while (idx3 <= e)
    {
        temp.push_back(arr[idx3++]);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[s + i] = temp[i];
    }
}
void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    // right part
    mergeSort(arr, mid + 1, e);
    // left part
    mergeSort(arr, s, mid);

    // Merge both
    merge(arr, s, e, mid);
}
int main()
{
    vector<int> arr = {1, 2, 23, 24, 2, 312, 123, 12, 312, 3, 3, 123, 12, 31, 3, 13, 12};
    int n = arr.size();
    int end = n - 1;
    mergeSort(arr, 0, end);
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }

    return 0;
}