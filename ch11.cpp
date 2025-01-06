#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the median using nth_element
        auto midPtr = nums.begin() + n / 2;
        nth_element(nums.begin(), midPtr, nums.end());
        int median = *midPtr;

        // Step 2: Virtual Index Mapping
        auto index = [&](int i) {
            return (2 * i + 1) % (n | 1);
        };

        // Step 3: Three-way Partition
        int left = 0, right = n - 1, i = 0;
        while (i <= right) {
            if (nums[index(i)] > median) {
                swap(nums[index(i)], nums[index(left)]);
                left++;
                i++;
            } else if (nums[index(i)] < median) {
                swap(nums[index(i)], nums[index(right)]);
                right--;
            } else {
                i++;
            }
        }
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> nums1 = {1, 5, 1, 1, 6, 4};
    solution.wiggleSort(nums1);
    cout << "Output for nums1: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {1, 3, 2, 2, 3, 1};
    solution.wiggleSort(nums2);
    cout << "Output for nums2: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

