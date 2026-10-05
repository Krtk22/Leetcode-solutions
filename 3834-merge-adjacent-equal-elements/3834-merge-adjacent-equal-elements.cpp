class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> stk;
        for (int num : nums) {
            long long curr = num;
            while (!stk.empty() && stk.top() == curr) {
                curr += stk.top();
                stk.pop();
            }
            stk.push(curr);
        }
        // Convert stack to vector (reverse order)
        vector<long long> ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};