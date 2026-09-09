class Solution {
    // OPTIMIZATION(Sliding window + hashmap)
public:
    int countCompleteSubarrays(vector<int>& nums) {

        int n = nums.size();

        // Taking set for distinct elements
        unordered_set<int> distinctElement(nums.begin(), nums.end());

        int totalDistinctElement = distinctElement.size();


        unordered_map<int, int> freq;
        int count = 0;
        int left = 0;

        for(int right = 0; right < n; right++) {
            freq[nums[right]]++;

            // Shrink window until it has all distinct elements
            while(freq.size() == totalDistinctElement) {
                // Every subarray starting at left and ending at right…n-1 is valid
                count += n - right;

                // Remove nums[left] and move left forward
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
                    left++;
            }
        }

        return count;

    }
};