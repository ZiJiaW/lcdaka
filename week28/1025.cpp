class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N+1, false);
        for (int i = 2; i <= N; i++) {
            for (int k = 1; k <= sqrt(i); k++) {
                if (i%k==0 && !dp[i-k]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};