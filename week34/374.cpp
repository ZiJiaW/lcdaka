class Solution {
public:
    int guessNumber(int n) {
        int64_t lo = 1, hi = (int64_t)n+1;
        while (lo+1 < hi) {
            auto mid = lo + (hi-lo)/2;
            if (guess(mid) < 0) hi = mid;
            else if (guess(mid) > 0) lo = mid + 1;
            else return mid;
        }
        return lo;
    }
};