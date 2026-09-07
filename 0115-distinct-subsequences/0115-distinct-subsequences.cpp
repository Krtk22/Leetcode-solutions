class Solution {
public:
    typedef unsigned long long ull;

    // MEMOIZATION
    // ull dp[1001][1001];

    // ull solve(string s, string t, int m, int n) {
        
    //     if(n == 0) return dp[m][n] = 1; // found 1 sub sequence
    //     if(m == 0) return dp[m][n] = 0; // s string exhausted

    //     if(dp[m][n] != -1) return dp[m][n];

    //     if(s[m - 1] == t[n - 1]) {
    //         return dp[m][n] = solve(s, t, m - 1, n - 1) + solve(s, t, m - 1, n);
    //     } else {
    //         return dp[m][n] = solve(s, t, m - 1, n);
    //     }

    //     // we need to return something for the function(DUMMY STATEMENT/ NOT REACHABLE)
    //     return -1;
    // }

    int numDistinct(string s, string t) {
        
        // TABULATION
        int m = s.size();
        int n = t.size();

        vector<vector<ull>> dp(m + 1, vector<ull>(n + 1));

        for(int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++) {
            dp[0][i] = 0;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
        
    }
};