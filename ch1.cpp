/* You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

 

Example 1:


Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0).*/

#include <algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Step 1: Find the closest point on the rectangle to the circle's center
        int closeX = max(x1, min(xCenter, x2));  // Closest x coordinate of the rectangle to the circle center
        int closeY = max(y1, min(yCenter, y2));  // Closest y coordinate of the rectangle to the circle center
        
        // Step 2: Calculate the distance between the closest point and the circle's center
        int distanceX = xCenter - closeX;  // Horizontal distance from the circle center to the closest point
        int distanceY = yCenter - closeY;  // Vertical distance from the circle center to the closest point
        
        // Step 3: Check if the distance is less than or equal to the circle's radius
        return (distanceX * distanceX + distanceY * distanceY) <= (radius * radius);
    }
};

