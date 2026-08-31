/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // JUST stimulate it
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        // Checking edge case
        vector<int> ans = {-1, -1};
        if(!head || !head -> next || !head -> next -> next) return ans;

        vector<int> criticalIndices;

        int index = 1;
        ListNode* prev = head;
        ListNode* curr = head -> next;

        // Finding critical indices
        while(curr -> next) {
            index++;
            int nextVal = curr -> next -> val;
            
            if ((curr->val > prev->val && curr->val > nextVal) || (curr->val < prev->val && curr->val < nextVal)) {
                criticalIndices.push_back(index);
            }
            
            prev = curr;
            curr = curr -> next;
        } 

        if (criticalIndices.size() < 2) return ans;

        // Computing min distance
        int minDist = INT_MAX;
        for (int i = 1; i < criticalIndices.size(); i++) {
            minDist = min(minDist, criticalIndices[i] - criticalIndices[i-1]);
        }

        // Max distance = last - first
        int maxDist = criticalIndices.back() - criticalIndices.front();

        ans[0] = minDist;
        ans[1] = maxDist;
        
        return ans;
    }
};