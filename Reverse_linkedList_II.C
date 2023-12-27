/*
92. Reverse Linked List II
Solved
Medium
Topics
Companies
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]


*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Move to the node at position left - 1
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        ListNode* start = prev->next;
        ListNode* end = start;

        // Move to the node at position right
        for (int i = 0; i < right - left; ++i) {
            end = end->next;
        }

        ListNode* nextNode = end->next;
        end->next = nullptr;

        // Reverse the sublist from start to end
        prev->next = reverse(start);
        start->next = nextNode;

        return dummy->next;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }
};

