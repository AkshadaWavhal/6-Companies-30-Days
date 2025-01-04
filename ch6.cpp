#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    Solution solution;

    // Example 1
    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> output1 = solution.findRepeatedDnaSequences(s1);
    cout << "Input: s = \"" << s1 << "\"" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < output1.size(); ++i) {
        cout << "\"" << output1[i] << "\"";
        if (i < output1.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    // Example 2
    string s2 = "AAAAAAAAAAAAA";
    vector<string> output2 = solution.findRepeatedDnaSequences(s2);
    cout << "Input: s = \"" << s2 << "\"" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < output2.size(); ++i) {
        cout << "\"" << output2[i] << "\"";
        if (i < output2.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}

