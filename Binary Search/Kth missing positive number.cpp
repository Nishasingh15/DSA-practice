// We are given a sorted array and need to find the Kth missing positive number.
// Calculate the number of missing elements at mid using arr[mid] - (mid + 1).
// Apply Binary Search to find the first index where missing count >= k.
// If missing count < k, move right; otherwise, move left.
// Finally, return low + k to get the Kth missing positive number.
//TC: O(log n)
//SC: O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int low = 0;
        int high = arr.size() - 1;
      while (low <= high) {
        int mid = (low+high) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low + k;
        
    }
};
