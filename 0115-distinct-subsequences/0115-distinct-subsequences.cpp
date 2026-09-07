class Solution {
    // MEMOIZATION
public:
    typedef unsigned long long ull;

    ull dp[1001][1001];

    ull solve(string s, string t, int m, int n) {
        
        if(n == 0) return dp[m][n] = 1; // found 1 sub sequence
        if(m == 0) return dp[m][n] = 0; // s string exhausted

        if(dp[m][n] != -1) return dp[m][n];

        if(s[m - 1] == t[n - 1]) {
            return dp[m][n] = solve(s, t, m - 1, n - 1) + solve(s, t, m - 1, n);
        } else {
            return dp[m][n] = solve(s, t, m - 1, n);
        }

        // we need to return something for the function(DUMMY STATEMENT/ NOT REACHABLE)
        return -1;
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        memset(dp, -1, sizeof(dp));

        return solve(s, t, m, n);
    }
};