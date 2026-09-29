class Solution {
public:

    // Merge two sorted halves and count inversions
    long long merge(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        long long cnt = 0;

        // Compare elements of both sorted halves
        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {

                // No inversion, so take the left element
                temp.push_back(nums[left]);
                left++;
            }
            else {

                // nums[left] > nums[right]
                // Since left half is sorted, nums[right]
                // is smaller than all remaining elements
                // from left to mid.
                // So, all of them form an inversion.
                cnt += (mid - left + 1);

                temp.push_back(nums[right]);
                right++;
            }
        }

        // Add remaining elements of left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Add remaining elements of right half
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy sorted elements back into nums
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return cnt;
    }


    // Divide the array into two halves,
    // count inversions in both halves,
    // and count cross inversions while merging.
    long long mergeSort(vector<int>& nums, int low, int high) {

        long long cnt = 0;

        // Single element is already sorted
        if (low >= high)
            return cnt;

        int mid = low + (high - low) / 2;

        // Count inversions in left half
        cnt += mergeSort(nums, low, mid);

        // Count inversions in right half
        cnt += mergeSort(nums, mid + 1, high);

        // Count inversions between left and right halves
        cnt += merge(nums, low, mid, high);

        return cnt;
    }


    // Start merge sort on the complete array
    long long int numberOfInversions(vector<int> nums) {

        int n = nums.size();

        return mergeSort(nums, 0, n - 1);
    }
};
