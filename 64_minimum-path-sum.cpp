/*
 Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 200
    0 <= grid[i][j] <= 200

*/

 class Solution{
    public:
     int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        dp[0][0] = grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 && j == 0) continue;
                int up = 1e9, left = 1e9;
                if(i > 0) up = grid[i][j] + dp[i - 1][j];
                if(j > 0) left = grid[i][j] + dp[i][j-1];

                dp[i][j] = min(up, left);
                }
            }

        return dp[n-1][m - 1];
    }
};

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Create a DP array with extra row and column initialized to INT_MAX
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        // Set the base case: the "cell" just after the bottom-right corner
        dp[m][n - 1] = 0;

        // Fill the DP array
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        // The top-left corner contains the minimum path sum
        return dp[0][0];
    }
};

