#include <iostream>
#include <vector>
using namespace std;

void SortColors(vector<int> &arr, int sz)
{
    int low = 0;
    int mid = 0;
    int high = sz - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void PrintArray(vector<int> &arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

int main()
{
    int sz;

    cout << "Enter the size of an array: ";
    cin >> sz;

    vector<int> arr(sz);

    cout << "Enter " << sz << " elements: " << endl;

    for (int i = 0; i < sz; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    cout << "Array after sorting 0, 1 and 2: " << endl;

    SortColors(arr, sz);

    PrintArray(arr, sz);

    return 0;
}