class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        sort(begin(nums), end(nums), greater<int>());
        vector<int> r;
        int t(0);
        for (auto n : nums) {
            if (t <= sum - t) {
                t += n;
                r.push_back(n);
            } else break;
        }
        return r;
    }
};