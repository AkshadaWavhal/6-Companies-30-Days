/* Here’s the C++ implementation using a class to solve the problem of finding two disjoint
 palindromic subsequences of a string such that the product of their lengths is maximized*/
 
 #include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countIncremovableSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long totalSubarrays = 0;

        // Iterate through the array
        for (int i = 0; i < n; ) {
            int start = i;

            // Find the strictly increasing segment
            while (i + 1 < n && nums[i] < nums[i + 1]) {
                i++;
            }

            // Length of the strictly increasing segment
            int len = i - start + 1;

            // Count all subarrays in this segment
            totalSubarrays += (1LL * len * (len + 1)) / 2;

            i++; // Move to the next potential segment
        }

        return totalSubarrays;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> nums = {1, 2, 3, 4}; // Input array
    cout << "The total number of incremovable subarrays is: " 
         << solution.countIncremovableSubarrays(nums) << endl;

    return 0;
}

