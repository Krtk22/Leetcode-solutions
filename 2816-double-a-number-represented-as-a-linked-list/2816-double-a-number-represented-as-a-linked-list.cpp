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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr -> next; // Store next node
            curr -> next = prev;      // Reverse current pointer
            prev = curr;           // Move prev forward
            curr = next;           // Move curr forward
        }
        return prev; // New head

    }

    ListNode* doubleIt(ListNode* head) {
    
        ListNode* newList = reverseList(head);
        
        int carry = 0;
        ListNode* temp = newList;
        ListNode* last = nullptr;

        while(temp != NULL) {

            int value = temp->val * 2 + carry;
            temp->val = value % 10;
            carry = value / 10;

            last = temp;
            temp = temp->next;
        }
        if(carry != 0) {
            last -> next = new ListNode(carry);
        }

        return reverseList(newList);
    }
};