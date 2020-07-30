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
    int res = 1;
    int dfs(TreeNode* t) {
        if (!t) return 0;
        int l = dfs(t->left);
        int r = dfs(t->right);
        if (t->left && t->val == t->left->val) l++;
        else l = 1;
        if (t->right && t->val == t->right->val) r++;
        else r = 1;
        res = max(res, l + r - 1);
        return max(l, r);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res-1;
    }
};