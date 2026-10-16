/ Intuition:
// We use binary search to find the smallest divisor.
// Take low = 1 and high = maximum element of the array.
// Calculate mid and find the sum of the array elements divided by mid, rounding each division up.
// If sum <= threshold, store mid in ans and search the left half for a smaller divisor. Otherwise, search the right half.
// Finally, return ans.
// Time Complexity: O(N * log M)
// Space Complexity: O(1)
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high= nums[0];                                         
        for(int i=1;i<nums.size();i++) {
            high=max(high,nums[i]);
        }

        int ans = -1;

        while (low <= high) {
            int mid = (low+high) / 2;
            int sum = 0;

            for (int i = 0; i < nums.size(); i++) {
                sum= sum + (nums[i] + mid - 1) / mid;
            }

            if (sum <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
