class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp0(n, 0);
        vector<int> dp1(n, 0);
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                dp1[i] = prices[i];
            } else {
                dp0[i] = max(dp1[i+1]-fee-prices[i], dp0[i+1]);
                dp1[i] = max(dp0[i+1]+prices[i], dp1[i+1]);
            }
        }
        return dp0[0];
    }
};