class Solution {
public:
    int n;

    int solve(vector<vector<int>>& dp, vector<int>& nums, int i, int p) {
        if(i == n) return 0;

        if(p != -1 && dp[p][i] != -1) return dp[p][i];

        int take = 0;
        if(p == -1 || nums[p] < nums[i]) {
            take = 1 + solve(dp, nums, i + 1, i);
        }

        int not_take = solve(dp, nums, i + 1, p);

        if(p != -1) dp[p][i] = max(take, not_take);
        
        return max(take, not_take);

    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));

        return solve(dp, nums, 0, -1);
    }
};