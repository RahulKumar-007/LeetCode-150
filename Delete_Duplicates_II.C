/*
 *
 Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

*/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;

        while (current->next && current->next->next) {
            if (current->next->val == current->next->next->val) {
                int duplicateValue = current->next->val;
                while (current->next && current->next->val == duplicateValue) {
                    ListNode* temp = current->next;
                    current->next = current->next->next;
                    delete temp;  // Free memory for the removed node
                }
            } else {
                current = current->next;
            }
        }

        return dummy->next;
    }
};

