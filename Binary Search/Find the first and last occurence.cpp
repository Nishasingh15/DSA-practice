// We use Binary Search because the array is sorted.
// In normal binary search, when we find the target,
// we usually return immediately.
// But here, finding the target is not enough because
// the target may occur multiple times.
// First Occurrence:
// Store mid and continue searching LEFT
// because there may be another target at a smaller index.
// Last Occurrence:
// Store mid and continue searching RIGHT
// because there may be another target at a larger index.
//TC = O(log n) + O(log n) = O(log n)
//SC = O(1)
class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target) {

        int first = -1;
        int last = -1;
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low+high) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        low = 0;
        high = nums.size() - 1;

        while (low <= high) {
            int mid = (low+high) / 2;

            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return {first, last};
    }
};
    
