class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        if (rods.empty()) return 0;
        int sum = accumulate(begin(rods), end(rods), 0);
        vector<vector<int>> dp(rods.size(), vector<int>(sum*2+1, -1));
        dp[0][sum-rods[0]] = rods[0];
        dp[0][sum+rods[0]] = 0;
        dp[0][sum] = 0;
        for (int i = 1; i < rods.size(); i++) {
            for (int d = -sum; d <= sum; d++) {
                if (dp[i-1][sum-d] != -1) 
                    dp[i][sum-d] = dp[i-1][sum-d];
                if (sum-d-rods[i] >= 0 && dp[i-1][sum-d-rods[i]] != -1) 
                    dp[i][sum-d] = max(dp[i][sum-d], dp[i-1][sum-d-rods[i]]);
                if (sum-d+rods[i] <= 2*sum && dp[i-1][sum-d+rods[i]] != -1) 
                    dp[i][sum-d] = max(dp[i][sum-d], rods[i]+dp[i-1][sum-d+rods[i]]);
            }
        }
        return dp[rods.size()-1][sum] >= 0 ? dp[rods.size()-1][sum] : 0;
    }
};