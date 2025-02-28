#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftmax(n, 0);
    vector<int> rightmax(n, 0);
    vector<int> water(n, 0);

    leftmax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftmax[i] = max(leftmax[i - 1], height[i]);
    }

    rightmax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightmax[i] = max(rightmax[i + 1], height[i]);
    }


    int ans = 0;
    for (int i = 0; i < n; i++) {
        water[i] = min(leftmax[i], rightmax[i]) - height[i];
        if (water[i] > 0) {
            ans += water[i];
        }
    }

    return ans;
}

int main() {
    vector<int> height = {4, 2, 0, 6, 3, 2, 5};
    cout << "Trapped water: " << trap(height) << " units" << endl;
    return 0;
}
