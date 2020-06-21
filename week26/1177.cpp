class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<vector<int>> count(s.size(), vector<int>(26, 0));
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) count[i][s[i]-'a']++;
            else {
                for (int j = 0; j < 26; j++) count[i][j] = count[i-1][j];
                count[i][s[i]-'a']++;
            }
        }
        for (auto &q: queries) {
            int odds = 0;
            int l = q[0], r = q[1], k = q[2];
            for (int i = 0; i < 26; i++) {
                if (l == 0) odds += count[r][i]&1;
                else odds += (count[r][i]-count[l-1][i])&1;
            }
            if (odds/2 <= k) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};