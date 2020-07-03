class Solution {
    int cost(char from, char to) {
        if (from == 26) return 0;
        return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<vector<int>>> dp(26, vector<vector<int>>(26, vector<int>(n, 0)));
        function<int(int, int, int)> dfs = [&](int l, int r, int pos) -> int {
            if (pos == n) return 0;
            if (dp[l][r][pos] == 0) {
                int next = word[pos] - 'A';
                dp[l][r][pos] = min(cost(l, next) + dfs(next, r, pos+1),
                                    cost(r, next) + dfs(l, next, pos+1));
            }
            return dp[l][r][pos];
        };
        int res = INT_MAX;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                res = min(res, dfs(i, j, 0));
            }
        }
        return res;
    }
};