#include <iostream>
using namespace std;

int sumBetweenIndices(int arr[], int n, int L, int R) {
    int sum = 0;
    
    if (L < 0 || R >= n || L > R) {
        cout << "Invalid indices. Please enter valid indices within the range [0, " << n - 1 << "]." << endl;
        return 0;
    }

    for (int i = L; i <= R; ++i) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid size. Please enter a positive integer between 1 and 100." << endl;
        return 1;
    }

    int arr[100]; // Assuming the maximum size of the array is 100, you can change this accordingly.

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int L, R;
    cout << "Enter the indices (L and R) to find the sum between (both inclusive): ";
    cin >> L >> R;

    int sum = sumBetweenIndices(arr, n, L, R);
    cout << "Sum of elements between index " << L << " and index " << R << ": " << sum << endl;

    return 0;
}
