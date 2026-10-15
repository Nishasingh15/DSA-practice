//Intuition:
//We use Binary Search to find the square root without checking every number one by one.
//If the square of mid is less than or equal to x, mid can be our answer, but we search the right half to find a bigger possible answer. 
//If its square is greater than x, we search the left half because mid is too large. 
//Finally, we return the answer found.
//Time Complexity:O(log x)
//Space complexity:O(1)
class Solution {
public:
    int mySqrt(int x) {
        int low=0;
        int high = x;
        int ans=0;
        while(low<=high) {
            int mid = (low+high)/2;
            if((1LL*mid*mid)<=x) {
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};
