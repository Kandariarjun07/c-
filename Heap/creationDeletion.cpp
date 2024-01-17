#include <iostream>
using namespace std;
class Heap
{
    int arr[100];
    int size;

public:
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }
    // T.C = O(logN)
    void insert(int val)
    {
        arr[++size] = val;
        int indx = size;
        while (indx > 1)
        {
            int parent = indx / 2;
            if (arr[indx] > arr[parent])
            {
                swap(arr[indx], arr[parent]);
                indx = parent;
            }
            else
            {
                return;
            }
        }
    }
    int remove()
    {
        if (size == 0)
        {
            cout << "Heap is empty! Cannot remove." << endl;
            return -1;
        }

        int rootValue = arr[1];
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (true)
        {
            int leftIndx = 2 * i;
            int rightIndx = leftIndx + 1;
            int largest = i;

            if (leftIndx <= size && arr[leftIndx] > arr[largest])
            {
                largest = leftIndx;
            }

            if (rightIndx <= size && arr[rightIndx] > arr[largest])
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
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Heap h;
    h.insert(20);
    h.insert(30);
    h.insert(60);
    h.insert(40);
    h.insert(55);
    h.insert(50);
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
}