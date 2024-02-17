class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        vector<vector<string>>ans;
        for(string& m:strs)
        {
            string sorted=m;
            sort(sorted.begin(),sorted.end());
            map[sorted].push_back(m);
        }
        for(auto& [_,x]:map)
        {
            ans.push_back(move(x));  // moves the ownership of x 
        }
        return ans;
    }
};
