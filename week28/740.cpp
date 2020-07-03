class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int count[10001] = {0};
        for (auto n : nums) count[n]++;
        int x = 0, y = 0, t;
        for (int i = 1; i < 10001; i++) {
            t = max(y, x + i*count[i]);
            x = y;
            y = t;
        }
        return y;
    }
};