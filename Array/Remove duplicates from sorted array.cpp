// Intuition:
// We use the two-pointer approach because the array is already sorted,
// so duplicate elements will always be next to each other.
//
// The first element is always unique, so we keep it at the first position.
// We use one pointer i to keep track of the position of the last unique
// element and another pointer j to traverse the array.
//
// Whenever nums[j] is different from the last unique element,
// we place nums[j] at the next position after i and move i forward.
//
// In this way, all unique elements are placed at the beginning of the array
// in their original order, and the duplicates are ignored.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return 1;
        int i=0;
        for(int j=1;j<n;j++) {
            if(nums[j]!=nums[i]) {
                nums[i+1]=nums[j];
                i++;
            }
        }
        return(i+1);
        
    }
};
