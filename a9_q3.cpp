#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxLengthEqualZerosAndOnes(const vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> countMap; // Key: Difference between count(0) and count(1), Value: Index

    int maxLength = 0;
    int count0 = 0;
    int count1 = 0;

    countMap[0] = -1; // Initialize the countMap with the difference = 0 at index -1.

    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            count0++;
        } else {
            count1++;
        }

        int diff = count0 - count1;

        if (countMap.find(diff) != countMap.end()) {
            maxLength = max(maxLength, i - countMap[diff]);
        } else {
            countMap[diff] = i;
        }
    }

    return maxLength;
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

    cout << "Enter " << n << " integers (0's and 1's only): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int maxLength = maxLengthEqualZerosAndOnes(arr);
    cout << "Maximum length of sequence containing equal numbers of 0's and 1's: " << maxLength << endl;

    return 0;
}
