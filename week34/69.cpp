class Solution {
public:
    int mySqrt(int x) {
        int64_t lo = 0, hi = (int64_t)x+1;
        while (lo+1 < hi) {
            auto mid = lo+(hi-lo)/2;
            if (mid*mid <= x) lo = mid;
            else hi = mid;
        }
        return lo;
    }
};