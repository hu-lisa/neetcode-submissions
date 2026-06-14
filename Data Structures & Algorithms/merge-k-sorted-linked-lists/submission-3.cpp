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
    ListNode* mergeTwo(ListNode *a, ListNode *b) {
        struct ListNode dummy(0);
        ListNode *curr = &dummy;
        while (a && b) {
            if (a->val < b->val) {
                curr->next = a;
                a = a->next;
            } else {
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }
        if (a) {
            curr->next = a;
        }
        if (b) {
            curr->next = b;
        }
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return nullptr;
        }
        for (int i = 1; i < n; i++) {
            lists[i] = mergeTwo(lists[i-1], lists[i]);
        }
        return lists[n-1];
    }
};
