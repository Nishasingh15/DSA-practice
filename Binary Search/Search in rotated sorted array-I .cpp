//We use Binary Search because, even after rotation, at least one half of the array is always sorted.
//First, find mid. If nums[mid] == target, return mid.
//Otherwise, check which half is sorted:
//If the left half is sorted, check whether the target lies between nums[low] and nums[mid]. If yes, search left; otherwise, search right.
//If the right half is sorted, check whether the target lies between nums[mid] and nums[high]. If yes, search right; otherwise, search left.
//Thus, we eliminate half of the search space in every step.
//TC: O(log n)
//SC: O(1)
class Solution {
public:
    int search(vector<int> &nums, int k) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = (low+high) / 2;
            if (nums[mid] == k)
                return mid;
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= k && k < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else {
                if (nums[mid] < k && k <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};
       
