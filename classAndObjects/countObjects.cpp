#include <iostream>
using namespace std;
void sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void separateAndSort(int arr[], int size)
{
    int oddNumbers[size];
    int evenNumbers[size];
    int oddCount = 0;
    int evenCount = 0;

    // Separate odd and even numbers
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenNumbers[evenCount++] = arr[i];
        }
        else
        {
            oddNumbers[oddCount++] = arr[i];
        }
    }

    // Sort odd numbers
    sort(oddNumbers, oddCount);

    // Sort even numbers
    sort(evenNumbers, evenCount);

    // Combine the arrays
    int index = 0;
    for (int i = 0; i < oddCount; i++)
    {
        arr[index++] = oddNumbers[i];
    }
    for (int i = 0; i < evenCount; i++)
    {
        arr[index++] = evenNumbers[i];
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 1, 21, 2, 12, 12, 12, 121324, 234, 43, 2, 13, 13, 1231, 12, 34, 45, 9, 8, 90, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    separateAndSort(arr, size);

    cout << "Separated and Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
