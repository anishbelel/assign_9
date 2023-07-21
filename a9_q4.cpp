#include <iostream>
#include <vector>
using namespace std;

int countOddSumSubarrays(const vector<int>& arr) {
    int n = arr.size();
    int oddCount = 0;
    int currentSum = 0;

    for (int i = 0; i < n; ++i) {
        currentSum += arr[i];

        if (currentSum % 2 != 0) {
            oddCount++;
        }

        // Check subarrays with odd sum ending at index i
        for (int j = i - 1; j >= 0; --j) {
            currentSum = currentSum - arr[j];

            if (currentSum % 2 != 0) {
                oddCount++;
            }
        }
    }

    return oddCount;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid size. Please enter a positive integer between 1 and 100." << endl;
        return 1;
    }

    vector<int> arr(n);

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int oddCount = countOddSumSubarrays(arr);
    cout << "Number of consecutive sequences (subarrays) with odd sum: " << oddCount << endl;

    return 0;
}
