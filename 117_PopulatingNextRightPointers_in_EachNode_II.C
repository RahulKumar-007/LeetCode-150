/*
    Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:


Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100
 
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      if(root==NULL)
      {
          return NULL;
      }
      queue<Node*> q;
      q.push(root);
      while(!q.empty())
      {
          int s=q.size();
          int i=s;
          vector<Node*> arr;
          while(i>0)
          {
              Node* temp=q.front();
              q.pop();
              if(temp->left)
              {
                  q.push(temp->left);
              }
              if(temp->right)
              {
                  q.push(temp->right);
              }
              arr.push_back(temp);
              i--;
          }
          i=0;
          while(arr.size()>i){
              if(i==arr.size()-1)
              {
                  arr[i]->next=NULL;
              }
              else
              {
                  arr[i]->next=arr[i+1];
              }
              i++;
          }
      }
      return root;
    }
};
