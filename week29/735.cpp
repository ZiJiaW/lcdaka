class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (auto i : asteroids) {
            int flag = 2;
            while (!s.empty() && s.back() > 0 && i < 0) {
                if (-i == s.back()) {
                    flag = 1;
                    break;
                }
                else if (-i > s.back()) {
                    s.pop_back();
                    flag = 2;
                } else {
                    flag = 3;
                    break;
                }
            }
            if (flag == 1) s.pop_back();
            else if (flag == 2) s.push_back(i);
        }
        return s;
    }
};