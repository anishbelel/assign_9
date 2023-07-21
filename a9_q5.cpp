#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(const vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, 1);

    int product = 1;
    for (int i = 0; i < n; ++i) {
        ans[i] *= product;
        product *= arr[i];
    }

    product = 1;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] *= product;
        product *= arr[i];
    }

    return ans;
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

    vector<int> ans = productExceptSelf(arr);

    cout << "Array ans: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
