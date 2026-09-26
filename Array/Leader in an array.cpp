// Intuition:
// Traverse the array from right to left and keep track of the maximum element
// seen so far. If the current element is strictly greater than this maximum,
// it is a leader because all elements to its right are smaller.
// Add it to the answer and update the maximum.
// Finally, reverse the answer to maintain the same order as in the original array.
//
// Time Complexity: O(n)
// Space Complexity: O(k), where k is the number of leaders.
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int>ans;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i= n-1;i>=0;i--) {
            if(nums[i]>maxi) {
                ans.push_back(nums[i]);
        }
        maxi=max(maxi,nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
      
    }
};
