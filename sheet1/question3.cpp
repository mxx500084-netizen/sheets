#include <iostream>
using namespace std;

// ==========================================
//      QUESTION 3 HELPER FUNCTIONS
// ==========================================
void ReadArray(int arr[], int size)
{
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
}

void DisplayArrayInListedFormat(int arr[], int size)
{
    cout << "Array elements in listed format:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "Element at index " << i << ": " << arr[i] << endl;
    }
}

void ReverseArray(int arr[], int size)
{
    cout << "Reversed array: ";
    for (int i = size - 1; i >= 0; --i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void DetectDuplicates(int arr[], int size)
{
    cout << "Duplicate elements in the array: ";
    bool foundDuplicate = false;
    int duplicate = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[i] << " ";
                foundDuplicate = true;
                duplicate++;
                break;
            }
        }
    }
    if (!foundDuplicate)
    {
        cout << "No duplicates found.";
    }
    cout << "Number of duplicate elements: " << duplicate << endl;
    cout << endl;
}

void MakeArrayFromAnotherArrayByComulativeSum(int sourceArr[], int destArr[], int size)
{
    destArr[0] = sourceArr[0];
    for (int i = 1; i < size; ++i)
    {
        destArr[i] = destArr[i - 1] + sourceArr[i];
    }
}

int main()
{
    cout << "\n===============================================================================================================" << endl;
    cout << "                                                    Question 3                                                 " << endl;
    cout << "===============================================================================================================" << endl;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    ReadArray(arr, size);
    DisplayArrayInListedFormat(arr, size);

    ReverseArray(arr, size);
    DetectDuplicates(arr, size);

    int *cumulativeSumArr = new int[size];
    MakeArrayFromAnotherArrayByComulativeSum(arr, cumulativeSumArr, size);
    cout << "Cumulative sum array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << cumulativeSumArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] cumulativeSumArr;

    return 0;
}
