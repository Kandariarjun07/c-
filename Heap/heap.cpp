#include <iostream>
#include <vector>

using namespace std;

class Heap
{
    vector<int> arr;

public:
    Heap() {}

    // T.C = O(logN)
    void insert(int val)
    {
        arr.push_back(val);
        int indx = arr.size() - 1;

        while (indx > 0)
        {
            int parent = (indx - 1) / 2;
            if (arr[indx] > arr[parent])
            {
                swap(arr[indx], arr[parent]);
                indx = parent;
            }
            else
            {
                break;
            }
        }
    }

    int remove()
    {
        if (arr.empty())
        {
            cout << "Heap is empty! Cannot remove." << endl;
            return -1;
        }

        int rootValue = arr[0];
        arr[0] = arr.back();
        arr.pop_back();

        int i = 0;
        while (true)
        {
            int leftIndx = 2 * i + 1;
            int rightIndx = 2 * i + 2;
            int largest = i;

            if (leftIndx < arr.size() && arr[leftIndx] > arr[largest])
            {
                largest = leftIndx;
            }

            if (rightIndx < arr.size() && arr[rightIndx] > arr[largest])
            {
                largest = rightIndx;
            }

            if (largest == i)
            {
                break;
            }

            swap(arr[i], arr[largest]);
            i = largest;
        }

        return rootValue;
    }

    void print()
    {
        for (int val : arr)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

void heapify(vector<int> &arr, int size, int i)
{
    int largest = i;

    while (true)
    {
        int leftIdx = 2 * i + 1;  // left child
        int rightIdx = 2 * i + 2; // right child

        if (leftIdx < size && arr[leftIdx] > arr[i])
        {
            largest = leftIdx;
        }

        if (rightIdx < size && arr[rightIdx] > arr[largest])
        {
            largest = rightIdx;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            i = largest;
        }
        else
        {
            return;
        }
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();
    // Build Heap (0-based indexing)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    Heap h;
    h.insert(20);
    h.insert(30);
    h.insert(60);
    h.insert(40);
    h.insert(55);
    h.insert(50);

    cout << "Initial Heap: ";
    h.print();

    h.remove();
    cout << "Heap after removal: ";
    h.print();

    vector<int> arr = {5, 3, 12, 54, 3, 42, 52, 423, 34, 23, 7};
    int n = arr.size();

    cout << "Array before Heap Sort: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
