class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        for (int i = 1; i < n; i++) cardPoints[i] += cardPoints[i-1];
        if (n == k) return cardPoints.back();
        int res = cardPoints[n-1] - cardPoints[n-k-1];
        for (int i = 1; i <= k; i++) {
            res = max(res, cardPoints[i-1] + cardPoints[n-1] - cardPoints[n-k+i-1]);
        }
        return res;
    }
};