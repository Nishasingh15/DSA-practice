// Intuition:
// Use the Dutch National Flag algorithm with three pointers: low, mid, high.
//
// low  -> position for the next 0
// mid  -> current element
// high -> position for the next 2
//
// If nums[mid] == 0, swap with low and move low, mid.
// If nums[mid] == 1, simply move mid.
// If nums[mid] == 2, swap with high and move high.
// Do not move mid after swapping 2, because the new element at mid
// is not checked yet.
//
// Continue until mid > high.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high) {
            if(nums[mid]==0) {
                swap(nums[low],nums[mid]);
                low++;
                mid++;

            }
            else if(nums[mid]==1) {
                mid++;
            }
            else {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};
