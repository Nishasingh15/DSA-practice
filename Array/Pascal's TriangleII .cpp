// Intuition:
// Start with 1, because the first element of every row is 1.
// Use the previous element (ans) to calculate the next element.
// Formula: ans = ans * (r - col) / col
//Time Complexity: O(r)
//Space Complexity: O(r)
class Solution {
public:
    vector<int> pascalTriangleII(int r) {
        vector<int> result;

        long long ans = 1;
        result.push_back(ans);

        for (int col = 1; col < r; col++) {
            ans = ans * (r - col)/col;
            result.push_back(ans);
        }

        return result;
    }
};
