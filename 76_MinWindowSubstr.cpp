/*
 Given two strings s and t of lengths m and n respectively, return the minimum window
substring
of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

 

Constraints:

    m == s.length
    n == t.length
    1 <= m, n <= 105
    s and t consist of uppercase and lowercase English letters.

 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/



class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::unordered_map<char, int> charCount;
        for (char c : t) {
            charCount[c]++;
        }

        int requiredCount = t.length();
        int i = 0, j = 0;
        int minLength = INT_MAX;
        int minStartIndex = 0;

        while (j < s.length()) {
            char currentChar = s[j];
            if (charCount.find(currentChar) != charCount.end()) {
                charCount[currentChar]--;
                if (charCount[currentChar] >= 0) {
                    requiredCount--;
                }
            }
            j++;

            while (requiredCount == 0) {
                if (j - i < minLength) {
                    minStartIndex = i;
                    minLength = j - i;
                }

                char charAtI = s[i];
                if (charCount.find(charAtI) != charCount.end()) {
                    charCount[charAtI]++;
                    if (charCount[charAtI] > 0) {
                        requiredCount++;
                    }
                }
                i++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        } else {
            return s.substr(minStartIndex, minLength);
        }
    }
};

