/*
 
   Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character



Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')



Constraints:

    0 <= word1.length, word2.length <= 500
    word1 and word2 consist of lowercase English letters.


 */

class Solution {
public:
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        // Check if the result for the current state has been computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // If we have reached the end of string 'a', the only option is to insert all remaining characters of 'b'
        if (i == a.length()) {
            dp[i][j] = b.length() - j;
            return dp[i][j];
        }

        // If we have reached the end of string 'b', the only option is to delete all remaining characters of 'a'
        if (j == b.length()) {
            dp[i][j] = a.length() - i;
            return dp[i][j];
        }

        // If characters match, move to the next characters in both strings
        if (a[i] == b[j]) {
            dp[i][j] = solve(a, b, i + 1, j + 1, dp);
        } else {
            // Calculate the cost of insertion, deletion, and replacement
            int insert = 1 + solve(a, b, i, j + 1, dp);
            int del = 1 + solve(a, b, i + 1, j, dp);
            int replace = 1 + solve(a, b, i + 1, j + 1, dp);
            dp[i][j] = min(insert, min(del, replace));
        }

        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};

