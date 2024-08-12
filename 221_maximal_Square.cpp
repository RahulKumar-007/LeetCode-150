class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=0;

        // convert the char to int 
          for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                  dp[i][j]=m[i][j]-'0';
                  if(dp[i][j]==1) ans=1;
            }
        }

        for (int i = 1; i < m.size(); i++) {
            for (int j = 1; j < m[0].size(); j++) {
                if(dp[i][j]==1){
                  dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]); // checking if all 3 neightbours have 1 
                  ans=max(ans,dp[i][j]*dp[i][j])     // calculate max area
            }
        }
    }
};
