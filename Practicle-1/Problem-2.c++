#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of borrow records: ";
    cin >> n;

    int arr[n];

    cout << "Enter book IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Books borrowed more than once:\n";

    for (int i = 0; i < n; i++) {
        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        bool printed = false;

        for (int k = 0; k < i; k++) {
            if (arr[k] == arr[i]) {
                printed = true;
                break;
            }
        }

        if (count > 1 && !printed) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}