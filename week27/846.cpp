class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        deque<int> t;
        for (int i = 0; i < nums.size(); i++) {
            if (t.empty()) t.push_back(1);
            else if (nums[i] == nums[i-1]) t.back()++;
            else if (t.size() == k) {
                int d = t.front();
                for (auto& x : t) x -= d;
                while (!t.empty() && t.front() <= 0) {
                    if (t.front() < 0) return false;
                    else t.pop_front();
                }
                i--;
            } else {
                if (nums[i] == nums[i-1] + 1) t.push_back(1);
                else return false;
            }
        }
        if (!t.empty()) {
            if (t.size() < k) return false;
            for (auto x : t) if (x != t.front()) return false;
        }
        return true;
    }
};