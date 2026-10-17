// Problem: Koko Eating Bananas
// Koko has n piles of bananas, where piles[i] represents the bananas in each pile.
// She can eat k bananas per hour from one pile.
// If a pile has fewer bananas than k, she eats all bananas in that pile in one hour.
// Return the minimum integer k such that Koko can eat all bananas within H hours.

// Optimal Intuition:
// We use binary search to find the minimum eating speed k from 1 to the maximum pile size.
// For each mid, calculate the total hours required to eat all bananas.
// If hours <= H, store mid as the answer and try a smaller speed.
// Otherwise, search the right half for a larger speed.
// TC: O(NlogM)
// SC: O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > high) {
                high = piles[i];
            }
        }
        int low = 1;
        int ans = high;
        while (low <= high) {
            int mid = (low+high) / 2;
            long long  hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours =  hours + (piles[i] + mid - 1) / mid;
            }
            if ( hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
        
    }
};
