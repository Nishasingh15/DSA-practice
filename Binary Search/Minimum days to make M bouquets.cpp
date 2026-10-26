//INTUITION:
// We need to find the minimum days to make m bouquets , where each bouquet requires k adjacent flowers.
// Use binary search on the number of days.
// If we can make enough bouquets, try fewer days.
// If we cannot make enough bouquets, try more days.
//  T.C = O(n * log(maxDay - minDay + 1))
//  S.C = O(1)
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if ((long long)m * k > n)
            return -1;

        int low = bloomDay[0];
        int high = bloomDay[0];

        for (int i = 0; i < n; i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        int ans = -1;
        while (low <= high) {
            int mid = (low+high) / 2;
            int bouquets = 0, flowers = 0;

            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    flowers++;
                if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }

            if (bouquets >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
