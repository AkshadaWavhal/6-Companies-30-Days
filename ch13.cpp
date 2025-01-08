#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charCount;

        // Count the frequency of each character
        for (char c : s) {
            charCount[c]++;
        }

        // Find the index of the first non-repeating character
        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }

        // If no unique character is found, return -1
        return -1;
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    int result = solution.firstUniqChar(s);
    cout << "Output: " << result << endl; // Output: 0
    return 0;
}

