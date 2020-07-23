class Solution {
public:
    int hammingDistance(int x, int y) {
        int r = x^y;
        int res = 0;
        while (r > 0) {
            res += r&1;
            r >>= 1;
        }
        return res;
    }
};