// Intuition:
// The problem states that we are given an integer array and a target.
// We need to find all unique quadruplets of four different indices
// i, j, k, and l such that:
// nums[i] + nums[j] + nums[k] + nums[l] == target.
//
// Brute Force Approach:
// We can use four nested loops to check every possible quadruplet.
// If the sum of the four elements is equal to the target,
// store that quadruplet.
// This approach takes O(n^4) time.
//
// Optimal Approach:
// To reduce the time complexity, first sort the array.
// Then fix two elements using i and j, and use two pointers
// k = j + 1 and l = n - 1 to find the remaining two elements.
//
// Calculate:
// sum = nums[i] + nums[j] + nums[k] + nums[l]
//
// If sum < target:
// Move k forward to increase the sum.
//
// If sum > target:
// Move l backward to decrease the sum.
//
// If sum == target:
// Store the quadruplet, move both pointers, and skip duplicate
// values so that we do not get duplicate quadruplets.
//
// Continue this process for all possible values of i and j.
//
// Time Complexity: O(n^3)
// Space Complexity: O(1) extra space
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++) {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            for(int j=i+1;j<n-2;j++) {
                if(j>i+1 && nums[j]==nums[j-1])
                continue;
                int k=j+1;
                int l=n-1;
                while(k<l) {
                    long long sum= (long long) nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1])
                        k++;
                        while(k<l && nums[l]==nums[l+1])
                        l--;
                    }
                    else if(sum<target) {
                        k++;
                    } 
                    else{
                        l--;
                    }
                }

            }
        }
        return ans;
        
    }
};
