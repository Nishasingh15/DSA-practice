//We need to find the first index where nums[i] >= target. 
//This is exactly the Lower Bound. 
//If nums[mid] >= target, mid can be the answer, so we store it and search on the left for an earlier valid index.
//Otherwise, nums[mid] < target, so we move right.
//Time Complexity: O(log N)
//Space Complexity: O(1)
class Solution {
public:
    int searchInsert(vector<int> &nums, int target)  {
        
       int low = 0, high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {
            int mid = (low +high) / 2;

            if (nums[mid] >= target) {
                ans = mid;      
                high = mid - 1; 
            }
            else {
                low = mid + 1; 
            }
        }

        return ans;
        
    }
};
