#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numSet;

    for (const auto& num : nums) {
        // If the number is already in the set, it's a duplicate
        if (numSet.find(num) != numSet.end()) {
            return true;
        }
        // Otherwise, add it to the set
        numSet.insert(num);
    }

    // No duplicates found
    return false;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 3, 4, 1};

    cout << "Array 1 contains duplicates: " << boolalpha << containsDuplicate(nums1) << endl;
    cout << "Array 2 contains duplicates: " << boolalpha << containsDuplicate(nums2) << endl;

    return 0;
}
