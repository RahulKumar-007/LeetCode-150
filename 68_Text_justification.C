/*
 Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

*/


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        while (i < words.size()) {
            int count = 0, totalWords = 0;
            vector<string> line;

            // Counting the number of words that can fit in a line
            while (i < words.size() && count + words[i].size() + totalWords <= maxWidth) {
                line.push_back(words[i]);
                count += words[i].size();
                totalWords++;
                i++;
            }

            // Calculate the remaining spaces to distribute
            int remainingSpaces = maxWidth - count;

            // If it's the last line or only one word in the line, left justify
            if (i == words.size() || totalWords == 1) {
                string temp = "";
                for (int j = 0; j < line.size(); j++) {
                    temp += line[j];
                    if (j != line.size() - 1)
                        temp += " ";
                }
                while (temp.size() < maxWidth) temp += " ";
                ans.push_back(temp);
                continue;
            }

            // Distribute spaces evenly between words
            int eachSpace = remainingSpaces / (totalWords - 1);
            int extraSpaces = remainingSpaces % (totalWords - 1);

            string temp = "";
            for (int j = 0; j < line.size(); j++) {
                temp += line[j];
                if (j != line.size() - 1) {
                    int spaces = eachSpace + (j < extraSpaces ? 1 : 0);
                    temp.append(spaces, ' ');
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

