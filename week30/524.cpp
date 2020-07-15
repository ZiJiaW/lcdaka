class Solution {
    int match(const string& s, const string& a) {
        if (a.size() > s.size()) return -1;
        int i = 0, j = 0;
        while (i < s.size()) {
            if (s[i++] == a[j]) j++;
            if (j == a.size()) return a.size();
        }
        return -1;
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        int res = -1;
        int maxLen = 0;
        for (int i = 0; i < d.size(); i++) {
            int t = match(s, d[i]);
            if (t > maxLen) {
                maxLen = t;
                res = i;
            } else if (t == maxLen && d[i] < d[res]) {
                res = i;
            }
        }
        return res < 0 ? "" : d[res];
    }
};