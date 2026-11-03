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

        // int n = cost.size();
        // vector<int>dp(n + 1, -1);

        // return min(solve(dp, cost, 0), solve(dp, cost, 1));

        // TABULATION
        int n = cost.size();
        vector<int>t(n + 1, 0);
        
        t[0] = 0;
        t[1] = 0;

        for(int i = 2; i <= n; i++) {
            t[i] = min(t[i - 1] + cost[i - 1], t[i - 2] + cost[i - 2]);
        }

        return t[n];
    }
};