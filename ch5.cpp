#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> rects;
    vector<int> prefixSums;
    int totalPoints;

public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        totalPoints = 0;
        prefixSums.reserve(rects.size());

        // Calculate the total number of integer points in each rectangle
        for (const auto& rect : rects) {
            int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
            int points = (x - a + 1) * (y - b + 1);
            totalPoints += points;
            prefixSums.push_back(totalPoints);
        }

        srand(time(0)); // Seed the random number generator
    }

    vector<int> pick() {
        // Generate a random number in the range [1, totalPoints]
        int randPoint = rand() % totalPoints;

        // Find the rectangle corresponding to the random point using binary search
        int rectIndex = lower_bound(prefixSums.begin(), prefixSums.end(), randPoint + 1) - prefixSums.begin();

        // Pick a random point within the selected rectangle
        const auto& rect = rects[rectIndex];
        int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
        int randX = a + rand() % (x - a + 1);
        int randY = b + rand() % (y - b + 1);

        return {randX, randY};
    }
};

// Example usage
int main() {
    vector<vector<int>> rects = {{-2, -2, 1, 1}, {2, 2, 4, 6}};
    Solution solution(rects);

    // Pick random points
    vector<int> point1 = solution.pick();
    vector<int> point2 = solution.pick();
    vector<int> point3 = solution.pick();

    return 0;
}

