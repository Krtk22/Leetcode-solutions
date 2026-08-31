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
    // USING PRIORITY QUEUE
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<int, vector<int>, greater<int>> pq;

        // Push all values from all lists
        for (auto node : lists) {
            while (node != nullptr) {
                pq.push(node->val);
                node = node->next;
            }
        }

        // If no nodes, return nullptr
        if (pq.empty()) return nullptr;

        // Build new sorted linked list
        ListNode* head = new ListNode(pq.top());
        pq.pop();
        ListNode* curr = head;

        while (!pq.empty()) {
            curr->next = new ListNode(pq.top());
            pq.pop();
            curr = curr->next;
        }

        return head;
    }
};