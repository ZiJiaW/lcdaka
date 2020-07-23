class Solution {
    int dfs(string& puzzle, int mask, int i, map<int, int> &m) {
        if (i == 7) {
            auto i = m.find(mask);
            return i == m.end() ? 0 : i->second;
        }
        return dfs(puzzle, mask, i+1, m) + dfs(puzzle, mask | (1<<(puzzle[i]-'a')), i+1, m);
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> res(puzzles.size(), 0);
        map<int, int> m;
        for (int i = 0; i < words.size(); i++) {
            int t = 0;
            for (auto c : words[i]) t |= 1 << (c-'a');
            m[t]++;
        }
        for (int i = 0; i < puzzles.size(); i++) {
            res[i] += dfs(puzzles[i], 1<<(puzzles[i][0]-'a'), 1, m);
        }
        return res;
    }
};