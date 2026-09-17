#include <iostream>
#include <vector>
using namespace std;

int BinarySerch(vector<int> arr, int target)
{
    int st = 0, end = arr.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (target > arr[mid])
        {
            st = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int RecursiveBinarySerch(vector<int> arr, int target, int st, int end)
{
    if (st > end)
    {
        return -1;
    }
    int mid = st + (end - st) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    if (target > arr[mid])
    {
        return RecursiveBinarySerch(arr, target, mid + 1, end);
    }
    else
    {
        return RecursiveBinarySerch(arr, target, st, mid - 1);
    }
}
int main()
{
    vector<int> arr = {101, 102, 103, 104, 105, 106, 107};
    int target = 106;

    cout <<"Using Binary Search:  "<< BinarySerch(arr, target) << endl;
    cout <<"Using Recursive Search  "<< RecursiveBinarySerch(arr, target, 0, arr.size() - 1) << endl;
    return 0;
}
