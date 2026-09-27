// Intuition:
// We use Kadane's Algorithm to find the maximum subarray sum.
// Keep two variables: currentSum and maxSum, and traverse the array
// from left to right.
//
// Add each element to currentSum.
// If currentSum becomes negative, discard it and reset currentSum to 0,
// because a negative sum will only decrease the sum of the next subarray.
//
// Whenever currentSum becomes greater than maxSum, update maxSum.
// At the end, maxSum is the maximum subarray sum.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0;
        int maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            currSum=currSum+nums[i];
            if(currSum>maxSum) {
                maxSum=currSum;
            }
            if(currSum<0) {
                currSum=0;
            }
        }
        return maxSum;

        
    }
};
