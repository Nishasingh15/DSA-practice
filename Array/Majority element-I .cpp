// Intuition:
// We use Moore's Voting Algorithm, which is based on the idea of pair cancellation.
// Whenever two different elements are found, they cancel each other because they cannot
// both contribute to making one element the majority.
// We maintain a candidate (possible majority element) and a count (remaining votes).
// If the current element is equal to the candidate, increase the count.
// Otherwise, decrease the count because one vote gets cancelled.
// When the count becomes 0, choose the current element as the new candidate.
// Since the majority element appears more than n/2 times, it cannot be completely cancelled.
// Therefore, the final candidate after traversing the array is the majority element.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=0;
        int count=0;
        for(int i=0;i<nums.size();i++) {
            if(count==0) {
                candidate=nums[i];
            }
            if(nums[i]==candidate) {
                count++;
            }
            else {
                count--;
            }
        }
        return candidate;
    }
};
