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
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode *first = head;
        ListNode *last = head;
        for (int i = 0; i < n; i++) {
            last = last->next;
        }
        while (last && last->next) {
            last = last->next;
            first = first->next;
        }
        if (!last && first == head) {
            return head->next;
        }
        first->next = first->next->next;
        return head;
    }
};
