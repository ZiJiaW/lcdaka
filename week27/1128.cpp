class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<vector<int>> m(9, vector<int>(9, 0));
        for (auto &p : dominoes) {
            m[p[0]-1][p[1]-1]++;
        }
        int res = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = i+1; j < 9; j++) {
                int t = m[i][j]+m[j][i];
                if (t > 1) res += t*(t-1)/2;
            }
            if (m[i][i] > 1) res += m[i][i]*(m[i][i]-1)/2;
        }
        return res;
    }
};