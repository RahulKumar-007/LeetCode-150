/*
 Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]

*/
class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index, int n) {
        if (index == n) {
            ans.push_back(nums);  // A complete permutation is generated
            return;
        }

        for (int i = index; i < n; i++) {
            // Swap the current element with the element at the current index
            swap(nums[i], nums[index]);

            // Recursively call for the next index
            solve(nums, ans, index + 1, n);

            // Backtrack by swapping back to the original position
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(nums, ans, 0, n);
        return ans;
    }
};


