'''
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).



Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false


Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.


Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
'''

# Two Pointer Approach  Beats 30 % User 

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True

        s_ptr, t_ptr = 0, 0
        while t_ptr < len(t):
            if s[s_ptr] == t[t_ptr]:
                s_ptr += 1
                if s_ptr == len(s):
                    return True
            t_ptr += 1

        return False

# Dynamic Programming Approach Beats 95 % Users

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        nxt = [{} for _ in range(len(t) + 1)]
        for i in range(len(t) - 1, -1, -1):
            nxt[i] = nxt[i + 1].copy()
            nxt[i][t[i]] = i + 1

        i = 0
        for c in s:
            if c in nxt[i]:
                i = nxt[i][c]
            else:
                return False
        return True

'''
this is simple explanation how DP Approach works


Input: s = "abc", t = "ahbgdc"

1. Initialize `nxt` as a list of dictionaries, each corresponding to a position in `t`. `nxt` initially looks like this:

   ```
   nxt = [{}, {}, {}, {}, {}, {}, {}]
   ```

   Each dictionary will be used to store characters and their next occurrence indices.

2. Loop through the characters in `t` in reverse order (from the end to the beginning):

   a. Start with `i = 5` (the index of the last character in `t`, which is 'c').

   b. For the character 'c' at index 5, update `nxt[5]` as follows:

      ```
      nxt[5] = {'c': 6}
      ```

   c. Move to the next character 'd' at index 4 and update `nxt[4]`:

      ```
      nxt[4] = {'d': 5}
      ```

   d. Continue this process for the rest of the characters in `t`:

      ```
      nxt[3] = {'g': 4}
      nxt[2] = {'b': 3}
      nxt[1] = {'h': 2}
      nxt[0] = {'a': 1}
      ```

   After this loop, `nxt` will be populated with dictionaries mapping each character to its next occurrence index.

3. Initialize `i` to 0. This will be used to traverse the string `t`.

4. Now, loop through the characters in `s`:

   a. For the first character in `s`, which is 'a', check if it exists in `nxt[0]`. It does, and `nxt[0]['a']` is 1. Update `i` to 1.

   b. For the second character in `s`, which is 'b', check if it exists in `nxt[1]`. It does, and `nxt[1]['b']` is 3. Update `i` to 3.

   c. For the third character in `s`, which is 'c', check if it exists in `nxt[3]`. It does, and `nxt[3]['c']` is 6. Update `i` to 6.

5. After processing all characters in `s`, we find that `i` is equal to the length of `t`, which is 7. This means that we successfully found all characters in `s` in the correct order within `t`, so we return `True`.

The code returns `True` because the characters "abc" are indeed a subsequence of "ahbgdc" in the given order. The algorithm efficiently uses the `nxt` data structure to keep track of the next occurrence of each character in `t`, making it a very efficient way to solve the subsequence problem.

'''

