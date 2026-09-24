// First, we will take the first element as the largest element
// and secondLargest as -1. Assume that the array does not contain
// any negative element.
//
// Traverse the array from the second element to the last element.
// If the current element is greater than the largest element,
// update secondLargest with the old value of largest and update
// largest with the current element.
//
// If the current element is greater than secondLargest but not
// equal to largest, update secondLargest.
//
// After traversing the array, secondLargest will contain the
// second largest element.
//
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int Largest = nums[0];
        int secondLargest = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > Largest) {
                secondLargest = Largest;
                Largest = nums[i];
            }
            else if(nums[i] > secondLargest && nums[i] != Largest) {
                secondLargest = nums[i];
            }
        }

        return secondLargest;
    }
};
