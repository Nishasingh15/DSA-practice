
        //INTUITION:
       // An element is a majority element if it appears more than n/3 times.
       // There can be at most 2 such elements.

        //So, we keep 2 candidates and their counts.
        // If the current element is same as a candidate, increase its count.
        //If any candidate has count 0, make the current element that candidate.
        //If the current element is different from both candidates,
          //decrease both counts because they cancel each other.

        //After finding the possible candidates, we count their actual
        //frequency again and check whether it is greater than n/3.
      //Time Complexity: O(n)
     // Space Complexity: O(1)

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {

        int n = nums.size();

        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {

            if (nums[i] == candidate1) {
                count1++;
            }
            else if (nums[i] == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] == candidate1)
                count1++;

            if (nums[i] == candidate2)
                count2++;
        }

        vector<int> ans;

        if (count1 > n / 3)
            ans.push_back(candidate1);

        if (count2 > n / 3)
            ans.push_back(candidate2);

        return ans;
    }
};
        
