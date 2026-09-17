#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of items: ";
    cin >> n;

    int arr[n];

    cout << "Enter items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter number of hours: ";
    cin >> h;

    h = h % n; /*if we don't write this so this will run more operations but
                   bcoz of this formula it will run only remainders time*/

    for (int i = 0; i < h; i++)
    {
        int first = arr[0];

        for (int j = 0; j < n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }

        arr[n - 1] = first;
    }

    cout << "Final display order: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}