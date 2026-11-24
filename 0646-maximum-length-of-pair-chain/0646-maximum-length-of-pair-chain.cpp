
class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& pairs, int i, int p) {
        if(i == pairs.size()) return 0;

        if(dp[i][p + 1] != -1) return dp[i][p + 1];

        int take = 0;

        if(p == -1 || pairs[i][0] > pairs[p][1]) {
            take = 1 + solve(dp, pairs, i + 1, i);
        }

        int not_take = solve(dp, pairs, i + 1, p);

        return dp[i][p + 1] = max(take, not_take);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs));

        int n = pairs.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(dp, pairs, 0, -1);
    }
};
