class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(res, root, 1);
        return res;
    }
    
    void dfs(vector<int>& res, TreeNode* p, int depth) {
        if (!p) return;
        if (res.size() < depth) {
            res.push_back(p->val);
        }
        dfs(res, p->right, depth + 1);
        dfs(res, p->left, depth + 1);
        return;
    }
};