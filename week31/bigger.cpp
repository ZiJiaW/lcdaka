class Solution {
public:
    int maximum(int a, int b) {
        int64_t dif = (int64_t)a - (int64_t)b;
        int flag = (dif>>63)&1;
        return a*(1-flag) + b*flag;
    }
};