// Intuition:
// In the brute force approach, we use extra arrays to store which rows
// and columns contain zero, taking O(n + m) extra space.
//
// To optimize space, we use the first row and first column of the matrix
// itself as markers instead of using extra arrays.
//
// Whenever matrix[i][j] == 0, mark its row by setting matrix[i][0] = 0
// and mark its column by setting matrix[0][j] = 0.
//
// The problem is that matrix[0][0] belongs to both the first row and
// the first column. So, we use a separate variable col0 to remember
// whether the first column needs to be zeroed.
//
// After marking, traverse the matrix again and set matrix[i][j] = 0
// whenever its row marker or column marker is 0.
//
// Finally, handle the first row and first column separately.
//
// Time Complexity: O(n * m)
// Space Complexity: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col0=1;
        for(int i=0;i<n;i++) {
            if(matrix[i][0]==0) {
                col0=0;
            }
            for(int j=1;j<m;j++) {
                if(matrix[i][j]==0) {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(matrix[i][0]==0||matrix[0][j]==0) {
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0) {
            for(int j=0;j<m;j++) {
                matrix[0][j]=0;
            }
        }
        if(col0==0) {
            for(int i=0;i<n;i++) {
                matrix[i][0]=0;
            }
        }
    }
};
