class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int, int>>(m, {0,0}));
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    res = 0;
                    dp[i][j].first = i > 0 ? dp[i-1][j].first + 1 : 1;
                    dp[i][j].second = j > 0 ? dp[i][j-1].second + 1 : 1;
                }
            }
        }
        if (res < 0) return 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = res; i+k<n&&j+k<m; k++) {
                        if (dp[i+k][j+k].first >= k+1 && dp[i+k][j+k].second >= k+1 &&
                            dp[i][j+k].second >= k+1 && dp[i+k][j].first >= k+1)
                            res = k;
                    }
                }
            }
        }
        return (res+1)*(res+1) ;
    }
};