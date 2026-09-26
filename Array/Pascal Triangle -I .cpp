// Intuition:
// We are given the row and column in 1-based indexing.
// Every element in Pascal's Triangle can be represented
// using the combination formula.
//
// For position (r, c), the required element is:
// C(r-1, c-1)
//
// Instead of creating the complete Pascal Triangle,
// we calculate this combination directly.
//
// We start with res = 1.
// In every iteration, we multiply res by the next value
// from (r-1) and divide it by the corresponding value
// from (c-1).
//
// The loop runs c-1 times because we need to calculate
// C(r-1, c-1).
//
// Thus, we get the required element directly using
// only one variable, without storing the triangle.
//
// Time Complexity: O(c)
// Space Complexity: O(1)
class Solution {
public:
    int pascalTriangleI(int r, int c) {
        long long res=1;
        for(int i=0;i<c-1;i++) {
            res=res*(r-1-i);
            res=res/(i+1);
        }
        return (int)res;

    }
};
