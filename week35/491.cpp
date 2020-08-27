class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        function<void(int, vector<int>&)> dfs = [&](int i, vector<int>& tmp) {
            if (tmp.size() >= 2) res.insert(tmp);
            for (int j = i; j < nums.size(); j++) {
                if (tmp.empty() || tmp.back() <= nums[j]) {
                    tmp.push_back(nums[j]);
                    dfs(j+1, tmp);
                    tmp.pop_back();
                }
            }
        };
        vector<int> tmp;
        dfs(0, tmp);
        return vector<vector<int>>(res.begin(), res.end());
    }
};