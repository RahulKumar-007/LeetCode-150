/*
 

   Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.



Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]



Constraints:

    1 <= inorder.length <= 3000
    postorder.length == inorder.length
    -3000 <= inorder[i], postorder[i] <= 3000
    inorder and postorder consist of unique values.
    Each value of postorder also appears in inorder.
    inorder is guaranteed to be the inorder traversal of the tree.
    postorder is guaranteed to be the postorder traversal of the tree.

*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int postStart = 0, postEnd = postorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;
  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }
  return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
    }
    TreeNode * constructTree(vector < int > & postorder, int postStart, int postEnd,
vector < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (postStart > postEnd || inStart > inEnd) return NULL;

  TreeNode * root = new TreeNode(postorder[postEnd]);
  int elem = mp[root -> val];
  int nElem = elem - inStart;

  root -> left = constructTree(postorder, postStart, postStart + nElem - 1,
  inorder, inStart, elem - 1, mp);
  root -> right = constructTree(postorder, postStart + nElem, postEnd-1, inorder,
  elem + 1, inEnd, mp);

  return root;
    }
};
