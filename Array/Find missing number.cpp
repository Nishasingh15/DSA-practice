// Intuition:
// The array should contain all numbers from 0 to n, but one number is missing.
// First, calculate the expected sum of numbers from 0 to n using n*(n+1)/2.
// Then, calculate the actual sum of the elements present in the array.
// The difference between the expected sum and actual sum gives the missing number.
//
// Complexity:
// Time Complexity: O(n) — We traverse the array once.
// Space Complexity: O(1) — Only a few variables are used.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int exceptedSum = n*(n+1)/2;
        int actualSum=0;
        for(int i=0;i<n;i++) {
            actualSum= actualSum+nums[i];
        }
        return exceptedSum-actualSum;
        
    }
};
