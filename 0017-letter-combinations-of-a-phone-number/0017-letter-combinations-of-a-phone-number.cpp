class Solution {
public:
    unordered_map<char, string> keys = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    void backtrack(string& digits, int index, string current, vector<string>& ans) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }
        for (char ch : keys[digits[index]]) {
            backtrack(digits, index + 1, current + ch, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;
        backtrack(digits, 0, "", ans);
        return ans;
    }
};
