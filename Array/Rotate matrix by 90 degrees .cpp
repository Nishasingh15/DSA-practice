// Intuition:
        // First, transpose the matrix to convert rows into columns.
        // Then, reverse every row to move the elements into their
        // correct 90-degree clockwise positions.
        // We do both operations in-place, so no extra matrix is needed.
//Time Complexity: O(n²)
//Space Complexity: O(1)
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};
