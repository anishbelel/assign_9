#include <iostream>
#include <vector>
using namespace std;

int highestAltitude(const vector<int>& height) {
    int n = height.size();
    int highestAlt = 0;
    int currentAlt = 0;

    for (int i = 0; i < n; ++i) {
        currentAlt += height[i];
        highestAlt = max(highestAlt, currentAlt);
    }

    return highestAlt;
}

int main() {
    int n;
    cout << "Enter the number of altitude changes (n): ";
    cin >> n;

    if (n < 0 || n > 100) {
        cout << "Invalid number of altitude changes. Please enter a non-negative integer less than or equal to 100." << endl;
        return 1;
    }

    vector<int> height(n);

    cout << "Enter " << n << " altitude changes: ";
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    int highestAlt = highestAltitude(height);
    cout << "The highest altitude during the trek is: " << highestAlt << endl;

    return 0;
}

