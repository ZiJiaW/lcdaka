class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        while (!s.empty() && s.back() == ' ') s.pop_back();
        int res = 0;
        for (auto i = rbegin(s); i != rend(s) && *i != ' '; i++) res++;
        return res;
    }
};