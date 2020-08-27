class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res(strs.front());
        for (int i = 1; i < strs.size(); i++) {
            if (res.empty()) break;
            int j = 0;
            for (; j < res.size() && j < strs[i].size(); j++) {
                if (res[j] != strs[i][j]) {
                    break;
                }
            }
            res = res.substr(0, j);
        }
        return res;
    }
};