/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int count = 0;
        TreeNode *curr = root;
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        while (count < k) {
            TreeNode *node = st.top();
            st.pop();
            count++;
            if (count == k) {
                return node->val;
            }
            if (node->right) {
                curr = node->right;
                while (curr) {
                    st.push(curr);
                    curr = curr->left;
                }
            }
        }
        return 0;
    }
};
