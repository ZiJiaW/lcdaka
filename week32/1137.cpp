class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int x = 0, y = 1, z = 1, w = 0;
        while (--n >= 2) {
            w = x+y+z;
            x = y;
            y = z;
            z = w;
        }
        return z;
    }
};