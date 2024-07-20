/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/


    

class Solution {
public:
    int dp[301]; // Assuming max length of s is 300 as per constraints
    
    int helper(int i, string& s, set<string>& wordDict) {
        // Base case: if we have reached the end of the string
        if (i == s.size())
            return 1;

        // Check if we have already computed the result for this index
        if (dp[i] != -1)
            return dp[i];

        string temp;
        // Try to break the string into all possible substrings starting from index i
        for (int j = i; j < s.size(); j++) {
            temp += s[j];
            // If the current substring is in the dictionary
            if (wordDict.find(temp) != wordDict.end()) {
                // Check if the remaining string can be segmented
                if (helper(j + 1, s, wordDict)) {
                    return dp[i] = 1;
                }
            }
        }

        // If no valid segmentation found, return 0
        return dp[i] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return helper(0, s, st);
    }
};

