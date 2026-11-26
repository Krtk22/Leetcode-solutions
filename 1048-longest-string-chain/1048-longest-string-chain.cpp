class Solution {
public:
    // function for stringmatching
    bool stringMatch(string a, string b) {
        int m = a.size();
        int n = b.size();

        int i = 0;
        int j = 0;

        while(i < m && j < n) {
            if(a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == m;
    }

    // MEMOIZATION
    int solve(vector<string>& words, vector<vector<int>>& m, int p, int i) {

        if(i >= words.size()) return 0;

        if(p != -1 && m[i][p + 1] != -1) return m[i][p + 1];

        int take = 0;
        if(p == -1 || ((words[p].size() + 1 == words[i].size()) && stringMatch(words[p], words[i])) ) {
            take = 1 + solve(words, m, i, i + 1);
        }

        int skip = solve(words, m, p, i + 1);

        return m[i][p + 1] = max(take, skip);
    }

    // TABULATION
    int longestStrChain(vector<string>& words) {
        
        // sorting on the basis of length
        sort(words.begin(), words.end(), [](string a, string b) {
            if(a.length() == b.length())
                return a < b;

            return a.length() < b.length();
        });

        int n = words.size();
        vector<int> t(n, 1);

        int chain = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(((words[j].size() + 1 == words[i].size()) && stringMatch(words[j], words[i]))) {
                    t[i] = max(t[i], t[j] + 1);
                    chain = max(chain, t[i]);
                }
            }
        }

        return chain;
    }
};