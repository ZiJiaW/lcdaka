class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> m;
        int res = 0;
        vector<int> c(26, 0);
        for (int i = 0; i < s.size() - minSize + 1; i++) {
            string t(s.substr(i, minSize));
            int count = 0;
            fill(begin(c), end(c), 0);
            for (auto ch : t) {
                if (++c[ch-'a'] == 1) count++;
            }
            if (count <= maxLetters) {
                if ((count = ++m[t]) > res) res = count;
            }
        }
        return res;
    }
};