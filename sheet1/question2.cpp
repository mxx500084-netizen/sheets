#include <iostream>
using namespace std;

// ==========================================
//      QUESTION 2 HELPER FUNCTIONS
// ==========================================
void ReadArray(int arr[], int size)
{
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
}

void PrintArray(int arr[], int size)
{
    cout << "Array elements: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SearchElementAndMaybeReplace(int arr[], int size, int element)
{
    bool found = false;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == element)
        {
            cout << "Element " << element << " found at index: " << i << endl;
            found = true;
            cout << "Do you want to replace it? (1 for Yes, 0 for No): ";
            int choice1;
            cin >> choice1;
            if (choice1 == 1)
            {
                cout << "Enter new value: ";
                int newValue;
                cin >> newValue;
                arr[i] = newValue;
                cout << "Element replaced. New array: ";
                PrintArray(arr, size);
            }
            else
            {
                cout << "Element not replaced." << endl;
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Element " << element << " not found in the array." << endl;
    }
}

void SwapElements(int arr[], int size, int index1, int index2)
{
    if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size)
    {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
        cout << "Elements swapped. New array: ";
        PrintArray(arr, size);
    }
    else
    {
        cout << "Invalid indices for swapping." << endl;
    }
}

void SortArrayUsingSwap(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                SwapElements(arr, size, j, j + 1);
            }
        }
    }
}

int main()
{
    cout << "\n===============================================================================================================" << endl;
    cout << "                                                    Question 2                                                 " << endl;
    cout << "===============================================================================================================" << endl;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    ReadArray(arr, size);
    PrintArray(arr, size);

    int elementToSearch1;
    cout << "Enter an element to search in the array: ";
    cin >> elementToSearch1;
    SearchElementAndMaybeReplace(arr, size, elementToSearch1);

    int index1, index2;
    cout << "Enter two indices to swap elements: ";
    cin >> index1 >> index2;
    SwapElements(arr, size, index1, index2);

    SortArrayUsingSwap(arr, size);
    cout << "Sorted array: ";
    PrintArray(arr, size);
    delete[] arr;

    int *arr2 = new int[size];
    ReadArray(arr2, size);
    PrintArray(arr2, size);

    int elementToSearch2;
    cout << "Enter an element to search in the second array: ";
    cin >> elementToSearch2;
    SearchElementAndMaybeReplace(arr2, size, elementToSearch2);

    int index3, index4;
    cout << "Enter two indices to swap elements in the second array: ";
    cin >> index3 >> index4;
    SwapElements(arr2, size, index3, index4);

    SortArrayUsingSwap(arr2, size);
    cout << "Sorted second array: ";
    PrintArray(arr2, size);
    delete[] arr2;

    int *arr3 = new int[size];
    ReadArray(arr3, size);
    PrintArray(arr3, size);

    int elementToSearch3;
    cout << "Enter an element to search in the third array: ";
    cin >> elementToSearch3;
    SearchElementAndMaybeReplace(arr3, size, elementToSearch3);

    int index5, index6;
    cout << "Enter two indices to swap elements in the third array: ";
    cin >> index5 >> index6;
    SwapElements(arr3, size, index5, index6);

    SortArrayUsingSwap(arr3, size);
    cout << "Sorted third array: ";
    PrintArray(arr3, size);
    delete[] arr3;

    return 0;
}
