// Intuition:
// To find the next greater permutation, we make the smallest possible
// change from the right side.
//
// 1. Traverse from right and find the first index where nums[i] < nums[i+1].
//    This is the position where we can make a change.
//
// 2. Find the smallest element greater than nums[index] from the right
//    and swap it with nums[index].
//
// 3. Reverse the elements after index to get the smallest possible order.
//
// If no such index is found, the array is already the last permutation,
// so reverse the entire array to get the first permutation.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for(int i=nums.size()-2;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
                index=i;
                break;
            }
        }
        if(index == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1;i>=index;i--) {
            if(nums[i]>nums[index]) {
                swap(nums[i],nums[index]);
                break;
            }

        }
        reverse(nums.begin()+index+1,nums.end());
    }
};
