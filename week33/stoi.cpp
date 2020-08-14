class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        while (i < str.size() && str[i] == ' ') i++;
        if (i == str.size()) return 0;
        bool minus = false;
        if (str[i] == '-') {
            minus = true;
            i++;
        } else if (str[i] == '+') i++;
        int64_t res = 0;
        while (i < str.size() && isdigit(str[i])) {
            res = 10*res + (str[i]-'0');
            i++;
            if (minus && res > INT_MAX) return INT_MIN;
            else if (!minus && res >= INT_MAX) return INT_MAX;
        }
        return minus ? -res : res;
    }
};