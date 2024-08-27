/*
 Given a string s, find the length of the longest
substring
without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        set<char> st;
        int ans = 0;

        while (j < s.size()) {
            // If the character at index j is not in the set, add it
            if (st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                ans = max(ans, j - i + 1);  // Update the maximum length
                j++;
            }
            // If the character is in the set, remove the character at index i
            else {
                st.erase(s[i]);
                i++;
            }
        }

        return ans;
    }
};

