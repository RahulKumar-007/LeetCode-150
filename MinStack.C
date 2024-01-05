/*


   Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.



Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


*/



class MinStack {
    private: 
    struct Node{
        int val;
        int mini;
        Node* next;

        Node(int value,int minimum,Node* nxt){
            val = value;
            mini = minimum;
            next = nxt;


        }
    };

    Node* head;
public:
    MinStack() {
       head = NULL; 
    }
    
    void push(int val) {
        
        if(head==NULL) head = new Node(val,val,NULL);
        else  head = new Node(val,min(head->mini ,val) , head);
   }
    
    void pop() {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->mini;
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
