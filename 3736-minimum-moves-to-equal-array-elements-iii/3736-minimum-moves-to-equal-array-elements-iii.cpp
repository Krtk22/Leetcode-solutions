class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxEle = nums[n - 1];

        for(int i = 0; i < n-1; i++) {
            count += maxEle - nums[i];
        }

        return count;
    }
};