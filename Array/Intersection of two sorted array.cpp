// Intuition:
// Since both arrays are sorted, we use two pointers.
// Place i at the beginning of nums1 and j at the beginning of nums2.
//
// If nums1[i] < nums2[j], move i because nums1[i] is smaller
// and cannot match any future element of nums2.
//
// If nums2[j] < nums1[i], move j because nums2[j] is smaller
// and cannot match any future element of nums1.
//
// If nums1[i] == nums2[j], we found a common element.
// Add it to the answer and move both pointers.
//
// Since the arrays are sorted, we can find the common elements
// efficiently without comparing every element with every other element.
//
// Complexity:
// Time Complexity: O(n + m)
// Space Complexity: O(k), where k is the number of common elements.
class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    vector<int> ans;

    while (i < nums1.size() && j < nums2.size()) {

        if (nums1[i] < nums2[j]) {
            i++;
        }
        else if (nums2[j] < nums1[i]) {
            j++;
        }
        else {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    return ans;
}
        
    };
