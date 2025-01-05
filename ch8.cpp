#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // Base case: zero odd numbers seen so far
        int oddCount = 0, result = 0;

        for (int num : nums) {
            // Increment oddCount if the current number is odd
            if (num % 2 != 0) {
                ++oddCount;
            }

            // Check if there exists a prefix with (oddCount - k) odd numbers
            if (prefixCount.find(oddCount - k) != prefixCount.end()) {
                result += prefixCount[oddCount - k];
            }

            // Update the prefixCount map with the current oddCount
            ++prefixCount[oddCount];
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 1, 2, 1, 1};
    int k1 = 3;
    cout << solution.numberOfSubarrays(nums1, k1) << endl; // Output: 2

    vector<int> nums2 = {2, 4, 6};
    int k2 = 1;
    cout << solution.numberOfSubarrays(nums2, k2) << endl; // Output: 0

    vector<int> nums3 = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k3 = 2;
    cout << solution.numberOfSubarrays(nums3, k3) << endl; // Output: 16

    return 0;
}

