class Solution {
public:
    
    int solve(vector<vector<int>>& dp, string word1, string word2, int i, int j) {
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int m = word1.size();
        int n = word2.size();

        if(i == m) {
            return n - j; // word1 has been exhausted and word2 is still left
        } else if(j == n) {
            return m - i; // word2 has been exhausted and word1 is still left
        }

        if(word1[i] == word2[j]) {

            return dp[i][j] = solve(dp, word1, word2, i + 1, j + 1);
        
        } else {

            int replace = 1 + solve(dp, word1, word2, i + 1, j + 1); // replace
            int remove = 1 + solve(dp, word1, word2, i + 1, j); // delete       
            int insert = 1 + solve(dp, word1, word2, i, j + 1); // insert

            return dp[i][j] = min(replace, min(remove, insert));
        }

        return -1;
    }


    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));

        return solve(dp, word1, word2, 0, 0);
    }
};