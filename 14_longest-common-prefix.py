'''
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

'''

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans=""
        a=len(strs)-1
        strs.sort()
        first=strs[0]
        last=strs[a]
        c=min(len(first),len(last))
        for i in range(c):
            if first[i]==last[i]:
                ans+=first[i]
            else:
                break
        return ans


