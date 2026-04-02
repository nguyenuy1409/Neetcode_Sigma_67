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
        int size = 0;
        ListNode* tmp = head;
        while(tmp!= nullptr) {
            size++;
            tmp=tmp->next;
        }
        int targetNode = (size - n) + 1;
        if (targetNode == 1) return head->next;
        ListNode* deleteNode = head;
        ListNode* prevNode = nullptr;
        int currNode = 1;
        while(deleteNode != nullptr) {
            if(currNode == targetNode) {
                prevNode->next = deleteNode->next;
                deleteNode->next = nullptr;
                delete deleteNode;
                break;
            }
            currNode++;
            prevNode = deleteNode;
            deleteNode=deleteNode->next;
        }
        return head;
    }
};
