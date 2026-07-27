// class Solution {
//     // RECURSIVE APPROACH
// public:
//     int solve(string s, int i, int j) {
//         // base case
//         if(i >= j) return 0;

//         if(s[i] == s[j]) {
//             return 0 + solve(s, i + 1, j - 1);
//         }

//         int ith_ele = solve(s,i + 1, j);
//         int jth_ele = solve(s,i, j - 1);

//         return 1 + min(ith_ele, jth_ele);
//     }

//     int minInsertions(string s) {
//         int n = s.size();
//         return solve(s, 0, n - 1);
//     }
// };

class Solution {
    // MEMOIZATION APPROACH
public:
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        // base case
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) {
            return dp[i][j] = 0 + solve(s, i + 1, j - 1, dp);
        }

        return dp[i][j] = 1 + min(solve(s,i + 1, j, dp), solve(s,i, j - 1, dp));
    }

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n - 1, dp);
    }
};