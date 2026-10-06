//intution:
//The minimum element is the rotation point of the sorted array.
//We use Binary Search to find that point. 
//If nums[mid] > nums[high], the minimum lies on the right, so we move low to mid + 1. 
//Otherwise, the minimum lies at mid or on the left, so we move high to mid. 
//We continue until low == high; that index contains the minimum.
//T.C=O(log n)
//S.C=O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high = nums.size()-1;
         while(low < high) {
        int mid=(low + high)/2;
        if(nums[mid]>nums[high]) {
            low=mid+1;
        }
        else{
            high=mid;
        }
      }
      return nums[low];

        
    }
};
