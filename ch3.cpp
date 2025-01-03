/* An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).


Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.

 

Example 1:


Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Example 2:


Input: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]*/

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));

        // Directions for the 8 neighbors and the cell itself
        int directions[9][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 0}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0, count = 0;

                // Traverse all neighbors and the cell itself
                for (int k = 0; k < 9; ++k) {
                    int ni = i + directions[k][0];
                    int nj = j + directions[k][1];

                    // Check if the neighbor is within bounds
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        sum += img[ni][nj];
                        ++count;
                    }
                }

                // Compute the floor of the average
                result[i][j] = sum / count;
            }
        }

        return result;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<vector<int>> img1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> result1 = solution.imageSmoother(img1);

    vector<vector<int>> img2 = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
    vector<vector<int>> result2 = solution.imageSmoother(img2);

    return 0;
}

