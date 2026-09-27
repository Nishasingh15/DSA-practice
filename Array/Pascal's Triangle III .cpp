// Intuition:
// We need the first n rows, so we generate each row one by one.
// For every row, we start with 1.
// Then for every column, we calculate the next value by:
// val = val * (row - col) / col
// After generating the complete row, we store it in ans.
//Time Complexity: O(n²)
//Space Complexity: O(n²)
class Solution {
public:
    vector<vector<int>> pascalTriangleIII(int n) {
        vector<vector<int>> ans;

        for (int row = 1; row <= n; row++) {
            vector<int> temp;
            long long val = 1;

            temp.push_back(val);

            for (int col = 1; col < row; col++) {
                val = val * (row - col);
                val = val / col;

                temp.push_back(val);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
