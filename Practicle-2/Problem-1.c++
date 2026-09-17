#include <iostream>
#include <string>
using namespace std;

int LinearSerch(string arr[], int sz, string target)
{
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int RecursiveSearch(string arr[], int sz, string target, int currentPos)
{
    if (currentPos > sz)
    {
        return -1; //if car is not found.if we don't stop it will run forever.
    }
    if (arr[currentPos] == target)
    {
        return currentPos; //if car is found return that position.
    }
    //calling helper to check remaining car.
    return RecursiveSearch(arr, sz, target, currentPos + 1);
}

int main()
{
    string arr[] = {"DL3C1234", "MH12AB99", "HR26XYZ1", "KA03BC55"};
    int sz = 7;
    string target = "MH12AB99";

    cout <<"Using Linear Search:  "<< LinearSerch(arr, sz, target) << endl;
    cout <<"Using Recursive Search  "<< RecursiveSearch(arr, sz, target, 0) << endl;
    return 0;
}
// in this parcticle we can not use binary serch bcoz car's are not in sorting.