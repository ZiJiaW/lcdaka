class Solution {
    int gcd(int i, int j) {
        return i == 0 ? j : gcd(j%i, i);
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (auto i : deck) m[i]++;
        int g = -1;
        for (auto &[_, k] : m) {
            if (g < 0) g = k;
            else g = g < k ? gcd(g, k) : gcd(k, g);
        }
        return g >= 2;
    }
};