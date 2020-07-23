class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hs;
        vector<string> res;
        if (s.size() <= 10) return res;
        for (int i = 0; i < s.size() - 9; i++) {
            hs[s.substr(i, 10)]++;
            if (hs[s.substr(i, 10)] == 2) res.push_back(s.substr(i, 10));
        }
        return res;
    }
};