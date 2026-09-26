 // Intuition:
 // The idea is to traverse the matrix layer by layer in a spiral manner.
 // We use four boundaries: top, bottom, left, and right.
 //
 // 1. Print the top row from left to right, then move top downward.
 // 2. Print the right column from top to bottom, then move right to left.
 // 3. Print the bottom row from right to left, then move bottom upward.
 // 4. Print the left column from bottom to top, then move left to right.
 //
 // After printing each side, we move that boundary inward and repeat
 // until the entire matrix is printed in spiral order.
 //
 // Time Complexity: O(N × M)
 // Space Complexity: O(1)  // Excluding the output array
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0, bottom=n-1;
        int left=0, right=m-1;
        while(top<=bottom && left<=right) {
            for(int i=left;i<=right;i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom) {
                for(int i=right;i>=left;i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right) {
                for(int i=bottom;i>=top;i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
        
        
    }
};
