class Solution {
public:
    int waysToStep(int n) {
        if (n == 1) return 1;
        int mod = 1e9+7;
        int64_t x = 0, y = 1, z = 1, w = 0;
        for (int _ = 2; _ <= n; _++) {
            x = (y+z+w) % mod;
            w = z;
            z = y;
            y = x;
        }
        return (int)x;
    }
};