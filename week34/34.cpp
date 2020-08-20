class Solution {
    using Iter = vector<int>::iterator;
    Iter find_left(Iter left, Iter right, int t) {
        int len = right - left;
        Iter it;
        while (len > 0) {
            it = left + len / 2;
            if (*it < t) {
                left = it + 1;
                len -= len/2 + 1;
            } else len = len/2;
        }
        return left;
    }
    Iter find_right(Iter left, Iter right, int t) {
        int len = right - left;
        Iter it;
        while (len > 0) {
            it = left + len/2;
            if (*it <= t) {
                left = it + 1;
                len -= len/2 + 1;
            } else len = len/2;
        }
        return left;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = find_left(nums.begin(), nums.end(), target);
        if (l == nums.end() || *l != target) return {-1, -1};
        auto r = find_right(l, nums.end(), target);
        return {static_cast<int>(l-nums.begin()), static_cast<int>(r-nums.begin()-1)};
    }
};