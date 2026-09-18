class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int> check;
        int n = nums.size();

        for(int i = 1; i < n; i++) {
            int sum = nums[i] + nums[i - 1];

            if(check.find(sum) != check.end()) {
                return true;
            }
            check.insert(sum);
        }
        return false;
    }
};