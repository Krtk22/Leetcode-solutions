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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // Doing it with one pointer and in built GCD function

        if (head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head;

        // Traverse while there is a pair of nodes to process
        while (curr != nullptr && curr->next != nullptr) {
            // GCD
            int gcdVal = gcd(curr->val, curr->next->val);
            ListNode* temp = new ListNode(gcdVal);

            // Insertion
            temp->next = curr->next;
            curr->next = temp;

            // Move
            curr = temp->next; 
        }

        return head;
        
    }
};