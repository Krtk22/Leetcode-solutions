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
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;

        // middle point
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // reverse the second half (starting from slow->next)
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; // Cut the connection to split the two halves

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // merging
        ListNode* first = head;
        ListNode* second = prev; // 'prev' is now the head of the reversed second half

        while (second != nullptr) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;    // Link first to second
            second->next = t1;       // Link second to the rest of the first half

            first = t1;              // Move forward
            second = t2;
        }

        return;
    }
};


