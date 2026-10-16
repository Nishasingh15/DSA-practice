// Intuition:
// We use binary search to find the Nth root of M.
// Calculate mid^N using a loop and compare it with M.
// If equal, return mid. If smaller, search the right half;
// otherwise, search the left half. If no integer root exists, return -1.
// Time Complexity: O(N * log M)
// Space Complexity: O(1)
class Solution {
public:
  int NthRoot(int N, int M) {
        int low = 1, high = M;
        while (low <= high) {
            int mid = (low+high) / 2;
            long long ans = 1;
            for (int i = 0; i < N; i++) {
                ans = ans * mid;
                if (ans > M)
                    break;
            }
            if (ans == M)
                return mid;
            else if (ans < M)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};
