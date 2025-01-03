/* Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Example 2:

Input: nums = [1,10,2,9]
Output: 16 */

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Sort the array to find the median
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2]; // Median for odd-sized array or middle element for even-sized
        int moves = 0;

        // Calculate the total moves needed
        for (int num : nums) {
            moves += abs(num - median);
        }

        return moves;
    }
};

// Example usage
int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    int result1 = solution.minMoves2(nums1); // Output: 2

    // Test case 2
    vector<int> nums2 = {1, 10, 2, 9};
    int result2 = solution.minMoves2(nums2); // Output: 16

    return 0;
}

