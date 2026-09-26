// Intuition:
// Since the array contains an equal number of positive and negative elements,
// we place positive elements at even indexes and negative elements at odd indexes.
// We use an extra array and maintain two pointers:
// pos = 0 -> next available even index for positive elements
// neg = 1 -> next available odd index for negative elements.
// While traversing the array, each positive is placed at pos and each negative
// is placed at neg. After placing an element, the corresponding pointer moves by 2.
// This ensures that positive and negative elements are arranged alternately.
//
// Time Complexity: O(N)
// Space Complexity: O(N)  // Extra array used for rearrangement
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int>ans(nums.size());
        int pos=0;
        int neg=1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>0) {
                ans[pos]=nums[i];
                pos=pos+2;
            }
            if(nums[i]<0) {
                ans[neg]=nums[i];
                neg=neg+2;
            }
        }
        return ans;
        
    }
};
