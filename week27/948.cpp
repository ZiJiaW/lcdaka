class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(begin(tokens), end(tokens));
        int i = 0, j = tokens.size() - 1, res = 0, r = 0;
        while (i <= j) {
            if (P >= tokens[i]) {
                P -= tokens[i++];
                r++;
                res = max(res, r);
            } else if (r > 0) {
                P += tokens[j--];
                r--;
            } else break;
        }
        return res;
    }
};