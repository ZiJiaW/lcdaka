class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        stack<int> s;
        vector<int> mins(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            mins[i] = min(nums[i], mins[i-1]);
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums[i] > s.top()) {
                if (mins[i] < s.top()) return true;
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};