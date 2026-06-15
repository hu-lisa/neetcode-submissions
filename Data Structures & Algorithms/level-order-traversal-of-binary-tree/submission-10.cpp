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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> row;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr) {
                    row.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            if (!row.empty()) {
                res.push_back(row);
            }
        }
        return res;
    }
};
