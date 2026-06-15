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
    bool isValid(TreeNode* root, int low, int high) {
        if (!root) {
            return true;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if (root->val <= low || root->val >= high) {
            return false;
        }
        if (left && (left->val <= low || left->val >= root->val || left->val >= high)) {
            return false;
        }
        if (right && (right->val <= low || right->val <= root->val || right->val >= high)) {
            return false;
        }
        return isValid(left, low, root->val) && isValid(right, root->val, high);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, -1001, 1001);
    }
};
