class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // using prefix array concept
        vector<int> maxEle(n, 0);
        vector<int> minEle(n, 0);

        // filling max element array
        maxEle[0] = nums[0];
        for(int i = 1; i < n; i++) {
            maxEle[i] = max(maxEle[i - 1], nums[i]);
        }
        // filling min element
        minEle[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            minEle[i] = min(minEle[i + 1], nums[i]);
        }
        int result = INT_MAX;
        for(int i = 0; i < n; i++) {
            int temp = maxEle[i] - minEle[i];
            if(temp <= k) {
                result = min(result, i);
            }
        }
        return (result == INT_MAX) ? -1 : result;
    }
};