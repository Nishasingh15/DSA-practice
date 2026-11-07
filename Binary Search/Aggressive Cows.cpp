// Intuition:
// Sort the stalls and apply Binary Search on the minimum distance.
// If mid is possible, try a larger distance. Otherwise, try a smaller distance.
// Return the maximum possible minimum distance.
class Solution {
public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 1;
        int high = nums.back() - nums[0];
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(nums, k, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
// Check whether we can place all k cows with at least mid distance between them.
bool isPossible(vector<int>& nums, int k, int mid) {
        int cows = 1;
        int last = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - last >= mid) {
                cows++;
                last = nums[i];
            }
        }

        return cows >= k;
    }
};
// TC: O(N log N + N log D)
// SC: O(1) auxiliary space
// D = Maximum stall position - Minimum stall position
