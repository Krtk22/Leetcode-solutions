class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        vector<int> temp;
        for(int& it : nums) {
            temp.push_back(abs(it));
        }

        sort(begin(temp), end(temp));

        int n = temp.size();
        int l = 0;
        int r = n - 1;
        long long ans = 0;
        
        while(l < r) {
            ans += 1LL * temp[r] * temp[r];
            ans -= 1LL * temp[l] * temp[l];
            l++;
            r--;
        }
        if (l == r) {
            ans += 1LL * temp[l] * temp[l];
        }


        return ans;
    }
};