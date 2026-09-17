#include <iostream>
#include <vector>
using namespace std;

void BubbleShort(vector<int> &arr, int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void SelectionShort(vector<int> &arr, int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        int smallestIDX = i;
        for (int j = i + 1; j < sz; j++)
        {
            if (arr[j] < arr[smallestIDX])
            {
                smallestIDX = j;
            }
            swap(arr[i], arr[smallestIDX]);
        }
    }
}
void Insertionshort(vector<int> &arr, int sz)
{
    for (int i = 1; i < sz; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
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

    cout << "Enter  " << sz << " element: " << endl;
    for (int i = 0; i < sz; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    cout << "Using Bubbleshort:  " << endl;
    BubbleShort(arr, sz);
    PrintArray(arr, sz);
    cout << "Using Selectionshort: " << endl;
    SelectionShort(arr, sz);
    PrintArray(arr, sz);
    cout << "Using Insertionshort: " << endl;
    Insertionshort(arr, sz);
    PrintArray(arr, sz);
}
