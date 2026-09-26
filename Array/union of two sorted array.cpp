// Intuition:
// Since both arrays are already sorted, we can use the Two Pointer technique.
// Place one pointer at the beginning of each array and compare their elements.
//
// If arr1[i] < arr2[j], add arr1[i] to the union if it is not already added,
// then move i forward.
//
// If arr2[j] < arr1[i], add arr2[j] to the union if it is not already added,
// then move j forward.
//
// If arr1[i] == arr2[j], add the element only once to avoid duplicates,
// then move both pointers forward.
//
// After one array is completely traversed, add the remaining elements
// from the other array while avoiding duplicates.
//
// Since the arrays are sorted, duplicate elements appear together.
// We can avoid duplicates by checking whether the current element
// is the same as the last element added to the union.
//
// Complexity:
// Time Complexity: O(n + m)
// Space Complexity: O(n + m) — for storing the union.
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    vector<int> ans;

    while (i < nums1.size() && j < nums2.size()) {

        if (nums1[i] < nums2[j]) {
            if (ans.empty() || ans.back() != nums1[i])
                ans.push_back(nums1[i]);
            i++;
        }

        else if (nums2[j] < nums1[i]) {
            if (ans.empty() || ans.back() != nums2[j])
                ans.push_back(nums2[j]);
            j++;
        }

        else {
            if (ans.empty() || ans.back() != nums1[i])
                ans.push_back(nums1[i]);

            i++;
            j++;
        }
    }

    while (i < nums1.size()) {
        if (ans.empty() || ans.back() != nums1[i])
            ans.push_back(nums1[i]);
        i++;
    }

    while (j < nums2.size()) {
        if (ans.empty() || ans.back() != nums2[j])
            ans.push_back(nums2[j]);
        j++;
    }

    return ans;
}
        
    };
