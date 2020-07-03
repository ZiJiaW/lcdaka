class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x = 0, y = cost.back(), z = 0;
        for (int i = cost.size()-2; i >= 0; i--) {
            x = cost[i] + min(y, z);
            z = y;
            y = x;
        }
        return min(y, z);
    }
};