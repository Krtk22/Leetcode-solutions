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
    int solve(ListNode* head) {
        if(head == nullptr) {
            return 0;
        }
        int carry = solve(head -> next);

        int val = (head -> val) * 2 + carry;
        
        head -> val = val % 10;
        carry = val / 10;
        return carry;
    }
    

    ListNode* doubleIt(ListNode* head) {
        ListNode* newList = head;

        int temp = solve(newList);
        if(temp == 0) return head;

        ListNode* dummy = new ListNode(temp);
        dummy -> next = head;
        return dummy;

    }
};