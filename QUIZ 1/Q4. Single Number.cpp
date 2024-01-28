#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;

    for (const auto& num : nums) {
        result ^= num;
    }

    return result;
}

int main() {
    vector<int> nums = {4, 2, 5, 2, 4};

    int single = singleNumber(nums);

    cout << "The single non-duplicate element is: " << single << endl;

    return 0;
}
