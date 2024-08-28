/*
 Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Example 3:

Input: n = 0
Output: 0
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        if(n<5)
        {
            return 0;
        }
        int test=1;
        while(test*5<=n)
        {
            test*=5;
            ans+=n/test;
        }
        return ans;
    }
};
