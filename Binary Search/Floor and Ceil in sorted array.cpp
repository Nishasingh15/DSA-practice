//Intuition:
//If nums[mid] < x, it can be the floor, so move right to find a larger possible floor.
//If nums[mid] > x, it can be the ceiling, so move left to find a smaller possible ceiling.
//If nums[mid]== x , then floor = ceiling = x.
//If floor or ceiling does not exist, it remains -1.
//TC: O(log N)
//SC: O(1)
class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {

        int low = 0;
        int high = nums.size() - 1;

        int floor = -1;
        int ceil = -1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] == x) {
                floor = nums[mid];
                ceil = nums[mid];
                break;
            }

            else if (nums[mid] < x) {
                floor = nums[mid];     
                low = mid + 1;       
            }

            else {
                ceil = nums[mid];     
                high = mid - 1;      
            }
        }
       return {floor, ceil};
    }
};
