/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/

// Iterative approach

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	    ListNode *result=new ListNode(0);
	    while(list1 && list2){
		    if(list1->val>list2->val)
		    {
			    result->next=new ListNode(list2->val);
			    list2=list2->next;
			}
		    else
		    {
			    result->next=new ListNode(list1->val);
			    list2=list1->next;
		    }

		    result=result->next;
	    }

	    if(list1)
	    {
		    result->next-=new ListNode(list1->val);
		    list1=list1->next;
		    result==result->next;
	    }

	    if(list2)
	    {
		    result->next-=new ListNode(list2->val);
		    list1=list2->next;
		    result==result->next;
	    }

	    return result->next;
    }
};


// Recursive approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};


			    
