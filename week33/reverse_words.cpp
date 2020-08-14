class Solution {
public:
    string reverseWords(string s) {
        string res, tmp;
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (!tmp.empty()) {
                    reverse(begin(tmp), end(tmp));
                    if (!res.empty()) res += " ";
                    res += tmp;
                    tmp.clear();
                }
            } else {
                tmp.push_back(s[i]);
            }
        }
        if (!tmp.empty()) {
            reverse(begin(tmp), end(tmp));
            if (!res.empty()) res += " ";
            res += tmp;
        }
        return res;
    }
};