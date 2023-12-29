/*
 Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]


*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller = new ListNode(0);
        ListNode* larger = new ListNode(0);

        ListNode* smallhead = smaller;
        ListNode* highhead = larger;

        while (head) {
            if (head->val < x) {
                smallhead->next = head;
                smallhead = smallhead->next;
            } else {
                highhead->next = head;
                highhead = highhead->next;
            }
            head = head->next;
        }

        highhead->next = NULL;
        smallhead->next = larger->next;

        ListNode* result = smaller->next;

        delete smaller;
        delete larger;

        return result;
    }
};

