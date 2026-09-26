// Intuition:
// We use the two-pointer approach to move all non-zero elements
// to the front while keeping all zeroes at the end.
//
// We keep two pointers:
// i -> scans every element of the array.
// j -> points to the position where the next non-zero element
//      should be placed.
//
// We traverse the array using i. Whenever we find a non-zero element,
// we swap it with the element at position j and then move j forward.
//
// This keeps all non-zero elements in their original order and
// automatically moves all zeroes towards the end.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=0) {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        
    }
};
