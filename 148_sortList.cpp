/*
 Given the head of a linked list, return the list after sorting it in ascending order.
Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Approach : sorting with constant space =⇒ Merge Sort
*/


class Solution {
public:
    // Merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* result = nullptr;
        
        if (l1->val < l2->val) {
            result = l1;
            result->next = merge(l1->next, l2);
        } else {
            result = l2;
            result->next = merge(l1, l2->next);
        }
        
        return result;
    }
    
    // Function to split the list into two halves and sort them recursively
    ListNode* sortList(ListNode* head) {
        // Base case
        if (!head || !head->next) return head;
        
        // Use the slow and fast pointer approach to find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split the list into two halves
        prev->next = nullptr;
        
        // Recursively sort each half
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        // Merge the sorted halves
        return merge(left, right);
    }
};


