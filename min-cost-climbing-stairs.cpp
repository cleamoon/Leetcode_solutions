class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> dp(cost.size()+1, INT_MAX);
        dp[0] = 0;
        dp[1] = cost[0];
        for (int i = 1; i < cost.size(); i++) {
            dp[i+1] = min(dp[i], dp[i-1]) + cost[i];
        }
        return dp[cost.size()];
    }
};
