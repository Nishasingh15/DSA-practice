// We have numbers from 1 to N.
// One number is repeated and one number is missing.
//Let:
// R = Repeating number
// M = Missing number
// Find the difference of sums:
//    Actual Sum - Expected Sum = R - M
//The repeated number is added one extra time,
//  while the missing number is not added.
// Find the difference of square sums:
//    Actual Square Sum - Expected Square Sum
//    = R² - M²
// Use the formula:
//    R² - M² = (R - M) × (R + M)
// We already know R - M from Step 1,
//so we can find R + M.
// Now we know both:
//    R - M
//    R + M
//Therefore:
//    R = ((R - M) + (R + M)) / 2
//    M = (R + M) - R
//So, using the normal sum and square sum,
// we can find both the repeating and missing numbers.
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        int n = nums.size();

        long long actualSum = 0;
        long long actualSquareSum = 0;

        for (int i = 0; i < n; i++) {
            actualSum = actualSum + nums[i];

            actualSquareSum = actualSquareSum 
                            + (long long)nums[i] * nums[i];
        }

        long long expectedSum = (long long)n * (n + 1) / 2;

        long long expectedSquareSum =
            (long long)n * (n + 1) * (2 * n + 1) / 6;

        long long diff = actualSum - expectedSum;

        long long squareDiff = actualSquareSum - expectedSquareSum;

        long long sum = squareDiff / diff;

        long long repeating = (diff + sum) / 2;

        long long missing = sum - repeating;

        return {(int)repeating, (int)missing};
    }
};
