/*


  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false

*/


class Solution {
public:
    bool isValid(string s) {
        bool ans = true;
        stack<char> st;

        for (auto m : s) {
            if (m == '(' || m == '{' || m == '[') {
                st.push(m);
            } else if (!st.empty()) {
                if ((m == ')' && st.top() == '(') || (m == '}' && st.top() == '{') || (m == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    ans = false;
                    break; // Break out of the loop since we already know the answer
                }
            } else {
                ans = false;
                break; // Break out of the loop since we already know the answer
            }
        }

        if (!st.empty()) {
            ans = false;
        }

        return ans;
    }
};

