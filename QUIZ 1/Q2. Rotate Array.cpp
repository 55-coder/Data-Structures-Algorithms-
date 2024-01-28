#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    // Handle the case where k is greater than the array size
    k %= n;

    // Reverse the entire array
    reverse(nums.begin(), nums.end());

    // Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Reverse the remaining elements
    reverse(nums.begin() + k, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    cout << "Rotated Array: ";
    for (const auto& num : nums) {
        cout << num << " ";
    }

    return 0;
}
