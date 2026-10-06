//Since the array is sorted, all occurrences of the target are consecutive. 
//Therefore, instead of counting each occurrence, we find the first and last occurrence using Binary Search.
//Once we have both indices, the number of occurrences is last - first + 1.
//If the target does not exist, the answer is 0.
//Time: O(log n)
//Space: O(1)
class Solution {
public:
    int countOccurrences(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (arr[mid] == target) {
                first = mid;
                high = mid - 1;   
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if (first == -1)
            return 0;
        
        low = 0;
        high = n - 1;
        int last = -1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (arr[mid] == target) {
                last = mid;
                low = mid + 1;  
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return last - first + 1;


    }
};
