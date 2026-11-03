class Solution {
public:
    // MEMOIZATION
    int solve(vector<int>& dp, vector<int>& cost, int i) {

        if(i >= cost.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int oneStep = cost[i] + solve(dp, cost, i + 1);
        int twoStep = cost[i] + solve(dp, cost, i + 2);

        return dp[i] = min(oneStep, twoStep);
    
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        vector<int>dp(n + 1, -1);

        return min(solve(dp, cost, 0), solve(dp, cost, 1));
    }
};