/*
 Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.

 

Constraints:

    n == nums.length
    1 <= n <= 3 * 104
    -3 * 104 <= nums[i] <= 3 * 104

*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        // Initialize max and min subarray sums
        int maxsub = nums[0];
        int currmax = nums[0];

        int minsub = nums[0];
        int currmin = nums[0];

        // Total sum of the array
        int total = nums[0];

        // Traverse through the array starting from the second element
        for (int i = 1; i < n; ++i) {
            total += nums[i];

            // Update currmax and maxsub
            currmax = max(nums[i], currmax + nums[i]);
            maxsub = max(maxsub, currmax);

            // Update currmin and minsub
            currmin = min(nums[i], currmin + nums[i]);
            minsub = min(minsub, currmin);
        }

        // If maxsub is negative, it means all numbers are negative
        // In this case, return maxsub as the result
        if (maxsub < 0)
            return maxsub;

        // Otherwise, calculate the maximum circular subarray sum
        return max(maxsub, total - minsub);
    }
};

