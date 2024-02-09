static const auto _ = [](){
  std::ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool ans=true;
        unordered_map<char,int>map;
        for(auto m:magazine)
        {
            map[m]++;
        }
        for(auto m:ransomNote)
        {
            if(map.find(m)==map.end())
            {
                ans=false;
            }
            else
            {
                if(map[m]<=0)
                {
                    ans=false;
                }
                else
                {
                    map[m]--;
                }
            }
        }
        return ans;
    }
};
