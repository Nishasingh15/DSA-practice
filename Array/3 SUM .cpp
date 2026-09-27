// Intuition:
// The problem states that we are given an integer array and need to find
// all unique triplets whose sum is equal to 0.
//
// Brute Force Approach:
// We can check all possible triplets using three nested loops.
// If nums[i] + nums[j] + nums[k] == 0, store the triplet.
// This approach takes O(n^3) time.
//
// Optimal Approach:
// To reduce the time complexity, first sort the given array.
// Sorting allows us to use the two-pointer approach and easily skip duplicates.
//
// Fix the first element nums[i].
// Then use two pointers:
// j = i + 1 and k = n - 1.
//
// Calculate:
// sum = nums[i] + nums[j] + nums[k]
//
// If sum == 0:
// Store the triplet and move both pointers.
// If sum < 0:
// Move j forward to increase the sum.
// If sum > 0:
// Move k backward to decrease the sum.
//
// Skip duplicate values for i, j, and k so that we do not get
// duplicate triplets.
// Continue until j crosses k.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1) extra space
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++) {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int j=i+1;
            int k=n-1;
            while(j<k) {
                int sum= nums[i]+nums[j]+nums[k];
                if(sum==0) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[i+1])
                    j++;
                    while(j<k && nums[k]==nums[k-1]) 
                        k--;

            
                }
                    else if(sum<0) {
                        j++;
                    }
                    else {
                        k--;
                    }
                }
            }
            return ans;

        
    }
};
