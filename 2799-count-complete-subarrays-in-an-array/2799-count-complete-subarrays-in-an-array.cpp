class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        int n = nums.size();

        // Taking set for distinct elements
        set<int> distinctEle(nums.begin(), nums.end());

        int distEle = distinctEle.size();


        // Double loop
        int count = 0;
        for(int i = 0; i < n; i++) {
            set<int> temp;
            for(int j = i; j < n; j++) {
                temp.insert(nums[j]);
                if(temp.size() == distEle) count++;
            }
        }

        return count;

    }
};