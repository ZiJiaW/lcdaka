class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s({ root });
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (t == nullptr) {
                res.push_back(s.top()->val);
                s.pop();
            }
            else {
                if (t->right) s.push(t->right);
                s.push(t);
                s.push(nullptr);
                if (t->left) s.push(t->left);
            }
        }
        return res;
    }
};