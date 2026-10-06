// First, take an empty set and store all the elements in it,
// so we can search for any number in O(1) average time.
// For every element num, check whether num - 1 exists in the set.
// If num - 1 does not exist, then num is the starting element of the consecutive sequence.
// For num, keep checking num + 1, num + 2, num + 3, ..., and count how many times the sequence continues.
// Keep updating the maximum length found.This avoids sorting and ensures that each sequence is
// explored only from its starting point.
//Time Complexity: Average O(n)
//Space Complexity: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int longest=0;
        for(int num:s) {
            if(s.find(num-1)==s.end()) {
                int curr=num;
                int cnt = 1;
                while(s.find(curr+1)!=s.end()) {
                    curr++;
                    cnt++;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
        
    }
};
