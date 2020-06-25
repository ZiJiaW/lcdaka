class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vector<int> v(14, 0);
        int MIN = 15, MAX = -1;
        for (auto n : nums) {
            v[n]++;
            if (n > 0 && v[n] > 1) return false; 
            if (n > 0 && n < MIN) MIN = n;
            if (n > MAX) MAX = n;
        }
        return MAX - MIN <= 4;
    }
};