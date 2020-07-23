class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int c[26] = {0};
        for (auto x : letters) c[x-'a']++;
        vector<vector<int>> w(words.size(), vector<int>(26, 0));
        for (int i = 0; i < words.size(); i++) {
            for (auto c : words[i]) w[i][c-'a']++;
        }
        int res = 0;
        int t[26] = {0};
        function<void(int)> dfs = [&](int i) {
            for (int k = 0; k < 26; k++) {
                if (t[k] > c[k]) return;
            }
            if (i == words.size()) {
                int s = 0;
                for (int k = 0; k < 26; k++) {
                    s += t[k]*score[k];
                }
                if (s > res) res = s;
                return;
            }
            dfs(i+1);
            for (int k = 0; k < 26; k++) t[k] += w[i][k];
            dfs(i+1);
            for (int k = 0; k < 26; k++) t[k] -= w[i][k];
        };
        dfs(0);
        return res;
    }
};