// Non optimized 3d DP
class Solution {
public:
      int solve(int index, bool allowed, vector<int>& prices, int limit ,vector<vector<vector<int>>>& memo) {
        if (index == prices.size() || limit==0)
            return 0;

        if (memo[index][allowed][limit] != -1)
            return memo[index][allowed][limit];

        int profit = 0;
        if (allowed) {
            int include = -prices[index] + solve(index + 1, !allowed, prices,limit , memo);
            int exclude = solve(index + 1, allowed, prices,limit , memo);
            profit = max(include, exclude);
        } else {
            int sell = prices[index] + solve(index + 1, !allowed, prices,limit-1, memo);
            int notsell = solve(index + 1, allowed, prices, limit ,memo);
            profit = max(sell, notsell);
        }

        return memo[index][allowed][limit]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,true,prices,2,memo);
    }
};


/* optimized to 2d DP again */

class Solution {
public:
    int solve(int ind,int trans,int n,vector<int> &prices,vector<vector<int>> &dp)
    {
        if(ind == n || trans == 4)
        return 0;

        if(dp[ind][trans] != -1)
        return dp[ind][trans];

        int profit = 0;
        if(trans%2 == 0)
        {
            profit = max(-prices[ind] + solve(ind+1,trans+1,n,prices,dp),0 + solve(ind+1,trans,n,prices,dp));
        }
        else
        {
            profit = max(prices[ind] + solve(ind+1,trans+1,n,prices,dp),0 + solve(ind+1,trans,n,prices,dp));
        }

        return dp[ind][trans] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(0,0,n,prices,dp);
    }
};

// A clever way

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(3, 0), cost(3, prices[0]);
        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= 2; k++) {
                cost[k] = min(cost[k], prices[i] - dp[k - 1]);
                dp[k] = max(dp[k], prices[i] - cost[k]);
            }
        }
        return dp[2];
    }
};

// a more clever way

#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int max_profit_v5(const std::vector<int>& prices) {
        // Represents the maximum profit after the first buy
        int buy1 = std::numeric_limits<int>::min();
        // Represents the maximum profit after the first sell
        int sell1 = 0;
        // Represents the maximum profit after the second buy
        int buy2 = std::numeric_limits<int>::min();
        // Represents the maximum profit after the second sell
        int sell2 = 0;

        for (int price : prices) {
            // Update in the correct order
            buy1 = std::max(buy1, -price);          // Maximum profit after first buy
            sell1 = std::max(sell1, buy1 + price);  // Maximum profit after first sell
            buy2 = std::max(buy2, sell1 - price);   // Maximum profit after second buy
            sell2 = std::max(sell2, buy2 + price);  // Maximum profit after second sell
        }

        return sell2;
    }
};
