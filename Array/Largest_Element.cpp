// Intuition:
// Assume the first element as the largest.
// Traverse from left to right and compare each element with the current largest.
// If an element is greater, update the largest.
// After traversing the entire array, the stored value is the largest element.
class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largest=nums[0];
        for(int i=0;i<nums.size();i++) 
        {
            if(nums[i]>largest) {
            
                largest=nums[i];
            }
            
        }
        return largest;

    }
};
