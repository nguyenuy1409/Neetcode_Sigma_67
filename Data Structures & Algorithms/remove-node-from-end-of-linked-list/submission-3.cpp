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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        while(n > 0) {
            n--;
            right=right->next;
        }

        while(right!=nullptr) {
            right=right->next;
            left=left->next;
        }

        ListNode* toDelete = left->next;
        left->next=left->next->next;
        delete toDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
