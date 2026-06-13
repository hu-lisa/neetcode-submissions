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
        if (!head || !head->next) {
            return;
        }
        stack<ListNode*> st;
        ListNode *curr = head;
        while (curr) {
            st.push(curr);
            curr = curr->next;
        }
        curr = head;
        while (true) {
            if (curr == st.top() || curr->next == st.top()) {
                st.top()->next = nullptr;
                break;
            }
            ListNode *next = curr->next;
            curr->next = st.top();
            st.pop();
            curr->next->next = next;
            curr = next;
        }
    }
};
