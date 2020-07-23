class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = 0, c = 0;
        for (auto i : nums) {
            if (c == 0) {
                n = i;
                c++;
            } else if (n == i) c++;
            else c--;
        }
        return n;
    }
};