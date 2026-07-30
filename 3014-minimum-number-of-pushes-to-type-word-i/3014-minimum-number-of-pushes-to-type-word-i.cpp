class Solution {
    // BRUTE FORCE
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n <= 8) return n;

        int push = 0;
        for(int i = 0; i < n; i++) {
            if(i <= 7) push += 1;
            if(i > 7 && i <= 15) push += 2;
            if(i > 15 && i <= 23) push += 3;
            if(i > 23) push += 4;
        }

        return push;
    }
};