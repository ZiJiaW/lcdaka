class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        if (k == 0) {
            bool pre = false;
            for (auto num : nums) {
                if (num == 0) {
                    if (pre) return true; 
                    else pre = true;
                } else pre = false;
            }
            return false;
        }
        unordered_set<long long> res({0});
        long long cur = nums[0] % k, pre = nums[0] % k;
        for (int i = 1; i < nums.size(); i++) {
            cur = (cur + nums[i]) % k;
            if (res.find(cur) != res.end()) return true;
            res.insert(pre);
            pre = cur;
        }
        return false;
    }
};