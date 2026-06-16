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
    int maxSum = -1001;
    int maxH(TreeNode *root) {
        int leftSum = 0;
        int rightSum = 0;
        if (root->left) {
            leftSum = maxH(root->left);
            if (leftSum < 0) {
                leftSum = 0;
            }
        }
        if (root->right) {
            rightSum = maxH(root->right);
            if (rightSum < 0) {
                rightSum = 0;
            }
        }
        int res = root->val + leftSum + rightSum;
        if (res > maxSum) {
            maxSum = res;
        }
        res = max(res - leftSum, res - rightSum);
        return res;
    }
    int maxPathSum(TreeNode* root) {
        maxH(root);
        return maxSum;
    }
};
