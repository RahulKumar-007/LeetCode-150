/*
 Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

 

Constraints:

    1 <= target <= 109
    1 <= nums.length <= 105
    1 <= nums[i] <= 104
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int mn = INT_MAX;
        int total = 0;

        while (j < nums.size()) {
            // Add the current element to the total
            total += nums[j];

            // Shrink the window from the left until the total is less than the target
            while (total >= target) {
                mn = min(mn, j - i + 1);
                total -= nums[i];
                i++;
            }

            // Move the right end of the window forward
            j++;
        }

        // If mn was never updated, it means no valid subarray was found
        return (mn == INT_MAX) ? 0 : mn;
    }
};

