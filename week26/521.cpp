class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.size() != b.size()) return max(a.size(), b.size());
        else if (a == b) return -1;
        else return a.size();
    }
};