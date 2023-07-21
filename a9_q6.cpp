#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] * arr[i - 1];
    }

    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i + 1] * arr[i + 1];
    }

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
        ans[i] = prefix[i] * suffix[i];
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

    cout << "Output: ";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
