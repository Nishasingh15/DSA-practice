// Intuition:
// Since the array is sorted, check the middle element.
// If arr[mid] < x, search right half.
// If arr[mid] > x, search left half.
// Thus, we eliminate half of the search space each time.

// TC: O(log n)
// SC: O(1)
class Solution{
public:
    int search(vector<int> &nums, int target){
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
     
    }
};
