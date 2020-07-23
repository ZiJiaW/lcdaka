class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int t = m^n, i = 0;
        while (t) {
            t >>= 1;
            i++;
        }
        return ((m&n)>>i)<<i;
    }
};