#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    // Check for an empty array
    if (nums.empty()) {
        return 0;
    }

    // Initialize a pointer to keep track of the unique elements
    int uniquePtr = 0;

    // Iterate through the array
    for (int i = 1; i < nums.size(); ++i) {
        // If the current element is different from the previous one, move the uniquePtr and update the element
        if (nums[i] != nums[uniquePtr]) {
            ++uniquePtr;
            nums[uniquePtr] = nums[i];
        }
    }

    // The length of the array with unique elements is uniquePtr + 1
    return uniquePtr + 1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int length = removeDuplicates(nums);

    cout << "New length: " << length << endl;
    cout << "Unique elements: ";
    for (int i = 0; i < length; ++i) {
        cout << nums[i] << " ";
    }

    return 0;
}
