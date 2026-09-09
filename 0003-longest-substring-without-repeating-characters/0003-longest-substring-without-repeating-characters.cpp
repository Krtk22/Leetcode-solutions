class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0, maxLen = 0;
        int n = s.size();
        unordered_map<char, int> mpp;
        for(int r = 0; r < n; r++) {
            char ch = s[r];
            if(mpp.count(ch)) {
                l = max(l, mpp[ch] + 1);
            }
            mpp[ch] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};