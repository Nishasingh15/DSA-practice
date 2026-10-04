// Intuition:
// In a rotated sorted array, at least one half is sorted.
// Check the sorted half and decide where the target can lie.
// If nums[low] == nums[mid] == nums[high], duplicates make
// it impossible to identify the sorted half, so shrink
// the search space using low++ and high--.
// Time Complexity: O(N) 
// Space Complexity: O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
         while (low <= high) {
         int mid = (low+high) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;

                else
                    low = mid + 1;
            }

            else {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;

                else
                    high = mid - 1;
            }
        }

        return false;
    }
};
