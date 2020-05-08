// Question - Check If It Is a Straight Line

/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.





Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false


Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

// Solution

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 0) {
            return true;
        }

        int y2 = coordinates[1][1];
        int y1 = coordinates[0][1];
        int x1 = coordinates[0][0];
        int x2 = coordinates[1][0];

        if(x2 - x1 == 0) {
            return false;
        }

        float m = (y2-y1)/(x2-x1);

        cout << " m " << m << endl;
        float temp;

        for(int i = 2 ; i < coordinates.size() ; i++) {
            x2 = coordinates[i][0];
            y2 = coordinates[i][1];

            if(x2 - x1 == 0) {
                return false;
            }

            temp = (y2-y1) * 1.0/(x2-x1) * 1.0;

            cout << temp << " " << m << endl;

            if(temp != m) {
                return false;
            }
        }

        return true;

    }
};
