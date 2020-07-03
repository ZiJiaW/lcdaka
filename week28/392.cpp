class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        int i = 0, j = 0;
        while (j < t.size()) {
            if (t[j] == s[i]) {
                if (++i == s.size())
                    break;
            }
            j++;
        }
        return i==s.size();
    }
};