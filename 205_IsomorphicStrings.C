/*
 Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

 

Constraints:

    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.


    */

class Solution {
public:
    bool isIso(string s,string t)
    {
        unordered_map<char,char> mp;
        for(int i=0;i<s.length();i++)
        {
           if(mp.find(s[i])==mp.end())
           {
               mp[s[i]]=t[i];
               cout<<s[i]<<mp[s[i]]<<endl;
           }
           else
           {
               char p=mp[s[i]];
               if(p==t[i]) continue;
               else return false;
            }
           }

        return true;
    }
    bool isIsomorphic(string s, string t) {
        bool a=isIso(s,t);
        bool b= isIso(t,s);
        return a && b;

    }
};
