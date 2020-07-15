class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size(), nMin = INT_MAX, nMax = INT_MIN;
        for (auto i : nums) {
            nMin = min(nMin, i);
            nMax = max(nMax, i);
        }
        int gap = (nMax - nMin)/(n+1) + 1;
        vector<int> mins(n+1, INT_MAX);
        vector<int> maxs(n+1, INT_MIN);
        int k;
        for (auto i : nums) {
            k = (i-nMin)/gap;
            mins[k] = min(mins[k], i);
            maxs[k] = max(maxs[k], i);
        }
        int lastMax = nMin, res = 0;
        for (int k = 0; k < n+1; k++) {
            if (mins[k] > maxs[k]) continue;
            res = max(res, mins[k] - lastMax);
            lastMax = maxs[k];
        }
        return res;
    }
};