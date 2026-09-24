class Solution {
public:

    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;  // add last digit
            n /= 10;        // remove last digit
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int sum = digitSum(nums[i]);
            if(sum == i) return i;
        }
        return -1;
    }
};