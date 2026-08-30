class Solution {
public:
    // Just do what it asked
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minInd = min_element(begin(nums), end(nums)) - begin(nums);
        int maxInd = max_element(begin(nums), end(nums)) - begin(nums);

        int left = min(minInd, maxInd);
        int right = max(minInd, maxInd);

        return min({left + 1 + n - right, right + 1, n - left});
    }
};