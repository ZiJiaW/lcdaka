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
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N%2 == 0) return {};
        if (N == 1) return {new TreeNode(0)};
        vector<TreeNode*> res;
        for (int L = 1; L <= N/2; L += 2) {
            auto left = allPossibleFBT(L);
            auto right = L == N-1-L ? left : allPossibleFBT(N-1-L);
            for (auto l : left) {
                for (auto r : right) {
                    res.push_back(new TreeNode(0, l, r));
                    if (L != N-1-L) res.push_back(new TreeNode(0, r, l));
                }
            }
        }
        return res;
    }
};