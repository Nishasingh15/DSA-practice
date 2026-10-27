// Intuition:
// The minimum capacity is the heaviest package, and the maximum
// capacity is the sum of all package weights. Use binary search
// to find the minimum capacity. If all packages can be shipped
// within D days, try a smaller capacity; otherwise, increase the capacity.
// Time Complexity: O(n * log(sum of weights))
// Space Complexity: O(1)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
        for (int i = 0; i < weights.size(); i++) {
            low = max(low, weights[i]);  
            high = high + weights[i]; 
        }

        while (low <= high) {
            int mid = (low+high) / 2;
            int dayCount = 1, capacity = 0;

            for (int i = 0; i < weights.size(); i++) {
                if (capacity + weights[i] > mid) {
                    dayCount++;
                    capacity = 0;
                }
                capacity=capacity + weights[i];
            }

            if (dayCount <= days) {
                high = mid - 1;  
            } else {
                low = mid + 1;  
            }
        }

        return low;
        
    }
};
