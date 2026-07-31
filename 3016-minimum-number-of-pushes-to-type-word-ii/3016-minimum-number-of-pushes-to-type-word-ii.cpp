class Solution {
public:
    // USING HASHMAP
    int minimumPushes(string word) {
        int n = word.size();
        if(n <= 8) return n;

        unordered_map<char, int> freq;
        for (char ch : word) {
            freq[ch]++;
        }

        vector<int> counts;
        for (auto& [ch, val] : freq) {
            counts.push_back(val);
        }

        sort(counts.rbegin(), counts.rend()); // sort descending

        int total = 0;
        for (int i = 0; i < counts.size(); i++) {
            int cost = min(4, i / 8 + 1); // batch cost
            total += counts[i] * cost;
        }

        return total;
    }
};