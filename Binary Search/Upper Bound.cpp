//Intuition:
//We need to find the first index where the element is strictly greater than x.
// If nums[mid] > x, then mid can be our answer.Store mid in ans and search on the left side to find a smaller valid index.
// If nums[mid] <= x, then mid cannot be the answer.So, search on the right side for an element greater than x.
// Repeat until low > high.Finally, return ans. If no element is greater than x,ans remains nums.size().
//Time Complexity: O(log N)
//Space Complexity: O(1)
class Solution {
public:
    int upperBound(vector<int> &nums, int x) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {
            int mid = (low +high)  / 2;

            if (nums[mid] > x) {
                ans = mid;   
                high = mid - 1; 
            }
            else {
                low = mid + 1; 
            }
        }

        return ans;
    }
};
