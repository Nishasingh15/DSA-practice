// First, we will traverse the array from left to right.
// At each position, we will compare the current element with the target.
// If the current element is equal to the target, return its index.
// If we traverse the complete array and the target is not found,
// return -1.
//
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};
