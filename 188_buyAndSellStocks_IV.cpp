/*
 
   You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

 */

class Solution {
public:
    int solve(int index, bool allowed, vector<int>& prices, int limit, vector<vector<vector<int>>>& memo) {
        if (index == prices.size() || limit == 0)
            return 0;

        if (memo[index][allowed][limit] != -1)
            return memo[index][allowed][limit];

        int profit = 0;
        if (allowed) {
            // We can either buy the stock or skip this day
            int include = -prices[index] + solve(index + 1, !allowed, prices, limit, memo);
            int exclude = solve(index + 1, allowed, prices, limit, memo);
            profit = max(include, exclude);
        } else {
            // We can either sell the stock or skip this day
            int sell = prices[index] + solve(index + 1, !allowed, prices, limit - 1, memo);
            int notsell = solve(index + 1, allowed, prices, limit, memo);
            profit = max(sell, notsell);
        }

        return memo[index][allowed][limit] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // Allocate memoization table with size (n) x (2) x (k + 1)
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, true, prices, k, memo);
    }
};

