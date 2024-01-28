/*
 Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100

*/

class Solution {
public:
    void bfs(TreeNode* root, vector<vector<int>>& ans, int level) {
        if (!root) {
            return;
        }

        // Ensure that ans has enough levels to store the current node's value
        if (ans.size() <= level) {
            ans.push_back(vector<int>());
        }

        ans[level].push_back(root->val);

        bfs(root->left, ans, level + 1);
        bfs(root->right, ans, level + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bfs(root, ans, 0);

        // Reverse the order for odd levels (0-based index)
        for (int i = 1; i < ans.size(); i += 2) {
            reverse(ans[i].begin(), ans[i].end());
        }

        return ans;
    }
};

