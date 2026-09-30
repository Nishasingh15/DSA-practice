// Lower Bound means finding the first index where arr[index] >= x.
// Since the array is sorted, we use Binary Search.
// If arr[mid] >= x:
// mid can be the lower bound.Store mid as the answer and search on the leftto check if an earlier valid index exists.
//If arr[mid] < x:
//arr[mid] is smaller than x, so it cannot be the answer.Move to the right half.
// At the end, ans gives the first index where arr[index] >= x.
// If no such element exists, ans = n.
// TC: O(log n)
// SC: O(1)
class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= x) {
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
