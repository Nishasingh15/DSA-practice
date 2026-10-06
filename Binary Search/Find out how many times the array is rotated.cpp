//intution:
//This problem is the same as finding the minimum element in a rotated sorted array. 
//The only difference is that in the previous problem, we found the minimum element itself,
//whereas here we need to find the index of the minimum element. 
//The index of the minimum element represents the number of times the array has been rotated.
//Time: O(log n)
//Space: O(1)
class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int low=0;
        int high = nums.size()-1;
        while(low < high) {
            int mid = (low + high)/2;
            if(nums[mid]>nums[high]) {
                low=mid+1;
            }
            else {
                high=mid;
            }

            
        }
        return low;
        
    }
};
