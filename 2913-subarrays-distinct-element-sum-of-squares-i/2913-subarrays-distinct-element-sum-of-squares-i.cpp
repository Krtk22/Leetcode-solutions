class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            set<int> temp;
            for(int j = i; j < n; j++) {
                temp.insert(nums[j]);
                int val = temp.size();
                ans += (val * val);
            }
        }

        return ans;
    }
};