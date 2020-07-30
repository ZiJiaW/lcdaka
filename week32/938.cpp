/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        int r = root->val > R ? 0 : rangeSumBST(root->right, L, R) + (root->val >= L ? root->val : 0);
        int l = root->val < L ? 0 : rangeSumBST(root->left, L, R);
        return r + l;
    }
};