class Solution {
public:
    string toLowerCase(string str) {
        for (auto &c : str) c <= 90 && c >= 65 ? c += 32 : 0;
        return str;
    }
};