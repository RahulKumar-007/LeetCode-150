/*
 You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

    "a->b" if a != b
    "a" if a == b

 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

 

Constraints:

    0 <= nums.length <= 20
    -231 <= nums[i] <= 231 - 1
    All the values of nums are unique.
    nums is sorted in ascending order.

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0) return ans; // Check for empty input

        int a = nums[0];

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + 1 != nums[i + 1]) { // If there's a break in the sequence
                if (nums[i] == a) { // Single element range
                    ans.push_back(to_string(a));
                } else { // Multiple element range
                    ans.push_back(to_string(a) + "->" + to_string(nums[i]));
                }
                a = nums[i + 1]; // Start new range
            }
        }

        // Handle the last range or element
        if (nums[n - 1] == a) {
            ans.push_back(to_string(a)); // Single element at the end
        } else {
            ans.push_back(to_string(a) + "->" + to_string(nums[n - 1])); // Range at the end
        }

        return ans;
    }
};

